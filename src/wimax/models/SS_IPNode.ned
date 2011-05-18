//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package numbat.wimax.models;

import numbat.mobility.*;


import inet.applications.pingapp.PingApp;
import inet.applications.tcpapp.TCPApp;
import inet.applications.udpapp.UDPApp;
import inet.applications.sctpapp.SCTPApp;   //I.R.
import inet.base.NotificationBoard;
import inet.linklayer.ethernet.EthernetInterface;
import inet.linklayer.ppp.PPPInterface;
import inet.linklayer.ext.ExtInterface; //I.R.
import inet.networklayer.common.InterfaceTable;
import inet.networklayer.ipv4.RoutingTable;
import inet.nodes.inet.NetworkLayer;
import inet.transport.tcp.TCP;
import inet.transport.udp.UDP;
import inet.transport.sctp.SCTP;    //I.R.
import inet.util.TCPDump;   //I.R.
import inet.util.NAMTraceWriter;

import Vlans.linklayer.*;
import Vlans.networklayer.*;
import Vlans.linklayer.EtherVlanInterface;

module SS_IPNode
{
    parameters:
        int numifs = 1;

        @display("bgb=602,511;i=device/cellphone");

        // Stack
        int numTcpApps = default(0);
        int numUdpApps = default(0);
        int numSctpApps = default(0);   //I.R.
        string tcpAppType = default("n/a");
        string udpAppType = default("n/a");
        string sctpAppType = default("n/a");    //I.R.
        bool IPForward = default(false);
        int namid = default(-1);
        string routingFile = default("");
        string mobilityType = default("NULL");
        @node;

    gates:
        output radioOut;
        input radioIn;


    submodules:


        // Stack
        namTrace: NAMTraceWriter {
            parameters:
                namid = namid;
                @display("p=60,310");
        }
        notificationBoard: NotificationBoard {
            parameters:
                @display("p=60,70");
        }
        interfaceTable: InterfaceTable {
            parameters:
                @display("p=60,150");
        }
        routingTable: RoutingTable {
            parameters:
                IPForward = IPForward;
                routerId = "";
                routingFile = routingFile;
                @display("p=60,230");
        }
        tcpApp[numTcpApps]: <tcpAppType> like TCPApp {
            parameters:
                @display("p=163,53");
        }
        tcp: TCP {
            parameters:
                @display("p=163,154");
        }
        udpApp[numUdpApps]: <udpAppType> like UDPApp {
            parameters:
                @display("p=272,67");
        }
        udp: UDP {
            parameters:
                @display("p=272,154");
        }
        sctpApp[numSctpApps]: <sctpAppType> like SCTPApp {  //I.R.
            parameters:
                @display("p=385,85");
        }
        sctp: SCTP {    //I.R.
            @display("p=382,170;i=block/wheelbarrow");
        }
        pingApp: PingApp {
            parameters:
                @display("p=376,241");
        }
        networkLayer_vlans: NetworkLayerVlans {
            parameters:
                proxyARP = false;
                @display("p=248,247;q=queue");
            gates:
                ifIn[numifs];   //I.R.
                ifOut[numifs];
        }
        tcpdump: TCPDump {  //I.R.
            parameters:
                @display("p=351,332;i=abstract/cache_s");
            gates:
                ifIn[numifs];
                in2[numifs];
                ifOut[numifs];
                out2[numifs];
        }
        wimax: WiMaxSSInterface {
            @display("p=233,434");
        }

        mobility: <mobilityType> like WiMaxBasicMobility {
            @display("p=60,397");
            controlModuleName = "WiMaxCC";
        }
    connections allowunconnected:

        for i=0..numTcpApps-1 {
            tcpApp[i].tcpOut --> tcp.appIn++;
            tcpApp[i].tcpIn <-- tcp.appOut++;
        }

        tcp.ipOut --> networkLayer_vlans.tcpIn;
        tcp.ipIn <-- networkLayer_vlans.TCPOut;

        for i=0..numUdpApps-1 {
            udpApp[i].udpOut --> udp.appIn++;
            udpApp[i].udpIn <-- udp.appOut++;
        }

        udp.ipOut --> networkLayer_vlans.udpIn;
        udp.ipIn <-- networkLayer_vlans.udpOut;

        for i=0..numSctpApps-1 {
            sctpApp[i].sctpOut --> sctp.from_appl++;
            sctp.to_appl++ --> sctpApp[i].sctpIn;
        }
        sctp.to_ip --> networkLayer_vlans.sctpIn;
        networkLayer_vlans.sctpOut --> sctp.from_ip;

        networkLayer_vlans.pingOut --> pingApp.pingIn;
        networkLayer_vlans.pingIn <-- pingApp.pingOut;


        tcpdump.ifOut[0] --> wimax.netwIn;
        wimax.netwOut --> tcpdump.ifIn[0];
        networkLayer_vlans.ifOut[0] --> tcpdump.in2[0];
        tcpdump.out2[0] --> networkLayer_vlans.ifIn[0];

        // WiMax
        wimax.out --> radioOut;
        radioIn --> wimax.in;
}
