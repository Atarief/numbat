//
// Generated file, do not edit! Created by opp_msgc 4.1 from ipv6/ipv6msg.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "ipv6msg_m.h"

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




Register_Class(IPv6Packet);

IPv6Packet::IPv6Packet(const char *name, int kind) : cPacket(name,kind)
{
    this->BindingUpdate_var = 0;
    this->BindingAck_var = 0;
    this->Dhcpv6Relay_var = 0;
}

IPv6Packet::IPv6Packet(const IPv6Packet& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

IPv6Packet::~IPv6Packet()
{
}

IPv6Packet& IPv6Packet::operator=(const IPv6Packet& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->srcIP_var = other.srcIP_var;
    this->dstIP_var = other.dstIP_var;
    this->BindingUpdate_var = other.BindingUpdate_var;
    this->BindingAck_var = other.BindingAck_var;
    this->Dhcpv6Relay_var = other.Dhcpv6Relay_var;
    return *this;
}

void IPv6Packet::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->srcIP_var);
    doPacking(b,this->dstIP_var);
    doPacking(b,this->BindingUpdate_var);
    doPacking(b,this->BindingAck_var);
    doPacking(b,this->Dhcpv6Relay_var);
}

void IPv6Packet::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->srcIP_var);
    doUnpacking(b,this->dstIP_var);
    doUnpacking(b,this->BindingUpdate_var);
    doUnpacking(b,this->BindingAck_var);
    doUnpacking(b,this->Dhcpv6Relay_var);
}

IPv6Addr& IPv6Packet::getSrcIP()
{
    return srcIP_var;
}

void IPv6Packet::setSrcIP(const IPv6Addr& srcIP_var)
{
    this->srcIP_var = srcIP_var;
}

IPv6Addr& IPv6Packet::getDstIP()
{
    return dstIP_var;
}

void IPv6Packet::setDstIP(const IPv6Addr& dstIP_var)
{
    this->dstIP_var = dstIP_var;
}

bool IPv6Packet::getBindingUpdate() const
{
    return BindingUpdate_var;
}

void IPv6Packet::setBindingUpdate(bool BindingUpdate_var)
{
    this->BindingUpdate_var = BindingUpdate_var;
}

bool IPv6Packet::getBindingAck() const
{
    return BindingAck_var;
}

void IPv6Packet::setBindingAck(bool BindingAck_var)
{
    this->BindingAck_var = BindingAck_var;
}

bool IPv6Packet::getDhcpv6Relay() const
{
    return Dhcpv6Relay_var;
}

void IPv6Packet::setDhcpv6Relay(bool Dhcpv6Relay_var)
{
    this->Dhcpv6Relay_var = Dhcpv6Relay_var;
}

class IPv6PacketDescriptor : public cClassDescriptor
{
  public:
    IPv6PacketDescriptor();
    virtual ~IPv6PacketDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(IPv6PacketDescriptor);

IPv6PacketDescriptor::IPv6PacketDescriptor() : cClassDescriptor("IPv6Packet", "cPacket")
{
}

IPv6PacketDescriptor::~IPv6PacketDescriptor()
{
}

bool IPv6PacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<IPv6Packet *>(obj)!=NULL;
}

const char *IPv6PacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int IPv6PacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int IPv6PacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *IPv6PacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "srcIP",
        "dstIP",
        "BindingUpdate",
        "BindingAck",
        "Dhcpv6Relay",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int IPv6PacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcIP")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dstIP")==0) return base+1;
    if (fieldName[0]=='B' && strcmp(fieldName, "BindingUpdate")==0) return base+2;
    if (fieldName[0]=='B' && strcmp(fieldName, "BindingAck")==0) return base+3;
    if (fieldName[0]=='D' && strcmp(fieldName, "Dhcpv6Relay")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *IPv6PacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "IPv6Addr",
        "IPv6Addr",
        "bool",
        "bool",
        "bool",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *IPv6PacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int IPv6PacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    IPv6Packet *pp = (IPv6Packet *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string IPv6PacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    IPv6Packet *pp = (IPv6Packet *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getSrcIP(); return out.str();}
        case 1: {std::stringstream out; out << pp->getDstIP(); return out.str();}
        case 2: return bool2string(pp->getBindingUpdate());
        case 3: return bool2string(pp->getBindingAck());
        case 4: return bool2string(pp->getDhcpv6Relay());
        default: return "";
    }
}

