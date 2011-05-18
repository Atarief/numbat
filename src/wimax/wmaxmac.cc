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
#include <sstream>
#include <math.h>
#include "wmaxmac.h"
#include "wmaxmsg_m.h"
#include "wmaxctrl.h"
#include "logger.h"

// INET / MANET
#include "IInterfaceTable.h"
#include "InterfaceTableAccess.h"
#include "InterfaceEntry.h"
#include "ModuleAccess.h"
#include "ServiceConfig.h"

using namespace std;

Register_Class(WMaxMacHeader);


ostream & operator<<(ostream & strum, WMaxMacCDMA &x) {
    strum << "code=" << x.code << " bandwidth=" << x.bandwidth << " cid=" << x.cid;
    return strum;
}

ostream & operator<<(ostream & s, WMaxConn &x) {
    s << "type=" << x.type << " sfid=" << x.sfid << " cid=" << x.cid;
    
    switch (x.type) {
    case WMAX_CONN_TYPE_BE:
		s << " qos=[BE, msr=" << x.qos.be.msr << ", req="<< x.qos.be.reqbw <<"]";
		break;
    case WMAX_CONN_TYPE_UGS:
		s << " qos=[UGS, msr=" << x.qos.ugs.msr << ", latency=" << x.qos.ugs.latency << ", jitter=" << x.qos.ugs.jitter << "]";
		break;
    case WMAX_CONN_TYPE_RTPS:
    	s << " qos=[RTPS, msr=" << x.qos.rtps.msr << ", mrr=" << x.qos.rtps.mrr << ", req="<< x.qos.rtps.reqbw << ", latency=" << x.qos.rtps.latency << "]";
    	break;
    default:
	break;
    }

    s << " runtime:[ bandwidth=" << x.bandwidth << "]"<<" gateIndex=" << x.gateIndex << " controlConn=" << (x.controlConn?"YES":"NO");
    return s;
}

/********************************************************************************/
/*** ssMAC compound module ******************************************************/
/********************************************************************************/

Define_Module(ssMAC);

void ssMAC::updateString() {
    if (!ev.isGUI()) 
	return;
    cModule *SS = getParentModule();
    cModule *macSS = getSubmodule("ssMac");
    char buf[80];
    sprintf(buf, "%s%d", getFullName(), SS->getIndex());
    cModule *ctrlSS = getSubmodule(buf);
    char buf1[80];
    sprintf(buf1, "%s\n%s", (macSS->getDisplayString()).getTagArg("t",0), (ctrlSS->getDisplayString()).getTagArg("t",0));
    getDisplayString().setTagArg("t",0, buf1);
}

void ssMAC::initialize()
{
    cModule *SS = getParentModule();
    char buf[80];
    sprintf(buf, "%s%d", getFullName(), SS->getIndex());
    setName(buf);

}



/********************************************************************************/
/*** WMax Mac (common for BS/SS) ************************************************/
/********************************************************************************/
WMaxMac::WMaxMac()
{
    GateIndex = 0;
    queuedMsgsCnt = 0;
    this->CDMAQueue = new cQueue("CDMAQueue");

    WATCH_LIST(Conns);
}

WMaxMac::~WMaxMac(){
	for (list<WMaxConn>::iterator it = Conns.begin(); it!=Conns.end(); it++) {
		it->queue->clean();
		delete it->queue;
	}
	Conns.clear();

}

void WMaxMac::stringUpdate() {
    if (ev.isGUI()) {

        stringstream displayIt;
        displayIt << queuedMsgsCnt << "msgs in " << (int)Conns.size() << " queues.";
        getDisplayString().setTagArg("t",0, (displayIt.str()).c_str());
    }
}

bool WMaxMac::addConn(WMaxConn conn)
{
    std::stringstream ss_cid;
    std::string st_cid;
    ss_cid << conn.cid;
    ss_cid >> st_cid;
    std::string name = conn.srvName + " CID: " + st_cid;
    conn.queue = new QForContainer(name.c_str());

    stringstream tmp;
    
    switch (conn.type) {
    case WMAX_CONN_TYPE_UGS:
	tmp << "UGS: msr=" << conn.qos.ugs.msr << ", latency=" << conn.qos.ugs.latency 
	    << ", jitter=" << conn.qos.ugs.jitter;
	break;
    case WMAX_CONN_TYPE_RTPS:
	tmp << "rtPS: msr=" << conn.qos.rtps.msr << ", mrr=" << conn.qos.rtps.mrr 
	    << ", latency=" << conn.qos.rtps.latency;
	break;
    case WMAX_CONN_TYPE_NRTPS:
	tmp << "nrtPS: msr=" << conn.qos.nrtps.msr << ", mrr=" << conn.qos.nrtps.mrr
	    << ", priority=" << conn.qos.nrtps.priority;
    case WMAX_CONN_TYPE_BE:
	tmp << "BestEffort: msr=" << conn.qos.be.msr;
	break;
    }
    cGate *target = gate("macOut", conn.gateIndex);
    target = target->getNextGate();
    cModule * owner = target->getOwnerModule();

    if (dynamic_cast<WMaxCtrlSS*>(owner)) {
	conn.controlConn = true;
    }
    else if (dynamic_cast<WMaxCtrlBS*>(owner)) {
	conn.controlConn = true;
    } else {
        conn.controlConn = false;
    }

    Log(Notice) << "Adding connection: sfid=" << conn.sfid << ", cid=" << conn.cid << ", type="
		<< tmp.str() << ", controlConn=" << (conn.controlConn?"YES":"NO") 
		<< ", connected to: " << owner->getFullName() << LogEnd;

    /// @todo - check if CID and sfid are unique
    Conns.push_back(conn);

    //setDisplayString("Conns"); // this doesn't work. Strange
    return true;
}
 
bool WMaxMac::delConn(uint16_t cid)
{
    for (list<WMaxConn>::iterator it = Conns.begin(); it!=Conns.end(); it++) {
	if (it->cid==cid) {
		it->queue->clean();
	    delete it->queue;
	    Conns.erase(it);
	    Log(Notice) << "Connection (cid=" << cid << ") removed." << LogEnd;
	    return true;
	}
    }
    Log(Error) << "Unable to delete connection with cid=" << cid << "." << LogEnd;
    return false;
}


void WMaxMac::printDlMap(WMaxMsgDlMap * dlmap)
{
    Log(Debug) << " --- DL-MAP (" << dlmap->getIEArraySize() << " IE(s) ---" << LogEnd;
    if (!logger::willPrint(logger::Debug))
	return;

    for (unsigned int i=0; i<dlmap->getIEArraySize(); i++) {
	WMaxDlMapIE &ie = dlmap->getIE(i);
	Log(Debug) << "IE[" << i << "]: cid=" << ie.cid << ", length=" << ie.length << ", symbols=" << ie.symbols << LogEnd;
    }
}

void WMaxMac::printUlMap(WMaxMsgUlMap * ulmap)
{
    Log(Debug) << " --- UL-MAP: " << ulmap->getIEArraySize() << " IE(s) ---" << LogEnd;
    if (!logger::willPrint(logger::Debug))
	return;

    for (unsigned int i=0; i<ulmap->getIEArraySize(); i++) {
	WMaxUlMapIE &ie = ulmap->getIE(i);
	Log(Debug) << "IE[" << i << "]: cid=" << ie.cid << ", uiuc=" << ie.uiuc;

	switch (ie.uiuc) {
	case WMAX_ULMAP_UIUC_FAST_FEEDBACK:
	case WMAX_ULMAP_UIUC_EXTENDED2:
	case WMAX_ULMAP_UIUC_PAPR:
	case WMAX_ULMAP_UIUC_EXTENDED:
	    Log(Cont) << " NOT SUPPORTED IE TYPE";
	    break;
	case WMAX_ULMAP_UIUC_CDMA_BWR: {
	    int a = (int)ie.cdmaIE.symbolOffset;
	    int b = (int)ie.cdmaIE.ofdmaSymbols;
	    int c = (int)ie.cdmaIE.subchannels;
	    int d = (int)ie.cdmaIE.rangingMethod;
	    Log(Cont) << "(CDMA BWR): symbolOffset=" << a << " ofdmaSymbols=" << b
		      << " subchannels=" << c << " rangingMethod=" << d;
	    switch (ie.cdmaIE.rangingMethod) {
	    case WMAX_RANGING_METHOD_INITIAL: 
		Log(Cont) << " initial ranging";
		break;
	    case WMAX_RANGING_METHOD_BWR:
		Log(Cont) << " bandwidth request";
		break;
	    default:
		Log(Cont) << "[unknown ranging method]";
	    }
	    break;
	}
	case WMAX_ULMAP_UIUC_CDMA_ALLOC:
	    Log(Cont) << "(CDMA ALLOCATION): duration=" << (int)ie.cdmaAllocIE.duration << " uiuc=" << (int)ie.cdmaAllocIE.uiuc
		      << " rangingCode=" << (int)ie.cdmaAllocIE.rangingCode << " rangingSymbol=" << (int)ie.cdmaAllocIE.rangingSymbol
		      << " rangingSubchannel=" << (int)ie.cdmaAllocIE.rangingSubchannel;
	    break;
	default:
	    Log(Cont) << "(DATA): duration=" << (int)ie.dataIE.duration;
	    break;
	}
	Log(Cont) << LogEnd;
    }
}

/********************************************************************************/
/*** WMax Mac BS ****************************************************************/
/********************************************************************************/
Define_Module(WMaxMacBS);

void WMaxMacBS::updateDisplay() {
    cDisplayString dispstr = BS->getDisplayString();


    char buf[80];
    sprintf(buf, "(%s,%s)", dispstr.getTagArg("p",0), dispstr.getTagArg("p",1));
    BS->getDisplayString().setTagArg("t",0, buf);
}

