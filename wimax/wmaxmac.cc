/**
 * @file   wmaxmac.c
 * @author Tomasz Mrugalski <thomson@klub.com.pl>
 * @date   Mon Nov 20 00:26:38 2006
 * 
 * @brief  WMaxMAC implementation
 * 
 * published under GNU GPLv2 or later
 */

#include <omnetpp.h>
#include "wmaxmac.h"
#include "wmaxmsg_m.h"

using namespace std;

/********************************************************************************/
/*** WMax Mac (common for BS/SS) ************************************************/
/********************************************************************************/

bool WMaxMac::addConn(WMaxConn conn)
{
    /// @todo - check if CID and sfid are unique
    Conns.push_back(conn);
    ev << "Connection sfid=" << conn.sfid << ", cid=" << conn.cid << ", connection type=";
    switch (conn.type) {
    case WMAX_CONN_TYPE_UGS:
	ev << "UGS";
	break;
    case WMAX_CONN_TYPE_BE:
	ev << "BestEffort";
	break;
    }
    ev << " configured." << endl;
    //setDisplayString("Conns"); // this doesn't work. Strange
    return true;
}
 
bool WMaxMac::delConn(uint32_t sfid)
{
    /// @todo - implement this
    return false;
}

/********************************************************************************/
/*** WMax Mac BS ****************************************************************/
/********************************************************************************/
Define_Module(WMaxMacBS);

void WMaxMacBS::initialize()
{
    SendQueue.setName("SendQueue");

    TxStart = new cMessage("TxStart");
    scheduleAt(0.0, TxStart);

    Conns.clear();

    WMaxConn conn;
    conn.type= WMAX_CONN_TYPE_UGS;
    conn.sfid = 1;
    conn.cid = 1024;
    conn.dataLen = 100;
    addConn(conn);
    
    conn.type= WMAX_CONN_TYPE_BE;
    conn.sfid = 2;
    conn.cid = 1025;
    conn.dataLen = 100;
    addConn(conn);
}

void WMaxMacBS::handleMessage(cMessage *msg)
{
    cGate * gate = msg->arrivalGate();
    if (msg==TxStart) {
	schedule();
	scheduleAt(simTime()+(double)par("FrameLength"), TxStart);
	return;
    }
    if (!strcmp(gate->fullName(),"phyIn")) {
	handleUlMessage(msg);
    }
    if (!strcmp(gate->fullName(),"ipIn")) {
	handleDlMessage(msg);
    }
}


void WMaxMacBS::schedule()
{
    int i;
    int ieCnt = 0;
    /// @todo - write some scheduling module

    // prepare DL 
    WMaxMsgDlMap * dlmap = new WMaxMsgDlMap("DL-MAP");
    dlmap->setName("DL-MAP");
    ieCnt = 0;
    if (SendQueue.length()) {
	for (i=0;i<1; i++) {
	    /// @todo - fix this condition: use frame length instead of sending one simple frame
	    ieCnt++;
	    dlmap->setIEArraySize(ieCnt);
	    cMessage * msg = (cMessage*)SendQueue.pop();
	    WMaxMapIE ie;
	    ie.cid = 0;
	    ie.dataLen = msg->length();
	    send(msg, "phyOut");
	}
    }

    ev << "Generating DL-MAP: " << dlmap->getIEArraySize() << "IE(s)" << endl;
    send(dlmap, "phyOut");

    // prepare UL
    WMaxMsgUlMap * ulmap = new WMaxMsgUlMap("UL-MAP");
    ieCnt = 0;
    
    for (list<WMaxConn>::iterator it=Conns.begin(); it!=Conns.end(); it++) {
	// for each configured service flow, grant some bandwidth (if necessary)
	ev << "#### type=" << it->type << ", sfid=" << it->sfid << ", cid=" << it->cid << endl;
	switch (it->type) {
	case WMAX_CONN_TYPE_BE:
	    /// @todo - best effort not supported yet
	    break;
	case WMAX_CONN_TYPE_UGS:
	    ieCnt++;
	    ulmap->setIEArraySize(ieCnt);
	    WMaxMapIE ie;
	    ie.cid = it->cid;
	    ie.dataLen = it->dataLen;
	    ulmap->setIE(ieCnt-1, ie);
	    break;
	}
    }

    ev << fullName() << ": Generating UL-MAP: " << ulmap->getIEArraySize() << "IE(s)" << endl;
    send(ulmap, "phyOut");

    // trigger PHY to start frame
    WMaxPhyDummyFrameStart * frameStart = new WMaxPhyDummyFrameStart();
    ev << fullName() << ": Generating FrameStart trigger for PHY" << endl;
    send(frameStart, "phyOut");
}

