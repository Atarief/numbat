/**
 * @file   ssinfo.cc
 * @author Maciej Jureko <maciek01@gmail.com>
 * @date   2007-06-30 21:01:52+0200
 * 
 * @brief  SS parameters
 * @licence GNU GPLv2
 * 
 */

#include <omnetpp.h>
#include <string>
#include <math.h>
#include "logger.h"
#include "ssinfo.h"

using namespace std;

ostream & operator<<(ostream & str, SSInfo_t &ss) {
    str << "MAC=" << ss.getMac() << ", basicCid=" << ss.basicCid << " sfCnt="
        << ss.sfCnt;
    for (int i=0; i < ss.sfCnt; i++) {
      str << " sf[" << i << "].cid=" << ss.sf[i].cid;
    }
    return str;
}

std::string SSInfo_t::getMac() {
    char buf[30];
    sprintf(buf, "%02x:%02x:%02x:%02x:%02x:%02x", 
	    (unsigned char)((macAddr >> 40) & 0xff),
	    (unsigned char)((macAddr >> 32) & 0xff),
	    (unsigned char)((macAddr >> 24) & 0xff),
	    (unsigned char)((macAddr >> 16) & 0xff),
	    (unsigned char)((macAddr >>  8) & 0xff),
	    (unsigned char)((macAddr )      & 0xff));
    return string(buf);
}

/********************************************************************************/
/*** ssInfo  ********************************************************************/
/********************************************************************************/

Define_Module(ssInfo);

void ssInfo::initialize() {
    info.macAddr = ((uint64_t)0x0018de << 24) + (rand()%(((uint64_t)1 << 24) - 1));
    info.basicCid = 0;

    CLEAR(&hoInfo);

    hoInfo.isMobile = parentModule()->par("wmaxIsMobile");
    hoInfo.wmax.hoOptim = parentModule()->par("wmaxHoOptim");


    hoInfo.ip.DadType = (DhcpDadType)(int)parentModule()->par("dadType");
    hoInfo.dhcp.skipInitialDelay = parentModule()->par("dhcpSkipInitialDelay");
    hoInfo.dhcp.pref255 = parentModule()->par("dhcpPref255");
    hoInfo.dhcp.rapidCommit = parentModule()->par("dhcpRapidCommit");

    int initialBS = parentModule()->par("initialBS");

    stringUpdate();
    Log(Notice) << "Creating new SS: " << info.getMac() << ", hoOptim=" << hoInfo.wmax.hoOptim 
		<< ", isMobile=" << hoInfo.isMobile << ", initialBS=" << initialBS << LogEnd;
    Log(Notice) << "New SS: " << info.getMac() << ", dadType=" << hoInfo.ip.DadType 
		<< ", dhcpSkipInitialDelay=" << hoInfo.dhcp.skipInitialDelay << ", dhcpPref255=" << hoInfo.dhcp.pref255
		<< ", dhcpRapidCommit=" << hoInfo.dhcp.rapidCommit << LogEnd;
}

void ssInfo::stringUpdate() {

    if (ev.isGUI()) {
        stringstream displayIt;
        displayIt << "macAddr=" << info.getMac() << endl;
        displayIt << "basicCID=" << dec << info.basicCid;

        displayString().setTagArg("t",0, (displayIt.str()).c_str());
    }
}