void WMaxMacBS::initialize()
{
    BS = getParentModule()->getParentModule();

	BEpoint = 0;

    updateDisplay();

    SendQueue.setName("SendQueue");
    FrameLength = par("FrameLength");

    TxStart = new cMessage("TxStart");
    scheduleAt(0.0, TxStart);

    Conns.clear();

    // configure scheduler
    schedUgsMinGrantSize = WMAX_SCHED_MIN_UGS_SYMBOLS;
    schedCdmaInitRngFreq = WMAX_CDMA_INIT_RNG_FREQ;
    schedCdmaBwrFreq     = WMAX_CDMA_BWR_FREQ;
    schedCdmaHoRngFreq   = WMAX_CDMA_HO_RNG_FREQ;
    schedDcdFreq         = WMAX_DCD_FREQ;
    schedUcdFreq         = WMAX_UCD_FREQ;

    schedCdmaInitRngCnt  = 0;
    schedCdmaHoRngCnt    = 0;
    schedCdmaBwrCnt      = 0;
    schedDcdCnt          = 0;
    schedUcdCnt          = 0;

    // Set the Mac name to sth unique (add bs index)
    char buf[80];
	sprintf(buf,"WMaxMacBS%d",WMaxCtrlBS::getIDFromName((char *)BS->getName()));
	setName(buf);

    // Create permanent INITIAL-RANGING connection
    addRangingConn();
    initialBCSent = false;
    WMaxMac::initialize();
}

/**
 * Delete a connection from the temporarily granted ones. This happens
 * when the Control Layer sends the add connection message. This connection is added
 * to the Conns list.
 *
 * NOTE:
 * TEMP Grant list is need in case we have too many requests at once. We check both Conns and
 * granted ones because a granted one may haven't added to the MAC layer yet.
 */
void WMaxMacBS::deleteGranted(WMaxQos  & qos){
	for (list<WMaxQos>::iterator it=GrantedConns.begin(); it!=GrantedConns.end(); it++){
		if (qos.connType == it->connType && qos.mrr == it->mrr && qos.msr == it->msr){
			GrantedConns.erase(it);
			return;
		}
	}
}

void WMaxMacBS::handleMessage(cMessage *msg)
{
    if (msg==TxStart) {
		schedule();
		scheduleAt(simTime()+FrameLength, TxStart);
		return;
    }

    if (WMaxMacAddConn *addconn = dynamic_cast<WMaxMacAddConn*>(msg)) {
        WMaxQos qos = addconn->getQos(0);

        WMaxConn conn;
        conn.srvName = addconn->getSrvName();

        conn.type= qos.connType;
        switch (qos.connType){
        case WMAX_CONN_TYPE_BE:
        	conn.qos.be.msr = qos.msr; // 100kbps
        	conn.qos.be.reqbw = 0;
        	break;
        case WMAX_CONN_TYPE_UGS:
            conn.qos.ugs.msr = qos.msr; // 100kbps
            break;
        case WMAX_CONN_TYPE_RTPS:
			conn.qos.rtps.msr = qos.msr; // 100kbps
			conn.qos.rtps.mrr = qos.mrr; // 100kbps
			conn.qos.rtps.reqbw = 0;
			break;
        default:
        	break;
        }
        conn.sfid = 2; /// @todo set sfid
        conn.cid  = addconn->getCid();
        conn.gateIndex = addconn->getGateIndex();

        conn.bandwidth = 0;
        addConn(conn);
        // delete from temporary
        deleteGranted(qos);

        send(msg, "macOut", 0);  // send add conn msg to CS

        //delete msg;
        return;
    }

    if (WMaxMacAddMngmntConn *addconn = dynamic_cast<WMaxMacAddMngmntConn*>(msg)) {
        uint16_t cid = addconn->getCid();
        addManagementConn(cid);
        delete msg;
        return;
    }

    if (WMaxEvent_DelConn* delconn = dynamic_cast<WMaxEvent_DelConn*>(msg)) {
		delConn(delconn->getCid());

		send(msg, "macOut", 0); // send delConn to CS
		return;
    }

    cGate * gate = msg->getArrivalGate();
    if (!strcmp(gate->getFullName(),"phyIn")) {
    	handleRxMessage(msg);
    	return;
    }

    // remaining gates must be downlink
    handleTxMessage(msg);
}

/**
 * Handle messages received from the phy layer.
 *
 * This function actually handles CDMA currently. Our
 * goal is to do Admission Control. AC should be done
 * based on the DSA_REQ messages. This _MUST_ be done
 * here cause the mac layer has the scheduler but the
 * control doesn't, thus the control doesn't know when
 * we are congested.
 */
void WMaxMacBS::handleRxMessage(cMessage *msg)
{
	// Handle here CDMA BWR
    if (dynamic_cast<WMaxMsgCDMA*>(msg))
    {
    	WMaxMsgCDMA * cdma = dynamic_cast<WMaxMsgCDMA*>(msg);
        if (cdma->getPurpose()==WMAX_CDMA_PURPOSE_BWR) 
        {
            Log(Debug) << "Received CDMA code " << cdma->getCode() << " (purpose=BWR)." << LogEnd;
            CDMAQueue->insert(msg);
            return;
        }
    }

    // Handle here DSA_REQ
    WMaxMsgDsaReq * dsareq = dynamic_cast<WMaxMsgDsaReq *>(msg);
    if (dsareq){
    	// If we cannot admit the connection
    	// we reply with a FAIL
    	if (!admitConnection(dsareq)){

    		// Construct the message
    		WMaxMsgDsaRsp *dsarsp = new WMaxMsgDsaRsp();
			dsarsp->setName("DSA-RSP");
			dsarsp->setTransactionID(dsareq->getTransactionID());
			dsarsp->setConfirmationCode(WMAX_CONFIRMATION_CODE_REJECT);
			dsarsp->setQosArraySize(1);
			dsarsp->setQos(0,dsareq->getQos(0));
			dsarsp->setCid(0);

			dsarsp->setControlInfo(dsareq->getControlInfo()->dup());

			// RVD GOES FIRST
			WMaxMsgDsxRvd *dsxrvd = new WMaxMsgDsxRvd();
			dsxrvd->setName("DSX-RVD");
			dsxrvd->setTransactionID(dsareq->getTransactionID());
			dsxrvd->setConfirmationCode(WMAX_CONFIRMATION_CODE_REJECT);

			dsxrvd->setControlInfo(dsareq->getControlInfo()->dup());

			EV << "DECLINE CONNECTION: "<< dsareq->getQos(0) << endl;

			// Send it :-)
			SendQueue.insert(dsxrvd);
			SendQueue.insert(dsarsp);
			delete msg;
			return;

    	}else{
    		// We admitted the connection...
    		GrantedConns.push_back(dsareq->getQos(0));
    	}
    }

    WMaxMac::handleRxMessage(msg);
}


double WMaxMacBS::dataRatePS2Symbols(int datarate){
	int bytesPerPS = 12;
	double dr_perSlot = double(datarate)*FrameLength;
	// bps -> symbol number
	return double(dr_perSlot)/(bytesPerPS*8);
}

/**
 * Urb@n
 *
 * Get the DSA_REQ message and decide if we can admit
 * this connection or we are out of symbols...
 *
 * Override to get different behaviour and CAC
 */
bool WMaxMacBS::admitConnection(WMaxMsgDsaReq * dsareq){
	string T = "admitConnection: ";
	// Allow all BE
	if (dsareq->getQos(0).connType == WMAX_CONN_TYPE_BE)
		return true;

	// TODO: FIXME: FUCKME: recalc. the "free" symbols after serving all the connections

	int dlSymbols = symbols*dlSymbolsPc;
	// Keep track of free symbols
	int free_symbols = dlSymbols*subchannels;

	for (list<WMaxConn>::iterator it=Conns.begin(); it!=Conns.end(); it++){
		EV<<T<< "CID: "<< it->cid <<"("<<it->type<<")";
		switch(it->type){
		case WMAX_CONN_TYPE_RTPS:
			EV <<" Subtracting "<< dataRatePS2Symbols(it->qos.rtps.mrr) <<" symbols."<<endl;
			free_symbols -= dataRatePS2Symbols(it->qos.rtps.mrr);
			break;
		case WMAX_CONN_TYPE_UGS:
			EV <<" Subtracting "<< dataRatePS2Symbols(it->qos.ugs.msr ) <<" symbols."<<endl;
			free_symbols -= dataRatePS2Symbols(it->qos.ugs.msr);
			break;
		default:
			break;
		}

		EV << endl;
		// Check symbols > 0
		if (free_symbols <= 0 ) {
			EV <<T<<"Out Of Symbols in already established connections" <<endl;
			return false;
		}
	}

	// Do the same for Granted ones
	for (list<WMaxQos>::iterator it=GrantedConns.begin(); it!=GrantedConns.end(); it++){
		switch(it->connType){
		case WMAX_CONN_TYPE_RTPS:
			EV <<" Subtracting "<< dataRatePS2Symbols(it->mrr) <<" symbols."<<endl;
			free_symbols -= dataRatePS2Symbols(it->mrr);
			break;
		case WMAX_CONN_TYPE_UGS:
			EV <<" Subtracting "<< dataRatePS2Symbols(it->msr) <<" symbols."<<endl;
			free_symbols -= dataRatePS2Symbols(it->msr);
			break;
		default:
			break;
		}

		// Check symbols > 0
		if (free_symbols <= 0 ){
			EV <<T<<"Out Of Symbols in GRANTED connections" <<endl;
			return false;
		}
	}

	int reqSymbols = 0;
	switch(dsareq->getQos(0).connType){
	case WMAX_CONN_TYPE_RTPS:
		reqSymbols = dataRatePS2Symbols(dsareq->getQos(0).mrr);
		break;
	case WMAX_CONN_TYPE_UGS:
		reqSymbols = dataRatePS2Symbols(dsareq->getQos(0).msr);
		break;
	default:
		break;
	}
	EV <<T<< "Connection Admission: Free symbols="<<free_symbols<<" Requested Symbols="<<reqSymbols<<endl;

	// Since we are here it means that symbols > 0
	if (free_symbols >= reqSymbols)
		return true;
	else {
		EV <<T<< "Congestion detected: Free symbols="<<free_symbols<<" Requested Symbols="<<reqSymbols<<endl;
		return false;
	}
}

void WMaxMacBS::schedule()
{
	/**
	 * Urb@n
	 *
	 *  48 symbols per frame for 5ms frame.
	 *  In theory this should change depending
	 *  on the frameLength parameter... (TODO)
	 *
	 *  Frame can vary from 2-20ms, but 5ms
	 *  is for MobileWiMax
	 *
	 */
    int dlSymbols = symbols*dlSymbolsPc;
    int ulSymbols = symbols - dlSymbols;


    scheduleBcastMessages();

    WMaxMsgDlMap * dlmap = scheduleDL(dlSymbols*subchannels);
    WMaxMsgUlMap * ulmap = scheduleUL(ulSymbols*subchannels);

    printDlMap(dlmap);
    printUlMap(ulmap);

    send(dlmap, "phyOut");
    send(ulmap, "phyOut");

    // trigger PHY to start frame
    WMaxPhyDummyFrameStart * frameStart = new WMaxPhyDummyFrameStart();
    // Log(Debug) << "Generating FrameStart trigger for PHY" << LogEnd;
    send(frameStart, "phyOut");
}

