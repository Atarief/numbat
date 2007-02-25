/**
 * @file   wmaxmac.h
 * @author Tomasz Mrugalski <thomson@klub.com.pl>
 * @date   2006-12-29 01:50:38+0100
 * 
 * @brief  Generic Finite State Machine implementation
 * @licence GNU GPLv2 or later
 * 
 */

#include <vector>

#ifndef FSM_H
#define FSM_H

#include <omnetpp.h>

#define TIMER(name, time, descr)                              \
    Timer##name##Value = time;			              \
    Timer##name        = new cMessage(descr);

#define TIMER_START(name)                                     \
    scheduleAt(simTime() + Timer##name##Value, Timer##name);

#define TIMER_STOP(name)                                      \
    if (Timer##name ->isScheduled())                          \
        cancelEvent(Timer##name);

#define TIMER_DEF(name)    \
    double Timer##name##Value; \
    cMessage* Timer##name;

#define IF_TIMER(name, event)                                  \
    if (msg==Timer##name)                                      \
       onEvent(event, msg);

#define CASE_IGNORE(e)                                                 \
	std::cout << fsm->fullName() << ": event "                     \
		  << fsm->Events[e].fullName() << " ignored in state " \
 	<< fsm->CurrentStateGet()->fullName() << endl; \
        return fsm->State();

#define FSM_MAX_TRANSITIONS 64

typedef int FsmStateType;
typedef int FsmEventType;

class Fsm;
class FsmEvent;
class FsmState;

typedef FsmStateType onEventFunc(Fsm *fsm, FsmEventType e, cMessage *msg);
typedef FsmStateType onEnterFunc(Fsm *fsm);
typedef FsmStateType onExitFunc (Fsm *fsm);


class FsmEvent
{
public:
    std::string fullName();
    FsmEventType type;
    std::string name;
    bool inited;
};


class FsmState
{
public:
    bool inited;
    FsmStateType type;
    std::string name;
    onEventFunc *onEvent;
    onEnterFunc *onEnter;
    onExitFunc  *onExit;
    std::string fullName();
    bool transitive;
    FsmStateType transitiveTo;
};

class Fsm : public cSimpleModule {
public:
    FsmStateType State() { return CurrentState; }
    FsmState * CurrentStateGet() { return &States[CurrentState]; }
    std::vector<FsmState> States;
    std::vector<FsmEvent> Events;

protected:
    virtual void fsmInit() = 0;
    bool stateVerify();
    bool eventVerify();
    void statesEventsInit(int statesCnt, int eventsCnt, FsmStateType s);
    virtual void onEvent(FsmEventType e, cMessage *msg);
    virtual void stateInit(FsmStateType type, std::string name, onEventFunc func); // stationary state
    virtual void stateInit(FsmStateType type, std::string name, onEventFunc onEvent, onEnterFunc onEnter, onExitFunc onExit); // stationary state
    virtual void stateInit(FsmStateType type, std::string name, int targetState, onEnterFunc onEnter); // transitive state
    void eventInit(FsmEventType type, std::string name);
    void stateSet(FsmStateType state);
    void stringUpdate();

    int StatesCnt;
    int EventsCnt;

    FsmStateType CurrentState;
};

#endif