void WMaxMacBS::handleDlMessage(cMessage *msg)
{
    SendQueue.insert(msg);
}

void WMaxMacBS::handleUlMessage(cMessage *msg)
{
    /// @todo - check if this really IPv6
    ev << ": sending message to IPv6 layer." << endl;
    send(msg, "ipOut");
}

/********************************************************************************/
/*** WMax Mac SS ****************************************************************/
/********************************************************************************/
Define_Module(WMaxMacSS);

void WMaxMacSS::initialize()
{
    SendQueue.setName("SendQueue");

    CLEAR(&Stats);

    Conns.clear();
    WMaxConn conn;
    conn.type= WMAX_CONN_TYPE_UGS;
    conn.sfid = 1;
    conn.cid = 1024;
    addConn(conn);
    
    conn.type= WMAX_CONN_TYPE_BE;
    conn.sfid = 2;
    conn.cid = 1025;
    addConn(conn);
}

void WMaxMacSS::handleMessage(cMessage *msg)
{
    cGate * gate = msg->arrivalGate();
    ev << fullName() << ":Message " << msg->fullName() << " received on gate: " << gate->fullName() << endl;
    if (!strcmp(gate->fullName(),"phyIn")) {
	handleUlMessage(msg);
    }
    if (!strcmp(gate->fullName(),"ipIn")) {
	handleDlMessage(msg);
    }
}

void WMaxMacSS::handleDlMessage(cMessage *msg)
{
    ev << fullName() << ": Queueing message." << endl;
    SendQueue.insert(msg);
}

void WMaxMacSS::handleUlMessage(cMessage *msg)
{
    if (dynamic_cast<WMaxMsgUlMap*>(msg)) {
	Stats.ulmaps++;
	schedule(dynamic_cast<WMaxMsgUlMap*>(msg));
	return;
    }

    if (dynamic_cast<WMaxMsgDlMap*>(msg)) {
	Stats.dlmaps++;
	WMaxMsgDlMap* dlmap = dynamic_cast<WMaxMsgDlMap*>(msg);
	ev << fullName() << "DL-MAP received: expecting " << dlmap->getIEArraySize() << " messages in this frame." << endl;
	delete msg;
	return;
    }

    /// @todo - if packet is IPv6, then handle it to upper layer
    send(msg, "ipOut");
}

void WMaxMacSS::schedule(WMaxMsgUlMap * ulmap)
{
    int bandwidth = 0;
    ev << "UL-MAP received with " << ulmap->getIEArraySize() << "IE(s)" << endl;
    int i;
    for (i=0; i<ulmap->getIEArraySize(); i++) {
	WMaxMapIE & ie = ulmap->getIE(i);
	for (list<WMaxConn>::iterator it = Conns.begin(); it!=Conns.end(); it++) {
	    if (it->cid==ie.cid) {
		bandwidth += ie.dataLen;
		ev << "#### UL-MAP entry: dataLen=" << it->dataLen << ", total bandwidth=" << bandwidth << endl;
		Stats.grants++;
	    }
	    
	}
    }

    if (SendQueue.length()) {
	ev << fullName() << ": Sending message" << endl;
	cMessage * msg = (cMessage*)SendQueue.pop();
	send(msg, "phyOut");
    }

    delete ulmap;
    Stats.bandwidth += bandwidth;

    WMaxPhyDummyFrameStart * frameStart = new WMaxPhyDummyFrameStart();
    ev << fullName() << ": Generating FrameStart trigger for PHY" << endl;
    send(frameStart, "phyOut");
}

void WMaxMacSS::finish()
{
    ev << " Stats for " << fullName() << endl;
    ev << "-----------------------" << endl;
    ev << "Grants            : " << Stats.grants << endl;
    ev << "Bandwidth granted : " << Stats.bandwidth << endl;
    ev << "UL-MAPs received  : " << Stats.ulmaps << endl;
    ev << "DL-MAPs received  : " << Stats.dlmaps << endl;
}
