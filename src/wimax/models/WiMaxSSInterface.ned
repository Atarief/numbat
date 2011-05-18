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

import numbat.wimax.*;
import numbat.ipv6.*;
import numbat.wimax.*;

module WiMaxSSInterface
{
    parameters:
        volatile int wmaxHoOptim;
        // isMobile == 1 -> handover executed after certain timeout
        // isMobile == 2 -> SS changes location and handover is based on distance
        // isMobile == 4 -> SS doesn't changes location and handover is based on distance
        volatile int wmaxIsMobile;
        volatile int movementType;
        volatile double x;
        volatile double y;
        volatile int initialBS;
        volatile double NetworkEntryTime;
        volatile double HandoverTime;
        volatile int dadType;
        volatile bool dhcpSkipInitialDelay;
        volatile bool dhcpPref255;
        volatile bool dhcpRapidCommit;
        volatile bool dhcpRemoteAutoconf;
        volatile bool dhcpAddrParams;
        volatile bool mipRemoteLocUpdate;
        /// WiMax Connection Type: 2=BE and 6=UGS.
        volatile int connType;
        /// MSR for UGS Connections
        volatile int connMsr @unit(bps);
        volatile double SStrace_centerx;
        volatile double SStrace_centery;
        volatile double SStrace_radius;
        volatile double SStrace_step;
    	@display("bgb=286,110;i=device/card");
    	
    gates:
        output out;
        input in;
        input netwIn;
        output netwOut;

    submodules:
        ssPhy: WMaxPhySS {
            parameters:
                @display("i=abstract/accesspoint,#ce1821;q=SendQueue;p=237,58");
        }
        ssMac: ssMAC {
            parameters:
                @display("i=block/control,#ce1821;p=137,47");
        }
        ssInfo: ssInfo {
            parameters:
                @display("i=block/blackboard,#ce1821;p=47,58");
        }



    connections allowunconnected:

        ssMac.phyOut --> ssPhy.phyIn;
        ssPhy.phyOut --> ssMac.phyIn;

        ssPhy.rfOut --> out;
        in --> ssPhy.rfIn;

        netwIn --> ssMac.netwIn;
        ssMac.netwOut --> netwOut;
}
