/*
 * Dibbler - a portable DHCPv6
 *
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>
 *          Marek Senderski <msend@o2.pl>
 * changes: Micha� Kowalczuk <michal@kowalczuk.eu>
 * changes: Micha� Kowalczuk <michal@kowalczuk.eu>
 *
 * $Id: Logger.h,v 1.15 2006-11-30 03:21:51 thomson Exp $
 *
 * Released under GNU GPL v2 licence
 *
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <omnetpp.h>
#include "cenvir.h"
#include <iostream>
#include <string>

#define Log(X) SLog(this,X)
#define SLog(OBJ,X) logger::setSimTime((float)OBJ->simTime()); logger::setLogName(OBJ->fullName()); logger::setEv(&ev); logger :: log##X ()
#define LogEnd logger :: endl

#define LOGMODE_DEFAULT LOGMODE_SIMTIME

namespace logger {
    const int Emerg=1;
    const int Alert=2;
    const int Crit=3;
    const int Error=4;
    const int Warning=5;
    const int Notice=6;
    const int Info=7;
    const int Debug=8;

    enum Elogmode {
	LOGMODE_FULL,
	LOGMODE_SHORT,
	LOGMODE_SYSLOG,
	LOGMODE_EVENTLOG, /* unix only */
	LOGMODE_PRECISE,
	LOGMODE_SIMTIME
    };

    using namespace std;
    ostream& logCont();
    ostream& logEmerg();
    ostream& logAlert();
    ostream& logCrit();
    ostream& logError();
    ostream& logWarning();
    ostream& logNotice();
    ostream& logInfo();
    ostream& logDebug();

    void Initialize(const char * file);
    void Terminate();
    void setLogName(string x);
    void setLogLevel(int x);
    void setLogMode(string x);
    void setEv(cEnvir * ev);
    void EchoOff();
    void EchoOn();
    string getLogName();
    int getLogLevel();
    void setSimTime(float x);
    bool willPrint(int x);
    
    ostream & endl (ostream & strum);

}

#endif