void WMaxMacBS::scheduleBcastMessages()
{
    schedDcdCnt++;
    schedUcdCnt++;

    if ((schedDcdFreq && schedDcdFreq<=schedDcdCnt++)) {
		schedDcdCnt = 0;
		WMaxMsgDCD * dcd = new WMaxMsgDCD("DCD");
		dcd->setName("DCD");
		WMaxMacHeader * hdr = new WMaxMacHeader();
		hdr->cid = WMAX_CID_BROADCAST;
		dcd->setControlInfo(hdr);
		SendQueue.insert(dcd);
		queuedMsgsCnt++;
    }


    if ((schedUcdFreq && schedUcdFreq<=schedUcdCnt++)) {
		schedUcdCnt = 0;
		WMaxMsgUCD * ucd = new WMaxMsgUCD("UCD");
		ucd->setName("UCD");
		WMaxMacHeader * hdr = new WMaxMacHeader();
		hdr->cid = WMAX_CID_BROADCAST;
		ucd->setControlInfo(hdr);
		SendQueue.insert(ucd);
		queuedMsgsCnt++;
    }

    // Either Way we where in these functions
    initialBCSent=true;

}


/** 
 * schedules downlink traffic
 * 
 * 
 * @return 
 */
WMaxMsgDlMap * WMaxMacBS::scheduleDL(int symbols)
{
    int startSymbols = symbols;
    int ieCnt = 0;
    WMaxDlMapIE ie; // map element

    int bytesPerPS = WMAX_BYTES_PER_SYMBOL; // this depends on modulation used, use 12 bytes/symbol for now
    int lengthInPS;
    cMessage * msg;

    WMaxMsgDlMap * dlmap = new WMaxMsgDlMap("DL-MAP");
    dlmap->setName("DL-MAP");
    ieCnt = 0;

    while (true) {
		Log(Debug) << symbols << " symbols left." << LogEnd;

		if (!SendQueue.length()) // nothing more to send
			break;

		if (symbols <=0)
			break;

		msg = (cMessage*) SendQueue.front();

		//msg does not have getByteLenght() so cast it to cPacket.... (MiM)

		if (check_and_cast<cPacket *>(msg)->getByteLength() > symbols*bytesPerPS) {
			// message won't fit in this frame. What should we do in such case?

		  Log(Debug) << "Tried to schedule message (len=" << check_and_cast<cPacket *>(msg)->getByteLength() << "), but there are only "
				   << symbols*bytesPerPS << " bytes left." << LogEnd;
	
			if (ieCnt) // something has been scheduled - ok, end scheduling
			break;
	
			// what to do, if we have not scheduled anything and the message still doesn't fit?
	
			// possible solutions:
			// a) implement fragmentation (the best one)
			// b) send message and end scheduling (flaw: sending more than possible)
			// c) ignore this message and try to scheduler next message, possibly smaller (flaw: message will never be sent)
			// d) abort simulation as there is no way to send this message
	
				// currently used: c)
				msg = (cMessage*) SendQueue.pop();
			queuedMsgsCnt--;
				Log(Error) << "Unable to send " << check_and_cast<cPacket *>(msg)->getByteLength() << "-byte message(" << msg->getFullName()
				   << "), because it won't fit in DL subframe. Message is dropped." << endl;
				delete msg;
				continue;
	
			// currently used: d)
			/*opp_error("Unable to send %d-byte long message(%s), because it won't fit in DL subframe (%d symbols *%dB/PS=%d bytes)",
				  msg->getByteLength(), msg->getFullName(), symbols, bytesPerPS, symbols*bytesPerPS);
			break;*/
		}

		// message will fit in this frame, send it
		ieCnt++;
		dlmap->setIEArraySize(ieCnt);

		/// @todo - DL-MAP generation

		msg = (cMessage*)SendQueue.pop();
		queuedMsgsCnt--;
	
		lengthInPS = (int)ceil(double(check_and_cast<cPacket *>(msg)->getByteLength())/bytesPerPS);
		symbols -= lengthInPS;

		WMaxMacHeader * hdr = dynamic_cast<WMaxMacHeader*>(msg->getControlInfo());
		if (!hdr)
			opp_error("Unable to obtain header information for message: %s\n", msg->getFullName());
		CLEAR(&ie);
		ie.length  = check_and_cast<cPacket *>(msg)->getByteLength();
		ie.cid     = hdr->cid;
		ie.symbols = lengthInPS;
		dlmap->setIE(ieCnt-1,ie);
	
		Log(Debug) << "Sent msg: length=" << ie.length << ", used " << lengthInPS << " symbols, "
			   << symbols << " symbol(s) left" << endl;

		// Record
		if (dynamic_cast<cPacket *>(msg)){
			numBytesSent+=dynamic_cast<cPacket *>(msg)->getByteLength();
			vecBytesSent.record(numBytesSent);
		 }
		send(msg, "phyOut");
    }

    Log(Debug) << "DL schedule: " << startSymbols << " symbols available for DL, " << startSymbols-symbols << " used." << LogEnd;
    if (symbols<=0)
    {
	Log(Warning) << "Full DL frame, " << startSymbols << " were available, " << symbols << " left." << LogEnd;
    }

    WMaxMacHeader * hdr = new WMaxMacHeader();
    hdr->cid = WMAX_CID_BROADCAST;
    dlmap->setControlInfo(hdr);

    stringUpdate();

    return dlmap;
}

/** 
 * scheduler up-link traffic
 * 
 * 
 * @return 
 */