bool IPv6PacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    IPv6Packet *pp = (IPv6Packet *)object; (void)pp;
    switch (field) {
        case 2: pp->setBindingUpdate(string2bool(value)); return true;
        case 3: pp->setBindingAck(string2bool(value)); return true;
        case 4: pp->setDhcpv6Relay(string2bool(value)); return true;
        default: return false;
    }
}

const char *IPv6PacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "IPv6Addr",
        "IPv6Addr",
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<5) ? fieldStructNames[field] : NULL;
}

void *IPv6PacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    IPv6Packet *pp = (IPv6Packet *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getSrcIP()); break;
        case 1: return (void *)(&pp->getDstIP()); break;
        default: return NULL;
    }
}

Register_Class(IPv6Ra);

IPv6Ra::IPv6Ra(const char *name, int kind) : IPv6Packet(name,kind)
{
}

IPv6Ra::IPv6Ra(const IPv6Ra& other) : IPv6Packet()
{
    setName(other.getName());
    operator=(other);
}

IPv6Ra::~IPv6Ra()
{
}

IPv6Ra& IPv6Ra::operator=(const IPv6Ra& other)
{
    if (this==&other) return *this;
    IPv6Packet::operator=(other);
    return *this;
}

void IPv6Ra::parsimPack(cCommBuffer *b)
{
    IPv6Packet::parsimPack(b);
}

void IPv6Ra::parsimUnpack(cCommBuffer *b)
{
    IPv6Packet::parsimUnpack(b);
}

class IPv6RaDescriptor : public cClassDescriptor
{
  public:
    IPv6RaDescriptor();
    virtual ~IPv6RaDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(IPv6RaDescriptor);

IPv6RaDescriptor::IPv6RaDescriptor() : cClassDescriptor("IPv6Ra", "IPv6Packet")
{
}

IPv6RaDescriptor::~IPv6RaDescriptor()
{
}

bool IPv6RaDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<IPv6Ra *>(obj)!=NULL;
}

