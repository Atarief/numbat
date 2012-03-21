/**
 * @file    wmaxmaccs.cc
 * @author  Maciej Jureko <maciek01@gmail.com>
 * @changes Tomasz Mrugalski <thomson@klub.com.pl>
 * @date    2007-04-20 23:09:38+0100
 * 
 * @brief   WMax MAC convergence sublayer
 * @licence GNU GPLv2 or later
 *
 */

#include <omnetpp.h>
#include <string>
#include "wmaxmaccs.h"
#include "IPv6Addr.h"
#include "wmaxmac.h"
#include "logger.h"
#include "ssinfo.h"
#include "wmaxctrl.h"

// INET / MANET
#include "ARPPacket_m.h"

// Vlan
#include "Ieee802VlanCtrl_m.h"

using namespace std;

ostream & operator <<(ostream & s, WMaxMacCSRule &rule)
{
    s << "cid=" << rule.cid << ", Vlan ID="<< rule.vlanid << ", dstAddr=" << rule.dstAddr.plain() << ", mac=" << MacToString(rule.macAddr);
    return s;
}

/********************************************************************************/
/*** WMaxMacCS ******************************************************************/
/********************************************************************************/

Define_Module(WMaxMacCS);

void WMaxMacCS::initialize() {
  WATCH_LIST(csTable);
  std::string name=getFullName();
  string type;
  if (!name.find("ss")) {
      BS = false;
      type = "ss";
  } else {
      BS = true;
      type = "bs";
  }

    // add number prefix to the module name
    cModule * ss = getParentModule()->getParentModule();
	char buf[80];
	sprintf(buf,"%sCS%d",type.c_str(),WMaxCtrlBS::getIDFromName((char *)ss->getName()));
	setName(buf);
}


void WMaxMacCS::handleMessage(cMessage *msg) {


    if (dynamic_cast<WMaxMacTerminateAllConns*>(msg)) {
        Log(Notice) << "All connections terminated." << LogEnd;
        csTable.clear();
        delete msg;
        return;
    }

    if (WMaxMacAddConn *addconn = dynamic_cast<WMaxMacAddConn*>(msg)) {
        WMaxMacCSRule rule = {0};
        rule.cid     = addconn->getCid();
        rule.dstAddr = addconn->getDstAddr();
        rule.macAddr = addconn->getMacAddr();
        rule.vlanid  = addconn->getVlanId(0);
	
        list<WMaxMacCSRule>::iterator it;
        csTable.push_back(rule);
        updateLog();
        delete msg;
        return;
    }

    if (WMaxEvent_DelConn *delcon = dynamic_cast<WMaxEvent_DelConn*>(msg)) {
		if (delcon->getIsBasic())
		{
			// there are no CS rules for basic connections
			delete msg;
			return;
		}
        list<WMaxMacCSRule>::iterator it;
        for(it=csTable.begin(); it!=csTable.end(); it++) {
            if((it->cid == delcon->getCid())) {
                csTable.erase(it);
                Log(Notice) << "Connection cid=" << delcon->getCid() << " removed." << LogEnd;
                updateLog();
                delete msg;
                return;
            }
        }
        Log(Error) << "Unable to delete connection with cid=" << delcon->getCid() << "." << LogEnd;
        delete msg;
        return;
    }

    cGate * gate = msg->getArrivalGate();
    if(!strcmp(gate->getFullName(),"macIn")) {
        handleUlMessage(msg);
        return;
    }

    handleDlMessage(msg);
}

/**
 * Urb@n
 *
 * The message arrived is a cPacket ALWAYS. The Numbat encapsulates the original
 * packet in a cPacket (instead of creating a new packet format). The outer
 * cPacket has the WiMax Header in the Control Info.
 *
 * If it has Ieee802Ctrl, leave it to go through AS IS. Messages originated by
 * the BS it self have no cid ?! and thus they cannot be mapped. So WE LEAVE
 * THEM THROUGH AS THEY ARE. It is the BS responsibility to make the proper format.
 *
 */
