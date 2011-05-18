cplusplus {{
#include "IPv6Addr.h"
}}


struct IPv6Addr;

//message --> packet due to migration to v4.0 (MiM)
//In other files: cMessage* pointer replaced by cPacket* (MiM)

//message IPv6
packet IPv6Packet
{
    IPv6Addr srcIP;
    IPv6Addr dstIP;

    bool BindingUpdate;
    bool BindingAck;
    bool Dhcpv6Relay;
}

packet IPv6Ra extends IPv6Packet
{
}


// ********************************************************************************
// *** DHCPv6 packets ************************************************************
// ********************************************************************************

packet DHCPv6Solicit extends IPv6Packet
{
    bool rapidCommit;
    bool addrParams;

    bool remoteConf;
    int remoteBS;
}

packet DHCPv6Advertise extends IPv6Packet
{
    int preference;
    bool addrParams;

    bool remoteConf;
}

packet DHCPv6Request extends IPv6Packet
{
    bool addrParams;

    bool remoteConf;
    int remoteBS;
}

packet DHCPv6Reply extends IPv6Packet
{
    IPv6Addr addr;
    bool addrParams;
    bool remoteConf;
}

packet DHCPv6Confirm extends IPv6Packet
{
    bool addrParams;

    bool remoteConf;
    int remoteBS;
}