const char *IPv6RaDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int IPv6RaDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int IPv6RaDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *IPv6RaDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int IPv6RaDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *IPv6RaDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *IPv6RaDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int IPv6RaDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    IPv6Ra *pp = (IPv6Ra *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string IPv6RaDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    IPv6Ra *pp = (IPv6Ra *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool IPv6RaDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    IPv6Ra *pp = (IPv6Ra *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *IPv6RaDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *IPv6RaDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    IPv6Ra *pp = (IPv6Ra *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(DHCPv6Solicit);

DHCPv6Solicit::DHCPv6Solicit(const char *name, int kind) : IPv6Packet(name,kind)
{
    this->rapidCommit_var = 0;
    this->addrParams_var = 0;
    this->remoteConf_var = 0;
    this->remoteBS_var = 0;
}

DHCPv6Solicit::DHCPv6Solicit(const DHCPv6Solicit& other) : IPv6Packet()
{
    setName(other.getName());
    operator=(other);
}

DHCPv6Solicit::~DHCPv6Solicit()
{
}

DHCPv6Solicit& DHCPv6Solicit::operator=(const DHCPv6Solicit& other)
{
    if (this==&other) return *this;
    IPv6Packet::operator=(other);
    this->rapidCommit_var = other.rapidCommit_var;
    this->addrParams_var = other.addrParams_var;
    this->remoteConf_var = other.remoteConf_var;
    this->remoteBS_var = other.remoteBS_var;
    return *this;
}

void DHCPv6Solicit::parsimPack(cCommBuffer *b)
{
    IPv6Packet::parsimPack(b);
    doPacking(b,this->rapidCommit_var);
    doPacking(b,this->addrParams_var);
    doPacking(b,this->remoteConf_var);
    doPacking(b,this->remoteBS_var);
}

void DHCPv6Solicit::parsimUnpack(cCommBuffer *b)
{
    IPv6Packet::parsimUnpack(b);
    doUnpacking(b,this->rapidCommit_var);
    doUnpacking(b,this->addrParams_var);
    doUnpacking(b,this->remoteConf_var);
    doUnpacking(b,this->remoteBS_var);
}

bool DHCPv6Solicit::getRapidCommit() const
{
    return rapidCommit_var;
}

void DHCPv6Solicit::setRapidCommit(bool rapidCommit_var)
{
    this->rapidCommit_var = rapidCommit_var;
}

bool DHCPv6Solicit::getAddrParams() const
{
    return addrParams_var;
}

void DHCPv6Solicit::setAddrParams(bool addrParams_var)
{
    this->addrParams_var = addrParams_var;
}

bool DHCPv6Solicit::getRemoteConf() const
{
    return remoteConf_var;
}

void DHCPv6Solicit::setRemoteConf(bool remoteConf_var)
{
    this->remoteConf_var = remoteConf_var;
}

int DHCPv6Solicit::getRemoteBS() const
{
    return remoteBS_var;
}

void DHCPv6Solicit::setRemoteBS(int remoteBS_var)
{
    this->remoteBS_var = remoteBS_var;
}

class DHCPv6SolicitDescriptor : public cClassDescriptor
{
  public:
    DHCPv6SolicitDescriptor();
    virtual ~DHCPv6SolicitDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(DHCPv6SolicitDescriptor);

DHCPv6SolicitDescriptor::DHCPv6SolicitDescriptor() : cClassDescriptor("DHCPv6Solicit", "IPv6Packet")
{
}

DHCPv6SolicitDescriptor::~DHCPv6SolicitDescriptor()
{
}

bool DHCPv6SolicitDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<DHCPv6Solicit *>(obj)!=NULL;
}

const char *DHCPv6SolicitDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int DHCPv6SolicitDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int DHCPv6SolicitDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *DHCPv6SolicitDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "rapidCommit",
        "addrParams",
        "remoteConf",
        "remoteBS",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int DHCPv6SolicitDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "rapidCommit")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "addrParams")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "remoteConf")==0) return base+2;
    if (fieldName[0]=='r' && strcmp(fieldName, "remoteBS")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *DHCPv6SolicitDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "bool",
        "int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *DHCPv6SolicitDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int DHCPv6SolicitDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    DHCPv6Solicit *pp = (DHCPv6Solicit *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string DHCPv6SolicitDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    DHCPv6Solicit *pp = (DHCPv6Solicit *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getRapidCommit());
        case 1: return bool2string(pp->getAddrParams());
        case 2: return bool2string(pp->getRemoteConf());
        case 3: return long2string(pp->getRemoteBS());
        default: return "";
    }
}

bool DHCPv6SolicitDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    DHCPv6Solicit *pp = (DHCPv6Solicit *)object; (void)pp;
    switch (field) {
        case 0: pp->setRapidCommit(string2bool(value)); return true;
        case 1: pp->setAddrParams(string2bool(value)); return true;
        case 2: pp->setRemoteConf(string2bool(value)); return true;
        case 3: pp->setRemoteBS(string2long(value)); return true;
        default: return false;
    }
}

const char *DHCPv6SolicitDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<4) ? fieldStructNames[field] : NULL;
}

