/**
 * @file   wmaxmaccs.h
 * @author Maciej Jureko <maciek01@gmail.com>
 * @date   2007-04-20 23:09:38+0100
 * 
 * @brief  WMax MAC convergence sublayer
 * @licence GNU GPLv2 or later
 * 
 */

#ifndef WMAXMACCS_H
#define WMAXMACCS_H

#include <omnetpp.h>
#include <string>
#include "Portable.h"
#include "ipv6msg_m.h"
#include "EtherFrame_m.h"

using namespace std;

/**************************************************************/
/*** STRUCTURES ***********************************************/
/**************************************************************/

typedef struct {
     uint16_t cid;
     uint16_t vlanid;
     //int gateIndex; 
     /// @todo IPv6 source and destination addr
     uint64_t macAddr;
     IPv6Addr dstAddr;
} WMaxMacCSRule;


/**************************************************************/
/*** MODULE DEFINITIONS STRUCTURES ****************************/
/**************************************************************/

class WMaxMacCS : public cSimpleModule {
public:

protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    /// Handle Messages going to Higher Layer
    virtual void handleUlMessage(cMessage *msg);
    /// Handle Messages going to Lower Layer
    virtual void handleDlMessage(cMessage *msg);
    virtual void updateLog();

    void dlMsgSend(cMessage * msg, int cid);
    IPv6Addr DstAddrGet(cMessage *msg);
    /**
     * Urb@n
     *
     * Get the Proper CID for the VLAN ID. If not supplied the
     * CID WMAX_CID_BROADCAST  is returned. Return -1 if not found.
     */
    //virtual int getCIDForVlan(int vlanid=-1);
    /**
     * Urb@n
     *
     * Get the MAC of a CID to be added in the EtherVlan info.
     */
    virtual std::string getMACForCID(int cid);
    /**
	 * Urb@n
	 *
	 * Get the Vlan of a CID to be added in the EtherVlan info.
	 */
	virtual int getVlanForCID(int cid);
    list<WMaxMacCSRule> csTable;
    bool BS;
};

ostream & operator <<(ostream & s, WMaxMacCSRule &f);

#endif
