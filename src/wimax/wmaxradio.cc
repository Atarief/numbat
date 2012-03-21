/**
 * @file   wmaxmac.h
 * @author Tomasz Mrugalski <thomson@klub.com.pl>
 * @date   2007-06-25 01:27:46+0200
 * 
 * @brief  WMax Radio connector (used to connect multiple SSes to one BS)
 * @licence GNU GPLv2
 * 
 */

#include <omnetpp.h>
#include <string>
#include "wmaxradio.h"
#include "logger.h"

#include "ModuleAccess.h"
#include "ChannelControl.h"

/********************************************************************************/
/*** IPv6 Node ******************************************************************/
/********************************************************************************/

Define_Module(WMaxRadio);


void WMaxRadio::initialize()
{
	// This is to register the BASE STATION!
	ChannelControl * cc = dynamic_cast<ChannelControl *>(findModuleSomewhereUp(par("controlModuleName").stdstringValue().c_str(), this));

	if (cc){
		cModule* BS = getParentModule();
		Coord c;
		c.x = atoi(BS->getDisplayString().getTagArg("p",0));
		c.y = atoi(BS->getDisplayString().getTagArg("p",1));
		cc->registerHost(BS, c, gate("radioIn",0));
	}
}

void WMaxRadio::handleMessage(cMessage *msg)
{
    // radioOut, radioIn, phyOut, phyIn
    cGate * g = msg->getArrivalGate();
    if (!strcmp(g->getFullName(),"phyIn")) {
	// Broadcast transmission (BS->all SSes)
	g = gate("radioIn", 0);
	for (int i=0; i<g->size(); i++) {
	    g = gate("radioOut", i);
	    if (g->isConnected()) {
		cMessage * copy = (cMessage*)msg->dup();
		if (msg->getControlInfo()) {
		    cPolymorphic * hdr = msg->getControlInfo();
		    cPolymorphic * hdr2 = hdr->dup();
		    copy->setControlInfo(hdr2);
		}
		send(copy, "radioOut", i);
	    }
	}
	delete msg;
	return;
    }

    // unicast transmission (SS -> BS)
    send(msg, "phyOut");	
}

void WMaxRadio::connect(cModule * ssif)
{
    Log(Debug) << "Connecting SS " << ssif->getParentModule()->getFullName() << " to this radio." << LogEnd;

    int maxSS = gate("radioOut",0)->size();

    cModule * bs = getParentModule();

    for (int i=0; i < maxSS; i++) {
		cGate * g = gate("radioOut", i);
		Log(Debug) << "Checking gate: radioOut[" << i << "]: " << (g->isConnected()?"CONNECTED":"NOT CONN") << LogEnd;
		if (!g->isConnected()) {

			// BS->SS
			cGate * bsGate = bs->gate("out",i);
			bsGate->disconnect();
			// radioOut --> BS out
			g->connectTo(bsGate);
			// BS out --> SS radioIn
			bsGate->connectTo(ssif->getParentModule()->gate("radioIn"));

			// SS->BS
			bsGate = bs->gate("in", i);
			// radioIn <-- BS in
			g = gate("radioIn", i);
			bsGate->connectTo(g);
			// BS in <-- SS radioOut
			ssif->getParentModule()->gate("radioOut")->disconnect();
			ssif->getParentModule()->gate("radioOut")->connectTo(bsGate);

			return;

		}
    }
}

void WMaxRadio::disconnect(cModule * ssIf, bool fromDestructor)
{
	Enter_Method_Silent("");
    if (!ssIf->gate("out")->getNextGate()->isConnected()) { //Urban ->getNextGate()
    	return;
    }
    
    cGate * bsGate = ssIf->gate("out")->getNextGate()->getNextGate(); //Urban ->getNextGate()
    cModule * bs = bsGate->getOwnerModule();

    Log(Debug) << "Disconnecting SS " << ssIf->getFullName() << " from " << bs->getFullName() << "." << LogEnd;
    if (bs!=getParentModule()) {
    	opp_error("Attempted to disconnect from the wrong BS.\n");
    }

    int ind = bsGate->getIndex();
    
    gate("radioOut", ind)->disconnect();
    gate("radioIn", ind)->disconnect();

    bs->gate("in", ind)->disconnect();
    bs->gate("out", ind)->disconnect();

    // Urb@n Dynamically remove modules call disconnect, but the do not send
    // WMaxMsgHOIND... so fake it here!
    if (fromDestructor){
    	Log(Debug) << "WMaxRadio::disconnect called from a destructor, sending WMaxMsgHOIND message to upper layers"<<endl;
		WMaxMsgHOIND * hoInd = new WMaxMsgHOIND();
		hoInd->setName("HO-IND");
		// Set Header
		ssInfo * ssnfo = dynamic_cast<ssInfo *>(ssIf->getSubmodule("ssInfo"));
		// Sanity Check
		if (!ssnfo) {
			opp_error("NO SSINFO!!! SHIT :(");
			return;
		}
		WMaxMacHeader * hdr = new WMaxMacHeader();
		hdr->cid = ssnfo->info.basicCid;;
		hoInd->setControlInfo(hdr);

		send(hoInd,"phyOut");
    }



}
