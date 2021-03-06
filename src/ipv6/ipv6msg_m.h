//
// Generated file, do not edit! Created by opp_msgc 4.1 from ipv6/ipv6msg.msg.
//

#ifndef _IPV6MSG_M_H_
#define _IPV6MSG_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0401
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif

// cplusplus {{
#include "IPv6Addr.h"
// }}



/**
 * Class generated from <tt>ipv6/ipv6msg.msg</tt> by opp_msgc.
 * <pre>
 * packet IPv6Packet
 * {
 *     IPv6Addr srcIP;
 *     IPv6Addr dstIP;
 * 
 *     bool BindingUpdate;
 *     bool BindingAck;
 *     bool Dhcpv6Relay;
 * }
 * </pre>
 */
class IPv6Packet : public ::cPacket
{
  protected:
    ::IPv6Addr srcIP_var;
    ::IPv6Addr dstIP_var;
    bool BindingUpdate_var;
    bool BindingAck_var;
    bool Dhcpv6Relay_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const IPv6Packet&);

  public:
    IPv6Packet(const char *name=NULL, int kind=0);
    IPv6Packet(const IPv6Packet& other);
    virtual ~IPv6Packet();
    IPv6Packet& operator=(const IPv6Packet& other);
    virtual IPv6Packet *dup() const {return new IPv6Packet(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual IPv6Addr& getSrcIP();
    virtual const IPv6Addr& getSrcIP() const {return const_cast<IPv6Packet*>(this)->getSrcIP();}
    virtual void setSrcIP(const IPv6Addr& srcIP_var);
    virtual IPv6Addr& getDstIP();
    virtual const IPv6Addr& getDstIP() const {return const_cast<IPv6Packet*>(this)->getDstIP();}
    virtual void setDstIP(const IPv6Addr& dstIP_var);
    virtual bool getBindingUpdate() const;
    virtual void setBindingUpdate(bool BindingUpdate_var);
    virtual bool getBindingAck() const;
    virtual void setBindingAck(bool BindingAck_var);
    virtual bool getDhcpv6Relay() const;
    virtual void setDhcpv6Relay(bool Dhcpv6Relay_var);
};

inline void doPacking(cCommBuffer *b, IPv6Packet& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, IPv6Packet& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>ipv6/ipv6msg.msg</tt> by opp_msgc.
 * <pre>
 * packet IPv6Ra extends IPv6Packet
 * {
 * }
 * </pre>
 */
class IPv6Ra : public ::IPv6Packet
{
  protected:

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const IPv6Ra&);

  public:
    IPv6Ra(const char *name=NULL, int kind=0);
    IPv6Ra(const IPv6Ra& other);
    virtual ~IPv6Ra();
    IPv6Ra& operator=(const IPv6Ra& other);
    virtual IPv6Ra *dup() const {return new IPv6Ra(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
};

inline void doPacking(cCommBuffer *b, IPv6Ra& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, IPv6Ra& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>ipv6/ipv6msg.msg</tt> by opp_msgc.
 * <pre>
 * packet DHCPv6Solicit extends IPv6Packet
 * {
 *     bool rapidCommit;
 *     bool addrParams;
 * 
 *     bool remoteConf;
 *     int remoteBS;
 * }
 * </pre>
 */
class DHCPv6Solicit : public ::IPv6Packet
{
  protected:
    bool rapidCommit_var;
    bool addrParams_var;
    bool remoteConf_var;
    int remoteBS_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const DHCPv6Solicit&);

  public:
    DHCPv6Solicit(const char *name=NULL, int kind=0);
    DHCPv6Solicit(const DHCPv6Solicit& other);
    virtual ~DHCPv6Solicit();
    DHCPv6Solicit& operator=(const DHCPv6Solicit& other);
    virtual DHCPv6Solicit *dup() const {return new DHCPv6Solicit(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual bool getRapidCommit() const;
    virtual void setRapidCommit(bool rapidCommit_var);
    virtual bool getAddrParams() const;
    virtual void setAddrParams(bool addrParams_var);
    virtual bool getRemoteConf() const;
    virtual void setRemoteConf(bool remoteConf_var);
    virtual int getRemoteBS() const;
    virtual void setRemoteBS(int remoteBS_var);
};

inline void doPacking(cCommBuffer *b, DHCPv6Solicit& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, DHCPv6Solicit& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>ipv6/ipv6msg.msg</tt> by opp_msgc.
 * <pre>
 * packet DHCPv6Advertise extends IPv6Packet
 * {
 *     int preference;
 *     bool addrParams;
 * 
 *     bool remoteConf;
 * }
 * </pre>
 */
class DHCPv6Advertise : public ::IPv6Packet
{
  protected:
    int preference_var;
    bool addrParams_var;
    bool remoteConf_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const DHCPv6Advertise&);

  public:
    DHCPv6Advertise(const char *name=NULL, int kind=0);
    DHCPv6Advertise(const DHCPv6Advertise& other);
    virtual ~DHCPv6Advertise();
    DHCPv6Advertise& operator=(const DHCPv6Advertise& other);
    virtual DHCPv6Advertise *dup() const {return new DHCPv6Advertise(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getPreference() const;
    virtual void setPreference(int preference_var);
    virtual bool getAddrParams() const;
    virtual void setAddrParams(bool addrParams_var);
    virtual bool getRemoteConf() const;
    virtual void setRemoteConf(bool remoteConf_var);
};

inline void doPacking(cCommBuffer *b, DHCPv6Advertise& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, DHCPv6Advertise& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>ipv6/ipv6msg.msg</tt> by opp_msgc.
 * <pre>
 * packet DHCPv6Request extends IPv6Packet
 * {
 *     bool addrParams;
 * 
 *     bool remoteConf;
 *     int remoteBS;
 * }
 * </pre>
 */
class DHCPv6Request : public ::IPv6Packet
{
  protected:
    bool addrParams_var;
    bool remoteConf_var;
    int remoteBS_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const DHCPv6Request&);

  public:
    DHCPv6Request(const char *name=NULL, int kind=0);
    DHCPv6Request(const DHCPv6Request& other);
    virtual ~DHCPv6Request();
    DHCPv6Request& operator=(const DHCPv6Request& other);
    virtual DHCPv6Request *dup() const {return new DHCPv6Request(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual bool getAddrParams() const;
    virtual void setAddrParams(bool addrParams_var);
    virtual bool getRemoteConf() const;
    virtual void setRemoteConf(bool remoteConf_var);
    virtual int getRemoteBS() const;
    virtual void setRemoteBS(int remoteBS_var);
};

inline void doPacking(cCommBuffer *b, DHCPv6Request& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, DHCPv6Request& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>ipv6/ipv6msg.msg</tt> by opp_msgc.
 * <pre>
 * packet DHCPv6Reply extends IPv6Packet
 * {
 *     IPv6Addr addr;
 *     bool addrParams;
 *     bool remoteConf;
 * }
 * </pre>
 */
class DHCPv6Reply : public ::IPv6Packet
{
  protected:
    ::IPv6Addr addr_var;
    bool addrParams_var;
    bool remoteConf_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const DHCPv6Reply&);

  public:
    DHCPv6Reply(const char *name=NULL, int kind=0);
    DHCPv6Reply(const DHCPv6Reply& other);
    virtual ~DHCPv6Reply();
    DHCPv6Reply& operator=(const DHCPv6Reply& other);
    virtual DHCPv6Reply *dup() const {return new DHCPv6Reply(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual IPv6Addr& getAddr();
    virtual const IPv6Addr& getAddr() const {return const_cast<DHCPv6Reply*>(this)->getAddr();}
    virtual void setAddr(const IPv6Addr& addr_var);
    virtual bool getAddrParams() const;
    virtual void setAddrParams(bool addrParams_var);
    virtual bool getRemoteConf() const;
    virtual void setRemoteConf(bool remoteConf_var);
};

inline void doPacking(cCommBuffer *b, DHCPv6Reply& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, DHCPv6Reply& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>ipv6/ipv6msg.msg</tt> by opp_msgc.
 * <pre>
 * packet DHCPv6Confirm extends IPv6Packet
 * {
 *     bool addrParams;
 * 
 *     bool remoteConf;
 *     int remoteBS;
 * }
 * </pre>
 */
class DHCPv6Confirm : public ::IPv6Packet
{
  protected:
    bool addrParams_var;
    bool remoteConf_var;
    int remoteBS_var;

    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const DHCPv6Confirm&);

  public:
    DHCPv6Confirm(const char *name=NULL, int kind=0);
    DHCPv6Confirm(const DHCPv6Confirm& other);
    virtual ~DHCPv6Confirm();
    DHCPv6Confirm& operator=(const DHCPv6Confirm& other);
    virtual DHCPv6Confirm *dup() const {return new DHCPv6Confirm(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual bool getAddrParams() const;
    virtual void setAddrParams(bool addrParams_var);
    virtual bool getRemoteConf() const;
    virtual void setRemoteConf(bool remoteConf_var);
    virtual int getRemoteBS() const;
    virtual void setRemoteBS(int remoteBS_var);
};

inline void doPacking(cCommBuffer *b, DHCPv6Confirm& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, DHCPv6Confirm& obj) {obj.parsimUnpack(b);}


#endif // _IPV6MSG_M_H_