void *DHCPv6SolicitDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    DHCPv6Solicit *pp = (DHCPv6Solicit *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(DHCPv6Advertise);

DHCPv6Advertise::DHCPv6Advertise(const char *name, int kind) : IPv6Packet(name,kind)
{
    this->preference_var = 0;
    this->addrParams_var = 0;
    this->remoteConf_var = 0;
}

DHCPv6Advertise::DHCPv6Advertise(const DHCPv6Advertise& other) : IPv6Packet()
{
    setName(other.getName());
    operator=(other);
}

DHCPv6Advertise::~DHCPv6Advertise()
{
}

DHCPv6Advertise& DHCPv6Advertise::operator=(const DHCPv6Advertise& other)
{
    if (this==&other) return *this;
    IPv6Packet::operator=(other);
    this->preference_var = other.preference_var;
    this->addrParams_var = other.addrParams_var;
    this->remoteConf_var = other.remoteConf_var;
    return *this;
}

void DHCPv6Advertise::parsimPack(cCommBuffer *b)
{
    IPv6Packet::parsimPack(b);
    doPacking(b,this->preference_var);
    doPacking(b,this->addrParams_var);
    doPacking(b,this->remoteConf_var);
}

void DHCPv6Advertise::parsimUnpack(cCommBuffer *b)
{
    IPv6Packet::parsimUnpack(b);
    doUnpacking(b,this->preference_var);
    doUnpacking(b,this->addrParams_var);
    doUnpacking(b,this->remoteConf_var);
}

int DHCPv6Advertise::getPreference() const
{
    return preference_var;
}

void DHCPv6Advertise::setPreference(int preference_var)
{
    this->preference_var = preference_var;
}

bool DHCPv6Advertise::getAddrParams() const
{
    return addrParams_var;
}

void DHCPv6Advertise::setAddrParams(bool addrParams_var)
{
    this->addrParams_var = addrParams_var;
}

bool DHCPv6Advertise::getRemoteConf() const
{
    return remoteConf_var;
}

void DHCPv6Advertise::setRemoteConf(bool remoteConf_var)
{
    this->remoteConf_var = remoteConf_var;
}

class DHCPv6AdvertiseDescriptor : public cClassDescriptor
{
  public:
    DHCPv6AdvertiseDescriptor();
    virtual ~DHCPv6AdvertiseDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(DHCPv6AdvertiseDescriptor);

DHCPv6AdvertiseDescriptor::DHCPv6AdvertiseDescriptor() : cClassDescriptor("DHCPv6Advertise", "IPv6Packet")
{
}

DHCPv6AdvertiseDescriptor::~DHCPv6AdvertiseDescriptor()
{
}

bool DHCPv6AdvertiseDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<DHCPv6Advertise *>(obj)!=NULL;
}

const char *DHCPv6AdvertiseDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int DHCPv6AdvertiseDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int DHCPv6AdvertiseDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *DHCPv6AdvertiseDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "preference",
        "addrParams",
        "remoteConf",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int DHCPv6AdvertiseDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "preference")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "addrParams")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "remoteConf")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *DHCPv6AdvertiseDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "bool",
        "bool",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *DHCPv6AdvertiseDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int DHCPv6AdvertiseDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    DHCPv6Advertise *pp = (DHCPv6Advertise *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string DHCPv6AdvertiseDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    DHCPv6Advertise *pp = (DHCPv6Advertise *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getPreference());
        case 1: return bool2string(pp->getAddrParams());
        case 2: return bool2string(pp->getRemoteConf());
        default: return "";
    }
}

bool DHCPv6AdvertiseDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    DHCPv6Advertise *pp = (DHCPv6Advertise *)object; (void)pp;
    switch (field) {
        case 0: pp->setPreference(string2long(value)); return true;
        case 1: pp->setAddrParams(string2bool(value)); return true;
        case 2: pp->setRemoteConf(string2bool(value)); return true;
        default: return false;
    }
}