void WMaxMacCS::handleUlMessage(cMessage *msg) {

	// Check if this is an EtherFrame...
	// These messages are ONLY generated from the
	// BS it self! Urb@n
	Ieee802Ctrl * ethctl = dynamic_cast<Ieee802Ctrl *>(msg->getControlInfo());


	if (ethctl){
		send(msg, "ipOut", 0);
		// Add a dummy CID to forward from the BS
		if (getMACForCID(0)==""){
			WMaxMacCSRule rule = {0};
			rule.cid     = 0;
			rule.dstAddr = IPv6Addr();
			rule.macAddr = NULL;
			rule.vlanid  = 0;
			csTable.push_back(rule);
			updateLog();
		}
		return;
	}


	int cid = (dynamic_cast<WMaxMacHeader *>(msg->getControlInfo()))->cid;

	// Check and cast to cPacket
	cPacket * encap = (dynamic_cast<cPacket *>(msg))->decapsulate();

	// Delete old
	delete msg;

	if (!encap){
		opp_error("WMaxMacCS::handleUlMessage: cMessage Received but it not a cPacket");
	}

	// Check for BROADCASTS
	if (cid == WMAX_CID_BROADCAST){
		if (dynamic_cast<ARPPacket *>(encap)){
			Ieee802Ctrl * ctl = new Ieee802Ctrl();
			ctl->setSrc( (dynamic_cast<ARPPacket *>(encap))->getSrcMACAddress());
			encap->setControlInfo(ctl);
		}else{
			EV << "*** UNKNOWN BroadCast Packet... cannot encapsulate to ether vlan... DROPPING"<<endl;
			delete encap;
			return;
		}
	// NON BC Message
	} else {

		MACAddress src_mac(getMACForCID(cid).c_str());
		int vlanid = getVlanForCID(cid);

		if (src_mac == MACAddress::UNSPECIFIED_ADDRESS){
			EV << "*** Cannot find src MAC address... DROPPING"<<endl;
			delete msg;
		}

		if (vlanid != -1){
			// Vlan Forward
			EV << "Forwarding to vlan: "<<vlanid<<endl;
			// Create Control Info for ether ENCAP
			Ieee802VlanCtrl * ctl = new Ieee802VlanCtrl();
			ctl->setSrc(src_mac);
			/**
			 * Fake Interface name to force VLAN encapsulation
			 */
			char ifname[10];
			sprintf(ifname, "0.%d", vlanid);
			ctl->setIfName(ifname);

			encap->removeControlInfo();
			encap->setControlInfo(ctl);
		}else{
			// No VLAN
			EV << "Forwarding (NO VLAN): "<<vlanid<<endl;
			Ieee802Ctrl * ctl = new Ieee802Ctrl();
			ctl->setSrc( src_mac);
			encap->setControlInfo(ctl);
		}
	}

    send(encap, "ipOut", 0);
}

IPv6Addr WMaxMacCS::DstAddrGet(cMessage *msg)
{
    if (dynamic_cast<IPv6Packet*>(msg))
    {
    	IPv6Packet* ipMsg = dynamic_cast<IPv6Packet*>(msg);
      return ipMsg->getDstIP();
    }
    EV << "Non-IPv6 message is trying to sneak thru WMaxMacCS module: "<< getFullName() << endl;
    return IPv6Addr();
}

std::string WMaxMacCS::getMACForCID(int cid){
	string ret="";
	list<WMaxMacCSRule>::iterator it;
	for(it=csTable.begin(); it!=csTable.end(); it++) {
		if (it->cid == cid)
			return MacToString(it->macAddr);
	}

	return ret;
}

int WMaxMacCS::getVlanForCID(int cid){
	list<WMaxMacCSRule>::iterator it;
	for(it=csTable.begin(); it!=csTable.end(); it++) {
		if (it->cid == cid)
			return it->vlanid;
	}

	return -1;

}


/**
 * Urb@n
 * Handle messages based on the vlan ID
 */