WMaxMsgUlMap * WMaxMacBS::scheduleUL(int symbols)
{
    int startSymbols = symbols;
    int i;
    int ieCnt = 0;
    WMaxUlMapIE ie;
    int bytesPerPS = WMAX_BYTES_PER_SYMBOL; // this depends on modulation used, use 12 bytes/symbol for now

    WMaxMsgUlMap * ulmap = new WMaxMsgUlMap("UL-MAP");

    schedCdmaInitRngCnt++;
    schedCdmaHoRngCnt++;
    schedCdmaBwrCnt++;

    if (schedCdmaBwrFreq && schedCdmaBwrFreq<=schedCdmaBwrCnt++) {
	// append IE for CDMA bandwidth request
	ieCnt++;
	schedCdmaBwrCnt=0;
	ulmap->setIEArraySize(ieCnt);
	CLEAR(&ie);
	ie.cid  = WMAX_CID_BROADCAST;
	ie.uiuc = WMAX_ULMAP_UIUC_CDMA_BWR;
	ie.cdmaIE.rangingMethod = WMAX_RANGING_METHOD_BWR;
	ie.cdmaIE.purpose = WMAX_CDMA_PURPOSE_BWR;

	/// @todo - full symbolOffset, ofdmaSymbols, subchannels
	ulmap->setIE(ieCnt-1,ie);
	symbols--; // use just 1 symbol for Bandwidth Requests
    }

    if (schedCdmaInitRngFreq && schedCdmaInitRngFreq<=schedCdmaInitRngCnt++) {
	// append IE for CDMA bandwidth request
	ieCnt++;
	schedCdmaInitRngCnt=0;
	ulmap->setIEArraySize(ieCnt);
	CLEAR(&ie);
	ie.cid  = WMAX_CID_BROADCAST;
	ie.uiuc = WMAX_ULMAP_UIUC_CDMA_BWR;
	ie.cdmaIE.rangingMethod = WMAX_RANGING_METHOD_INITIAL;
	ie.cdmaIE.purpose       = WMAX_CDMA_PURPOSE_INITIAL_RNG;
	/// @todo - full symbolOffset, ofdmaSymbols, subchannels
	ulmap->setIE(ieCnt-1,ie);
	symbols--; // use just 1 symbol for Initial Ranging
    }

    if (CDMAQueue->length()) {
	// append IE for allocation of bandwidth to a user that requested bandwidth using a CDMA code
	for (i=0; i<CDMAQueue->length(); i++) {
	    ieCnt++;
	    schedCdmaInitRngCnt=0;
	    ulmap->setIEArraySize(ieCnt);
	    CLEAR(&ie);
	    ie.cid  = WMAX_CID_BROADCAST;
	    ie.uiuc = WMAX_ULMAP_UIUC_CDMA_ALLOC;
	    WMaxMsgCDMA *msgcdma = (WMaxMsgCDMA*)CDMAQueue->pop();
	    ie.cdmaAllocIE.rangingCode = msgcdma->getCode();
	    /// @todo - duration, rangingSymbol, rangingSubchannel
	    ulmap->setIE(ieCnt-1,ie);
	    delete msgcdma;
	    symbols--; // use just 1 symbol
	    if (symbols==0)
		break;
	}
    }

    if (symbols && schedCdmaHoRngFreq && schedCdmaHoRngFreq<=schedCdmaHoRngCnt++) {
	// append IE for handover ranging
	ieCnt++;
	schedCdmaHoRngCnt=0;
	ulmap->setIEArraySize(ieCnt);
	CLEAR(&ie);
	ie.cid  = WMAX_CID_BROADCAST;
	ie.uiuc = WMAX_ULMAP_UIUC_CDMA_BWR;
	ie.cdmaIE.rangingMethod = WMAX_RANGING_METHOD_INITIAL;
	ie.cdmaIE.purpose       = WMAX_CDMA_PURPOSE_HO_RNG;
	/// @todo - full symbolOffset, ofdmaSymbols, subchannels
	ulmap->setIE(ieCnt-1,ie);
	symbols--; // use just 1 symbol for Initial Ranging
    }
    

    /**
     * Urb@n (- I don't understand sh*t from above...)
     *
     * Scan all connections and assign UL bandwidth.
     * Theoretically we should first assign bw to UGS and RTPS
     * connections and with a third loop assign to BE...
     *
     * RTPS NOTE:
     * 	- If all the BE connections can be covered, then we assign more
     *    bandwidth to the RTPS.
     *  - If the BE requested cannot be covered then we assign only the
     *    MRR to the RTPS
     *
     */

    /**-------------------------------------------------------------------------------------------------
     * Urban
     *
     *  UGS (guaranteed) loop
     *
     *  Also:
     *  - Satisfy Ctrl CIDs (else we have scanning and reporting problems)
     *  - Collect total number of requested for BE to
     *  be used later.
     *  - Collect minimum RTPS required allocation.
     *  - Collect above mrr bandwidth for RTPS
     *----------------------------------------------------------------------------------------------------
     */
    uint64_t totbereq=0;
    uint64_t minrtpsreq=0;
    uint64_t maxrtpsreq=0;
    int count_be = 0;
    for (list<WMaxConn>::iterator it=Conns.begin(); it!=Conns.end(); it++) {
    		if (symbols <=0) {
    			Log(Debug) << "No symbols left, scheduling aborted." << LogEnd;
    			break;
    		}

    		// for each configured service flow, grant the MSR bandwidth
    		switch (it->type) {
    		case WMAX_CONN_TYPE_UGS:
    		{
    			/**
    			 * Urb@n
    			 *
    			 * ... changed this. MSR is now in bps from configuration
    			 * and the MSR is always allocated to the SS. NOTE: the MSR
    			 * and ONLY, NOTHING MORE NOTHING LESS :-).
    			 *
    			 * Example app.
    			 * CBR Traffic: Voice without noise cancellation
    			 */
    			it->bandwidth = uint32_t(double(it->qos.ugs.msr)*FrameLength);
    			// bps -> symbol number
    			int symbolLength = (int)floor(double(it->bandwidth)/(bytesPerPS*8));

    			// Check minimum
    			if (it->bandwidth < (WMAX_SCHED_MIN_UGS_SYMBOLS*8*12)){
    				it->bandwidth=(WMAX_SCHED_MIN_UGS_SYMBOLS*8*12);
    				symbolLength = WMAX_SCHED_MIN_UGS_SYMBOLS;
    			}

    			if (  (symbols>=symbolLength) ) {
    				symbols -= symbolLength;

    				Log(Debug) << ": Adding UGS grant: cid=" << ie.cid << ", bandwidth=" << ie.dataIE.duration << ", "
    					   << symbolLength << " symbols, left=" << symbols << LogEnd;

    				ieCnt++;
					ulmap->setIEArraySize(ieCnt);
					WMaxUlMapIE ie;
					CLEAR(&ie);
					ie.uiuc = WMAX_ULMAP_UIUC_DATA_1;
					ie.cid = it->cid;
					ie.dataIE.duration = symbolLength;
					ulmap->setIE(ieCnt-1, ie);
					break;
    			}else {
    				symbolLength=symbols;
    				symbols=0;

    				Log(Crit) << "Failed to add UGS grant: cid=" << it->cid << ", bandwidth=" << it->bandwidth << ", "
    								   << symbolLength << " symbols out of: "<< symbols << ", MSR="<<
    								   it->qos.ugs.msr  << LogEnd;
    				// MisConfigured Granted service...
    				//opp_error("MISCONFIGURED MSR in UGS service... The Maximum you can have is:\nSumbols/frame: %d\nTotal uplink is: %e",
    				//		48*60 , (double)48*60*bytesPerPS*8*(double)(1.0/FrameLength)/2);

    				EV<<"MISCONFIGURED MSR in UGS service... The Maximum you can have is:\nSumbols/frame: "<<
    						(this->symbols*subchannels)<<"\nTotal uplink is: "<<
    						((double)48*60*bytesPerPS*8*(double)(1.0/FrameLength)/2)<<endl;
    				cout<<"MISCONFIGURED MSR in UGS service... The Maximum you can have is:\nSumbols/frame: "<<
							(this->symbols*subchannels)<<"\nTotal uplink is: "<<
							((double)48*60*bytesPerPS*8*(double)(1.0/FrameLength)/2)<<endl;
    			}


    		}
    		// Collect stats
    		case WMAX_CONN_TYPE_BE:
    		{

    			int reqbw = (double)it->qos.be.reqbw/WMAX_CDMA_BWR_FREQ /*+ it->bandwidth*/;

				// Handle Control Connections HERE
				if (it->controlConn){

					// Find Symbols
					int symbolLength = (int)ceil(((double) reqbw)/(bytesPerPS*8));
					symbols-=symbolLength;

					ieCnt++;
					ulmap->setIEArraySize(ieCnt);

					WMaxUlMapIE ie;
					CLEAR(&ie);
					ie.uiuc = WMAX_ULMAP_UIUC_DATA_2;
					ie.cid = it->cid;
					ie.dataIE.duration = symbolLength;
					ulmap->setIE(ieCnt-1, ie);
					it->bandwidth = reqbw;

					Log(Debug)<<"*** Control: symbols="<<symbolLength<<", bw="<<it->bandwidth<<endl;
					continue;
				}

				// This is request in bits
				totbereq+=reqbw;
				count_be++;

    			break;
    		}
    		case WMAX_CONN_TYPE_RTPS:
			{
				// Urb@n
				// Get the min rtPS
				if (it->qos.rtps.mrr*FrameLength < WMAX_SCHED_MIN_RTPS_SYMBOLS*8*12)
					minrtpsreq+=WMAX_SCHED_MIN_RTPS_SYMBOLS*8*12;
				else
					// Convert to request in bits
					minrtpsreq+=it->qos.rtps.mrr*FrameLength;

				// Get the max rtPS
				if (it->qos.rtps.reqbw == 0 || it->qos.rtps.msr*FrameLength*WMAX_CDMA_BWR_FREQ < it->qos.rtps.reqbw){
					maxrtpsreq+=it->qos.rtps.msr*FrameLength;
				}else{
					maxrtpsreq+= ((double)it->qos.rtps.reqbw)/WMAX_CDMA_BWR_FREQ;
				}


				break;
			}
    		default:
    			break;
    		}

    } // End of MSR based

    /**-------------------------------------------------------------------------------------------------
	* Urban
	*
	*  RTPS (guaranteed) loop
	*----------------------------------------------------------------------------------------------------
	*/
   // currently free
   uint64_t freebw=symbols*12*8;
   uint64_t spare_rtps = 0;
   uint64_t totrtpsover = 0;
   if (maxrtpsreq > minrtpsreq)
	   totrtpsover = maxrtpsreq - minrtpsreq;



   // Check if we have spare
   if (freebw < minrtpsreq){
	   // Enable to block RTPS misconfig
	   //opp_error("MISCONFIGURED MRR in RTPS service... You have: minrtpsreq=%d freebw=%d free_symbols=%d", minrtpsreq, freebw, symbols);
   }
   // NOTICE: DO NOT OVERFLOW BELLOW --^
   if (totbereq < ((double)freebw - (double)minrtpsreq )){
	   spare_rtps = (double)freebw - (double)totbereq - (double)minrtpsreq;
   }

   // TAKE THIS OUT TO SUPPORT ONLY RTPS MRR AND GIVE THE REST TO BE
   spare_rtps = ((double)freebw - (double)minrtpsreq );

   Log(Crit) << "!! Stats After UGS: We have (all in bits requested) [free="<<freebw<<", totbereq="<<totbereq<<", minrtpsreq="
   			   <<minrtpsreq<<", maxrtpsreq="<<maxrtpsreq<<" ,SPARE="<<spare_rtps<<"]" << LogEnd;

   for (list<WMaxConn>::iterator it=Conns.begin(); it!=Conns.end(); it++) {
		if (symbols <=10) {
			Log(Debug) << "No symbols left, scheduling aborted." << LogEnd;
			break;
		}

		// for each configured service RTPS flow, grant at least the MRR bandwidth
		switch (it->type) {
		case WMAX_CONN_TYPE_RTPS:
		{

			// No Spare
			it->bandwidth = uint32_t(double(it->qos.rtps.mrr)*FrameLength);
			int symbolLength = 0;
			// Check minimum
			if ((int)it->bandwidth < (WMAX_SCHED_MIN_RTPS_SYMBOLS*8*bytesPerPS)){
				it->bandwidth=(WMAX_SCHED_MIN_RTPS_SYMBOLS*8*bytesPerPS);
				symbolLength = WMAX_SCHED_MIN_RTPS_SYMBOLS;
			}
			// bps -> symbol number
			symbolLength = (int)floor(double(it->bandwidth)/(bytesPerPS*8));


			// Add sth more if we have
			if (spare_rtps > 0) {
				// Fair Allocation ...

				// 1 - Find min. for this service (bits per frame)
				// Already done above in it->bandwidth...

				// 2 - Over-allocation for single rtPS and SINGLE SLOT
				uint32_t over = 0;

				if (it->qos.rtps.reqbw==0 || it->qos.rtps.reqbw >  it->qos.rtps.msr*FrameLength*WMAX_CDMA_BWR_FREQ){
					// Give MSR as over allocation
					over = ((double)it->qos.rtps.msr*FrameLength) - it->bandwidth;
				}else if (it->qos.rtps.reqbw > it->bandwidth*WMAX_CDMA_BWR_FREQ) {
					// Give Requested
					over = ((double)it->qos.rtps.reqbw/WMAX_CDMA_BWR_FREQ) - it->bandwidth;
				} else
					over = 0;

				// 3 - Get the analogy (per Slot from now on)...
				uint32_t extra = over;

				// 4 - Check congestion
				//    NOTE: if spare_rtps/totrtpsover > 1 extra goes higher !!!
				if (spare_rtps < totrtpsover )
					extra = (double)over*((double)spare_rtps/totrtpsover);

				// 4 - Add it raw on the current min bandwidth
				it->bandwidth += extra;

				// 5 - Fix New Symbols
				symbolLength = (int)floor(double(it->bandwidth)/(bytesPerPS*8));

				Log(Debug) << ":: Extra RTPS grant: cid=" << it->cid << ", spare_rtps=" << spare_rtps << ", over=" << over << ", req="<< (double)it->qos.rtps.reqbw/WMAX_CDMA_BWR_FREQ
						<< ", mrr=" << it->qos.rtps.mrr*FrameLength << ", msr=" << it->qos.rtps.msr*FrameLength
						<< ", totover="<<totrtpsover << ", free="<< freebw << "\n\t minreq=" << minrtpsreq << " extra/sec=" << (uint64_t)((double)extra/FrameLength)
						<< " extra/slot=" << extra << LogEnd;


			}



			// "Always" true... else misconfig
			if (  (symbols>=symbolLength) ) {
				symbols -= symbolLength;

				Log(Debug) << ": Adding RTPS grant: cid=" << ie.cid << ", bandwidth=" << it->bandwidth << ", "
					   << symbolLength << " symbols, left=" << symbols << LogEnd;

			}else {
				Log(Crit) << "Failed to add RTPS grant: cid=" << it->cid << ", bandwidth=" << it->bandwidth << ", "
								   << symbolLength << " symbols out of: "<< symbols << ", MSR="<<
								   it->qos.rtps.msr << ", MRR="<< it->qos.rtps.mrr << LogEnd;
				// MisConfigured Granted service...
				//opp_error("MISCONFIGURED MSR in RTPS service... \nsymbols=%d \nsymbolLength=%d",symbols,symbolLength);

				symbolLength=symbols-10; // Leave 10 for Ctl cons.
				symbols=10;

				Log(Crit) << "Failed to add RTPS grant: cid=" << it->cid << ", bandwidth=" << it->bandwidth << ", "
					   << symbolLength << " symbols out of: "<< symbols << ", MSR="<<
					   it->qos.rtps.msr << ", MRR="<< it->qos.rtps.mrr << LogEnd;


				EV<<"MISCONFIGURED MSR in RTPS service... \nsymbols="<<symbols<<""
						"\nsymbolLength="<<symbolLength<<endl;
				cout<<"MISCONFIGURED MSR in RTPS service... \nsymbols="<<symbols<<""
						"\nsymbolLength="<<symbolLength<<endl;
			}



			ieCnt++;
			ulmap->setIEArraySize(ieCnt);
			WMaxUlMapIE ie;
			CLEAR(&ie);
			ie.uiuc = WMAX_ULMAP_UIUC_DATA_1;
			ie.cid = it->cid;
			ie.dataIE.duration = symbolLength;
			ulmap->setIE(ieCnt-1, ie);
			break;
		}
		default:
			break;
		}

   } // End of RTPS based




    /**
     * Urb@n
     *
     * Calculate how much we have free for
     * BE in bps...
     *
     * In congestion case we end up giving to only one each time...
     * In order to avoid giving to the same one we loop circularly.
     *
     * FAIRNESS IS A PAIN IN THE ASS
     */
    freebw=symbols*12*8;

    list<WMaxConn>::iterator itbe=Conns.begin();

    // Adjust iterator
    if (BEpoint > Conns.size())
    	BEpoint = Conns.size();
    advance(itbe,BEpoint);
    Log(Crit)<<"Starting BE at CID="<<itbe->cid<<endl;

    bool moreBE = false;
    for (int i=0; i<(int)Conns.size(); i++){
    	Log(Debug)<<"i="<<i<<" Total="<<Conns.size()<<endl;
    	switch (itbe->type) {
		case WMAX_CONN_TYPE_BE:
		{
			int reqbw = (double)itbe->qos.be.reqbw/WMAX_CDMA_BWR_FREQ;
			uint32_t tmp_bw = reqbw ;
			int symbolLength = 0;


			uint32_t tmp_bw_anal =  tmp_bw;
			Log(Debug)<<" Starting BE with: freebw="<<freebw<<", totbereq="<< totbereq<<endl;
			if (freebw < totbereq)
				tmp_bw_anal = ceil( ((double)tmp_bw) * ((double)freebw)/totbereq);

			// Symbol length just to be printed
			symbolLength = (int)ceil(((double) tmp_bw_anal)/(bytesPerPS*8));

			// Handle Control Connections HERE
			if (itbe->controlConn) {
				itbe++;
				continue;
			}


			// NON Control
			if (count_be*WMAX_SCHED_MIN_BE_SYMBOLS*bytesPerPS*8 > freebw) {

				// We cannot serve all of them and we cannot serve partially
				Log(Debug)<<"SERVING IN RR FASHION"<<endl;
				Log(Debug)<<i<<" point:"<<BEpoint<<endl;
				/**
				 * If the connection requests the more than the min. give the min.
				 * If the symbols left are less than the min. give what is left.
				 * If the symbols are LESS than 11. DO NOT GIVE ANYTHING. Keep it
				 * for control conns
				 */
				if (tmp_bw > WMAX_SCHED_MIN_BE_SYMBOLS*bytesPerPS*8 && symbols>10) {
					// assign min.
					// We have the min. to assign
					if (WMAX_SCHED_MIN_BE_SYMBOLS <= symbols) {
						// assign min.
						tmp_bw_anal = WMAX_SCHED_MIN_BE_SYMBOLS*bytesPerPS*8;
						BEpoint = (i+1)%Conns.size();
					}
					// There is no min. to assign... assign what we have
					// DO not advance iterator
					else{
						tmp_bw_anal = symbols*bytesPerPS*8;
						BEpoint = i;
					}
					moreBE = false;
				}else{
					// Do not allocate at all here...
					//itbe->bandwidth+=reqbw;
					totbereq -= itbe->qos.be.reqbw;//itbe->bandwidth;
					itbe->bandwidth=0;

					moreBE = true;

					Log(Debug) << ": Skipping BE under congestion: cid=" << itbe->cid << ", bandwith=" << tmp_bw << ", Final_bw: "<<tmp_bw_anal
							<< ", reqbw="<< reqbw  << ", "<< symbolLength << " symbols, left=" << symbols << LogEnd;

					itbe++;
					continue;
				}
			} // EoCongested
			else {
				// We are not congested
				Log(Debug)<<"Not Congested: tmp_anal="<<tmp_bw_anal<<", min="<< WMAX_SCHED_MIN_BE_SYMBOLS*bytesPerPS*8
						<<", free="<<freebw<<", req="<<reqbw<<endl;
				if (tmp_bw_anal < (uint)WMAX_SCHED_MIN_BE_SYMBOLS*bytesPerPS*8){

					// Ignore this connection... less than a frame to Tx
					totbereq -= itbe->qos.be.reqbw;  //is it the same as bellow?
					//freebw+=tmp_bw_anal;
					Log(Debug) << ": Skipping BE grant: cid=" << itbe->cid << ", bandwith=" << tmp_bw << ", Final_bw: "<<tmp_bw_anal
						<< ", reqbw="<< reqbw  << ", "<< symbolLength << " symbols, left=" << symbols << LogEnd;
					itbe++;
					continue;
				}
			} // End of Decision Part... Now all are set... (theoretically)

			// Find Symbols
			symbolLength = (int)ceil(((double) tmp_bw_anal)/(bytesPerPS*8));
			// Check for the last one
			if (symbolLength > symbols) symbolLength = symbols;
			symbols -= symbolLength;

			Log(Debug) << ": Adding BE grant: cid=" << itbe->cid << ", bandwith=" << tmp_bw << ", Final_bw: "<<tmp_bw_anal
						<< ", reqbw="<< reqbw  << ", "<< symbolLength << " symbols, left=" << symbols << LogEnd;


			if (symbols<-2)
				opp_error("? you 'll find this error easily\nSymbols: %d",symbols);


			ieCnt++;
			ulmap->setIEArraySize(ieCnt);

			WMaxUlMapIE ie;
			CLEAR(&ie);
			ie.uiuc = WMAX_ULMAP_UIUC_DATA_2;
			ie.cid = itbe->cid;
			ie.dataIE.duration = symbolLength;
			ulmap->setIE(ieCnt-1, ie);
			itbe->bandwidth = tmp_bw_anal;


			break;
		}
		default:
			break;
		}//EoBE Switch

    	// Advance iterator
    	itbe++;

    } // End Of BE loop

    //if (!moreBE)
    //	BEpoint= 0;



    Log(Debug) << "UL schedule: " << startSymbols << " symbols available for UL, " << startSymbols-symbols << " used." << LogEnd;
    if (symbols<=0)
    {
    	Log(Warning) << "Full UL frame, " << startSymbols << " were available, " << symbols << " free." << LogEnd;
    }

    WMaxMacHeader * hdr = new WMaxMacHeader();
    hdr->cid = WMAX_CID_BROADCAST;
    ulmap->setControlInfo(hdr);

    return ulmap;
}