const char *DHCPv6AdvertiseDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *DHCPv6AdvertiseDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    DHCPv6Advertise *pp = (DHCPv6Advertise *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(DHCPv6Request);

DHCPv6Request::DHCPv6Request(const char *name, int kind) : IPv6Packet(name,kind)
{
    this->addrParams_var = 0;
    this->remoteConf_var = 0;
    this->remoteBS_var = 0;
}

DHCPv6Request::DHCPv6Request(const DHCPv6Request& other) : IPv6Packet()
{
    setName(other.getName());
    operator=(other);
}

DHCPv6Request::~DHCPv6Request()
{
}

DHCPv6Request& DHCPv6Request::operator=(const DHCPv6Request& other)
{
    if (this==&other) return *this;
    IPv6Packet::operator=(other);
    this->addrParams_var = other.addrParams_var;
    this->remoteConf_var = other.remoteConf_var;
    this->remoteBS_var = other.remoteBS_var;
    return *this;
}

void DHCPv6Request::parsimPack(cCommBuffer *b)
{
    IPv6Packet::parsimPack(b);
    doPacking(b,this->addrParams_var);
    doPacking(b,this->remoteConf_var);
    doPacking(b,this->remoteBS_var);
}

void DHCPv6Request::parsimUnpack(cCommBuffer *b)
{
    IPv6Packet::parsimUnpack(b);
    doUnpacking(b,this->addrParams_var);
    doUnpacking(b,this->remoteConf_var);
    doUnpacking(b,this->remoteBS_var);
}

bool DHCPv6Request::getAddrParams() const
{
    return addrParams_var;
}

void DHCPv6Request::setAddrParams(bool addrParams_var)
{
    this->addrParams_var = addrParams_var;
}

bool DHCPv6Request::getRemoteConf() const
{
    return remoteConf_var;
}

void DHCPv6Request::setRemoteConf(bool remoteConf_var)
{
    this->remoteConf_var = remoteConf_var;
}

int DHCPv6Request::getRemoteBS() const
{
    return remoteBS_var;
}

void DHCPv6Request::setRemoteBS(int remoteBS_var)
{
    this->remoteBS_var = remoteBS_var;
}

class DHCPv6RequestDescriptor : public cClassDescriptor
{
  public:
    DHCPv6RequestDescriptor();
    virtual ~DHCPv6RequestDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(DHCPv6RequestDescriptor);

DHCPv6RequestDescriptor::DHCPv6RequestDescriptor() : cClassDescriptor("DHCPv6Request", "IPv6Packet")
{
}

DHCPv6RequestDescriptor::~DHCPv6RequestDescriptor()
{
}

bool DHCPv6RequestDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<DHCPv6Request *>(obj)!=NULL;
}

const char *DHCPv6RequestDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int DHCPv6RequestDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int DHCPv6RequestDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *DHCPv6RequestDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "addrParams",
        "remoteConf",
        "remoteBS",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int DHCPv6RequestDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "addrParams")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "remoteConf")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "remoteBS")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *DHCPv6RequestDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *DHCPv6RequestDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int DHCPv6RequestDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    DHCPv6Request *pp = (DHCPv6Request *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string DHCPv6RequestDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    DHCPv6Request *pp = (DHCPv6Request *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getAddrParams());
        case 1: return bool2string(pp->getRemoteConf());
        case 2: return long2string(pp->getRemoteBS());
        default: return "";
    }
}

bool DHCPv6RequestDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    DHCPv6Request *pp = (DHCPv6Request *)object; (void)pp;
    switch (field) {
        case 0: pp->setAddrParams(string2bool(value)); return true;
        case 1: pp->setRemoteConf(string2bool(value)); return true;
        case 2: pp->setRemoteBS(string2long(value)); return true;
        default: return false;
    }
}