void WMaxMacCS::handleDlMessage(cMessage *msg) {

	// ---- Not initialized Yet
	if (csTable.size() == 0)
	{
		Log(Cont)  << "Unable to forward message(" << msg->getFullName() << "), no CS rules defined." << LogEnd;
		delete msg;
		return;
	}

	// Check for ARP from the higher layer
	// Should be checked later... (see bellow)
	if (dynamic_cast<ARPPacket *>(msg)){
		// Remember; DELETE CONTROL INFO
		msg->removeControlInfo();
		// Send to CID WMAX_CID_BROADCAST
		dlMsgSend(msg, WMAX_CID_BROADCAST);
		Log(Debug) << "Broadcast ARP message (" << msg->getFullName()
				   << ") sent to CID=" <<WMAX_CID_BROADCAST<< LogEnd;
		return;
	}

	/*
	 *  Try to find a valid vlan/CID mapping.
	 *  If not found send to the WMAX_CID_BROADCAST.
	 */
	Ieee802VlanCtrl * ctrl = dynamic_cast<Ieee802VlanCtrl *>(msg->removeControlInfo());

	// -- BC
	if (ctrl == NULL){
		// Send to CID WMAX_CID_BROADCAST
		dlMsgSend(msg, WMAX_CID_BROADCAST);
		Log(Debug) << "Broadcast message (" << msg->getFullName() << ") sent to CID=" <<WMAX_CID_BROADCAST<< LogEnd;
		return;
	}

	// -- CID
	int vlanid=0;
	std::string ifname = ctrl->getIfName();
	int subif = ifname.find('.');
	if (subif!=(int)std::string::npos)
		vlanid = atoi(ifname.substr(subif+1).c_str());

	// Check again... to be sure
	if (vlanid == 0) {
		dlMsgSend(msg, WMAX_CID_BROADCAST);
		Log(Debug) << "NO VLAN INFO in Control field of the message (" << msg->getFullName() << ") sent to CID=" <<WMAX_CID_BROADCAST<< LogEnd;
		return;
	}

	// ---- Scan table
	list<WMaxMacCSRule>::iterator it;
	for(it=csTable.begin(); it!=csTable.end(); it++) {
		if (it->vlanid == vlanid){
			dlMsgSend(msg, it->cid);
			Log(Debug) << "Trying to forward DL msg (" << msg->getFullName() << ") vlanid=" << it->vlanid
			       << " to CID="<<it->cid<< ", MAC=" << (it->macAddr?MacToString(it->macAddr):"unknown") << LogEnd;
			return;
		}

	}


	// ** FIXME: AFTER CHECKING VLAN ID (ARPReQ Will be BC in a VLAN)
	// THIS DOESN'T WORK FOR BE CIDs cause they do not meet the minimum
	// allocation criteria, and get 0 BW! So ARP times out


	Log(Info) << "Unable to find a proper connection for msg(" << msg->getFullName() << ") from vlan=" << vlanid << endl;

	delete msg;
	return;


}

void WMaxMacCS::dlMsgSend(cMessage * msg, int cid)
{
  /*cMessage*/ cPacket *wmaxmacmsg = new cPacket/*Message*/(msg->getFullName());//MiM
  wmaxmacmsg->encapsulate(check_and_cast<cPacket *>(msg)); //MiM
    
    WMaxMacHeader * hdr = new WMaxMacHeader();
    hdr->cid = cid;
    wmaxmacmsg->setControlInfo(hdr);
    
    send(wmaxmacmsg, "macOut");
}

void WMaxMacCS::updateLog() {
    list<WMaxMacCSRule>::iterator it;
    string log;
    log = "Convergence Sublayer clasifier: ";
    for(it=csTable.begin(); it!=csTable.end(); it++) {
        stringstream ss_cid;
        string st_cid;
        ss_cid << it->cid;
        ss_cid >> st_cid;
        log = log + "CID=" + st_cid + " | ";
    }
    Log(Notice) << log << LogEnd;
}