WMaxMacBS::~WMaxMacBS(){

	cancelAndDelete(TxStart);

	delete CDMAQueue;
}

void WMaxMacBS::finish()
{
}


void WMaxMac::initialize(){
	// Stats
	numBytesRecv = 0;
	numBytesSent = 0;
	vecBytesRecv.setName("bytesReceived");
	vecBytesSent.setName("bytesSent");

	queueLimit = par("queueLimit");

	// Initialize MAC parameters statically currently
	symbols = 48;
	/// the % of symbols to be used for upload
	dlSymbolsPc = 0.5;
	subchannels = 60;

}

/**
 * Urb@n
 *
 * Handle the received bw request. Separate function so it can be
 * overriden!!
 */
void WMaxMac::handleRxBWR(WMaxMacHeader *hdr){
	Log(Debug) << "Received bandwidth request, CID=" << hdr->cid << " bandwidth: " << hdr->bwr << LogEnd;
	for (list<WMaxConn>::iterator it = Conns.begin(); it!=Conns.end(); it++) {
		/**
		 * Urb@n
		 *
		 * Check also the connection type. Since for QoS
		 * union was used, we don't want to mess-up with
		 * wrong part of it.
		 */
		if (it->cid == hdr->cid) {
			switch (it->type){
			case WMAX_CONN_TYPE_BE:
				it->qos.be.reqbw = hdr->bwr;
				break;
			case WMAX_CONN_TYPE_RTPS:
				it->qos.rtps.reqbw = hdr->bwr;
				break;
			default:
				Log(Error) << "Received BWR for WRONG Connection Type (cid=" << hdr->cid << ", type="<<it->type<<"). Ignored." << LogEnd;
			}

			return;
		}
	}
	Log(Error) << "Received BWR for unknown (cid=" << hdr->cid << ") connection. Ignored." << LogEnd;
}

/** 
 * Method used to process received (RX) message (i.e. received from PHY, handled to MAC)
 * 
 * @param msg 
 */
