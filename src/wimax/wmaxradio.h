/**
 * @file   wmaxmac.h
 * @author Tomasz Mrugalski <thomson@klub.com.pl>
 * @date   2007-06-25 01:27:46+0200
 * 
 * @brief  WMax Radio connector (used to connect multiple SSes to one BS)
 * @licence GNU GPLv2
 * 
 */

#ifndef WMAXRADIO_H
#define WMAXRADIO_H

#include <omnetpp.h>
#include <vector>
#include "fsm.h"
#include "wmaxmsg_m.h"
#include "wmaxmac.h"
#include "ssinfo.h"

class WMaxRadio : public cSimpleModule
{
public:
    void connect(cModule * ss);
    /**
     * Urban: Second parameter indicates if the call comes
     * from a destructor. If true, the module will send a
     * WMaxMacHeader message do clean the BS ssList.
     */
    void disconnect(cModule * ss, bool fromDestructor=false);
protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

#endif
