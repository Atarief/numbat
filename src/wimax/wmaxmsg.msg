cplusplus {{
#include "wmaxmsg.h"
#include "IPv6Addr.h"
}}


struct WMaxUlMapIE;

struct WMaxDlMapIE;

struct WMaxBSFull;

struct WMaxQos;

struct WMaxRngReq;

struct WMaxRngRsp;

struct IPv6Addr;

//struct uint64_t;//MiM removed

// ********************************************************************************
// *** real WiMAX MAC messages ****************************************************
// ********************************************************************************


class WMaxMacHeader
{
    @customize(true);
    abstract int cid;
    abstract bool ht;
    abstract int bwr;
}

//message --> packet changes (MiM)
//message WMaxMsgDlMap
packet WMaxMsgDlMap
{
    WMaxDlMapIE IE[];
}


packet WMaxMsgUlMap
{
    WMaxUlMapIE IE[];
}

packet WMaxMsgDCD
{
    int confChangeCount;
}

packet WMaxMsgUCD
{
    int confChangeCount;
}

packet WMaxMsgRngReq
{
    int purpose;
    WMaxRngReq rngReq;
    IPv6Addr myIP; // used in remote autoconf

    // used during HO (to perform CID update and recreate connections at target BS)
    WMaxQos SfQos[];
    int SfCid[];
}

packet WMaxMsgRngRsp
{
    int purpose;
    WMaxRngRsp rngRsp;

    // used during HO (to perform CID update and recreate connections at target BS)
    int oldCid[];
    int newCid[];
}

packet WMaxMsgSbcReq
{
}
packet WMaxMsgSbcRsp
{
}

packet WMaxMsgPkmReq
{
    int code;
}

packet WMaxMsgPkmRsp
{
    int code;
}

packet WMaxMsgRegReq
{
}
packet WMaxMsgRegRsp
{
}

packet WMaxMsgMobScnReq
{
}

packet WMaxMsgMobScnRsp
{
}

packet WMaxMsgMSHOREQ
{
    WMaxBSFull BSFull[];
}

packet WMaxMsgBSHORSP
{
    WMaxBSFull BSFull[];
}

packet WMaxMsgHOIND
{
    int status;
    WMaxBSFull target;
}

packet WMaxMsgCDMA
{
    int code;
    int purpose; // use WMaxCdmaPurpose type here

    /// @todo - add other parameters
}

packet WMaxMsgBWR
{
}

// Table 38
// Urb@n
// Add vlan ID so the BS knows the vlan
// for this cid
//
packet WMaxMsgDsaReq
{
    int transactionID;
    WMaxQos qos[];
    // Used to bridge in the BS
    int vlanId[];
}

// Table 56
packet WMaxMsgDsxRvd
{
    int transactionID;
    int confirmationCode; // Table 384
}
cplusplus {{
   enum ConfirmationConde{
        WMAX_CONFIRMATION_CODE_SUCCESS, WMAX_CONFIRMATION_CODE_REJECT
   };
}}

// Table 39
packet WMaxMsgDsaRsp
{
    int transactionID;
    int confirmationCode; // Table 384
    WMaxQos qos[];
    int cid;
}

// Table 40
packet WMaxMsgDsaAck
{
    int transactionID;
    int confirmationCode; // Table 384
    WMaxQos qos[];
}

// ********************************************************************************
// *** fake packets used to communicate between modules **************************
// ********************************************************************************

// this packet is sent once every 5ms from MAC to PHY to initiate next frame
packet WMaxPhyDummyFrameStart
{
}

//
// Urb@n
// - Add service name on flow creation so that
// 	 is more understood when logging statistics.
//
packet WMaxEvent_FlowCreationStart
{
    int skipDSA;
    int gateIndex;
    string srvName;
    WMaxQos qos[];
}

//
// Urb@n
// - Add connection based on the 
//	 VLAN ID
//
packet WMaxMacAddConn
{
    int gateIndex;
    int cid;
    string srvName;
    WMaxQos qos[];
    int vlanId[];
    IPv6Addr dstAddr;
    uint64_t macAddr;
}

packet WMaxMacAddMngmntConn
{
    int cid;
}

packet WMaxEvent_DelConn
{
    int cid;
    bool isBasic;
}

packet WMaxEvent_FlowEnable
{
}

packet WMaxEvent_FlowDisable
{
}

packet WMaxMacTerminateAllConns
{
}


