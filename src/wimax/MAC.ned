package numbat.wimax;

simple WMaxMacCS
{
    gates:
        input macIn;
        output macOut;
        input ipIn[];
        output ipOut[];
}

simple WMaxMacSS
{
    parameters:
        // WiMax Frame Length
        // Frame can vary from 2-20ms, but 5ms
	 	// is for MobileWiMax
        volatile double FrameLength @unit(s) = default(5ms);
        
        int queueLimit = default(1000);
    gates:
        input phyIn;
        output phyOut;
        input macIn[];
        output macOut[];
}

simple WMaxCtrlSS
{
    gates:
        output macOut;
        input macIn;
        input eventIn;
}

moduleinterface IWMaxMacBS
{
    parameters:
        // WiMax Frame Length
        // Frame can vary from 2-20ms, but 5ms
	 	// is for MobileWiMax
        volatile double FrameLength @unit(s);
        int queueLimit;
    gates:
        input phyIn;
        output phyOut;
        input macIn[];
        output macOut[];
}

simple WMaxMacBS like IWMaxMacBS
{
    parameters:
        // WiMax Frame Length
        // Frame can vary from 2-20ms, but 5ms
	 	// is for MobileWiMax
        volatile double FrameLength @unit(s) = default(5ms);
        int queueLimit = default(1000);
    gates:
        input phyIn;
        output phyOut;
        input macIn[];
        output macOut[];
}

simple WMaxCtrlBS
{
    parameters:
        volatile double MinDelayCdmav @unit(s) = default(0s);
        volatile double MaxDelayCdma @unit(s) = default(0s);
        volatile double MinDelayRng @unit(s) = default(0s);
        volatile double MaxDelayRng @unit(s) = default(0s);
        volatile double MinDelaySbc @unit(s) = default(0s);
        volatile double MaxDelaySbc @unit(s) = default(0s);
        volatile double MinDelayScn @unit(s) = default(0s);
        volatile double MaxDelayScn @unit(s) = default(0s);
        volatile double MinDelayReg @unit(s) = default(0s);
        volatile double MaxDelayReg @unit(s) = default(0s);
        volatile double MinDelayHoRsp @unit(s) = default(0s);
        volatile double MaxDelayHoRsp @unit(s) = default(0s);
        volatile double MinDelayDsxRvd @unit(s) = default(0s);
        volatile double MaxDelayDsxRvd @unit(s) = default(0s);
        volatile double MinDelayDsxRsp @unit(s) = default(0s);
        volatile double MaxDelayDsxRsp @unit(s) = default(0s);
        volatile double MinDelaySaTek @unit(s) = default(0s);
        volatile double MaxDelaySaTek @unit(s) = default(0s);
    gates:
        output macOut;
        input macIn;
}


module ssMAC
{
    parameters:
        @display("bgb=346,162");

    gates:
        output phyOut;
        output netwOut;
        input phyIn;
        input netwIn;
        
    submodules:
        ssMac: WMaxMacSS {
            parameters:
                @display("i=block/control,#ce1821;p=160,96;q=SendQueue");
        }
        WMaxCtrlSS: WMaxCtrlSS {
            parameters:
                @display("i=block/cogwheel,#ce1821;p=264,80");
        }
        ssCS: WMaxMacCS {
            parameters:
                @display("p=64,64;i=block/classifier,#ce1821");
        }
    connections allowunconnected:
        ssMac.phyOut --> phyOut;
        phyIn --> ssMac.phyIn;

        ssCS.ipOut++ --> netwOut;
        netwIn --> ssCS.ipIn++;

        ssMac.macOut++ --> ssCS.macIn;
        ssCS.macOut --> ssMac.macIn++;

        ssMac.macOut++ --> WMaxCtrlSS.macIn;
        WMaxCtrlSS.macOut --> ssMac.macIn++;

}


module bsMAC
{
    parameters:
        @display("bgb=306,162");
        string macModule = default("WMaxMacBS");
    gates:
        output phyOut;
        output ipOut;
        input phyIn;
        input ipIn;
    submodules:
        bsMac: <macModule> like IWMaxMacBS {
            parameters:
                @display("i=block/control,#40e221;p=152,112;q=SendQueue");
        }
        WMaxCtrlBS: WMaxCtrlBS {
            parameters:
                @display("i=block/cogwheel,#40e221;p=240,72");
        }
        bsCS: WMaxMacCS {
            parameters:
                @display("i=block/classifier,#40e221;p=72,72");
        }
    connections allowunconnected:

        bsMac.phyOut --> phyOut;
        phyIn --> bsMac.phyIn;

        bsCS.ipOut++ --> ipOut;
        ipIn --> bsCS.ipIn++;

        bsMac.macOut++ --> bsCS.macIn;
        bsCS.macOut --> bsMac.macIn++;

        bsMac.macOut++ --> WMaxCtrlBS.macIn;
        WMaxCtrlBS.macOut --> bsMac.macIn++;

}