const char *DHCPv6RequestDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *DHCPv6RequestDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    DHCPv6Request *pp = (DHCPv6Request *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(DHCPv6Reply);

DHCPv6Reply::DHCPv6Reply(const char *name, int kind) : IPv6Packet(name,kind)
{
    this->addrParams_var = 0;
    this->remoteConf_var = 0;
}

DHCPv6Reply::DHCPv6Reply(const DHCPv6Reply& other) : IPv6Packet()
{
    setName(other.getName());
    operator=(other);
}

DHCPv6Reply::~DHCPv6Reply()
{
}

DHCPv6Reply& DHCPv6Reply::operator=(const DHCPv6Reply& other)
{
    if (this==&other) return *this;
    IPv6Packet::operator=(other);
    this->addr_var = other.addr_var;
    this->addrParams_var = other.addrParams_var;
    this->remoteConf_var = other.remoteConf_var;
    return *this;
}

void DHCPv6Reply::parsimPack(cCommBuffer *b)
{
    IPv6Packet::parsimPack(b);
    doPacking(b,this->addr_var);
    doPacking(b,this->addrParams_var);
    doPacking(b,this->remoteConf_var);
}

void DHCPv6Reply::parsimUnpack(cCommBuffer *b)
{
    IPv6Packet::parsimUnpack(b);
    doUnpacking(b,this->addr_var);
    doUnpacking(b,this->addrParams_var);
    doUnpacking(b,this->remoteConf_var);
}

IPv6Addr& DHCPv6Reply::getAddr()
{
    return addr_var;
}

void DHCPv6Reply::setAddr(const IPv6Addr& addr_var)
{
    this->addr_var = addr_var;
}

bool DHCPv6Reply::getAddrParams() const
{
    return addrParams_var;
}

void DHCPv6Reply::setAddrParams(bool addrParams_var)
{
    this->addrParams_var = addrParams_var;
}

bool DHCPv6Reply::getRemoteConf() const
{
    return remoteConf_var;
}

void DHCPv6Reply::setRemoteConf(bool remoteConf_var)
{
    this->remoteConf_var = remoteConf_var;
}

class DHCPv6ReplyDescriptor : public cClassDescriptor
{
  public:
    DHCPv6ReplyDescriptor();
    virtual ~DHCPv6ReplyDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(DHCPv6ReplyDescriptor);

DHCPv6ReplyDescriptor::DHCPv6ReplyDescriptor() : cClassDescriptor("DHCPv6Reply", "IPv6Packet")
{
}

DHCPv6ReplyDescriptor::~DHCPv6ReplyDescriptor()
{
}

bool DHCPv6ReplyDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<DHCPv6Reply *>(obj)!=NULL;
}

const char *DHCPv6ReplyDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int DHCPv6ReplyDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int DHCPv6ReplyDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *DHCPv6ReplyDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "addr",
        "addrParams",
        "remoteConf",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int DHCPv6ReplyDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "addr")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "addrParams")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "remoteConf")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *DHCPv6ReplyDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "IPv6Addr",
        "bool",
        "bool",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *DHCPv6ReplyDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int DHCPv6ReplyDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    DHCPv6Reply *pp = (DHCPv6Reply *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string DHCPv6ReplyDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    DHCPv6Reply *pp = (DHCPv6Reply *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getAddr(); return out.str();}
        case 1: return bool2string(pp->getAddrParams());
        case 2: return bool2string(pp->getRemoteConf());
        default: return "";
    }
}

bool DHCPv6ReplyDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    DHCPv6Reply *pp = (DHCPv6Reply *)object; (void)pp;
    switch (field) {
        case 1: pp->setAddrParams(string2bool(value)); return true;
        case 2: pp->setRemoteConf(string2bool(value)); return true;
        default: return false;
    }
}

const char *DHCPv6ReplyDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "IPv6Addr",
        NULL,
        NULL,
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *DHCPv6ReplyDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    DHCPv6Reply *pp = (DHCPv6Reply *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getAddr()); break;
        default: return NULL;
    }
}

Register_Class(DHCPv6Confirm);

