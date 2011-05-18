#ifndef WMAXMSG_H
#define WMAXMSG_H

#include "Portable.h"
#include <omnetpp.h>
#include <iostream>

typedef enum
{
    WMAX_CONN_TYPE_BE,    // best effort
    WMAX_CONN_TYPE_RTPS,
    WMAX_CONN_TYPE_NRTPS, // Non-Real Time Packet Switched
    WMAX_CONN_TYPE_UGS    // Unsolicited Grant Interval
} WMaxConnType;

typedef enum
{
    WMAX_PKM_SA_TEK_CHALLENGE,
    WMAX_PKM_SA_TEK_REQ,
    WMAX_PKM_SA_TEK_RSP
} WMaxPKMCode;

typedef enum {
    WMAX_ULMAP_UIUC_FAST_FEEDBACK = 0,
    WMAX_ULMAP_UIUC_DATA_1    = 1,
    WMAX_ULMAP_UIUC_DATA_2    = 2,
    WMAX_ULMAP_UIUC_DATA_3    = 3,
    WMAX_ULMAP_UIUC_DATA_4    = 4,
    WMAX_ULMAP_UIUC_DATA_5    = 5,
    WMAX_ULMAP_UIUC_DATA_6    = 6,
    WMAX_ULMAP_UIUC_DATA_7    = 7,
    WMAX_ULMAP_UIUC_DATA_8    = 8,
    WMAX_ULMAP_UIUC_DATA_9    = 9,
    WMAX_ULMAP_UIUC_DATA_10   = 10,
    WMAX_ULMAP_UIUC_EXTENDED2 = 11,
    WMAX_ULMAP_UIUC_CDMA_BWR  = 12,
    WMAX_ULMAP_UIUC_PAPR      = 13, // not used
    WMAX_ULMAP_UIUC_CDMA_ALLOC= 14,
    WMAX_ULMAP_UIUC_EXTENDED  = 15
} WMaxUlMapUiuc;


/* Information Element (simplified version) */
typedef struct  {
    uint16_t duration;
} WMaxDataIE;

typedef struct  {
    uint8_t         duration;
    WMaxUlMapUiuc   uiuc;
    uint8_t         rangingCode;
    uint8_t         rangingSymbol;
    uint8_t         rangingSubchannel;
} WMaxCdmaAllocationIE;

typedef enum {
    WMAX_RANGING_METHOD_INITIAL = 0,/* initial ranging */
    WMAX_RANGING_METHOD_BWR = 1 /* bandwith request */
} WMaxRangingMethod;

/* following type is not a real field. It is a simplification only, used for simulation.
   Real WiMAX defines that whole range (0...255) of CDMA code is split into 4 separate
   pools, each with different purpose */
typedef enum {                     /* this CDMA opportunity should be used for: */
    WMAX_CDMA_PURPOSE_INITIAL_RNG, /* initial ranging */
    WMAX_CDMA_PURPOSE_HO_RNG,      /* handover ranging */
    WMAX_CDMA_PURPOSE_BWR,         /* bandwidth request */
    WMAX_CDMA_PURPOSE_PERIODIC_RNG /* periodic ranging */
} WMaxCdmaPurpose;

typedef struct {
    uint8_t symbolOffset;
    uint8_t ofdmaSymbols;
    uint8_t subchannels;
    WMaxRangingMethod rangingMethod;
    
    WMaxCdmaPurpose purpose; // not a real field (simulation simplification) 
} WMaxCdmaIE;

// see table 287, IEEE 802.16-2004
typedef struct {
    uint16_t cid;
    WMaxUlMapUiuc uiuc;

    // uiuc 1..11
    WMaxDataIE dataIE;

    // uiuc=12
    WMaxCdmaIE cdmaIE;

    // uiuc=14 (cdma allocation IE)
    WMaxCdmaAllocationIE cdmaAllocIE;

    // uiuc=15 (extended uiuc)
    /// @todo - code this
} WMaxUlMapIE;

inline std::ostream & operator<<(std::ostream & out, const WMaxUlMapIE & ie){


	out<< "cid=" << ie.cid << ", uiuc=" << ie.uiuc;

	switch (ie.uiuc) {
	case WMAX_ULMAP_UIUC_FAST_FEEDBACK:
	case WMAX_ULMAP_UIUC_EXTENDED2:
	case WMAX_ULMAP_UIUC_PAPR:
	case WMAX_ULMAP_UIUC_EXTENDED:
		out << " NOT SUPPORTED IE TYPE";
		break;
	case WMAX_ULMAP_UIUC_CDMA_BWR: {
		int a = (int)ie.cdmaIE.symbolOffset;
		int b = (int)ie.cdmaIE.ofdmaSymbols;
		int c = (int)ie.cdmaIE.subchannels;
		int d = (int)ie.cdmaIE.rangingMethod;
		out << "(CDMA BWR): symbolOffset=" << a << " ofdmaSymbols=" << b
			  << " subchannels=" << c << " rangingMethod=" << d;
		switch (ie.cdmaIE.rangingMethod) {
		case WMAX_RANGING_METHOD_INITIAL:
		out << " initial ranging";
		break;
		case WMAX_RANGING_METHOD_BWR:
		out << " bandwidth request";
		break;
		default:
		out << "[unknown ranging method]";
		}
		break;
	}
	case WMAX_ULMAP_UIUC_CDMA_ALLOC:
		out << "(CDMA ALLOCATION): duration=" << (int)ie.cdmaAllocIE.duration << " uiuc=" << (int)ie.cdmaAllocIE.uiuc
			  << " rangingCode=" << (int)ie.cdmaAllocIE.rangingCode << " rangingSymbol=" << (int)ie.cdmaAllocIE.rangingSymbol
			  << " rangingSubchannel=" << (int)ie.cdmaAllocIE.rangingSubchannel;
		break;
	default:
		out << "(DATA): duration=" << (int)ie.dataIE.duration;
		break;
	}
	return out;
}


typedef struct {
    /// @todo - implement this for real
    uint16_t cid;
    uint16_t symbols;
    uint32_t length;
} WMaxDlMapIE;


typedef struct {
    uint8_t bsId[6];
} WMaxBSFull;


typedef struct {
    WMaxConnType connType;
    uint32_t msr;
    uint32_t mrr;
} WMaxQos;

inline std::ostream & operator<<(std::ostream & out, const WMaxQos & qos){
	out<< "ConnType=" << qos.connType << ", msr=" << qos.msr << ", mrr="<< qos.mrr;
	return out;
}

// Table 364
typedef struct {
    uint64_t macAddr;
} WMaxRngReq;

// Table 367
typedef struct {
    uint64_t ssMacAddr;
    uint16_t basicCid;
} WMaxRngRsp;

#endif
