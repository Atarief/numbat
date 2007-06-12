/*                                                                           
 * Dibbler - a portable DHCPv6                                               
 *                                                                           
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>                           
 *          Marek Senderski <msend@o2.pl>                                    
 * changes: Micha� Kowalczuk <michal@kowalczuk.eu>
 *                                                                           
 * released under GNU GPL v2 or later licence                                
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <sys/time.h>
#include <time.h>
#include "logger.h"
#include <omnetpp.h>
#include "cenvir.h"

namespace logger {
//    const int Emerg=1;
//    const int Alert=2;
//    const int Crit=3;
//    const int Error=4;
//    const int Warning=5;
//    const int Notice=6;
//    const int Info=7;
//    const int Debug=8;

    string logname="Init";
    int logLevel=8;
    Elogmode logmode = LOGMODE_DEFAULT; /* default logmode */
    ofstream logFile;    // file where wanted msgs are stored
    bool logFileMode = false;
    bool echo = true; // print copy of the message to the console
    int curLogEntry = 8; // 8 - debug 
    float simTime = -1.0f;
    cEnvir * ev = 0;

    ostringstream buffer;

    // LogEnd;
    ostream & endl (ostream & strum) {
	if (curLogEntry <= logLevel) {
	    // log on the console
	    if (echo)
		std::cout << buffer.str() << std::endl;

	    // log to the file
	    if (logFileMode)
		logger::logFile << buffer.str() << std::endl;

	    if (ev)
		*ev << buffer.str() << std::endl;
	}

	buffer.str(std::string());
	buffer.clear();

	return strum;
    }
    
    ostream & logCommon(int x) {
	static char lv[][10]= {"Emergency",
			       "Alert    ",
			       "Critical ",
			       "Error    ",
			       "Warning  ",
			       "Notice   ",
			       "Info     ",
			       "Debug    " };

	logger::curLogEntry = x;

	time_t teraz;
	teraz = time(NULL);
	struct tm * now = localtime( &teraz );
	switch(logmode) {
	case LOGMODE_FULL:
	    buffer << (1900+now->tm_year) << ".";
	    buffer.width(2); buffer.fill('0'); buffer << now->tm_mon+1 << ".";
	    buffer.width(2); buffer.fill('0'); buffer << now->tm_mday  << " ";
	    buffer.width(2);    buffer.fill('0'); buffer << now->tm_hour  << ":";
	    buffer.width(2);	buffer.fill('0'); buffer << now->tm_min   << ":";
	    buffer.width(2);	buffer.fill('0'); buffer << now->tm_sec;
	    break;
	case LOGMODE_SHORT:
	    buffer.width(2);	buffer.fill('0'); buffer << now->tm_min   << ":";
	    buffer.width(2);	buffer.fill('0'); buffer << now->tm_sec;
	    break;
	case LOGMODE_PRECISE:
		int sec, usec;
#ifndef WIN32
		/* get time, Unix style */
		struct timeval preciseTime;
		gettimeofday(&preciseTime, NULL);
		sec  = preciseTime.tv_sec%3600;
		usec = preciseTime.tv_usec; 
#else
		/* get time, Windws style */
		SYSTEMTIME now;
		GetSystemTime(&now);
		sec = now.wMinute*60 + now.wSecond;
		usec= now.wMilliseconds*1000;
#endif
		buffer.width(4); buffer.fill('0'); buffer << sec  << "s,";
	    buffer.width(6); buffer.fill('0'); buffer << usec << "us ";
	    break;
	case LOGMODE_SIMTIME:
	    buffer << "[";
	    buffer.width(5);
	    buffer << simTime << "]";
	    break;
	    break;
	case LOGMODE_SYSLOG:
	    buffer << "SYSLOG logging mode not supported yet.";
	    break;
	case LOGMODE_EVENTLOG:
	    buffer << "SYSLOG logging mode not supported yet.";
	    break;
	}
	buffer << ' ';
	buffer.width(10);
	buffer << logger::logname ;
	buffer << ' ' << lv[x-1] << " ";
	return buffer;
    }

    ostream& logCont()    { return logger::buffer; }
    ostream& logEmerg()   { return logger::logCommon(1); }
    ostream& logAlert()   { return logger::logCommon(2); }
    ostream& logCrit()    { return logger::logCommon(3); }
    ostream& logError()   { return logger::logCommon(4); }
    ostream& logWarning() { return logger::logCommon(5); }
    ostream& logNotice()  { return logger::logCommon(6); }
    ostream& logInfo()    { return logger::logCommon(7); }
    ostream& logDebug()   { return logger::logCommon(8); }

    void Initialize(const char * file) {
	logger::logFileMode = true;
	logger::logFile.open(file, ofstream::out | ofstream::app);
    }

    void Terminate() {
	logger::logFileMode = false;
	logger::logFile.close();
    }

    void EchoOn() {
	logger::echo = true;
    }
    
    void EchoOff() {
	logger::echo = false;
    }

    void setLogLevel(int x) {
	if (x>8 || x<1) 
	    return;
	logger::logLevel = x;
    }

    void setLogName(string x) {
	logger::logname = x;
    }

    string getLogName() {
        return logger::logname;
    }

    int getLogLevel() {
        return logger::logLevel;
    }

    void setSimTime(float x) {
	simTime = x;
    }

    void setEv(cEnvir * x) {
	ev = x;
    }

    bool willPrint(int x) {
	if (curLogEntry <= logLevel) {
	    return true;
	} else {
	    return false;
	}
    }

    void setLogMode(string x) {
	if (x=="short") {
	    logger::logmode = LOGMODE_SHORT;
	}
	if (x=="full") {
	    logger::logmode = LOGMODE_FULL;
	}
	if (x=="precise") {
	    logger::logmode = LOGMODE_PRECISE;
	}

#ifdef LINUX
	if (x=="syslog") {
	    logger::logmode = LOGMODE_SYSLOG;
	}
#endif 
#ifdef WIN32
	if (x=="eventlog") {
	    logger::logmode = LOGMODE_EVENTLOG;
	}
#endif
    }
}