void WMaxMac::handleRxMessage(cMessage *msg)
{
    int cid = -1;
    int gateIndex = -1;
    if (dynamic_cast<WMaxMacHeader*>(msg->getControlInfo())) {
		WMaxMacHeader * hdr = dynamic_cast<WMaxMacHeader*>(msg->getControlInfo());
		cid = hdr->cid;

		// bandwidth request arrived in MAC
		if (hdr->ht == true) {
			handleRxBWR(hdr);
			delete msg;
			return;
        }else {
        	// --- BROADCASTS ---
			if (cid==WMAX_CID_BROADCAST){

				// If we are base station...
				if (dynamic_cast<WMaxMacBS*>(this)){
					// Duplicate CtrlInfo...
					cMessage * bcdup = msg->dup();
					bcdup->setControlInfo((dynamic_cast<WMaxMacHeader *>(msg->getControlInfo()))->dup());

					// Send to all the other SSs
					handleTxMessage(msg);

					// Send to the UpLink for BS or to upper Layer
					send(bcdup, "macOut", 0);

				// else we are an SS
				}else{
					// Send to the UpLink for BS or to upper Layer
					send(msg, "macOut", 0);
				}

				// Record
				if (dynamic_cast<cPacket *>(msg)){
					numBytesRecv+=dynamic_cast<cPacket *>(msg)->getByteLength();
					vecBytesRecv.record(numBytesRecv);
				}
				return;


			}
        }
    } else {
		Log(Error) << "Malformed message received: " << msg->getFullName()
			   << ". WMaxMacHeader structure missing." << LogEnd;
		return;
    }





    // check if there is such connection (cid has to match)
    for (list<WMaxConn>::iterator it = Conns.begin(); it!=Conns.end(); it++) {
	if (it->cid == cid) {
	    gateIndex = it->gateIndex;
	    break;
	}
    }

    if (gateIndex != -1) {
    	EV << "Sending message to upper (IPv6) layer (CID=" << cid << ", gateIndex="
    			<< gateIndex << ")" << LogEnd;

		if (dynamic_cast<cPacket *>(msg)){
			numBytesRecv+=dynamic_cast<cPacket *>(msg)->getByteLength();
			vecBytesRecv.record(numBytesRecv);
		}
		send(msg, "macOut", gateIndex);
    } else {
	Log(Debug) << "Unable to find connection for CID=" << cid << ", message dropped." << LogEnd;
	STAT_INC(dropInvalidCid);
        delete msg;
    }
}


void WMaxMac::addRangingConn()
{
    int conns = gateSize("macOut");
    int i = conns - 1; // control connection
    WMaxConn conn;
    CLEAR(&conn.qos);
    conn.type= WMAX_CONN_TYPE_BE;
    conn.sfid = 0; // not important/not used
    conn.cid = 0; // CID=0 (well known CID for initial ranging)
    conn.gateIndex = i;
    conn.qos.be.msr = 100000; // 100kbps
    conn.qos.be.reqbw = 0;
    conn.bandwidth = 0;
    conn.srvName = "Ranging";
    addConn(conn);
    Log(Debug) << "Initial-ranging connection added." << LogEnd;
}

void WMaxMac::addManagementConn(uint16_t cid)
{
    int conns = gateSize("macOut");
    int i = conns - 1; // control connection
    WMaxConn conn;
    CLEAR(&conn.qos);
    conn.type= WMAX_CONN_TYPE_BE;
    conn.sfid = 0; // not important/not used
    conn.cid = cid;
    conn.gateIndex = i;
    conn.qos.be.msr = 100000; // 100kbps
    conn.qos.be.reqbw = 0;
    conn.bandwidth = 0;
    conn.srvName="Ctrl";
    addConn(conn);
    Log(Notice) << "Management connection added. CID: " << cid << LogEnd;
}

/********************************************************************************/
/*** WMax Mac SS ****************************************************************/
/********************************************************************************/
Define_Module(WMaxMacSS);

void WMaxMacSS::initialize(int stage)
{
	if (stage==0){
		SSif = getParentModule()->getParentModule();
		BEpoint = 0;
		SendQueue.setName("SendQueue");
		CLEAR(&Stats);

		ChangePosition = 0;

		// Create permanent INITIAL-RANGING connection
		addRangingConn();

		WATCH_LIST(CDMAlist);

		setInitialPosition();

		int isMobile = (int)SSif->par("wmaxIsMobile");
		if (isMobile>0) {

			if(isMobile==2) { // 2 = SS movement
			  ChangePosition = new cMessage("ChangePosition");
			  scheduleAt(0.0, ChangePosition);
			}
		}

		char buf[80];
		sprintf(buf, "%s%d", getFullName(), SSif->getIndex());
		setName(buf);


		registerInterface(75.0);
		WMaxMac::initialize();


//----- stage : 1 -------
	} else {
		updateIfTableMAC();
	}
}

void WMaxMacSS::registerInterface(double txrate)
{

    IInterfaceTable *ift = InterfaceTableAccess().getIfExists();
    if (!ift)
        return;

    InterfaceEntry * interfaceEntry = new InterfaceEntry();


    // interface name: our module name without special characters ([])
    char *interfaceName = new char[strlen(getParentModule()->getParentModule()->getFullName())+1];
    char *d=interfaceName;
    for (const char *s=getParentModule()->getParentModule()->getFullName(); *s; s++)
        if (isalnum(*s))
            *d++ = *s;
    *d = '\0';

    interfaceEntry->setName(interfaceName);
	string masterifname =  interfaceName;
    delete [] interfaceName;

    // data rate
    interfaceEntry->setDatarate(txrate);

    interfaceEntry->setMtu(1500);

    // capabilities
    interfaceEntry->setMulticast(true);
    interfaceEntry->setBroadcast(true);

    // add
    ift->addInterface(interfaceEntry, this);

    /**
     * If there are services configured use the
     * ServiceConfig to register sub-interfaces
     */
    if (dynamic_cast<ServiceConfig *>( findModuleSomewhereUp("serviceConfig",this)) != NULL){
    	ServiceConfig * srvcfg = dynamic_cast<ServiceConfig *>( findModuleSomewhereUp("serviceConfig",this));
		SrvList serviceList = srvcfg->srvs;

		// Get vlan and register sub interface
		for (int i=0; i<(int)serviceList.size(); i++){
			InterfaceEntry * subInterfaceEntry = new InterfaceEntry();

			// name
			char sub_name[80];
			sprintf(sub_name,"%s.%d",masterifname.c_str(), serviceList[i].vlan);
			subInterfaceEntry->setName(sub_name);

			// generate a link-layer address to be used as interface token for IPv6
			MACAddress addr = MACAddress::generateAutoAddress();
			subInterfaceEntry->setMACAddress(addr);
			subInterfaceEntry->setInterfaceToken(addr.formInterfaceIdentifier());

			// data rate
			subInterfaceEntry->setDatarate(txrate);
			subInterfaceEntry->setMtu(1500);

			// capabilities
			subInterfaceEntry->setMulticast(true);
			subInterfaceEntry->setBroadcast(true);

			// add
			ift->addInterface(subInterfaceEntry, this);
		}
    }
}

void WMaxMacSS::updateIfTableMAC()
{

    IInterfaceTable *ift = InterfaceTableAccess().getIfExists();
    if (!ift)
        return;

    // GET MAC
    ssInfo * ssnfo = ModuleAccess<ssInfo>("ssInfo").get();
    // interface name: our module name without special characters ([])
	char *interfaceName = new char[strlen(getParentModule()->getParentModule()->getFullName())+1];
	char *d=interfaceName;
	for (const char *s=getParentModule()->getParentModule()->getFullName(); *s; s++)
		if (isalnum(*s))
			*d++ = *s;
	*d = '\0';

	string ifname = interfaceName;
    delete [] interfaceName;


    for (int k=0; k<ift->getNumInterfaces(); k++){
    	InterfaceEntry *ie = ift->getInterface(k);
    	if (ie->getName() == ifname){
    		MACAddress mac(MacToString(ssnfo->info.macAddr).c_str());
    		ie->setMACAddress(mac);
    		ie->setInterfaceToken(mac.formInterfaceIdentifier());
    	}
    }
}

void WMaxMacSS::setInitialPosition() {
    cDisplayString dispstr = SSif->getParentModule()->getDisplayString(); // Urban
    long int x,y;
    if ((long int)SSif->par("x")) {
        x = (long int)SSif->par("x");
    } else {
	// expand 50,50,p,300 in physim.ned
	int multi = atoi(SSif->getParentModule()->getDisplayString().getTagArg("p",3));
        x = atoi(SSif->getDisplayString().getTagArg("p", 0));
	x = x + multi*SSif->getIndex();
    }
    if ((long int)SSif->par("y")) {
        y = (long int)SSif->par("y");
    } else {
        y = atoi(SSif->getParentModule()->getDisplayString().getTagArg("p", 1));
    }
    dispstr.setTagArg("p", 0, x);
    dispstr.setTagArg("p", 1, y);
    dispstr.setTagArg("p", 2, "");
    dispstr.setTagArg("p", 3, "");
    SSif->getParentModule()->setDisplayString(dispstr);

    char buf[80];
    sprintf(buf, "(%ld,%ld)", x, y );

    SSif->getParentModule()->getDisplayString().setTagArg("t",0, buf);

}

void WMaxMacSS::updateDisplay() {
    cDisplayString dispstr = SSif->getParentModule()->getDisplayString();


    char buf[80];
    sprintf(buf, "(%s,%s)", dispstr.getTagArg("p",0), dispstr.getTagArg("p",1));
    SSif->getParentModule()->getDisplayString().setTagArg("t",0, buf);
}