DHCPv6Confirm::DHCPv6Confirm(const char *name, int kind) : IPv6Packet(name,kind)
{
    this->addrParams_var = 0;
    this->remoteConf_var = 0;
    this->remoteBS_var = 0;
}

DHCPv6Confirm::DHCPv6Confirm(const DHCPv6Confirm& other) : IPv6Packet()
{
    setName(other.getName());
    operator=(other);
}

DHCPv6Confirm::~DHCPv6Confirm()
{
}

DHCPv6Confirm& DHCPv6Confirm::operator=(const DHCPv6Confirm& other)
{
    if (this==&other) return *this;
    IPv6Packet::operator=(other);
    this->addrParams_var = other.addrParams_var;
    this->remoteConf_var = other.remoteConf_var;
    this->remoteBS_var = other.remoteBS_var;
    return *this;
}

void DHCPv6Confirm::parsimPack(cCommBuffer *b)
{
    IPv6Packet::parsimPack(b);
    doPacking(b,this->addrParams_var);
    doPacking(b,this->remoteConf_var);
    doPacking(b,this->remoteBS_var);
}

void DHCPv6Confirm::parsimUnpack(cCommBuffer *b)
{
    IPv6Packet::parsimUnpack(b);
    doUnpacking(b,this->addrParams_var);
    doUnpacking(b,this->remoteConf_var);
    doUnpacking(b,this->remoteBS_var);
}

bool DHCPv6Confirm::getAddrParams() const
{
    return addrParams_var;
}

void DHCPv6Confirm::setAddrParams(bool addrParams_var)
{
    this->addrParams_var = addrParams_var;
}

bool DHCPv6Confirm::getRemoteConf() const
{
    return remoteConf_var;
}

void DHCPv6Confirm::setRemoteConf(bool remoteConf_var)
{
    this->remoteConf_var = remoteConf_var;
}

int DHCPv6Confirm::getRemoteBS() const
{
    return remoteBS_var;
}

void DHCPv6Confirm::setRemoteBS(int remoteBS_var)
{
    this->remoteBS_var = remoteBS_var;
}

class DHCPv6ConfirmDescriptor : public cClassDescriptor
{
  public:
    DHCPv6ConfirmDescriptor();
    virtual ~DHCPv6ConfirmDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(DHCPv6ConfirmDescriptor);

DHCPv6ConfirmDescriptor::DHCPv6ConfirmDescriptor() : cClassDescriptor("DHCPv6Confirm", "IPv6Packet")
{
}

DHCPv6ConfirmDescriptor::~DHCPv6ConfirmDescriptor()
{
}

bool DHCPv6ConfirmDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<DHCPv6Confirm *>(obj)!=NULL;
}

const char *DHCPv6ConfirmDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int DHCPv6ConfirmDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int DHCPv6ConfirmDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *DHCPv6ConfirmDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "addrParams",
        "remoteConf",
        "remoteBS",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int DHCPv6ConfirmDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "addrParams")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "remoteConf")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "remoteBS")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *DHCPv6ConfirmDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *DHCPv6ConfirmDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int DHCPv6ConfirmDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    DHCPv6Confirm *pp = (DHCPv6Confirm *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string DHCPv6ConfirmDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    DHCPv6Confirm *pp = (DHCPv6Confirm *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getAddrParams());
        case 1: return bool2string(pp->getRemoteConf());
        case 2: return long2string(pp->getRemoteBS());
        default: return "";
    }
}

bool DHCPv6ConfirmDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    DHCPv6Confirm *pp = (DHCPv6Confirm *)object; (void)pp;
    switch (field) {
        case 0: pp->setAddrParams(string2bool(value)); return true;
        case 1: pp->setRemoteConf(string2bool(value)); return true;
        case 2: pp->setRemoteBS(string2long(value)); return true;
        default: return false;
    }
}

const char *DHCPv6ConfirmDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *DHCPv6ConfirmDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    DHCPv6Confirm *pp = (DHCPv6Confirm *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


