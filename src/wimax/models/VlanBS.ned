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

import Vlans.linklayer.EtherMacVlan;
import inet.base.NotificationBoard;
import inet.networklayer.common.InterfaceTable;
import Vlans.linklayer.EtherVlanInterface;
import numbat.wimax.MacDummy;
import numbat.ipv6.*;
import numbat.wimax.*;
import numbat.wimax.WMaxPhyBS;

module VlanBS
{
    parameters:
        //volatile double x;
        //volatile double y;
        @display("bgb=350,117;i=device/antennatower");
        @node;
        // Maximum SSes for this BS
        int maxSS = default(100);

    gates:
        output out[maxSS];
        input in[maxSS];
        inout phy;


    submodules:
        bsPhy: WMaxPhyBS {
            parameters:
                @display("i=abstract/accesspoint,#40e221;p=232,55;q=SendQueue");
        }
        bsMac: bsMAC {
            parameters:
                @display("i=block/control,#40e221;p=151,55;q=SendQueue");
        }
        radio: WMaxRadio {
            parameters:
                @display("p=312,55;i=device/receiverdish,#40e221,30");
            gates:
                radioIn[sizeof(in)];
                radioOut[sizeof(in)]; // use in, for consistency

        }
        etherVlanInterface: EtherVlanInterface {
            @display("p=65,55");
        }
    connections allowunconnected:

        bsMac.phyOut --> bsPhy.phyIn;
        bsPhy.phyOut --> bsMac.phyIn;

        radio.phyOut --> bsPhy.rfIn;
        bsPhy.rfOut --> radio.phyIn;

        etherVlanInterface.netwOut --> bsMac.ipIn;
        bsMac.ipOut --> etherVlanInterface.netwIn;
        etherVlanInterface.phys <--> phy;

        //radio.radioOut[0] --> out++;
        //in++ --> radio.radioIn[0];
}