void WMaxMacSS::handleMessage(cMessage *msg)
{
    stringstream tmp;
    tmp << "ssMac[" << SSif->getIndex() << "]";
    if (ssMAC *mac = dynamic_cast<ssMAC*>(SSif->getSubmodule(tmp.str().c_str())))
	mac->updateString();

    if (msg==ChangePosition) {
		changePosition();
		scheduleAt(simTime()+0.1, ChangePosition);
		return;
    }

    cGate * gate = msg->getArrivalGate();

    if (dynamic_cast<WMaxMacTerminateAllConns*>(msg)) {
        Log(Notice) << "All connections terminated." << LogEnd;

        int droppedCnt = 0;
        list<WMaxConn>::iterator it;
        for (it = Conns.begin(); it!=Conns.end(); it++) {
        	// Display warning for droped packets
			if (it->queue->getFullName()) {
				Log(Warning) << it->queue->length() << " msg(s) dropped in queue " << it->queue->getFullName() << " during handover." << LogEnd;
				droppedCnt += it->queue->length();
			}
			// Clean the old queues and force logging
            it->queue->clean();
            delete it->queue;
            it->queue=0;
        }
        queuedMsgsCnt -= droppedCnt;
        Conns.clear();
        CDMAlist.clear();
        send(msg, "macOut", 0);

        stringUpdate();

        //initialize();
        addRangingConn();
        return;
    }

    if (WMaxMacAddMngmntConn *addconn = dynamic_cast<WMaxMacAddMngmntConn*>(msg)) {
        uint16_t cid = addconn->getCid();
        addManagementConn(cid);
        delete msg;
        return;
    }

    if (WMaxMacAddConn *addconn = dynamic_cast<WMaxMacAddConn*>(msg)) {
        WMaxQos qos = addconn->getQos(0);

        WMaxConn conn;
        conn.type= qos.connType;
        conn.srvName = addconn->getSrvName();

        switch (qos.connType){
		case WMAX_CONN_TYPE_BE:
			conn.qos.be.msr = qos.msr; // 100kbps
			conn.qos.be.reqbw = 0;
			break;
		case WMAX_CONN_TYPE_UGS:
			conn.qos.ugs.msr = qos.msr; // 100kbps
			break;
		case WMAX_CONN_TYPE_RTPS:
			conn.qos.rtps.msr = qos.msr; // 100kbps
			conn.qos.rtps.mrr = qos.mrr; // 100kbps
			conn.qos.rtps.reqbw = 0;
			break;
		default:
			break;
		}
        conn.sfid = 2; /// @todo set sfid
        conn.cid  = addconn->getCid();
        conn.gateIndex = addconn->getGateIndex();
        conn.bandwidth = 0;
        std::stringstream ss_cid;
        std::string st_cid;
        ss_cid << conn.cid;
        ss_cid >> st_cid;
        addConn(conn);

        send(msg, "macOut", 0);  // send add conn msg to CS
        return;
    }

    Log(Debug) << "Message " << msg->getFullName() << " received on gate: " << gate->getFullName() << LogEnd;
    if (strcmp(gate->getFullName(),"phyIn")) {
        //phyIn gate: downlink (BS->SS)
    	handleTxMessage(msg);
		updateDisplay();
    	return;
    } else {
    	// "macIn" remaining gates must be uplink (SS -> BS)
    	handleRxMessage(msg);
    	return;
    }
}

/** 
 * method used to handle to-be-transmitted (TX) message (i.e. received from MAC, to be sent to PHY)
 * 
 * @param msg 
 */
void WMaxMac::handleTxMessage(cMessage *msg)
{
    cGate * gate = msg->getArrivalGate();
    list<WMaxConn>::iterator it;
    
    // message from WMaxCtrl - add header
     if (!msg->getControlInfo()) {
	 for (it = Conns.begin(); it!=Conns.end(); it++) {
	     if ((it->gateIndex == gate->getIndex()) && (it->controlConn == true)) {
			 WMaxMacHeader * hdr = new WMaxMacHeader();
			 hdr->cid = it->cid;
			 msg->setControlInfo(hdr);
			 break;
	     }
	 }
     }
     
     WMaxMacHeader * hdr = 0;
     hdr = dynamic_cast<WMaxMacHeader*>(msg->getControlInfo());
     if (!hdr)
    	 opp_error("Unable to handle %s message: no header included", msg->getFullName());

     // Urb@n - Check BC
     if (hdr->cid == WMAX_CID_BROADCAST){
    	 SendQueue.insert(msg);
    	 queuedMsgsCnt++;
    	 stringUpdate();
    	 return;
     }

     // find proper connection, not just get first one
     for (it = Conns.begin(); it!=Conns.end(); it++) {
		 if (it->cid == hdr->cid) {
			 break;
		 }
     }

     if (it==Conns.end()) {
		 Log(Error) << "Unable to find connection for CID=" << hdr->cid << LogEnd;
		 delete msg;
		 return;
     }

     // SS ONLY ------------------------
     if (dynamic_cast<WMaxMacSS*>(this)) {
		 // Check if the Queue is full
		 if (it->queue->length() >= queueLimit){
			 Log(Debug) << "Dropping Message "<<msg<<" Queue is FULL..." << LogEnd;
			 it->queue->vec->numBytesDropped+=check_and_cast<cPacket *>(msg)->getByteLength();
			 it->queue->vec->recordVectors();
			 delete msg;
			 return;
		 }

		 switch(it->type) {
		 case WMAX_CONN_TYPE_BE:
		 {
			 Log(Debug) << "Received BE message (CID=" << it->cid << ", len=" << check_and_cast<cPacket *>(msg)->getByteLength() << ") ";
			 int bitsRequested = (int)ceil(double(check_and_cast<cPacket *>(msg)->getByteLength())*8);
			 it->qos.be.reqbw += bitsRequested;
			 if(check_and_cast<cPacket *>(msg)->getByteLength() == 0) {
				 it->qos.be.reqbw += WMAX_BYTES_PER_SYMBOL*8;
			 }
			 Log(Cont) << "CID=" << it->cid << " Required bandwidth: " << bitsRequested << " bits (" << (double)bitsRequested*8/WMAX_BYTES_PER_SYMBOL << " symbols)"
				   << ", " << it->qos.be.reqbw << " required so far" << LogEnd;

			 break;
		 }
		 case WMAX_CONN_TYPE_UGS:
		 {
			 Log(Debug) << "Received UGS message (CID=" << it->cid << ", len=" << check_and_cast<cPacket *>(msg)->getByteLength() << ") ";
			 int symbolLength = (int)ceil(double(check_and_cast<cPacket *>(msg)->getByteLength())/WMAX_BYTES_PER_SYMBOL);

			 Log(Cont) << "CID=" << it->cid << " Required bandwidth: " << symbolLength << " (" << symbolLength*WMAX_BYTES_PER_SYMBOL << ")" << LogEnd;
			 break;
		 }
		 case WMAX_CONN_TYPE_RTPS:
		 {
			 Log(Debug) << "Received RTPS message (CID=" << it->cid << ", len=" << check_and_cast<cPacket *>(msg)->getByteLength() << ") ";
			 int bitsRequested = (int)ceil(double(check_and_cast<cPacket *>(msg)->getByteLength())*8);
			 it->qos.rtps.reqbw += bitsRequested;
			 if(check_and_cast<cPacket *>(msg)->getByteLength() == 0) {
				 it->qos.rtps.reqbw += WMAX_BYTES_PER_SYMBOL*8;
			 }
			 Log(Cont) << "CID=" << it->cid << " Required bandwidth: "<< bitsRequested << " bits ("  << (double)bitsRequested*8/WMAX_BYTES_PER_SYMBOL << ")" << LogEnd;
			 break;
		 }
		 default:
			 opp_error("Unsupported traffic type: %d", it->type);
		 }



		 // Enqueue
		 it->queue->insert(dynamic_cast<cPacket *>(msg));
     } else {
       Log(Debug) << "Queueing message (CID=" << it->cid << ", gateIndex=" << gate->getIndex() << ", length=" << check_and_cast<cPacket *>(msg)->getByteLength() << ")." << LogEnd;
       SendQueue.insert(msg);
     }
     queuedMsgsCnt++;
     stringUpdate();
}

void WMaxMacSS::handleRxMessage(cMessage *msg)
{
    bool bcastMsg = false; // is this a broadcast message?
    if (dynamic_cast<WMaxMsgUlMap*>(msg)) {
		WMaxMsgUlMap * ulmap = dynamic_cast<WMaxMsgUlMap*>(msg);
		printUlMap(ulmap);
		STAT_INC(rcvdUlmaps);
		bcastMsg = true;

		schedule(ulmap);
    }
    if (dynamic_cast<WMaxMsgDCD*>(msg)) {
	bcastMsg = true;
    }
    if (dynamic_cast<WMaxMsgUCD*>(msg)) {
	bcastMsg = true;
    }

    if (bcastMsg) {
	// handle this map to WMaxCtrl
	list<WMaxConn>::iterator it;
	for (it = Conns.begin(); it!=Conns.end(); it++) {
	    if (it->controlConn) {
		// ev << getFullName() << "Dispatching " << msg->getFullName() << " to gate " << it->gateIndex 
		// << ", ctrl=" << ((int)(it->controlConn)) << endl;
		cMessage * copy = (cMessage*)msg->dup();

		send(copy, "macOut", it->gateIndex);
		break;
	    }
	}

	delete msg;
	return;
    }


    if (dynamic_cast<WMaxMsgDlMap*>(msg)) {
		printDlMap(dynamic_cast<WMaxMsgDlMap*>(msg));
		STAT_INC(rcvdDlmaps);
		WMaxMsgDlMap* dlmap = dynamic_cast<WMaxMsgDlMap*>(msg);
		Log(Debug) << "DL-MAP received: expecting " << dlmap->getIEArraySize() << " messages in this frame." << LogEnd;

		// handle this map to WMaxCtrl
		list<WMaxConn>::iterator it;
		for (it = Conns.begin(); it!=Conns.end(); it++) {
			if (it->controlConn) {
			Log(Debug) << "Dispatching dlmap to gate " << it->gateIndex << ", ctrl=" << ((int)(it->controlConn)) << LogEnd;
			send(msg, "macOut", it->gateIndex);
			break;
			}
		}

		// @todo - delete dlmap
		//delete msg;
		return;
    }

    WMaxMac::handleRxMessage(msg);
}

void WMaxMacSS::changePosition() {
    cDisplayString dispstr = SSif->getParentModule()->getDisplayString(); // URban ->getParentModule()
    long int x = atoi(dispstr.getTagArg("p",0));
    long int y = atoi(dispstr.getTagArg("p",1));

    switch ((int)SSif->par("movementType")) {
    case 0:
        x++;
        break;
    case 1:
        float centerx=(double)SSif->par("SStrace_centerx");
        float centery=(double)SSif->par("SStrace_centery");
        float radius=(double)SSif->par("SStrace_radius");
        float radstep=(double)SSif->par("SStrace_step");
        x=(long int)(sin(radian)*radius+centerx);
        y=(long int)(cos(radian)*radius+centery);
        radian=radian+radstep;
        break;
    }

    dispstr.setTagArg("p",0,x);
    dispstr.setTagArg("p",1,y);
    SSif->getParentModule()->setDisplayString(dispstr);

    char buf[80];
    sprintf(buf, "(%s,%s)", (SSif->getParentModule()->getDisplayString()).getTagArg("p",0),
							(SSif->getParentModule()->getDisplayString()).getTagArg("p",1));
    SSif->getParentModule()->getDisplayString().setTagArg("t",0, buf);
}

/**
 * Urb@n: TODO: Re-Write !!!! Spaghetti code...
 */
