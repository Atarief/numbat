/**
 * @file   dhcpbv6.h
 * @author Tomasz Mrugalski <thomson@klub.com.pl>
 * @date   Tue Aug  7 12:55:16 CET 2007
 * 
 * @brief  DHCPv6 server/client
 * 
 * Published under GNU GPLv2 or later 
 */

#ifndef DHCPV6_H
#define DHCPV6_H

#include <stdint.h>
#include <omnetpp.h>
#include "fsm.h"


class MobIPv6mn : public Fsm
{
 public:
 protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    void fsmInit();
 private:
};

class MobIPv6ha : public cSimpleModule
{
 public:
 protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
 private:
};

class MobIPv6cn: public cSimpleModule
{
 public:
 protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
 private:
};

#endif