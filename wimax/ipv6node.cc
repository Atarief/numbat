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

using namespace std;

/********************************************************************************/
/*** IPv6 Node ******************************************************************/
/********************************************************************************/

Define_Module(IPv6Node);


void IPv6Node::initialize()
{
    sendTimer = new cMessage("IPv6 send");
    scheduleAt(0.010, sendTimer);

    SentBytes = 0;
    SentPkts  = 0;
    RcvdBytes = 0;
    RcvdPkts  = 0;
    
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
}

void IPv6Node::handleMessage(cMessage *msg)
{
    if (msg==sendTimer) {
	generateTraffic();
	return;
    }
    
    ev << fullName() << ": Message " << msg->fullName() << " received." << endl;
    RcvdPkts++;
    RcvdBytes += msg->length();
    updateStats();

    delete msg;
}

void IPv6Node::generateTraffic()
{
    cMessage *m = new cMessage("IPv6 packet");
    m->setLength((long)exponential(100));
    SentPkts++;
    SentBytes += m->length();
    send(m, "ipOut");

    m = new cMessage("IPv6 packet");
    m->setLength((long)exponential(100));
    SentPkts++;
    SentBytes += m->length();
    send(m, "ipOut");

    m = new cMessage("IPv6 packet");
    m->setLength((long)exponential(100));
    SentPkts++;
    SentBytes += m->length();
    send(m, "ipOut");

    updateStats();

    scheduleAt(simTime()+(double)(0.025), sendTimer);

    // reschedule this timer
}

void IPv6Node::updateStats()
{
    char buf[80];
    sprintf(buf, "sent=%ld(%ld), rcvd=%ld(%ld)", 
	    SentPkts, SentBytes, RcvdPkts, RcvdBytes);
    if (ev.isGUI()) 
	displayString().setTagArg("t",0,buf);

    SentPktsVector.record(SentPkts);
    SentBytesVector.record(SentBytes);
    RcvdPktsVector.record(RcvdPkts);
    RcvdBytesVector.record(RcvdBytes);
}