void WMaxMacSS::schedule(WMaxMsgUlMap * ulmap)
{
    uint32_t bandwidth = 0;
    Log(Debug) << "UL-MAP received with " << ulmap->getIEArraySize() << " IE(s)." << LogEnd;
    unsigned int i;
    for (i=0; i<ulmap->getIEArraySize(); i++) {
		WMaxUlMapIE & ie = ulmap->getIE(i);

		for (list<WMaxConn>::iterator it = Conns.begin(); it!=Conns.end(); it++) {

			// Check CID
			if (it->cid!=ie.cid) continue;


			if (ie.uiuc>=WMAX_ULMAP_UIUC_DATA_1 || ie.uiuc<=WMAX_ULMAP_UIUC_DATA_10) {


				STAT_INC(rcvdGrants);

				int bytesPerPS = WMAX_BYTES_PER_SYMBOL; // this depends on modulation used, use 12 bytes/symbol for now
				int lengthInPS;
				cMessage * msg;
				int ieCnt = 0;
				int symbols = ie.dataIE.duration;

				bandwidth = symbols*8*bytesPerPS;

				// Update bandwidth
				it->bandwidth = bandwidth;


				/**
				 * Urb@n
				 *
				 * Do the same for UGS traffic !!!
				 * (I think we should...)
				 */

				if ((it->type == WMAX_CONN_TYPE_BE || it->type == WMAX_CONN_TYPE_UGS || it->type == WMAX_CONN_TYPE_RTPS)
						&& it->queue->length() && bandwidth){

					bool moveToNextIE=false;
					while (true) {
						Log(Debug) << "CID="<<it->cid << " "<< symbols << " symbols left." << LogEnd;

						 if (!it->queue->length()) {
							 Log(Debug) << "CID="<<it->cid << " is OUT OF PACKETS (check starvation)" << LogEnd;
							 break;
						 }

						 if (symbols <=0)
						 break;

						 msg = (cMessage*) it->queue->front();
						 int bytes_len = check_and_cast<cPacket *>(msg)->getByteLength();
						 // fix zero length
						 if (bytes_len == 0) bytes_len = bytesPerPS;

						 if (bytes_len > symbols*bytesPerPS) {
							 // message won't fit in this frame. What should we do in such case?
								 Log(Debug) << ": CID="<<it->cid << " Tried to schedule message (len=" << check_and_cast<cPacket *>(msg)->getByteLength() << "), but there are only "
										 << symbols*bytesPerPS << " bytes left." << LogEnd;

							 /**
							  * Urb@n
							  *
							  * break if the message does not fit....
							  * We are going to suffer from huge delay but not droprate.
							  * The BS shouldn't allocate less than the min. for the service
							  * type and we should eng. the packet size to conform with the
							  * min. allocation.... (or implement fragmentation (< NOT ME :-) ))
							  *
							  * I leave it for compatibility, either way we are going to eng. our traffic
							  * characteristics later and avoid this situation.
							  */
							 if (ieCnt) // something has been scheduled - ok, end scheduling
							 break;

							 // currently used: c)
							 //msg = (cMessage*) it->queue->popNoLogging();
//							 Log(Error) << ": Unable to send " << check_and_cast<cPacket *>(msg)->getByteLength() << "-byte message(" << msg->getFullName()
//								<<") to CID="<<it->cid<<", because it won't fit in UL subframe. Message is dropped." << LogEnd;
							 //queuedMsgsCnt--;
							 //delete msg;
							 //continue;
							 Log(Error) << ": Unable to send " << check_and_cast<cPacket *>(msg)->getByteLength() << "-byte message(" << msg->getFullName()
									<<") to CID="<<it->cid<<", because it won't fit in UL subframe. Going to Next IE." << LogEnd;
							 moveToNextIE=true;
							 break; // break the while loop

							 // currently used: d)
							 /*opp_error("Unable to send %d-byte long message(%s), because it won't fit in UL subframe (%d symbols *%dB/PS=%d bytes)",
							 msg->getByteLength(), msg->getFullName(), symbols, bytesPerPS, symbols*bytesPerPS);
							 break;*/
						 }

						 // message will fit in this frame, send it
						 ieCnt++;

						 msg = (cMessage*)it->queue->pop();
						 queuedMsgsCnt--;

						 // Reduce required bandwidth for this CID
						 if (it->type == WMAX_CONN_TYPE_BE){
							 it->qos.be.reqbw -= bytes_len*8;
						 }else if (it->type == WMAX_CONN_TYPE_RTPS){
							 it->qos.rtps.reqbw -= bytes_len*8;
							 EV <<"SHIT: "<<it->qos.rtps.reqbw<<" - "<<bytes_len*8 <<endl;
						 }

						 lengthInPS = (int)ceil(double(bytes_len)/bytesPerPS);

						 symbols -= lengthInPS;

						 WMaxMacHeader * hdr = dynamic_cast<WMaxMacHeader*>(msg->getControlInfo());
						 if (!hdr)
							  opp_error("Unable to obtain header information for message: %s\n", msg->getFullName());

						 Log(Debug) << ": CID="<<it->cid <<" Sent msg: length=" << check_and_cast<cPacket *>(msg)->getByteLength() << ", used " << lengthInPS << " symbols, "
								 << symbols << " symbol(s) left" << LogEnd;

						 if (dynamic_cast<cPacket *>(msg)){
							numBytesSent+=dynamic_cast<cPacket *>(msg)->getByteLength();
							vecBytesSent.record(numBytesSent);
						 }

						 send(msg, "phyOut");
					} // End of while (send all the packets till bandwidth is reached)
				} // End of WMAX_CONN_TYPE_BE/UGS

			} // End of WMAX_ULMAP_UIUC_DATA_1 >= ie.uiuc <= WMAX_ULMAP_UIUC_DATA_10

			/* @todo - Urb@n
			else if (ie.uiuc==WMAX_ULMAP_UIUC_CDMA_BWR) {
			} else if (ie.uiuc==WMAX_ULMAP_UIUC_CDMA_ALLOC) {}
			*/



		} // End of for loop for cids/connections

		/**
		 * We are queried for our required bandwidth... Reply for BE and rtPS.
		 */
		if (ie.uiuc==WMAX_ULMAP_UIUC_CDMA_BWR && ie.cdmaIE.rangingMethod==WMAX_RANGING_METHOD_BWR) {

			for (unsigned int i=0; i!=Conns.size(); i++) {

				list<WMaxConn>::iterator REQit = Conns.begin();
				for (int j=0; j!=BEpoint; j++){
					REQit++;
					if (REQit == Conns.end())
						REQit = Conns.begin();
				}

				BEpoint++;
				BEpoint = BEpoint%(int)Conns.size();

				if (REQit->type == WMAX_CONN_TYPE_BE) {
					if (REQit->qos.be.reqbw) {
						WMaxMacCDMA cdma;
						cdma.code = rand()%256;
						cdma.bandwidth = REQit->qos.be.reqbw;
						//REQit->qos.be.reqbw = 0;
						cdma.cid = REQit->cid;
						CDMAlist.push_back(cdma);
						WMaxMsgCDMA *cdmamsg = new WMaxMsgCDMA("CDMA");
						cdmamsg->setCode(cdma.code);
						cdmamsg->setPurpose(WMAX_CDMA_PURPOSE_BWR);
						Log(Debug) << "Sending CDMA code: " << cdma.code <<" (cid: " << cdma.cid << ", bandwidth: "
									<< cdma.bandwidth << ")" << LogEnd;
						send(cdmamsg, "phyOut");
						//break;
					}
				}else if (REQit->type == WMAX_CONN_TYPE_RTPS) {
					if (REQit->qos.rtps.reqbw) {
						WMaxMacCDMA cdma;
						cdma.code = rand()%256;
						cdma.bandwidth = REQit->qos.rtps.reqbw;
						 EV <<"SHIT_REP: "<<REQit->qos.rtps.reqbw<<endl;
						//REQit->qos.rtps.reqbw = 0;
						cdma.cid = REQit->cid;
						CDMAlist.push_back(cdma);
						WMaxMsgCDMA *cdmamsg = new WMaxMsgCDMA("CDMA");
						cdmamsg->setCode(cdma.code);
						cdmamsg->setPurpose(WMAX_CDMA_PURPOSE_BWR);
						Log(Debug) << "Sending CDMA code: " << cdma.code <<" (cid: " << cdma.cid << ", bandwidth: "
									<< cdma.bandwidth << ")" << LogEnd;
						send(cdmamsg, "phyOut");
						//break;
					}
				}
			}


		}
	
			if (ie.uiuc==WMAX_ULMAP_UIUC_CDMA_ALLOC) {
			   for (list<WMaxMacCDMA>::iterator it = CDMAlist.begin(); it!=CDMAlist.end(); it++) {
				   if (it->code == ie.cdmaAllocIE.rangingCode){
					   WMaxMacHeader *hdr = new WMaxMacHeader();
					   hdr->ht = true;
					   hdr->bwr = it->bandwidth;
	
					   for (list<WMaxConn>::iterator it2=Conns.begin(); it2!=Conns.end(); it2++) {
						   if (it2->cid == it->cid){
							   if (!it2->queue->empty()) {
								   cMessage * msg = (cMessage*) it2->queue->front();
								   if(hdr->bwr < check_and_cast<cPacket *>(msg)->getByteLength())
									   hdr->bwr = check_and_cast<cPacket *>(msg)->getByteLength();
							   }
						   }
					   }
	
					   hdr->cid = it->cid;
					   WMaxMsgBWR *msg = new WMaxMsgBWR("Bandwidth request");
					   msg->setControlInfo(hdr);
					   Log(Info) << "Sending Bandwidth request (bandwidth: " << hdr->bwr << ", cid: "  << hdr->cid << ")" << LogEnd;
					   send(msg, "phyOut");
					   CDMAlist.erase(it);
					   break;
				   }
			   }
		}

    }


    if (SendQueue.length()) {
    	cMessage * msg = (cMessage*)SendQueue.pop();
    	queuedMsgsCnt--;
    	send(msg, "phyOut");
    }

    STAT_ADD(rcvdBandwidth, bandwidth);

    WMaxPhyDummyFrameStart * frameStart = new WMaxPhyDummyFrameStart();
    send(frameStart, "phyOut");

    stringUpdate();
}

WMaxMacSS::~WMaxMacSS(){

	if (ChangePosition)
		cancelAndDelete(ChangePosition);
	delete CDMAQueue;

}

void WMaxMacSS::finish()
{


}
