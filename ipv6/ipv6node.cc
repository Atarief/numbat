/**
 * @file    ipv6node.h
 * @author  Tomasz Mrugalski <thomson@klub.com.pl>
 * @date    Sat Nov 18 18:42:04 2006
 *
 * @brief  IPv6 transmitter/receiver
 * 
 * Published under GNU GPLv2 or later 
 */

#include <omnetpp.h>
#include <string>
#include "ipv6node.h"
#include "logger.h"

using namespace std;

/********************************************************************************/
/*** IPv6 Node ******************************************************************/
/********************************************************************************/

Define_Module(IPv6Node);


void IPv6Node::initialize()
{

    SentBytes = 0;
    SentPkts  = 0;
    RcvdBytes = 0;
    RcvdPkts  = 0;

    this->BurstInterval   = (double)par("BurstInterval");
    this->BurstSize       = (int)par("BurstSize");
    this->MaxPacketSize = (int)par("BurstPacketSize");

    double initialDelay = (double)par("InitialDelay");

    cModule * ss = parentModule()->parentModule();
    char buf[80];
    sprintf(buf, "%s[%d]", fullName(), ss->index());
    if (ev.isGUI()) 
        setName(buf);

    Log(Info) << " traffic parameters: BurstSize=" << BurstSize << ", PktSize=" << MinPacketSize
	      << ".." << MaxPacketSize << ", BurstInterval=" << BurstInterval << LogEnd;

    sendTimer = new cMessage("IPv6 send");
    scheduleAt(initialDelay, sendTimer);
    
    std::string x;
    x = fullName();
    x = x+std::string(" Sent Packets");
    SentPktsVector.setName(x.c_str());

    x = fullName();
    x = x+std::string(" Sent Bytes");
    SentBytesVector.setName(x.c_str());

    x = fullName();
    x = x+std::string(" Received Packets");
    RcvdPktsVector.setName(x.c_str());

    x = fullName();
    x = x+std::string(" Received Bytes");
    RcvdBytesVector.setName(x.c_str());

    x = fullName();
    x = x+std::string(" Sent Pkt size");
    SentPktSizeVector.setName(x.c_str());

    x = fullName();
    x = x+std::string(" Rcvd Pkt size");
    RcvdPktSizeVector.setName(x.c_str());

    MinPacketSize = 48; // IPv6 header (40) + UDP header (8)
    Mean   = (MaxPacketSize+MinPacketSize)/2.0;
    StdDev = 0.8*(Mean-MinPacketSize);
}

void IPv6Node::handleMessage(cMessage *msg)
{
    if (msg==sendTimer) {
	generateTraffic();
	return;
    }
    
    Log(Debug) << "Message " << msg->fullName() << " received." << endl;
    RcvdPkts++;
    long len = msg->byteLength();
    RcvdBytes += len;
    RcvdPktSizeVector.record(len);
    updateStats();

    delete msg;
}

void IPv6Node::generateTraffic()
{
    cMessage *m = 0;

    for (int i=0; i<BurstSize; i++) 
    {
	m = new cMessage("IPv6 packet");
	
	long len;
	do {
	    len = (long)normal(Mean, StdDev);
	} while (len<MinPacketSize || len>MaxPacketSize);

	m->setByteLength(len);
	SentPkts++;
	SentBytes += len;
	Log(Debug) << "Sending message " << len << " bytes long." << LogEnd;
	send(m, "ipOut");

	SentPktSizeVector.record(len);
    }

    updateStats();

    scheduleAt(simTime()+(double)(BurstInterval), sendTimer);

    // reschedule this timer
}

void IPv6Node::updateStats()
{
    char buf[80];
    sprintf(buf, "sent=%u(%u), rcvd=%u(%u)", 
	    SentPkts, SentBytes, RcvdPkts, RcvdBytes);
    if (ev.isGUI()) 
	displayString().setTagArg("t",0,buf);

    SentPktsVector.record(SentPkts);
    SentBytesVector.record(SentBytes);
    RcvdPktsVector.record(RcvdPkts);
    RcvdBytesVector.record(RcvdBytes);
}
