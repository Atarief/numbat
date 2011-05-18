//
// Generated file, do not edit! Created by opp_msgc 4.1 from wimax/wmaxmsg.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "wmaxmsg_m.h"

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




WMaxMacHeader_Base::WMaxMacHeader_Base() : cObject()
{
}

WMaxMacHeader_Base::WMaxMacHeader_Base(const WMaxMacHeader_Base& other) : cObject()
{
    operator=(other);
}

WMaxMacHeader_Base::~WMaxMacHeader_Base()
{
}

WMaxMacHeader_Base& WMaxMacHeader_Base::operator=(const WMaxMacHeader_Base& other)
{
    if (this==&other) return *this;
    cObject::operator=(other);
    return *this;
}

void WMaxMacHeader_Base::parsimPack(cCommBuffer *b)
{
    // field cid is abstract -- please do packing in customized class
    // field ht is abstract -- please do packing in customized class
    // field bwr is abstract -- please do packing in customized class
}

void WMaxMacHeader_Base::parsimUnpack(cCommBuffer *b)
{
    // field cid is abstract -- please do unpacking in customized class
    // field ht is abstract -- please do unpacking in customized class
    // field bwr is abstract -- please do unpacking in customized class
}

class WMaxMacHeaderDescriptor : public cClassDescriptor
{
  public:
    WMaxMacHeaderDescriptor();
    virtual ~WMaxMacHeaderDescriptor();

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

Register_ClassDescriptor(WMaxMacHeaderDescriptor);

WMaxMacHeaderDescriptor::WMaxMacHeaderDescriptor() : cClassDescriptor("WMaxMacHeader", "cObject")
{
}

WMaxMacHeaderDescriptor::~WMaxMacHeaderDescriptor()
{
}

bool WMaxMacHeaderDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxMacHeader_Base *>(obj)!=NULL;
}

const char *WMaxMacHeaderDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxMacHeaderDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int WMaxMacHeaderDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *WMaxMacHeaderDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "cid",
        "ht",
        "bwr",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int WMaxMacHeaderDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "cid")==0) return base+0;
    if (fieldName[0]=='h' && strcmp(fieldName, "ht")==0) return base+1;
    if (fieldName[0]=='b' && strcmp(fieldName, "bwr")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxMacHeaderDescriptor::getFieldTypeString(void *object, int field) const
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
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *WMaxMacHeaderDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxMacHeaderDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMacHeader_Base *pp = (WMaxMacHeader_Base *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string WMaxMacHeaderDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMacHeader_Base *pp = (WMaxMacHeader_Base *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getCid());
        case 1: return bool2string(pp->getHt());
        case 2: return long2string(pp->getBwr());
        default: return "";
    }
}

bool WMaxMacHeaderDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMacHeader_Base *pp = (WMaxMacHeader_Base *)object; (void)pp;
    switch (field) {
        case 0: pp->setCid(string2long(value)); return true;
        case 1: pp->setHt(string2bool(value)); return true;
        case 2: pp->setBwr(string2long(value)); return true;
        default: return false;
    }
}

const char *WMaxMacHeaderDescriptor::getFieldStructName(void *object, int field) const
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

void *WMaxMacHeaderDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMacHeader_Base *pp = (WMaxMacHeader_Base *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(WMaxMsgDlMap);

WMaxMsgDlMap::WMaxMsgDlMap(const char *name, int kind) : cPacket(name,kind)
{
    IE_arraysize = 0;
    this->IE_var = 0;
}

WMaxMsgDlMap::WMaxMsgDlMap(const WMaxMsgDlMap& other) : cPacket()
{
    setName(other.getName());
    IE_arraysize = 0;
    this->IE_var = 0;
    operator=(other);
}

WMaxMsgDlMap::~WMaxMsgDlMap()
{
    delete [] IE_var;
}

WMaxMsgDlMap& WMaxMsgDlMap::operator=(const WMaxMsgDlMap& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    delete [] this->IE_var;
    this->IE_var = (other.IE_arraysize==0) ? NULL : new ::WMaxDlMapIE[other.IE_arraysize];
    IE_arraysize = other.IE_arraysize;
    for (unsigned int i=0; i<IE_arraysize; i++)
        this->IE_var[i] = other.IE_var[i];
    return *this;
}

void WMaxMsgDlMap::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    b->pack(IE_arraysize);
    doPacking(b,this->IE_var,IE_arraysize);
}

void WMaxMsgDlMap::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    delete [] this->IE_var;
    b->unpack(IE_arraysize);
    if (IE_arraysize==0) {
        this->IE_var = 0;
    } else {
        this->IE_var = new ::WMaxDlMapIE[IE_arraysize];
        doUnpacking(b,this->IE_var,IE_arraysize);
    }
}

void WMaxMsgDlMap::setIEArraySize(unsigned int size)
{
    ::WMaxDlMapIE *IE_var2 = (size==0) ? NULL : new ::WMaxDlMapIE[size];
    unsigned int sz = IE_arraysize < size ? IE_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        IE_var2[i] = this->IE_var[i];
    IE_arraysize = size;
    delete [] this->IE_var;
    this->IE_var = IE_var2;
}

unsigned int WMaxMsgDlMap::getIEArraySize() const
{
    return IE_arraysize;
}

WMaxDlMapIE& WMaxMsgDlMap::getIE(unsigned int k)
{
    if (k>=IE_arraysize) throw cRuntimeError("Array of size %d indexed by %d", IE_arraysize, k);
    return IE_var[k];
}

void WMaxMsgDlMap::setIE(unsigned int k, const WMaxDlMapIE& IE_var)
{
    if (k>=IE_arraysize) throw cRuntimeError("Array of size %d indexed by %d", IE_arraysize, k);
    this->IE_var[k]=IE_var;
}

class WMaxMsgDlMapDescriptor : public cClassDescriptor
{
  public:
    WMaxMsgDlMapDescriptor();
    virtual ~WMaxMsgDlMapDescriptor();

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

Register_ClassDescriptor(WMaxMsgDlMapDescriptor);

WMaxMsgDlMapDescriptor::WMaxMsgDlMapDescriptor() : cClassDescriptor("WMaxMsgDlMap", "cPacket")
{
}

WMaxMsgDlMapDescriptor::~WMaxMsgDlMapDescriptor()
{
}

bool WMaxMsgDlMapDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxMsgDlMap *>(obj)!=NULL;
}

const char *WMaxMsgDlMapDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxMsgDlMapDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int WMaxMsgDlMapDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *WMaxMsgDlMapDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "IE",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int WMaxMsgDlMapDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='I' && strcmp(fieldName, "IE")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxMsgDlMapDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "WMaxDlMapIE",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *WMaxMsgDlMapDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxMsgDlMapDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgDlMap *pp = (WMaxMsgDlMap *)object; (void)pp;
    switch (field) {
        case 0: return pp->getIEArraySize();
        default: return 0;
    }
}

std::string WMaxMsgDlMapDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgDlMap *pp = (WMaxMsgDlMap *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getIE(i); return out.str();}
        default: return "";
    }
}

bool WMaxMsgDlMapDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgDlMap *pp = (WMaxMsgDlMap *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *WMaxMsgDlMapDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "WMaxDlMapIE",
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *WMaxMsgDlMapDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgDlMap *pp = (WMaxMsgDlMap *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getIE(i)); break;
        default: return NULL;
    }
}

Register_Class(WMaxMsgUlMap);

WMaxMsgUlMap::WMaxMsgUlMap(const char *name, int kind) : cPacket(name,kind)
{
    IE_arraysize = 0;
    this->IE_var = 0;
}

WMaxMsgUlMap::WMaxMsgUlMap(const WMaxMsgUlMap& other) : cPacket()
{
    setName(other.getName());
    IE_arraysize = 0;
    this->IE_var = 0;
    operator=(other);
}

WMaxMsgUlMap::~WMaxMsgUlMap()
{
    delete [] IE_var;
}

WMaxMsgUlMap& WMaxMsgUlMap::operator=(const WMaxMsgUlMap& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    delete [] this->IE_var;
    this->IE_var = (other.IE_arraysize==0) ? NULL : new ::WMaxUlMapIE[other.IE_arraysize];
    IE_arraysize = other.IE_arraysize;
    for (unsigned int i=0; i<IE_arraysize; i++)
        this->IE_var[i] = other.IE_var[i];
    return *this;
}

void WMaxMsgUlMap::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    b->pack(IE_arraysize);
    doPacking(b,this->IE_var,IE_arraysize);
}

void WMaxMsgUlMap::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    delete [] this->IE_var;
    b->unpack(IE_arraysize);
    if (IE_arraysize==0) {
        this->IE_var = 0;
    } else {
        this->IE_var = new ::WMaxUlMapIE[IE_arraysize];
        doUnpacking(b,this->IE_var,IE_arraysize);
    }
}

void WMaxMsgUlMap::setIEArraySize(unsigned int size)
{
    ::WMaxUlMapIE *IE_var2 = (size==0) ? NULL : new ::WMaxUlMapIE[size];
    unsigned int sz = IE_arraysize < size ? IE_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        IE_var2[i] = this->IE_var[i];
    IE_arraysize = size;
    delete [] this->IE_var;
    this->IE_var = IE_var2;
}

unsigned int WMaxMsgUlMap::getIEArraySize() const
{
    return IE_arraysize;
}

WMaxUlMapIE& WMaxMsgUlMap::getIE(unsigned int k)
{
    if (k>=IE_arraysize) throw cRuntimeError("Array of size %d indexed by %d", IE_arraysize, k);
    return IE_var[k];
}

void WMaxMsgUlMap::setIE(unsigned int k, const WMaxUlMapIE& IE_var)
{
    if (k>=IE_arraysize) throw cRuntimeError("Array of size %d indexed by %d", IE_arraysize, k);
    this->IE_var[k]=IE_var;
}

class WMaxMsgUlMapDescriptor : public cClassDescriptor
{
  public:
    WMaxMsgUlMapDescriptor();
    virtual ~WMaxMsgUlMapDescriptor();

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

Register_ClassDescriptor(WMaxMsgUlMapDescriptor);

WMaxMsgUlMapDescriptor::WMaxMsgUlMapDescriptor() : cClassDescriptor("WMaxMsgUlMap", "cPacket")
{
}

WMaxMsgUlMapDescriptor::~WMaxMsgUlMapDescriptor()
{
}

bool WMaxMsgUlMapDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxMsgUlMap *>(obj)!=NULL;
}

const char *WMaxMsgUlMapDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxMsgUlMapDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int WMaxMsgUlMapDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *WMaxMsgUlMapDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "IE",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int WMaxMsgUlMapDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='I' && strcmp(fieldName, "IE")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxMsgUlMapDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "WMaxUlMapIE",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *WMaxMsgUlMapDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxMsgUlMapDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgUlMap *pp = (WMaxMsgUlMap *)object; (void)pp;
    switch (field) {
        case 0: return pp->getIEArraySize();
        default: return 0;
    }
}

std::string WMaxMsgUlMapDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgUlMap *pp = (WMaxMsgUlMap *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getIE(i); return out.str();}
        default: return "";
    }
}

bool WMaxMsgUlMapDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgUlMap *pp = (WMaxMsgUlMap *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *WMaxMsgUlMapDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "WMaxUlMapIE",
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *WMaxMsgUlMapDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgUlMap *pp = (WMaxMsgUlMap *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getIE(i)); break;
        default: return NULL;
    }
}

Register_Class(WMaxMsgDCD);

WMaxMsgDCD::WMaxMsgDCD(const char *name, int kind) : cPacket(name,kind)
{
    this->confChangeCount_var = 0;
}

WMaxMsgDCD::WMaxMsgDCD(const WMaxMsgDCD& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

WMaxMsgDCD::~WMaxMsgDCD()
{
}

WMaxMsgDCD& WMaxMsgDCD::operator=(const WMaxMsgDCD& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->confChangeCount_var = other.confChangeCount_var;
    return *this;
}

void WMaxMsgDCD::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->confChangeCount_var);
}

void WMaxMsgDCD::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->confChangeCount_var);
}

int WMaxMsgDCD::getConfChangeCount() const
{
    return confChangeCount_var;
}

void WMaxMsgDCD::setConfChangeCount(int confChangeCount_var)
{
    this->confChangeCount_var = confChangeCount_var;
}

class WMaxMsgDCDDescriptor : public cClassDescriptor
{
  public:
    WMaxMsgDCDDescriptor();
    virtual ~WMaxMsgDCDDescriptor();

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

Register_ClassDescriptor(WMaxMsgDCDDescriptor);

WMaxMsgDCDDescriptor::WMaxMsgDCDDescriptor() : cClassDescriptor("WMaxMsgDCD", "cPacket")
{
}

WMaxMsgDCDDescriptor::~WMaxMsgDCDDescriptor()
{
}

bool WMaxMsgDCDDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxMsgDCD *>(obj)!=NULL;
}

const char *WMaxMsgDCDDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxMsgDCDDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int WMaxMsgDCDDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *WMaxMsgDCDDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "confChangeCount",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int WMaxMsgDCDDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "confChangeCount")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxMsgDCDDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *WMaxMsgDCDDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxMsgDCDDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgDCD *pp = (WMaxMsgDCD *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string WMaxMsgDCDDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgDCD *pp = (WMaxMsgDCD *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getConfChangeCount());
        default: return "";
    }
}

bool WMaxMsgDCDDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgDCD *pp = (WMaxMsgDCD *)object; (void)pp;
    switch (field) {
        case 0: pp->setConfChangeCount(string2long(value)); return true;
        default: return false;
    }
}

const char *WMaxMsgDCDDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *WMaxMsgDCDDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgDCD *pp = (WMaxMsgDCD *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(WMaxMsgUCD);

WMaxMsgUCD::WMaxMsgUCD(const char *name, int kind) : cPacket(name,kind)
{
    this->confChangeCount_var = 0;
}

WMaxMsgUCD::WMaxMsgUCD(const WMaxMsgUCD& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

WMaxMsgUCD::~WMaxMsgUCD()
{
}

WMaxMsgUCD& WMaxMsgUCD::operator=(const WMaxMsgUCD& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->confChangeCount_var = other.confChangeCount_var;
    return *this;
}

void WMaxMsgUCD::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->confChangeCount_var);
}

void WMaxMsgUCD::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->confChangeCount_var);
}

int WMaxMsgUCD::getConfChangeCount() const
{
    return confChangeCount_var;
}

void WMaxMsgUCD::setConfChangeCount(int confChangeCount_var)
{
    this->confChangeCount_var = confChangeCount_var;
}

class WMaxMsgUCDDescriptor : public cClassDescriptor
{
  public:
    WMaxMsgUCDDescriptor();
    virtual ~WMaxMsgUCDDescriptor();

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

Register_ClassDescriptor(WMaxMsgUCDDescriptor);

WMaxMsgUCDDescriptor::WMaxMsgUCDDescriptor() : cClassDescriptor("WMaxMsgUCD", "cPacket")
{
}

WMaxMsgUCDDescriptor::~WMaxMsgUCDDescriptor()
{
}

bool WMaxMsgUCDDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxMsgUCD *>(obj)!=NULL;
}

const char *WMaxMsgUCDDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxMsgUCDDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int WMaxMsgUCDDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *WMaxMsgUCDDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "confChangeCount",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int WMaxMsgUCDDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "confChangeCount")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxMsgUCDDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *WMaxMsgUCDDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxMsgUCDDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgUCD *pp = (WMaxMsgUCD *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string WMaxMsgUCDDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgUCD *pp = (WMaxMsgUCD *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getConfChangeCount());
        default: return "";
    }
}

bool WMaxMsgUCDDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgUCD *pp = (WMaxMsgUCD *)object; (void)pp;
    switch (field) {
        case 0: pp->setConfChangeCount(string2long(value)); return true;
        default: return false;
    }
}

const char *WMaxMsgUCDDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *WMaxMsgUCDDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgUCD *pp = (WMaxMsgUCD *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(WMaxMsgRngReq);

WMaxMsgRngReq::WMaxMsgRngReq(const char *name, int kind) : cPacket(name,kind)
{
    this->purpose_var = 0;
    SfQos_arraysize = 0;
    this->SfQos_var = 0;
    SfCid_arraysize = 0;
    this->SfCid_var = 0;
}

WMaxMsgRngReq::WMaxMsgRngReq(const WMaxMsgRngReq& other) : cPacket()
{
    setName(other.getName());
    SfQos_arraysize = 0;
    this->SfQos_var = 0;
    SfCid_arraysize = 0;
    this->SfCid_var = 0;
    operator=(other);
}

WMaxMsgRngReq::~WMaxMsgRngReq()
{
    delete [] SfQos_var;
    delete [] SfCid_var;
}

WMaxMsgRngReq& WMaxMsgRngReq::operator=(const WMaxMsgRngReq& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->purpose_var = other.purpose_var;
    this->rngReq_var = other.rngReq_var;
    this->myIP_var = other.myIP_var;
    delete [] this->SfQos_var;
    this->SfQos_var = (other.SfQos_arraysize==0) ? NULL : new ::WMaxQos[other.SfQos_arraysize];
    SfQos_arraysize = other.SfQos_arraysize;
    for (unsigned int i=0; i<SfQos_arraysize; i++)
        this->SfQos_var[i] = other.SfQos_var[i];
    delete [] this->SfCid_var;
    this->SfCid_var = (other.SfCid_arraysize==0) ? NULL : new int[other.SfCid_arraysize];
    SfCid_arraysize = other.SfCid_arraysize;
    for (unsigned int i=0; i<SfCid_arraysize; i++)
        this->SfCid_var[i] = other.SfCid_var[i];
    return *this;
}

void WMaxMsgRngReq::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->purpose_var);
    doPacking(b,this->rngReq_var);
    doPacking(b,this->myIP_var);
    b->pack(SfQos_arraysize);
    doPacking(b,this->SfQos_var,SfQos_arraysize);
    b->pack(SfCid_arraysize);
    doPacking(b,this->SfCid_var,SfCid_arraysize);
}

void WMaxMsgRngReq::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->purpose_var);
    doUnpacking(b,this->rngReq_var);
    doUnpacking(b,this->myIP_var);
    delete [] this->SfQos_var;
    b->unpack(SfQos_arraysize);
    if (SfQos_arraysize==0) {
        this->SfQos_var = 0;
    } else {
        this->SfQos_var = new ::WMaxQos[SfQos_arraysize];
        doUnpacking(b,this->SfQos_var,SfQos_arraysize);
    }
    delete [] this->SfCid_var;
    b->unpack(SfCid_arraysize);
    if (SfCid_arraysize==0) {
        this->SfCid_var = 0;
    } else {
        this->SfCid_var = new int[SfCid_arraysize];
        doUnpacking(b,this->SfCid_var,SfCid_arraysize);
    }
}

int WMaxMsgRngReq::getPurpose() const
{
    return purpose_var;
}

void WMaxMsgRngReq::setPurpose(int purpose_var)
{
    this->purpose_var = purpose_var;
}

WMaxRngReq& WMaxMsgRngReq::getRngReq()
{
    return rngReq_var;
}

void WMaxMsgRngReq::setRngReq(const WMaxRngReq& rngReq_var)
{
    this->rngReq_var = rngReq_var;
}

IPv6Addr& WMaxMsgRngReq::getMyIP()
{
    return myIP_var;
}

void WMaxMsgRngReq::setMyIP(const IPv6Addr& myIP_var)
{
    this->myIP_var = myIP_var;
}

void WMaxMsgRngReq::setSfQosArraySize(unsigned int size)
{
    ::WMaxQos *SfQos_var2 = (size==0) ? NULL : new ::WMaxQos[size];
    unsigned int sz = SfQos_arraysize < size ? SfQos_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        SfQos_var2[i] = this->SfQos_var[i];
    SfQos_arraysize = size;
    delete [] this->SfQos_var;
    this->SfQos_var = SfQos_var2;
}

unsigned int WMaxMsgRngReq::getSfQosArraySize() const
{
    return SfQos_arraysize;
}

WMaxQos& WMaxMsgRngReq::getSfQos(unsigned int k)
{
    if (k>=SfQos_arraysize) throw cRuntimeError("Array of size %d indexed by %d", SfQos_arraysize, k);
    return SfQos_var[k];
}

void WMaxMsgRngReq::setSfQos(unsigned int k, const WMaxQos& SfQos_var)
{
    if (k>=SfQos_arraysize) throw cRuntimeError("Array of size %d indexed by %d", SfQos_arraysize, k);
    this->SfQos_var[k]=SfQos_var;
}

void WMaxMsgRngReq::setSfCidArraySize(unsigned int size)
{
    int *SfCid_var2 = (size==0) ? NULL : new int[size];
    unsigned int sz = SfCid_arraysize < size ? SfCid_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        SfCid_var2[i] = this->SfCid_var[i];
    for (unsigned int i=sz; i<size; i++)
        SfCid_var2[i] = 0;
    SfCid_arraysize = size;
    delete [] this->SfCid_var;
    this->SfCid_var = SfCid_var2;
}

unsigned int WMaxMsgRngReq::getSfCidArraySize() const
{
    return SfCid_arraysize;
}

int WMaxMsgRngReq::getSfCid(unsigned int k) const
{
    if (k>=SfCid_arraysize) throw cRuntimeError("Array of size %d indexed by %d", SfCid_arraysize, k);
    return SfCid_var[k];
}

void WMaxMsgRngReq::setSfCid(unsigned int k, int SfCid_var)
{
    if (k>=SfCid_arraysize) throw cRuntimeError("Array of size %d indexed by %d", SfCid_arraysize, k);
    this->SfCid_var[k]=SfCid_var;
}

class WMaxMsgRngReqDescriptor : public cClassDescriptor
{
  public:
    WMaxMsgRngReqDescriptor();
    virtual ~WMaxMsgRngReqDescriptor();

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

Register_ClassDescriptor(WMaxMsgRngReqDescriptor);

WMaxMsgRngReqDescriptor::WMaxMsgRngReqDescriptor() : cClassDescriptor("WMaxMsgRngReq", "cPacket")
{
}

WMaxMsgRngReqDescriptor::~WMaxMsgRngReqDescriptor()
{
}

bool WMaxMsgRngReqDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxMsgRngReq *>(obj)!=NULL;
}

const char *WMaxMsgRngReqDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxMsgRngReqDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int WMaxMsgRngReqDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *WMaxMsgRngReqDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "purpose",
        "rngReq",
        "myIP",
        "SfQos",
        "SfCid",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int WMaxMsgRngReqDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "purpose")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "rngReq")==0) return base+1;
    if (fieldName[0]=='m' && strcmp(fieldName, "myIP")==0) return base+2;
    if (fieldName[0]=='S' && strcmp(fieldName, "SfQos")==0) return base+3;
    if (fieldName[0]=='S' && strcmp(fieldName, "SfCid")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxMsgRngReqDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "WMaxRngReq",
        "IPv6Addr",
        "WMaxQos",
        "int",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *WMaxMsgRngReqDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxMsgRngReqDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgRngReq *pp = (WMaxMsgRngReq *)object; (void)pp;
    switch (field) {
        case 3: return pp->getSfQosArraySize();
        case 4: return pp->getSfCidArraySize();
        default: return 0;
    }
}

std::string WMaxMsgRngReqDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgRngReq *pp = (WMaxMsgRngReq *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getPurpose());
        case 1: {std::stringstream out; out << pp->getRngReq(); return out.str();}
        case 2: {std::stringstream out; out << pp->getMyIP(); return out.str();}
        case 3: {std::stringstream out; out << pp->getSfQos(i); return out.str();}
        case 4: return long2string(pp->getSfCid(i));
        default: return "";
    }
}

bool WMaxMsgRngReqDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgRngReq *pp = (WMaxMsgRngReq *)object; (void)pp;
    switch (field) {
        case 0: pp->setPurpose(string2long(value)); return true;
        case 4: pp->setSfCid(i,string2long(value)); return true;
        default: return false;
    }
}

const char *WMaxMsgRngReqDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        "WMaxRngReq",
        "IPv6Addr",
        "WMaxQos",
        NULL,
    };
    return (field>=0 && field<5) ? fieldStructNames[field] : NULL;
}

void *WMaxMsgRngReqDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgRngReq *pp = (WMaxMsgRngReq *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getRngReq()); break;
        case 2: return (void *)(&pp->getMyIP()); break;
        case 3: return (void *)(&pp->getSfQos(i)); break;
        default: return NULL;
    }
}

Register_Class(WMaxMsgRngRsp);

WMaxMsgRngRsp::WMaxMsgRngRsp(const char *name, int kind) : cPacket(name,kind)
{
    this->purpose_var = 0;
    oldCid_arraysize = 0;
    this->oldCid_var = 0;
    newCid_arraysize = 0;
    this->newCid_var = 0;
}

WMaxMsgRngRsp::WMaxMsgRngRsp(const WMaxMsgRngRsp& other) : cPacket()
{
    setName(other.getName());
    oldCid_arraysize = 0;
    this->oldCid_var = 0;
    newCid_arraysize = 0;
    this->newCid_var = 0;
    operator=(other);
}

WMaxMsgRngRsp::~WMaxMsgRngRsp()
{
    delete [] oldCid_var;
    delete [] newCid_var;
}

WMaxMsgRngRsp& WMaxMsgRngRsp::operator=(const WMaxMsgRngRsp& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->purpose_var = other.purpose_var;
    this->rngRsp_var = other.rngRsp_var;
    delete [] this->oldCid_var;
    this->oldCid_var = (other.oldCid_arraysize==0) ? NULL : new int[other.oldCid_arraysize];
    oldCid_arraysize = other.oldCid_arraysize;
    for (unsigned int i=0; i<oldCid_arraysize; i++)
        this->oldCid_var[i] = other.oldCid_var[i];
    delete [] this->newCid_var;
    this->newCid_var = (other.newCid_arraysize==0) ? NULL : new int[other.newCid_arraysize];
    newCid_arraysize = other.newCid_arraysize;
    for (unsigned int i=0; i<newCid_arraysize; i++)
        this->newCid_var[i] = other.newCid_var[i];
    return *this;
}

void WMaxMsgRngRsp::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->purpose_var);
    doPacking(b,this->rngRsp_var);
    b->pack(oldCid_arraysize);
    doPacking(b,this->oldCid_var,oldCid_arraysize);
    b->pack(newCid_arraysize);
    doPacking(b,this->newCid_var,newCid_arraysize);
}

void WMaxMsgRngRsp::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->purpose_var);
    doUnpacking(b,this->rngRsp_var);
    delete [] this->oldCid_var;
    b->unpack(oldCid_arraysize);
    if (oldCid_arraysize==0) {
        this->oldCid_var = 0;
    } else {
        this->oldCid_var = new int[oldCid_arraysize];
        doUnpacking(b,this->oldCid_var,oldCid_arraysize);
    }
    delete [] this->newCid_var;
    b->unpack(newCid_arraysize);
    if (newCid_arraysize==0) {
        this->newCid_var = 0;
    } else {
        this->newCid_var = new int[newCid_arraysize];
        doUnpacking(b,this->newCid_var,newCid_arraysize);
    }
}

int WMaxMsgRngRsp::getPurpose() const
{
    return purpose_var;
}

void WMaxMsgRngRsp::setPurpose(int purpose_var)
{
    this->purpose_var = purpose_var;
}

WMaxRngRsp& WMaxMsgRngRsp::getRngRsp()
{
    return rngRsp_var;
}

void WMaxMsgRngRsp::setRngRsp(const WMaxRngRsp& rngRsp_var)
{
    this->rngRsp_var = rngRsp_var;
}

void WMaxMsgRngRsp::setOldCidArraySize(unsigned int size)
{
    int *oldCid_var2 = (size==0) ? NULL : new int[size];
    unsigned int sz = oldCid_arraysize < size ? oldCid_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        oldCid_var2[i] = this->oldCid_var[i];
    for (unsigned int i=sz; i<size; i++)
        oldCid_var2[i] = 0;
    oldCid_arraysize = size;
    delete [] this->oldCid_var;
    this->oldCid_var = oldCid_var2;
}

unsigned int WMaxMsgRngRsp::getOldCidArraySize() const
{
    return oldCid_arraysize;
}

int WMaxMsgRngRsp::getOldCid(unsigned int k) const
{
    if (k>=oldCid_arraysize) throw cRuntimeError("Array of size %d indexed by %d", oldCid_arraysize, k);
    return oldCid_var[k];
}

void WMaxMsgRngRsp::setOldCid(unsigned int k, int oldCid_var)
{
    if (k>=oldCid_arraysize) throw cRuntimeError("Array of size %d indexed by %d", oldCid_arraysize, k);
    this->oldCid_var[k]=oldCid_var;
}

void WMaxMsgRngRsp::setNewCidArraySize(unsigned int size)
{
    int *newCid_var2 = (size==0) ? NULL : new int[size];
    unsigned int sz = newCid_arraysize < size ? newCid_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        newCid_var2[i] = this->newCid_var[i];
    for (unsigned int i=sz; i<size; i++)
        newCid_var2[i] = 0;
    newCid_arraysize = size;
    delete [] this->newCid_var;
    this->newCid_var = newCid_var2;
}

unsigned int WMaxMsgRngRsp::getNewCidArraySize() const
{
    return newCid_arraysize;
}

int WMaxMsgRngRsp::getNewCid(unsigned int k) const
{
    if (k>=newCid_arraysize) throw cRuntimeError("Array of size %d indexed by %d", newCid_arraysize, k);
    return newCid_var[k];
}

void WMaxMsgRngRsp::setNewCid(unsigned int k, int newCid_var)
{
    if (k>=newCid_arraysize) throw cRuntimeError("Array of size %d indexed by %d", newCid_arraysize, k);
    this->newCid_var[k]=newCid_var;
}

class WMaxMsgRngRspDescriptor : public cClassDescriptor
{
  public:
    WMaxMsgRngRspDescriptor();
    virtual ~WMaxMsgRngRspDescriptor();

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

Register_ClassDescriptor(WMaxMsgRngRspDescriptor);

WMaxMsgRngRspDescriptor::WMaxMsgRngRspDescriptor() : cClassDescriptor("WMaxMsgRngRsp", "cPacket")
{
}

WMaxMsgRngRspDescriptor::~WMaxMsgRngRspDescriptor()
{
}

bool WMaxMsgRngRspDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxMsgRngRsp *>(obj)!=NULL;
}

const char *WMaxMsgRngRspDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxMsgRngRspDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int WMaxMsgRngRspDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *WMaxMsgRngRspDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "purpose",
        "rngRsp",
        "oldCid",
        "newCid",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int WMaxMsgRngRspDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "purpose")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "rngRsp")==0) return base+1;
    if (fieldName[0]=='o' && strcmp(fieldName, "oldCid")==0) return base+2;
    if (fieldName[0]=='n' && strcmp(fieldName, "newCid")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxMsgRngRspDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "WMaxRngRsp",
        "int",
        "int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *WMaxMsgRngRspDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxMsgRngRspDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgRngRsp *pp = (WMaxMsgRngRsp *)object; (void)pp;
    switch (field) {
        case 2: return pp->getOldCidArraySize();
        case 3: return pp->getNewCidArraySize();
        default: return 0;
    }
}

std::string WMaxMsgRngRspDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgRngRsp *pp = (WMaxMsgRngRsp *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getPurpose());
        case 1: {std::stringstream out; out << pp->getRngRsp(); return out.str();}
        case 2: return long2string(pp->getOldCid(i));
        case 3: return long2string(pp->getNewCid(i));
        default: return "";
    }
}

bool WMaxMsgRngRspDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgRngRsp *pp = (WMaxMsgRngRsp *)object; (void)pp;
    switch (field) {
        case 0: pp->setPurpose(string2long(value)); return true;
        case 2: pp->setOldCid(i,string2long(value)); return true;
        case 3: pp->setNewCid(i,string2long(value)); return true;
        default: return false;
    }
}

const char *WMaxMsgRngRspDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        "WMaxRngRsp",
        NULL,
        NULL,
    };
    return (field>=0 && field<4) ? fieldStructNames[field] : NULL;
}

void *WMaxMsgRngRspDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgRngRsp *pp = (WMaxMsgRngRsp *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getRngRsp()); break;
        default: return NULL;
    }
}

Register_Class(WMaxMsgSbcReq);

WMaxMsgSbcReq::WMaxMsgSbcReq(const char *name, int kind) : cPacket(name,kind)
{
}

WMaxMsgSbcReq::WMaxMsgSbcReq(const WMaxMsgSbcReq& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

WMaxMsgSbcReq::~WMaxMsgSbcReq()
{
}

WMaxMsgSbcReq& WMaxMsgSbcReq::operator=(const WMaxMsgSbcReq& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    return *this;
}

void WMaxMsgSbcReq::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
}

void WMaxMsgSbcReq::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
}

class WMaxMsgSbcReqDescriptor : public cClassDescriptor
{
  public:
    WMaxMsgSbcReqDescriptor();
    virtual ~WMaxMsgSbcReqDescriptor();

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

Register_ClassDescriptor(WMaxMsgSbcReqDescriptor);

WMaxMsgSbcReqDescriptor::WMaxMsgSbcReqDescriptor() : cClassDescriptor("WMaxMsgSbcReq", "cPacket")
{
}

WMaxMsgSbcReqDescriptor::~WMaxMsgSbcReqDescriptor()
{
}

bool WMaxMsgSbcReqDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxMsgSbcReq *>(obj)!=NULL;
}

const char *WMaxMsgSbcReqDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxMsgSbcReqDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int WMaxMsgSbcReqDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *WMaxMsgSbcReqDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int WMaxMsgSbcReqDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxMsgSbcReqDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *WMaxMsgSbcReqDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxMsgSbcReqDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgSbcReq *pp = (WMaxMsgSbcReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string WMaxMsgSbcReqDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgSbcReq *pp = (WMaxMsgSbcReq *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool WMaxMsgSbcReqDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgSbcReq *pp = (WMaxMsgSbcReq *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *WMaxMsgSbcReqDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *WMaxMsgSbcReqDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgSbcReq *pp = (WMaxMsgSbcReq *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(WMaxMsgSbcRsp);

WMaxMsgSbcRsp::WMaxMsgSbcRsp(const char *name, int kind) : cPacket(name,kind)
{
}

WMaxMsgSbcRsp::WMaxMsgSbcRsp(const WMaxMsgSbcRsp& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

WMaxMsgSbcRsp::~WMaxMsgSbcRsp()
{
}

WMaxMsgSbcRsp& WMaxMsgSbcRsp::operator=(const WMaxMsgSbcRsp& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    return *this;
}

void WMaxMsgSbcRsp::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
}

void WMaxMsgSbcRsp::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
}

class WMaxMsgSbcRspDescriptor : public cClassDescriptor
{
  public:
    WMaxMsgSbcRspDescriptor();
    virtual ~WMaxMsgSbcRspDescriptor();

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

Register_ClassDescriptor(WMaxMsgSbcRspDescriptor);

WMaxMsgSbcRspDescriptor::WMaxMsgSbcRspDescriptor() : cClassDescriptor("WMaxMsgSbcRsp", "cPacket")
{
}

WMaxMsgSbcRspDescriptor::~WMaxMsgSbcRspDescriptor()
{
}

bool WMaxMsgSbcRspDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxMsgSbcRsp *>(obj)!=NULL;
}

const char *WMaxMsgSbcRspDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxMsgSbcRspDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int WMaxMsgSbcRspDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *WMaxMsgSbcRspDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int WMaxMsgSbcRspDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxMsgSbcRspDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *WMaxMsgSbcRspDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxMsgSbcRspDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgSbcRsp *pp = (WMaxMsgSbcRsp *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string WMaxMsgSbcRspDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgSbcRsp *pp = (WMaxMsgSbcRsp *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool WMaxMsgSbcRspDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgSbcRsp *pp = (WMaxMsgSbcRsp *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *WMaxMsgSbcRspDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *WMaxMsgSbcRspDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgSbcRsp *pp = (WMaxMsgSbcRsp *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(WMaxMsgPkmReq);

WMaxMsgPkmReq::WMaxMsgPkmReq(const char *name, int kind) : cPacket(name,kind)
{
    this->code_var = 0;
}

WMaxMsgPkmReq::WMaxMsgPkmReq(const WMaxMsgPkmReq& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

WMaxMsgPkmReq::~WMaxMsgPkmReq()
{
}

WMaxMsgPkmReq& WMaxMsgPkmReq::operator=(const WMaxMsgPkmReq& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->code_var = other.code_var;
    return *this;
}

void WMaxMsgPkmReq::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->code_var);
}

void WMaxMsgPkmReq::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->code_var);
}

int WMaxMsgPkmReq::getCode() const
{
    return code_var;
}

void WMaxMsgPkmReq::setCode(int code_var)
{
    this->code_var = code_var;
}

class WMaxMsgPkmReqDescriptor : public cClassDescriptor
{
  public:
    WMaxMsgPkmReqDescriptor();
    virtual ~WMaxMsgPkmReqDescriptor();

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

Register_ClassDescriptor(WMaxMsgPkmReqDescriptor);

WMaxMsgPkmReqDescriptor::WMaxMsgPkmReqDescriptor() : cClassDescriptor("WMaxMsgPkmReq", "cPacket")
{
}

WMaxMsgPkmReqDescriptor::~WMaxMsgPkmReqDescriptor()
{
}

bool WMaxMsgPkmReqDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxMsgPkmReq *>(obj)!=NULL;
}

const char *WMaxMsgPkmReqDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxMsgPkmReqDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int WMaxMsgPkmReqDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *WMaxMsgPkmReqDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "code",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int WMaxMsgPkmReqDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "code")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxMsgPkmReqDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *WMaxMsgPkmReqDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxMsgPkmReqDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgPkmReq *pp = (WMaxMsgPkmReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string WMaxMsgPkmReqDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgPkmReq *pp = (WMaxMsgPkmReq *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getCode());
        default: return "";
    }
}

bool WMaxMsgPkmReqDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgPkmReq *pp = (WMaxMsgPkmReq *)object; (void)pp;
    switch (field) {
        case 0: pp->setCode(string2long(value)); return true;
        default: return false;
    }
}

const char *WMaxMsgPkmReqDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *WMaxMsgPkmReqDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgPkmReq *pp = (WMaxMsgPkmReq *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(WMaxMsgPkmRsp);

WMaxMsgPkmRsp::WMaxMsgPkmRsp(const char *name, int kind) : cPacket(name,kind)
{
    this->code_var = 0;
}

WMaxMsgPkmRsp::WMaxMsgPkmRsp(const WMaxMsgPkmRsp& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

WMaxMsgPkmRsp::~WMaxMsgPkmRsp()
{
}

WMaxMsgPkmRsp& WMaxMsgPkmRsp::operator=(const WMaxMsgPkmRsp& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->code_var = other.code_var;
    return *this;
}

void WMaxMsgPkmRsp::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->code_var);
}

void WMaxMsgPkmRsp::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->code_var);
}

int WMaxMsgPkmRsp::getCode() const
{
    return code_var;
}

void WMaxMsgPkmRsp::setCode(int code_var)
{
    this->code_var = code_var;
}

class WMaxMsgPkmRspDescriptor : public cClassDescriptor
{
  public:
    WMaxMsgPkmRspDescriptor();
    virtual ~WMaxMsgPkmRspDescriptor();

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

Register_ClassDescriptor(WMaxMsgPkmRspDescriptor);

WMaxMsgPkmRspDescriptor::WMaxMsgPkmRspDescriptor() : cClassDescriptor("WMaxMsgPkmRsp", "cPacket")
{
}

WMaxMsgPkmRspDescriptor::~WMaxMsgPkmRspDescriptor()
{
}

bool WMaxMsgPkmRspDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxMsgPkmRsp *>(obj)!=NULL;
}

const char *WMaxMsgPkmRspDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxMsgPkmRspDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int WMaxMsgPkmRspDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *WMaxMsgPkmRspDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "code",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int WMaxMsgPkmRspDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "code")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxMsgPkmRspDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *WMaxMsgPkmRspDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxMsgPkmRspDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgPkmRsp *pp = (WMaxMsgPkmRsp *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string WMaxMsgPkmRspDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgPkmRsp *pp = (WMaxMsgPkmRsp *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getCode());
        default: return "";
    }
}

bool WMaxMsgPkmRspDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgPkmRsp *pp = (WMaxMsgPkmRsp *)object; (void)pp;
    switch (field) {
        case 0: pp->setCode(string2long(value)); return true;
        default: return false;
    }
}

const char *WMaxMsgPkmRspDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *WMaxMsgPkmRspDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgPkmRsp *pp = (WMaxMsgPkmRsp *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(WMaxMsgRegReq);

WMaxMsgRegReq::WMaxMsgRegReq(const char *name, int kind) : cPacket(name,kind)
{
}

WMaxMsgRegReq::WMaxMsgRegReq(const WMaxMsgRegReq& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

WMaxMsgRegReq::~WMaxMsgRegReq()
{
}

WMaxMsgRegReq& WMaxMsgRegReq::operator=(const WMaxMsgRegReq& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    return *this;
}

void WMaxMsgRegReq::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
}

void WMaxMsgRegReq::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
}

class WMaxMsgRegReqDescriptor : public cClassDescriptor
{
  public:
    WMaxMsgRegReqDescriptor();
    virtual ~WMaxMsgRegReqDescriptor();

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

Register_ClassDescriptor(WMaxMsgRegReqDescriptor);

WMaxMsgRegReqDescriptor::WMaxMsgRegReqDescriptor() : cClassDescriptor("WMaxMsgRegReq", "cPacket")
{
}

WMaxMsgRegReqDescriptor::~WMaxMsgRegReqDescriptor()
{
}

bool WMaxMsgRegReqDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxMsgRegReq *>(obj)!=NULL;
}

const char *WMaxMsgRegReqDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxMsgRegReqDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int WMaxMsgRegReqDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *WMaxMsgRegReqDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int WMaxMsgRegReqDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxMsgRegReqDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *WMaxMsgRegReqDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxMsgRegReqDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgRegReq *pp = (WMaxMsgRegReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string WMaxMsgRegReqDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgRegReq *pp = (WMaxMsgRegReq *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool WMaxMsgRegReqDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgRegReq *pp = (WMaxMsgRegReq *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *WMaxMsgRegReqDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *WMaxMsgRegReqDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgRegReq *pp = (WMaxMsgRegReq *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(WMaxMsgRegRsp);

WMaxMsgRegRsp::WMaxMsgRegRsp(const char *name, int kind) : cPacket(name,kind)
{
}

WMaxMsgRegRsp::WMaxMsgRegRsp(const WMaxMsgRegRsp& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

WMaxMsgRegRsp::~WMaxMsgRegRsp()
{
}

WMaxMsgRegRsp& WMaxMsgRegRsp::operator=(const WMaxMsgRegRsp& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    return *this;
}

void WMaxMsgRegRsp::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
}

void WMaxMsgRegRsp::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
}

class WMaxMsgRegRspDescriptor : public cClassDescriptor
{
  public:
    WMaxMsgRegRspDescriptor();
    virtual ~WMaxMsgRegRspDescriptor();

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

Register_ClassDescriptor(WMaxMsgRegRspDescriptor);

WMaxMsgRegRspDescriptor::WMaxMsgRegRspDescriptor() : cClassDescriptor("WMaxMsgRegRsp", "cPacket")
{
}

WMaxMsgRegRspDescriptor::~WMaxMsgRegRspDescriptor()
{
}

bool WMaxMsgRegRspDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxMsgRegRsp *>(obj)!=NULL;
}

const char *WMaxMsgRegRspDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxMsgRegRspDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int WMaxMsgRegRspDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *WMaxMsgRegRspDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int WMaxMsgRegRspDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxMsgRegRspDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *WMaxMsgRegRspDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxMsgRegRspDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgRegRsp *pp = (WMaxMsgRegRsp *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string WMaxMsgRegRspDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgRegRsp *pp = (WMaxMsgRegRsp *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool WMaxMsgRegRspDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgRegRsp *pp = (WMaxMsgRegRsp *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *WMaxMsgRegRspDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *WMaxMsgRegRspDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgRegRsp *pp = (WMaxMsgRegRsp *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(WMaxMsgMobScnReq);

WMaxMsgMobScnReq::WMaxMsgMobScnReq(const char *name, int kind) : cPacket(name,kind)
{
}

WMaxMsgMobScnReq::WMaxMsgMobScnReq(const WMaxMsgMobScnReq& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

WMaxMsgMobScnReq::~WMaxMsgMobScnReq()
{
}

WMaxMsgMobScnReq& WMaxMsgMobScnReq::operator=(const WMaxMsgMobScnReq& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    return *this;
}

void WMaxMsgMobScnReq::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
}

void WMaxMsgMobScnReq::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
}

class WMaxMsgMobScnReqDescriptor : public cClassDescriptor
{
  public:
    WMaxMsgMobScnReqDescriptor();
    virtual ~WMaxMsgMobScnReqDescriptor();

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

Register_ClassDescriptor(WMaxMsgMobScnReqDescriptor);

WMaxMsgMobScnReqDescriptor::WMaxMsgMobScnReqDescriptor() : cClassDescriptor("WMaxMsgMobScnReq", "cPacket")
{
}

WMaxMsgMobScnReqDescriptor::~WMaxMsgMobScnReqDescriptor()
{
}

bool WMaxMsgMobScnReqDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxMsgMobScnReq *>(obj)!=NULL;
}

const char *WMaxMsgMobScnReqDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxMsgMobScnReqDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int WMaxMsgMobScnReqDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *WMaxMsgMobScnReqDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int WMaxMsgMobScnReqDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxMsgMobScnReqDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *WMaxMsgMobScnReqDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxMsgMobScnReqDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgMobScnReq *pp = (WMaxMsgMobScnReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string WMaxMsgMobScnReqDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgMobScnReq *pp = (WMaxMsgMobScnReq *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool WMaxMsgMobScnReqDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgMobScnReq *pp = (WMaxMsgMobScnReq *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *WMaxMsgMobScnReqDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *WMaxMsgMobScnReqDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgMobScnReq *pp = (WMaxMsgMobScnReq *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(WMaxMsgMobScnRsp);

WMaxMsgMobScnRsp::WMaxMsgMobScnRsp(const char *name, int kind) : cPacket(name,kind)
{
}

WMaxMsgMobScnRsp::WMaxMsgMobScnRsp(const WMaxMsgMobScnRsp& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

WMaxMsgMobScnRsp::~WMaxMsgMobScnRsp()
{
}

WMaxMsgMobScnRsp& WMaxMsgMobScnRsp::operator=(const WMaxMsgMobScnRsp& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    return *this;
}

void WMaxMsgMobScnRsp::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
}

void WMaxMsgMobScnRsp::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
}

class WMaxMsgMobScnRspDescriptor : public cClassDescriptor
{
  public:
    WMaxMsgMobScnRspDescriptor();
    virtual ~WMaxMsgMobScnRspDescriptor();

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

Register_ClassDescriptor(WMaxMsgMobScnRspDescriptor);

WMaxMsgMobScnRspDescriptor::WMaxMsgMobScnRspDescriptor() : cClassDescriptor("WMaxMsgMobScnRsp", "cPacket")
{
}

WMaxMsgMobScnRspDescriptor::~WMaxMsgMobScnRspDescriptor()
{
}

bool WMaxMsgMobScnRspDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxMsgMobScnRsp *>(obj)!=NULL;
}

const char *WMaxMsgMobScnRspDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxMsgMobScnRspDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int WMaxMsgMobScnRspDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *WMaxMsgMobScnRspDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int WMaxMsgMobScnRspDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxMsgMobScnRspDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *WMaxMsgMobScnRspDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxMsgMobScnRspDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgMobScnRsp *pp = (WMaxMsgMobScnRsp *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string WMaxMsgMobScnRspDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgMobScnRsp *pp = (WMaxMsgMobScnRsp *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool WMaxMsgMobScnRspDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgMobScnRsp *pp = (WMaxMsgMobScnRsp *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *WMaxMsgMobScnRspDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *WMaxMsgMobScnRspDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgMobScnRsp *pp = (WMaxMsgMobScnRsp *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(WMaxMsgMSHOREQ);

WMaxMsgMSHOREQ::WMaxMsgMSHOREQ(const char *name, int kind) : cPacket(name,kind)
{
    BSFull_arraysize = 0;
    this->BSFull_var = 0;
}

WMaxMsgMSHOREQ::WMaxMsgMSHOREQ(const WMaxMsgMSHOREQ& other) : cPacket()
{
    setName(other.getName());
    BSFull_arraysize = 0;
    this->BSFull_var = 0;
    operator=(other);
}

WMaxMsgMSHOREQ::~WMaxMsgMSHOREQ()
{
    delete [] BSFull_var;
}

WMaxMsgMSHOREQ& WMaxMsgMSHOREQ::operator=(const WMaxMsgMSHOREQ& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    delete [] this->BSFull_var;
    this->BSFull_var = (other.BSFull_arraysize==0) ? NULL : new ::WMaxBSFull[other.BSFull_arraysize];
    BSFull_arraysize = other.BSFull_arraysize;
    for (unsigned int i=0; i<BSFull_arraysize; i++)
        this->BSFull_var[i] = other.BSFull_var[i];
    return *this;
}

void WMaxMsgMSHOREQ::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    b->pack(BSFull_arraysize);
    doPacking(b,this->BSFull_var,BSFull_arraysize);
}

void WMaxMsgMSHOREQ::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    delete [] this->BSFull_var;
    b->unpack(BSFull_arraysize);
    if (BSFull_arraysize==0) {
        this->BSFull_var = 0;
    } else {
        this->BSFull_var = new ::WMaxBSFull[BSFull_arraysize];
        doUnpacking(b,this->BSFull_var,BSFull_arraysize);
    }
}

void WMaxMsgMSHOREQ::setBSFullArraySize(unsigned int size)
{
    ::WMaxBSFull *BSFull_var2 = (size==0) ? NULL : new ::WMaxBSFull[size];
    unsigned int sz = BSFull_arraysize < size ? BSFull_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        BSFull_var2[i] = this->BSFull_var[i];
    BSFull_arraysize = size;
    delete [] this->BSFull_var;
    this->BSFull_var = BSFull_var2;
}

unsigned int WMaxMsgMSHOREQ::getBSFullArraySize() const
{
    return BSFull_arraysize;
}

WMaxBSFull& WMaxMsgMSHOREQ::getBSFull(unsigned int k)
{
    if (k>=BSFull_arraysize) throw cRuntimeError("Array of size %d indexed by %d", BSFull_arraysize, k);
    return BSFull_var[k];
}

void WMaxMsgMSHOREQ::setBSFull(unsigned int k, const WMaxBSFull& BSFull_var)
{
    if (k>=BSFull_arraysize) throw cRuntimeError("Array of size %d indexed by %d", BSFull_arraysize, k);
    this->BSFull_var[k]=BSFull_var;
}

class WMaxMsgMSHOREQDescriptor : public cClassDescriptor
{
  public:
    WMaxMsgMSHOREQDescriptor();
    virtual ~WMaxMsgMSHOREQDescriptor();

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

Register_ClassDescriptor(WMaxMsgMSHOREQDescriptor);

WMaxMsgMSHOREQDescriptor::WMaxMsgMSHOREQDescriptor() : cClassDescriptor("WMaxMsgMSHOREQ", "cPacket")
{
}

WMaxMsgMSHOREQDescriptor::~WMaxMsgMSHOREQDescriptor()
{
}

bool WMaxMsgMSHOREQDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxMsgMSHOREQ *>(obj)!=NULL;
}

const char *WMaxMsgMSHOREQDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxMsgMSHOREQDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int WMaxMsgMSHOREQDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *WMaxMsgMSHOREQDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "BSFull",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int WMaxMsgMSHOREQDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='B' && strcmp(fieldName, "BSFull")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxMsgMSHOREQDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "WMaxBSFull",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *WMaxMsgMSHOREQDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxMsgMSHOREQDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgMSHOREQ *pp = (WMaxMsgMSHOREQ *)object; (void)pp;
    switch (field) {
        case 0: return pp->getBSFullArraySize();
        default: return 0;
    }
}

std::string WMaxMsgMSHOREQDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgMSHOREQ *pp = (WMaxMsgMSHOREQ *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getBSFull(i); return out.str();}
        default: return "";
    }
}

bool WMaxMsgMSHOREQDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgMSHOREQ *pp = (WMaxMsgMSHOREQ *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *WMaxMsgMSHOREQDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "WMaxBSFull",
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *WMaxMsgMSHOREQDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgMSHOREQ *pp = (WMaxMsgMSHOREQ *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getBSFull(i)); break;
        default: return NULL;
    }
}

Register_Class(WMaxMsgBSHORSP);

WMaxMsgBSHORSP::WMaxMsgBSHORSP(const char *name, int kind) : cPacket(name,kind)
{
    BSFull_arraysize = 0;
    this->BSFull_var = 0;
}

WMaxMsgBSHORSP::WMaxMsgBSHORSP(const WMaxMsgBSHORSP& other) : cPacket()
{
    setName(other.getName());
    BSFull_arraysize = 0;
    this->BSFull_var = 0;
    operator=(other);
}

WMaxMsgBSHORSP::~WMaxMsgBSHORSP()
{
    delete [] BSFull_var;
}

WMaxMsgBSHORSP& WMaxMsgBSHORSP::operator=(const WMaxMsgBSHORSP& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    delete [] this->BSFull_var;
    this->BSFull_var = (other.BSFull_arraysize==0) ? NULL : new ::WMaxBSFull[other.BSFull_arraysize];
    BSFull_arraysize = other.BSFull_arraysize;
    for (unsigned int i=0; i<BSFull_arraysize; i++)
        this->BSFull_var[i] = other.BSFull_var[i];
    return *this;
}

void WMaxMsgBSHORSP::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    b->pack(BSFull_arraysize);
    doPacking(b,this->BSFull_var,BSFull_arraysize);
}

void WMaxMsgBSHORSP::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    delete [] this->BSFull_var;
    b->unpack(BSFull_arraysize);
    if (BSFull_arraysize==0) {
        this->BSFull_var = 0;
    } else {
        this->BSFull_var = new ::WMaxBSFull[BSFull_arraysize];
        doUnpacking(b,this->BSFull_var,BSFull_arraysize);
    }
}

void WMaxMsgBSHORSP::setBSFullArraySize(unsigned int size)
{
    ::WMaxBSFull *BSFull_var2 = (size==0) ? NULL : new ::WMaxBSFull[size];
    unsigned int sz = BSFull_arraysize < size ? BSFull_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        BSFull_var2[i] = this->BSFull_var[i];
    BSFull_arraysize = size;
    delete [] this->BSFull_var;
    this->BSFull_var = BSFull_var2;
}

unsigned int WMaxMsgBSHORSP::getBSFullArraySize() const
{
    return BSFull_arraysize;
}

WMaxBSFull& WMaxMsgBSHORSP::getBSFull(unsigned int k)
{
    if (k>=BSFull_arraysize) throw cRuntimeError("Array of size %d indexed by %d", BSFull_arraysize, k);
    return BSFull_var[k];
}

void WMaxMsgBSHORSP::setBSFull(unsigned int k, const WMaxBSFull& BSFull_var)
{
    if (k>=BSFull_arraysize) throw cRuntimeError("Array of size %d indexed by %d", BSFull_arraysize, k);
    this->BSFull_var[k]=BSFull_var;
}

class WMaxMsgBSHORSPDescriptor : public cClassDescriptor
{
  public:
    WMaxMsgBSHORSPDescriptor();
    virtual ~WMaxMsgBSHORSPDescriptor();

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

Register_ClassDescriptor(WMaxMsgBSHORSPDescriptor);

WMaxMsgBSHORSPDescriptor::WMaxMsgBSHORSPDescriptor() : cClassDescriptor("WMaxMsgBSHORSP", "cPacket")
{
}

WMaxMsgBSHORSPDescriptor::~WMaxMsgBSHORSPDescriptor()
{
}

bool WMaxMsgBSHORSPDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxMsgBSHORSP *>(obj)!=NULL;
}

const char *WMaxMsgBSHORSPDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxMsgBSHORSPDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int WMaxMsgBSHORSPDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *WMaxMsgBSHORSPDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "BSFull",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int WMaxMsgBSHORSPDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='B' && strcmp(fieldName, "BSFull")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxMsgBSHORSPDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "WMaxBSFull",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *WMaxMsgBSHORSPDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxMsgBSHORSPDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgBSHORSP *pp = (WMaxMsgBSHORSP *)object; (void)pp;
    switch (field) {
        case 0: return pp->getBSFullArraySize();
        default: return 0;
    }
}

std::string WMaxMsgBSHORSPDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgBSHORSP *pp = (WMaxMsgBSHORSP *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getBSFull(i); return out.str();}
        default: return "";
    }
}

bool WMaxMsgBSHORSPDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgBSHORSP *pp = (WMaxMsgBSHORSP *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *WMaxMsgBSHORSPDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "WMaxBSFull",
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *WMaxMsgBSHORSPDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgBSHORSP *pp = (WMaxMsgBSHORSP *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getBSFull(i)); break;
        default: return NULL;
    }
}

Register_Class(WMaxMsgHOIND);

WMaxMsgHOIND::WMaxMsgHOIND(const char *name, int kind) : cPacket(name,kind)
{
    this->status_var = 0;
}

WMaxMsgHOIND::WMaxMsgHOIND(const WMaxMsgHOIND& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

WMaxMsgHOIND::~WMaxMsgHOIND()
{
}

WMaxMsgHOIND& WMaxMsgHOIND::operator=(const WMaxMsgHOIND& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->status_var = other.status_var;
    this->target_var = other.target_var;
    return *this;
}

void WMaxMsgHOIND::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->status_var);
    doPacking(b,this->target_var);
}

void WMaxMsgHOIND::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->status_var);
    doUnpacking(b,this->target_var);
}

int WMaxMsgHOIND::getStatus() const
{
    return status_var;
}

void WMaxMsgHOIND::setStatus(int status_var)
{
    this->status_var = status_var;
}

WMaxBSFull& WMaxMsgHOIND::getTarget()
{
    return target_var;
}

void WMaxMsgHOIND::setTarget(const WMaxBSFull& target_var)
{
    this->target_var = target_var;
}

class WMaxMsgHOINDDescriptor : public cClassDescriptor
{
  public:
    WMaxMsgHOINDDescriptor();
    virtual ~WMaxMsgHOINDDescriptor();

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

Register_ClassDescriptor(WMaxMsgHOINDDescriptor);

WMaxMsgHOINDDescriptor::WMaxMsgHOINDDescriptor() : cClassDescriptor("WMaxMsgHOIND", "cPacket")
{
}

WMaxMsgHOINDDescriptor::~WMaxMsgHOINDDescriptor()
{
}

bool WMaxMsgHOINDDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxMsgHOIND *>(obj)!=NULL;
}

const char *WMaxMsgHOINDDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxMsgHOINDDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int WMaxMsgHOINDDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *WMaxMsgHOINDDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "status",
        "target",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int WMaxMsgHOINDDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "status")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "target")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxMsgHOINDDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "WMaxBSFull",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *WMaxMsgHOINDDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxMsgHOINDDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgHOIND *pp = (WMaxMsgHOIND *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string WMaxMsgHOINDDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgHOIND *pp = (WMaxMsgHOIND *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getStatus());
        case 1: {std::stringstream out; out << pp->getTarget(); return out.str();}
        default: return "";
    }
}

bool WMaxMsgHOINDDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgHOIND *pp = (WMaxMsgHOIND *)object; (void)pp;
    switch (field) {
        case 0: pp->setStatus(string2long(value)); return true;
        default: return false;
    }
}

const char *WMaxMsgHOINDDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        "WMaxBSFull",
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *WMaxMsgHOINDDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgHOIND *pp = (WMaxMsgHOIND *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getTarget()); break;
        default: return NULL;
    }
}

Register_Class(WMaxMsgCDMA);

WMaxMsgCDMA::WMaxMsgCDMA(const char *name, int kind) : cPacket(name,kind)
{
    this->code_var = 0;
    this->purpose_var = 0;
}

WMaxMsgCDMA::WMaxMsgCDMA(const WMaxMsgCDMA& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

WMaxMsgCDMA::~WMaxMsgCDMA()
{
}

WMaxMsgCDMA& WMaxMsgCDMA::operator=(const WMaxMsgCDMA& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->code_var = other.code_var;
    this->purpose_var = other.purpose_var;
    return *this;
}

void WMaxMsgCDMA::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->code_var);
    doPacking(b,this->purpose_var);
}

void WMaxMsgCDMA::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->code_var);
    doUnpacking(b,this->purpose_var);
}

int WMaxMsgCDMA::getCode() const
{
    return code_var;
}

void WMaxMsgCDMA::setCode(int code_var)
{
    this->code_var = code_var;
}

int WMaxMsgCDMA::getPurpose() const
{
    return purpose_var;
}

void WMaxMsgCDMA::setPurpose(int purpose_var)
{
    this->purpose_var = purpose_var;
}

class WMaxMsgCDMADescriptor : public cClassDescriptor
{
  public:
    WMaxMsgCDMADescriptor();
    virtual ~WMaxMsgCDMADescriptor();

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

Register_ClassDescriptor(WMaxMsgCDMADescriptor);

WMaxMsgCDMADescriptor::WMaxMsgCDMADescriptor() : cClassDescriptor("WMaxMsgCDMA", "cPacket")
{
}

WMaxMsgCDMADescriptor::~WMaxMsgCDMADescriptor()
{
}

bool WMaxMsgCDMADescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxMsgCDMA *>(obj)!=NULL;
}

const char *WMaxMsgCDMADescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxMsgCDMADescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int WMaxMsgCDMADescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *WMaxMsgCDMADescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "code",
        "purpose",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int WMaxMsgCDMADescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "code")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "purpose")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxMsgCDMADescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *WMaxMsgCDMADescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxMsgCDMADescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgCDMA *pp = (WMaxMsgCDMA *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string WMaxMsgCDMADescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgCDMA *pp = (WMaxMsgCDMA *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getCode());
        case 1: return long2string(pp->getPurpose());
        default: return "";
    }
}

bool WMaxMsgCDMADescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgCDMA *pp = (WMaxMsgCDMA *)object; (void)pp;
    switch (field) {
        case 0: pp->setCode(string2long(value)); return true;
        case 1: pp->setPurpose(string2long(value)); return true;
        default: return false;
    }
}

const char *WMaxMsgCDMADescriptor::getFieldStructName(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *WMaxMsgCDMADescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgCDMA *pp = (WMaxMsgCDMA *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(WMaxMsgBWR);

WMaxMsgBWR::WMaxMsgBWR(const char *name, int kind) : cPacket(name,kind)
{
}

WMaxMsgBWR::WMaxMsgBWR(const WMaxMsgBWR& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

WMaxMsgBWR::~WMaxMsgBWR()
{
}

WMaxMsgBWR& WMaxMsgBWR::operator=(const WMaxMsgBWR& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    return *this;
}

void WMaxMsgBWR::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
}

void WMaxMsgBWR::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
}

class WMaxMsgBWRDescriptor : public cClassDescriptor
{
  public:
    WMaxMsgBWRDescriptor();
    virtual ~WMaxMsgBWRDescriptor();

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

Register_ClassDescriptor(WMaxMsgBWRDescriptor);

WMaxMsgBWRDescriptor::WMaxMsgBWRDescriptor() : cClassDescriptor("WMaxMsgBWR", "cPacket")
{
}

WMaxMsgBWRDescriptor::~WMaxMsgBWRDescriptor()
{
}

bool WMaxMsgBWRDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxMsgBWR *>(obj)!=NULL;
}

const char *WMaxMsgBWRDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxMsgBWRDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int WMaxMsgBWRDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *WMaxMsgBWRDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int WMaxMsgBWRDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxMsgBWRDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *WMaxMsgBWRDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxMsgBWRDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgBWR *pp = (WMaxMsgBWR *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string WMaxMsgBWRDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgBWR *pp = (WMaxMsgBWR *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool WMaxMsgBWRDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgBWR *pp = (WMaxMsgBWR *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *WMaxMsgBWRDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *WMaxMsgBWRDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgBWR *pp = (WMaxMsgBWR *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(WMaxMsgDsaReq);

WMaxMsgDsaReq::WMaxMsgDsaReq(const char *name, int kind) : cPacket(name,kind)
{
    this->transactionID_var = 0;
    qos_arraysize = 0;
    this->qos_var = 0;
    vlanId_arraysize = 0;
    this->vlanId_var = 0;
}

WMaxMsgDsaReq::WMaxMsgDsaReq(const WMaxMsgDsaReq& other) : cPacket()
{
    setName(other.getName());
    qos_arraysize = 0;
    this->qos_var = 0;
    vlanId_arraysize = 0;
    this->vlanId_var = 0;
    operator=(other);
}

WMaxMsgDsaReq::~WMaxMsgDsaReq()
{
    delete [] qos_var;
    delete [] vlanId_var;
}

WMaxMsgDsaReq& WMaxMsgDsaReq::operator=(const WMaxMsgDsaReq& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->transactionID_var = other.transactionID_var;
    delete [] this->qos_var;
    this->qos_var = (other.qos_arraysize==0) ? NULL : new ::WMaxQos[other.qos_arraysize];
    qos_arraysize = other.qos_arraysize;
    for (unsigned int i=0; i<qos_arraysize; i++)
        this->qos_var[i] = other.qos_var[i];
    delete [] this->vlanId_var;
    this->vlanId_var = (other.vlanId_arraysize==0) ? NULL : new int[other.vlanId_arraysize];
    vlanId_arraysize = other.vlanId_arraysize;
    for (unsigned int i=0; i<vlanId_arraysize; i++)
        this->vlanId_var[i] = other.vlanId_var[i];
    return *this;
}

void WMaxMsgDsaReq::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->transactionID_var);
    b->pack(qos_arraysize);
    doPacking(b,this->qos_var,qos_arraysize);
    b->pack(vlanId_arraysize);
    doPacking(b,this->vlanId_var,vlanId_arraysize);
}

void WMaxMsgDsaReq::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->transactionID_var);
    delete [] this->qos_var;
    b->unpack(qos_arraysize);
    if (qos_arraysize==0) {
        this->qos_var = 0;
    } else {
        this->qos_var = new ::WMaxQos[qos_arraysize];
        doUnpacking(b,this->qos_var,qos_arraysize);
    }
    delete [] this->vlanId_var;
    b->unpack(vlanId_arraysize);
    if (vlanId_arraysize==0) {
        this->vlanId_var = 0;
    } else {
        this->vlanId_var = new int[vlanId_arraysize];
        doUnpacking(b,this->vlanId_var,vlanId_arraysize);
    }
}

int WMaxMsgDsaReq::getTransactionID() const
{
    return transactionID_var;
}

void WMaxMsgDsaReq::setTransactionID(int transactionID_var)
{
    this->transactionID_var = transactionID_var;
}

void WMaxMsgDsaReq::setQosArraySize(unsigned int size)
{
    ::WMaxQos *qos_var2 = (size==0) ? NULL : new ::WMaxQos[size];
    unsigned int sz = qos_arraysize < size ? qos_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        qos_var2[i] = this->qos_var[i];
    qos_arraysize = size;
    delete [] this->qos_var;
    this->qos_var = qos_var2;
}

unsigned int WMaxMsgDsaReq::getQosArraySize() const
{
    return qos_arraysize;
}

WMaxQos& WMaxMsgDsaReq::getQos(unsigned int k)
{
    if (k>=qos_arraysize) throw cRuntimeError("Array of size %d indexed by %d", qos_arraysize, k);
    return qos_var[k];
}

void WMaxMsgDsaReq::setQos(unsigned int k, const WMaxQos& qos_var)
{
    if (k>=qos_arraysize) throw cRuntimeError("Array of size %d indexed by %d", qos_arraysize, k);
    this->qos_var[k]=qos_var;
}

void WMaxMsgDsaReq::setVlanIdArraySize(unsigned int size)
{
    int *vlanId_var2 = (size==0) ? NULL : new int[size];
    unsigned int sz = vlanId_arraysize < size ? vlanId_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        vlanId_var2[i] = this->vlanId_var[i];
    for (unsigned int i=sz; i<size; i++)
        vlanId_var2[i] = 0;
    vlanId_arraysize = size;
    delete [] this->vlanId_var;
    this->vlanId_var = vlanId_var2;
}

unsigned int WMaxMsgDsaReq::getVlanIdArraySize() const
{
    return vlanId_arraysize;
}

int WMaxMsgDsaReq::getVlanId(unsigned int k) const
{
    if (k>=vlanId_arraysize) throw cRuntimeError("Array of size %d indexed by %d", vlanId_arraysize, k);
    return vlanId_var[k];
}

void WMaxMsgDsaReq::setVlanId(unsigned int k, int vlanId_var)
{
    if (k>=vlanId_arraysize) throw cRuntimeError("Array of size %d indexed by %d", vlanId_arraysize, k);
    this->vlanId_var[k]=vlanId_var;
}

class WMaxMsgDsaReqDescriptor : public cClassDescriptor
{
  public:
    WMaxMsgDsaReqDescriptor();
    virtual ~WMaxMsgDsaReqDescriptor();

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

Register_ClassDescriptor(WMaxMsgDsaReqDescriptor);

WMaxMsgDsaReqDescriptor::WMaxMsgDsaReqDescriptor() : cClassDescriptor("WMaxMsgDsaReq", "cPacket")
{
}

WMaxMsgDsaReqDescriptor::~WMaxMsgDsaReqDescriptor()
{
}

bool WMaxMsgDsaReqDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxMsgDsaReq *>(obj)!=NULL;
}

const char *WMaxMsgDsaReqDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxMsgDsaReqDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int WMaxMsgDsaReqDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *WMaxMsgDsaReqDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "transactionID",
        "qos",
        "vlanId",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int WMaxMsgDsaReqDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "transactionID")==0) return base+0;
    if (fieldName[0]=='q' && strcmp(fieldName, "qos")==0) return base+1;
    if (fieldName[0]=='v' && strcmp(fieldName, "vlanId")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxMsgDsaReqDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "WMaxQos",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *WMaxMsgDsaReqDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxMsgDsaReqDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgDsaReq *pp = (WMaxMsgDsaReq *)object; (void)pp;
    switch (field) {
        case 1: return pp->getQosArraySize();
        case 2: return pp->getVlanIdArraySize();
        default: return 0;
    }
}

std::string WMaxMsgDsaReqDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgDsaReq *pp = (WMaxMsgDsaReq *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getTransactionID());
        case 1: {std::stringstream out; out << pp->getQos(i); return out.str();}
        case 2: return long2string(pp->getVlanId(i));
        default: return "";
    }
}

bool WMaxMsgDsaReqDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgDsaReq *pp = (WMaxMsgDsaReq *)object; (void)pp;
    switch (field) {
        case 0: pp->setTransactionID(string2long(value)); return true;
        case 2: pp->setVlanId(i,string2long(value)); return true;
        default: return false;
    }
}

const char *WMaxMsgDsaReqDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        "WMaxQos",
        NULL,
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *WMaxMsgDsaReqDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgDsaReq *pp = (WMaxMsgDsaReq *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getQos(i)); break;
        default: return NULL;
    }
}

Register_Class(WMaxMsgDsxRvd);

WMaxMsgDsxRvd::WMaxMsgDsxRvd(const char *name, int kind) : cPacket(name,kind)
{
    this->transactionID_var = 0;
    this->confirmationCode_var = 0;
}

WMaxMsgDsxRvd::WMaxMsgDsxRvd(const WMaxMsgDsxRvd& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

WMaxMsgDsxRvd::~WMaxMsgDsxRvd()
{
}

WMaxMsgDsxRvd& WMaxMsgDsxRvd::operator=(const WMaxMsgDsxRvd& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->transactionID_var = other.transactionID_var;
    this->confirmationCode_var = other.confirmationCode_var;
    return *this;
}

void WMaxMsgDsxRvd::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->transactionID_var);
    doPacking(b,this->confirmationCode_var);
}

void WMaxMsgDsxRvd::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->transactionID_var);
    doUnpacking(b,this->confirmationCode_var);
}

int WMaxMsgDsxRvd::getTransactionID() const
{
    return transactionID_var;
}

void WMaxMsgDsxRvd::setTransactionID(int transactionID_var)
{
    this->transactionID_var = transactionID_var;
}

int WMaxMsgDsxRvd::getConfirmationCode() const
{
    return confirmationCode_var;
}

void WMaxMsgDsxRvd::setConfirmationCode(int confirmationCode_var)
{
    this->confirmationCode_var = confirmationCode_var;
}

class WMaxMsgDsxRvdDescriptor : public cClassDescriptor
{
  public:
    WMaxMsgDsxRvdDescriptor();
    virtual ~WMaxMsgDsxRvdDescriptor();

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

Register_ClassDescriptor(WMaxMsgDsxRvdDescriptor);

WMaxMsgDsxRvdDescriptor::WMaxMsgDsxRvdDescriptor() : cClassDescriptor("WMaxMsgDsxRvd", "cPacket")
{
}

WMaxMsgDsxRvdDescriptor::~WMaxMsgDsxRvdDescriptor()
{
}

bool WMaxMsgDsxRvdDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxMsgDsxRvd *>(obj)!=NULL;
}

const char *WMaxMsgDsxRvdDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxMsgDsxRvdDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int WMaxMsgDsxRvdDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *WMaxMsgDsxRvdDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "transactionID",
        "confirmationCode",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int WMaxMsgDsxRvdDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "transactionID")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "confirmationCode")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxMsgDsxRvdDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *WMaxMsgDsxRvdDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxMsgDsxRvdDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgDsxRvd *pp = (WMaxMsgDsxRvd *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string WMaxMsgDsxRvdDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgDsxRvd *pp = (WMaxMsgDsxRvd *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getTransactionID());
        case 1: return long2string(pp->getConfirmationCode());
        default: return "";
    }
}

bool WMaxMsgDsxRvdDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgDsxRvd *pp = (WMaxMsgDsxRvd *)object; (void)pp;
    switch (field) {
        case 0: pp->setTransactionID(string2long(value)); return true;
        case 1: pp->setConfirmationCode(string2long(value)); return true;
        default: return false;
    }
}

const char *WMaxMsgDsxRvdDescriptor::getFieldStructName(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *WMaxMsgDsxRvdDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgDsxRvd *pp = (WMaxMsgDsxRvd *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(WMaxMsgDsaRsp);

WMaxMsgDsaRsp::WMaxMsgDsaRsp(const char *name, int kind) : cPacket(name,kind)
{
    this->transactionID_var = 0;
    this->confirmationCode_var = 0;
    qos_arraysize = 0;
    this->qos_var = 0;
    this->cid_var = 0;
}

WMaxMsgDsaRsp::WMaxMsgDsaRsp(const WMaxMsgDsaRsp& other) : cPacket()
{
    setName(other.getName());
    qos_arraysize = 0;
    this->qos_var = 0;
    operator=(other);
}

WMaxMsgDsaRsp::~WMaxMsgDsaRsp()
{
    delete [] qos_var;
}

WMaxMsgDsaRsp& WMaxMsgDsaRsp::operator=(const WMaxMsgDsaRsp& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->transactionID_var = other.transactionID_var;
    this->confirmationCode_var = other.confirmationCode_var;
    delete [] this->qos_var;
    this->qos_var = (other.qos_arraysize==0) ? NULL : new ::WMaxQos[other.qos_arraysize];
    qos_arraysize = other.qos_arraysize;
    for (unsigned int i=0; i<qos_arraysize; i++)
        this->qos_var[i] = other.qos_var[i];
    this->cid_var = other.cid_var;
    return *this;
}

void WMaxMsgDsaRsp::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->transactionID_var);
    doPacking(b,this->confirmationCode_var);
    b->pack(qos_arraysize);
    doPacking(b,this->qos_var,qos_arraysize);
    doPacking(b,this->cid_var);
}

void WMaxMsgDsaRsp::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->transactionID_var);
    doUnpacking(b,this->confirmationCode_var);
    delete [] this->qos_var;
    b->unpack(qos_arraysize);
    if (qos_arraysize==0) {
        this->qos_var = 0;
    } else {
        this->qos_var = new ::WMaxQos[qos_arraysize];
        doUnpacking(b,this->qos_var,qos_arraysize);
    }
    doUnpacking(b,this->cid_var);
}

int WMaxMsgDsaRsp::getTransactionID() const
{
    return transactionID_var;
}

void WMaxMsgDsaRsp::setTransactionID(int transactionID_var)
{
    this->transactionID_var = transactionID_var;
}

int WMaxMsgDsaRsp::getConfirmationCode() const
{
    return confirmationCode_var;
}

void WMaxMsgDsaRsp::setConfirmationCode(int confirmationCode_var)
{
    this->confirmationCode_var = confirmationCode_var;
}

void WMaxMsgDsaRsp::setQosArraySize(unsigned int size)
{
    ::WMaxQos *qos_var2 = (size==0) ? NULL : new ::WMaxQos[size];
    unsigned int sz = qos_arraysize < size ? qos_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        qos_var2[i] = this->qos_var[i];
    qos_arraysize = size;
    delete [] this->qos_var;
    this->qos_var = qos_var2;
}

unsigned int WMaxMsgDsaRsp::getQosArraySize() const
{
    return qos_arraysize;
}

WMaxQos& WMaxMsgDsaRsp::getQos(unsigned int k)
{
    if (k>=qos_arraysize) throw cRuntimeError("Array of size %d indexed by %d", qos_arraysize, k);
    return qos_var[k];
}

void WMaxMsgDsaRsp::setQos(unsigned int k, const WMaxQos& qos_var)
{
    if (k>=qos_arraysize) throw cRuntimeError("Array of size %d indexed by %d", qos_arraysize, k);
    this->qos_var[k]=qos_var;
}

int WMaxMsgDsaRsp::getCid() const
{
    return cid_var;
}

void WMaxMsgDsaRsp::setCid(int cid_var)
{
    this->cid_var = cid_var;
}

class WMaxMsgDsaRspDescriptor : public cClassDescriptor
{
  public:
    WMaxMsgDsaRspDescriptor();
    virtual ~WMaxMsgDsaRspDescriptor();

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

Register_ClassDescriptor(WMaxMsgDsaRspDescriptor);

WMaxMsgDsaRspDescriptor::WMaxMsgDsaRspDescriptor() : cClassDescriptor("WMaxMsgDsaRsp", "cPacket")
{
}

WMaxMsgDsaRspDescriptor::~WMaxMsgDsaRspDescriptor()
{
}

bool WMaxMsgDsaRspDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxMsgDsaRsp *>(obj)!=NULL;
}

const char *WMaxMsgDsaRspDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxMsgDsaRspDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int WMaxMsgDsaRspDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *WMaxMsgDsaRspDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "transactionID",
        "confirmationCode",
        "qos",
        "cid",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int WMaxMsgDsaRspDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "transactionID")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "confirmationCode")==0) return base+1;
    if (fieldName[0]=='q' && strcmp(fieldName, "qos")==0) return base+2;
    if (fieldName[0]=='c' && strcmp(fieldName, "cid")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxMsgDsaRspDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "WMaxQos",
        "int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *WMaxMsgDsaRspDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxMsgDsaRspDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgDsaRsp *pp = (WMaxMsgDsaRsp *)object; (void)pp;
    switch (field) {
        case 2: return pp->getQosArraySize();
        default: return 0;
    }
}

std::string WMaxMsgDsaRspDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgDsaRsp *pp = (WMaxMsgDsaRsp *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getTransactionID());
        case 1: return long2string(pp->getConfirmationCode());
        case 2: {std::stringstream out; out << pp->getQos(i); return out.str();}
        case 3: return long2string(pp->getCid());
        default: return "";
    }
}

bool WMaxMsgDsaRspDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgDsaRsp *pp = (WMaxMsgDsaRsp *)object; (void)pp;
    switch (field) {
        case 0: pp->setTransactionID(string2long(value)); return true;
        case 1: pp->setConfirmationCode(string2long(value)); return true;
        case 3: pp->setCid(string2long(value)); return true;
        default: return false;
    }
}

const char *WMaxMsgDsaRspDescriptor::getFieldStructName(void *object, int field) const
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
        "WMaxQos",
        NULL,
    };
    return (field>=0 && field<4) ? fieldStructNames[field] : NULL;
}

void *WMaxMsgDsaRspDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgDsaRsp *pp = (WMaxMsgDsaRsp *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getQos(i)); break;
        default: return NULL;
    }
}

Register_Class(WMaxMsgDsaAck);

WMaxMsgDsaAck::WMaxMsgDsaAck(const char *name, int kind) : cPacket(name,kind)
{
    this->transactionID_var = 0;
    this->confirmationCode_var = 0;
    qos_arraysize = 0;
    this->qos_var = 0;
}

WMaxMsgDsaAck::WMaxMsgDsaAck(const WMaxMsgDsaAck& other) : cPacket()
{
    setName(other.getName());
    qos_arraysize = 0;
    this->qos_var = 0;
    operator=(other);
}

WMaxMsgDsaAck::~WMaxMsgDsaAck()
{
    delete [] qos_var;
}

WMaxMsgDsaAck& WMaxMsgDsaAck::operator=(const WMaxMsgDsaAck& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->transactionID_var = other.transactionID_var;
    this->confirmationCode_var = other.confirmationCode_var;
    delete [] this->qos_var;
    this->qos_var = (other.qos_arraysize==0) ? NULL : new ::WMaxQos[other.qos_arraysize];
    qos_arraysize = other.qos_arraysize;
    for (unsigned int i=0; i<qos_arraysize; i++)
        this->qos_var[i] = other.qos_var[i];
    return *this;
}

void WMaxMsgDsaAck::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->transactionID_var);
    doPacking(b,this->confirmationCode_var);
    b->pack(qos_arraysize);
    doPacking(b,this->qos_var,qos_arraysize);
}

void WMaxMsgDsaAck::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->transactionID_var);
    doUnpacking(b,this->confirmationCode_var);
    delete [] this->qos_var;
    b->unpack(qos_arraysize);
    if (qos_arraysize==0) {
        this->qos_var = 0;
    } else {
        this->qos_var = new ::WMaxQos[qos_arraysize];
        doUnpacking(b,this->qos_var,qos_arraysize);
    }
}

int WMaxMsgDsaAck::getTransactionID() const
{
    return transactionID_var;
}

void WMaxMsgDsaAck::setTransactionID(int transactionID_var)
{
    this->transactionID_var = transactionID_var;
}

int WMaxMsgDsaAck::getConfirmationCode() const
{
    return confirmationCode_var;
}

void WMaxMsgDsaAck::setConfirmationCode(int confirmationCode_var)
{
    this->confirmationCode_var = confirmationCode_var;
}

void WMaxMsgDsaAck::setQosArraySize(unsigned int size)
{
    ::WMaxQos *qos_var2 = (size==0) ? NULL : new ::WMaxQos[size];
    unsigned int sz = qos_arraysize < size ? qos_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        qos_var2[i] = this->qos_var[i];
    qos_arraysize = size;
    delete [] this->qos_var;
    this->qos_var = qos_var2;
}

unsigned int WMaxMsgDsaAck::getQosArraySize() const
{
    return qos_arraysize;
}

WMaxQos& WMaxMsgDsaAck::getQos(unsigned int k)
{
    if (k>=qos_arraysize) throw cRuntimeError("Array of size %d indexed by %d", qos_arraysize, k);
    return qos_var[k];
}

void WMaxMsgDsaAck::setQos(unsigned int k, const WMaxQos& qos_var)
{
    if (k>=qos_arraysize) throw cRuntimeError("Array of size %d indexed by %d", qos_arraysize, k);
    this->qos_var[k]=qos_var;
}

class WMaxMsgDsaAckDescriptor : public cClassDescriptor
{
  public:
    WMaxMsgDsaAckDescriptor();
    virtual ~WMaxMsgDsaAckDescriptor();

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

Register_ClassDescriptor(WMaxMsgDsaAckDescriptor);

WMaxMsgDsaAckDescriptor::WMaxMsgDsaAckDescriptor() : cClassDescriptor("WMaxMsgDsaAck", "cPacket")
{
}

WMaxMsgDsaAckDescriptor::~WMaxMsgDsaAckDescriptor()
{
}

bool WMaxMsgDsaAckDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxMsgDsaAck *>(obj)!=NULL;
}

const char *WMaxMsgDsaAckDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxMsgDsaAckDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int WMaxMsgDsaAckDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *WMaxMsgDsaAckDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "transactionID",
        "confirmationCode",
        "qos",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int WMaxMsgDsaAckDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "transactionID")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "confirmationCode")==0) return base+1;
    if (fieldName[0]=='q' && strcmp(fieldName, "qos")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxMsgDsaAckDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "WMaxQos",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *WMaxMsgDsaAckDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxMsgDsaAckDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgDsaAck *pp = (WMaxMsgDsaAck *)object; (void)pp;
    switch (field) {
        case 2: return pp->getQosArraySize();
        default: return 0;
    }
}

std::string WMaxMsgDsaAckDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgDsaAck *pp = (WMaxMsgDsaAck *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getTransactionID());
        case 1: return long2string(pp->getConfirmationCode());
        case 2: {std::stringstream out; out << pp->getQos(i); return out.str();}
        default: return "";
    }
}

bool WMaxMsgDsaAckDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgDsaAck *pp = (WMaxMsgDsaAck *)object; (void)pp;
    switch (field) {
        case 0: pp->setTransactionID(string2long(value)); return true;
        case 1: pp->setConfirmationCode(string2long(value)); return true;
        default: return false;
    }
}

const char *WMaxMsgDsaAckDescriptor::getFieldStructName(void *object, int field) const
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
        "WMaxQos",
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *WMaxMsgDsaAckDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMsgDsaAck *pp = (WMaxMsgDsaAck *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getQos(i)); break;
        default: return NULL;
    }
}

Register_Class(WMaxPhyDummyFrameStart);

WMaxPhyDummyFrameStart::WMaxPhyDummyFrameStart(const char *name, int kind) : cPacket(name,kind)
{
}

WMaxPhyDummyFrameStart::WMaxPhyDummyFrameStart(const WMaxPhyDummyFrameStart& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

WMaxPhyDummyFrameStart::~WMaxPhyDummyFrameStart()
{
}

WMaxPhyDummyFrameStart& WMaxPhyDummyFrameStart::operator=(const WMaxPhyDummyFrameStart& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    return *this;
}

void WMaxPhyDummyFrameStart::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
}

void WMaxPhyDummyFrameStart::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
}

class WMaxPhyDummyFrameStartDescriptor : public cClassDescriptor
{
  public:
    WMaxPhyDummyFrameStartDescriptor();
    virtual ~WMaxPhyDummyFrameStartDescriptor();

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

Register_ClassDescriptor(WMaxPhyDummyFrameStartDescriptor);

WMaxPhyDummyFrameStartDescriptor::WMaxPhyDummyFrameStartDescriptor() : cClassDescriptor("WMaxPhyDummyFrameStart", "cPacket")
{
}

WMaxPhyDummyFrameStartDescriptor::~WMaxPhyDummyFrameStartDescriptor()
{
}

bool WMaxPhyDummyFrameStartDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxPhyDummyFrameStart *>(obj)!=NULL;
}

const char *WMaxPhyDummyFrameStartDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxPhyDummyFrameStartDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int WMaxPhyDummyFrameStartDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *WMaxPhyDummyFrameStartDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int WMaxPhyDummyFrameStartDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxPhyDummyFrameStartDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *WMaxPhyDummyFrameStartDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxPhyDummyFrameStartDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxPhyDummyFrameStart *pp = (WMaxPhyDummyFrameStart *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string WMaxPhyDummyFrameStartDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxPhyDummyFrameStart *pp = (WMaxPhyDummyFrameStart *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool WMaxPhyDummyFrameStartDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxPhyDummyFrameStart *pp = (WMaxPhyDummyFrameStart *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *WMaxPhyDummyFrameStartDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *WMaxPhyDummyFrameStartDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxPhyDummyFrameStart *pp = (WMaxPhyDummyFrameStart *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(WMaxEvent_FlowCreationStart);

WMaxEvent_FlowCreationStart::WMaxEvent_FlowCreationStart(const char *name, int kind) : cPacket(name,kind)
{
    this->skipDSA_var = 0;
    this->gateIndex_var = 0;
    this->srvName_var = 0;
    qos_arraysize = 0;
    this->qos_var = 0;
}

WMaxEvent_FlowCreationStart::WMaxEvent_FlowCreationStart(const WMaxEvent_FlowCreationStart& other) : cPacket()
{
    setName(other.getName());
    qos_arraysize = 0;
    this->qos_var = 0;
    operator=(other);
}

WMaxEvent_FlowCreationStart::~WMaxEvent_FlowCreationStart()
{
    delete [] qos_var;
}

WMaxEvent_FlowCreationStart& WMaxEvent_FlowCreationStart::operator=(const WMaxEvent_FlowCreationStart& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->skipDSA_var = other.skipDSA_var;
    this->gateIndex_var = other.gateIndex_var;
    this->srvName_var = other.srvName_var;
    delete [] this->qos_var;
    this->qos_var = (other.qos_arraysize==0) ? NULL : new ::WMaxQos[other.qos_arraysize];
    qos_arraysize = other.qos_arraysize;
    for (unsigned int i=0; i<qos_arraysize; i++)
        this->qos_var[i] = other.qos_var[i];
    return *this;
}

void WMaxEvent_FlowCreationStart::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->skipDSA_var);
    doPacking(b,this->gateIndex_var);
    doPacking(b,this->srvName_var);
    b->pack(qos_arraysize);
    doPacking(b,this->qos_var,qos_arraysize);
}

void WMaxEvent_FlowCreationStart::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->skipDSA_var);
    doUnpacking(b,this->gateIndex_var);
    doUnpacking(b,this->srvName_var);
    delete [] this->qos_var;
    b->unpack(qos_arraysize);
    if (qos_arraysize==0) {
        this->qos_var = 0;
    } else {
        this->qos_var = new ::WMaxQos[qos_arraysize];
        doUnpacking(b,this->qos_var,qos_arraysize);
    }
}

int WMaxEvent_FlowCreationStart::getSkipDSA() const
{
    return skipDSA_var;
}

void WMaxEvent_FlowCreationStart::setSkipDSA(int skipDSA_var)
{
    this->skipDSA_var = skipDSA_var;
}

int WMaxEvent_FlowCreationStart::getGateIndex() const
{
    return gateIndex_var;
}

void WMaxEvent_FlowCreationStart::setGateIndex(int gateIndex_var)
{
    this->gateIndex_var = gateIndex_var;
}

const char * WMaxEvent_FlowCreationStart::getSrvName() const
{
    return srvName_var.c_str();
}

void WMaxEvent_FlowCreationStart::setSrvName(const char * srvName_var)
{
    this->srvName_var = srvName_var;
}

void WMaxEvent_FlowCreationStart::setQosArraySize(unsigned int size)
{
    ::WMaxQos *qos_var2 = (size==0) ? NULL : new ::WMaxQos[size];
    unsigned int sz = qos_arraysize < size ? qos_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        qos_var2[i] = this->qos_var[i];
    qos_arraysize = size;
    delete [] this->qos_var;
    this->qos_var = qos_var2;
}

unsigned int WMaxEvent_FlowCreationStart::getQosArraySize() const
{
    return qos_arraysize;
}

WMaxQos& WMaxEvent_FlowCreationStart::getQos(unsigned int k)
{
    if (k>=qos_arraysize) throw cRuntimeError("Array of size %d indexed by %d", qos_arraysize, k);
    return qos_var[k];
}

void WMaxEvent_FlowCreationStart::setQos(unsigned int k, const WMaxQos& qos_var)
{
    if (k>=qos_arraysize) throw cRuntimeError("Array of size %d indexed by %d", qos_arraysize, k);
    this->qos_var[k]=qos_var;
}

class WMaxEvent_FlowCreationStartDescriptor : public cClassDescriptor
{
  public:
    WMaxEvent_FlowCreationStartDescriptor();
    virtual ~WMaxEvent_FlowCreationStartDescriptor();

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

Register_ClassDescriptor(WMaxEvent_FlowCreationStartDescriptor);

WMaxEvent_FlowCreationStartDescriptor::WMaxEvent_FlowCreationStartDescriptor() : cClassDescriptor("WMaxEvent_FlowCreationStart", "cPacket")
{
}

WMaxEvent_FlowCreationStartDescriptor::~WMaxEvent_FlowCreationStartDescriptor()
{
}

bool WMaxEvent_FlowCreationStartDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxEvent_FlowCreationStart *>(obj)!=NULL;
}

const char *WMaxEvent_FlowCreationStartDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxEvent_FlowCreationStartDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int WMaxEvent_FlowCreationStartDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *WMaxEvent_FlowCreationStartDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "skipDSA",
        "gateIndex",
        "srvName",
        "qos",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int WMaxEvent_FlowCreationStartDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "skipDSA")==0) return base+0;
    if (fieldName[0]=='g' && strcmp(fieldName, "gateIndex")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "srvName")==0) return base+2;
    if (fieldName[0]=='q' && strcmp(fieldName, "qos")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxEvent_FlowCreationStartDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "string",
        "WMaxQos",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *WMaxEvent_FlowCreationStartDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxEvent_FlowCreationStartDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxEvent_FlowCreationStart *pp = (WMaxEvent_FlowCreationStart *)object; (void)pp;
    switch (field) {
        case 3: return pp->getQosArraySize();
        default: return 0;
    }
}

std::string WMaxEvent_FlowCreationStartDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxEvent_FlowCreationStart *pp = (WMaxEvent_FlowCreationStart *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSkipDSA());
        case 1: return long2string(pp->getGateIndex());
        case 2: return oppstring2string(pp->getSrvName());
        case 3: {std::stringstream out; out << pp->getQos(i); return out.str();}
        default: return "";
    }
}

bool WMaxEvent_FlowCreationStartDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxEvent_FlowCreationStart *pp = (WMaxEvent_FlowCreationStart *)object; (void)pp;
    switch (field) {
        case 0: pp->setSkipDSA(string2long(value)); return true;
        case 1: pp->setGateIndex(string2long(value)); return true;
        case 2: pp->setSrvName((value)); return true;
        default: return false;
    }
}

const char *WMaxEvent_FlowCreationStartDescriptor::getFieldStructName(void *object, int field) const
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
        "WMaxQos",
    };
    return (field>=0 && field<4) ? fieldStructNames[field] : NULL;
}

void *WMaxEvent_FlowCreationStartDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxEvent_FlowCreationStart *pp = (WMaxEvent_FlowCreationStart *)object; (void)pp;
    switch (field) {
        case 3: return (void *)(&pp->getQos(i)); break;
        default: return NULL;
    }
}

Register_Class(WMaxMacAddConn);

WMaxMacAddConn::WMaxMacAddConn(const char *name, int kind) : cPacket(name,kind)
{
    this->gateIndex_var = 0;
    this->cid_var = 0;
    this->srvName_var = 0;
    qos_arraysize = 0;
    this->qos_var = 0;
    vlanId_arraysize = 0;
    this->vlanId_var = 0;
    this->macAddr_var = 0;
}

WMaxMacAddConn::WMaxMacAddConn(const WMaxMacAddConn& other) : cPacket()
{
    setName(other.getName());
    qos_arraysize = 0;
    this->qos_var = 0;
    vlanId_arraysize = 0;
    this->vlanId_var = 0;
    operator=(other);
}

WMaxMacAddConn::~WMaxMacAddConn()
{
    delete [] qos_var;
    delete [] vlanId_var;
}

WMaxMacAddConn& WMaxMacAddConn::operator=(const WMaxMacAddConn& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->gateIndex_var = other.gateIndex_var;
    this->cid_var = other.cid_var;
    this->srvName_var = other.srvName_var;
    delete [] this->qos_var;
    this->qos_var = (other.qos_arraysize==0) ? NULL : new ::WMaxQos[other.qos_arraysize];
    qos_arraysize = other.qos_arraysize;
    for (unsigned int i=0; i<qos_arraysize; i++)
        this->qos_var[i] = other.qos_var[i];
    delete [] this->vlanId_var;
    this->vlanId_var = (other.vlanId_arraysize==0) ? NULL : new int[other.vlanId_arraysize];
    vlanId_arraysize = other.vlanId_arraysize;
    for (unsigned int i=0; i<vlanId_arraysize; i++)
        this->vlanId_var[i] = other.vlanId_var[i];
    this->dstAddr_var = other.dstAddr_var;
    this->macAddr_var = other.macAddr_var;
    return *this;
}

void WMaxMacAddConn::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->gateIndex_var);
    doPacking(b,this->cid_var);
    doPacking(b,this->srvName_var);
    b->pack(qos_arraysize);
    doPacking(b,this->qos_var,qos_arraysize);
    b->pack(vlanId_arraysize);
    doPacking(b,this->vlanId_var,vlanId_arraysize);
    doPacking(b,this->dstAddr_var);
    doPacking(b,this->macAddr_var);
}

void WMaxMacAddConn::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->gateIndex_var);
    doUnpacking(b,this->cid_var);
    doUnpacking(b,this->srvName_var);
    delete [] this->qos_var;
    b->unpack(qos_arraysize);
    if (qos_arraysize==0) {
        this->qos_var = 0;
    } else {
        this->qos_var = new ::WMaxQos[qos_arraysize];
        doUnpacking(b,this->qos_var,qos_arraysize);
    }
    delete [] this->vlanId_var;
    b->unpack(vlanId_arraysize);
    if (vlanId_arraysize==0) {
        this->vlanId_var = 0;
    } else {
        this->vlanId_var = new int[vlanId_arraysize];
        doUnpacking(b,this->vlanId_var,vlanId_arraysize);
    }
    doUnpacking(b,this->dstAddr_var);
    doUnpacking(b,this->macAddr_var);
}

int WMaxMacAddConn::getGateIndex() const
{
    return gateIndex_var;
}

void WMaxMacAddConn::setGateIndex(int gateIndex_var)
{
    this->gateIndex_var = gateIndex_var;
}

int WMaxMacAddConn::getCid() const
{
    return cid_var;
}

void WMaxMacAddConn::setCid(int cid_var)
{
    this->cid_var = cid_var;
}

const char * WMaxMacAddConn::getSrvName() const
{
    return srvName_var.c_str();
}

void WMaxMacAddConn::setSrvName(const char * srvName_var)
{
    this->srvName_var = srvName_var;
}

void WMaxMacAddConn::setQosArraySize(unsigned int size)
{
    ::WMaxQos *qos_var2 = (size==0) ? NULL : new ::WMaxQos[size];
    unsigned int sz = qos_arraysize < size ? qos_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        qos_var2[i] = this->qos_var[i];
    qos_arraysize = size;
    delete [] this->qos_var;
    this->qos_var = qos_var2;
}

unsigned int WMaxMacAddConn::getQosArraySize() const
{
    return qos_arraysize;
}

WMaxQos& WMaxMacAddConn::getQos(unsigned int k)
{
    if (k>=qos_arraysize) throw cRuntimeError("Array of size %d indexed by %d", qos_arraysize, k);
    return qos_var[k];
}

void WMaxMacAddConn::setQos(unsigned int k, const WMaxQos& qos_var)
{
    if (k>=qos_arraysize) throw cRuntimeError("Array of size %d indexed by %d", qos_arraysize, k);
    this->qos_var[k]=qos_var;
}

void WMaxMacAddConn::setVlanIdArraySize(unsigned int size)
{
    int *vlanId_var2 = (size==0) ? NULL : new int[size];
    unsigned int sz = vlanId_arraysize < size ? vlanId_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        vlanId_var2[i] = this->vlanId_var[i];
    for (unsigned int i=sz; i<size; i++)
        vlanId_var2[i] = 0;
    vlanId_arraysize = size;
    delete [] this->vlanId_var;
    this->vlanId_var = vlanId_var2;
}

unsigned int WMaxMacAddConn::getVlanIdArraySize() const
{
    return vlanId_arraysize;
}

int WMaxMacAddConn::getVlanId(unsigned int k) const
{
    if (k>=vlanId_arraysize) throw cRuntimeError("Array of size %d indexed by %d", vlanId_arraysize, k);
    return vlanId_var[k];
}

void WMaxMacAddConn::setVlanId(unsigned int k, int vlanId_var)
{
    if (k>=vlanId_arraysize) throw cRuntimeError("Array of size %d indexed by %d", vlanId_arraysize, k);
    this->vlanId_var[k]=vlanId_var;
}

IPv6Addr& WMaxMacAddConn::getDstAddr()
{
    return dstAddr_var;
}

void WMaxMacAddConn::setDstAddr(const IPv6Addr& dstAddr_var)
{
    this->dstAddr_var = dstAddr_var;
}

uint64_t WMaxMacAddConn::getMacAddr() const
{
    return macAddr_var;
}

void WMaxMacAddConn::setMacAddr(uint64_t macAddr_var)
{
    this->macAddr_var = macAddr_var;
}

class WMaxMacAddConnDescriptor : public cClassDescriptor
{
  public:
    WMaxMacAddConnDescriptor();
    virtual ~WMaxMacAddConnDescriptor();

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

Register_ClassDescriptor(WMaxMacAddConnDescriptor);

WMaxMacAddConnDescriptor::WMaxMacAddConnDescriptor() : cClassDescriptor("WMaxMacAddConn", "cPacket")
{
}

WMaxMacAddConnDescriptor::~WMaxMacAddConnDescriptor()
{
}

bool WMaxMacAddConnDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxMacAddConn *>(obj)!=NULL;
}

const char *WMaxMacAddConnDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxMacAddConnDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int WMaxMacAddConnDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *WMaxMacAddConnDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "gateIndex",
        "cid",
        "srvName",
        "qos",
        "vlanId",
        "dstAddr",
        "macAddr",
    };
    return (field>=0 && field<7) ? fieldNames[field] : NULL;
}

int WMaxMacAddConnDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='g' && strcmp(fieldName, "gateIndex")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "cid")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "srvName")==0) return base+2;
    if (fieldName[0]=='q' && strcmp(fieldName, "qos")==0) return base+3;
    if (fieldName[0]=='v' && strcmp(fieldName, "vlanId")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "dstAddr")==0) return base+5;
    if (fieldName[0]=='m' && strcmp(fieldName, "macAddr")==0) return base+6;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxMacAddConnDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "string",
        "WMaxQos",
        "int",
        "IPv6Addr",
        "uint64_t",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : NULL;
}

const char *WMaxMacAddConnDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxMacAddConnDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMacAddConn *pp = (WMaxMacAddConn *)object; (void)pp;
    switch (field) {
        case 3: return pp->getQosArraySize();
        case 4: return pp->getVlanIdArraySize();
        default: return 0;
    }
}

std::string WMaxMacAddConnDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMacAddConn *pp = (WMaxMacAddConn *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getGateIndex());
        case 1: return long2string(pp->getCid());
        case 2: return oppstring2string(pp->getSrvName());
        case 3: {std::stringstream out; out << pp->getQos(i); return out.str();}
        case 4: return long2string(pp->getVlanId(i));
        case 5: {std::stringstream out; out << pp->getDstAddr(); return out.str();}
        case 6: return uint642string(pp->getMacAddr());
        default: return "";
    }
}

bool WMaxMacAddConnDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMacAddConn *pp = (WMaxMacAddConn *)object; (void)pp;
    switch (field) {
        case 0: pp->setGateIndex(string2long(value)); return true;
        case 1: pp->setCid(string2long(value)); return true;
        case 2: pp->setSrvName((value)); return true;
        case 4: pp->setVlanId(i,string2long(value)); return true;
        case 6: pp->setMacAddr(string2uint64(value)); return true;
        default: return false;
    }
}

const char *WMaxMacAddConnDescriptor::getFieldStructName(void *object, int field) const
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
        "WMaxQos",
        NULL,
        "IPv6Addr",
        NULL,
    };
    return (field>=0 && field<7) ? fieldStructNames[field] : NULL;
}

void *WMaxMacAddConnDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMacAddConn *pp = (WMaxMacAddConn *)object; (void)pp;
    switch (field) {
        case 3: return (void *)(&pp->getQos(i)); break;
        case 5: return (void *)(&pp->getDstAddr()); break;
        default: return NULL;
    }
}

Register_Class(WMaxMacAddMngmntConn);

WMaxMacAddMngmntConn::WMaxMacAddMngmntConn(const char *name, int kind) : cPacket(name,kind)
{
    this->cid_var = 0;
}

WMaxMacAddMngmntConn::WMaxMacAddMngmntConn(const WMaxMacAddMngmntConn& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

WMaxMacAddMngmntConn::~WMaxMacAddMngmntConn()
{
}

WMaxMacAddMngmntConn& WMaxMacAddMngmntConn::operator=(const WMaxMacAddMngmntConn& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->cid_var = other.cid_var;
    return *this;
}

void WMaxMacAddMngmntConn::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->cid_var);
}

void WMaxMacAddMngmntConn::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->cid_var);
}

int WMaxMacAddMngmntConn::getCid() const
{
    return cid_var;
}

void WMaxMacAddMngmntConn::setCid(int cid_var)
{
    this->cid_var = cid_var;
}

class WMaxMacAddMngmntConnDescriptor : public cClassDescriptor
{
  public:
    WMaxMacAddMngmntConnDescriptor();
    virtual ~WMaxMacAddMngmntConnDescriptor();

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

Register_ClassDescriptor(WMaxMacAddMngmntConnDescriptor);

WMaxMacAddMngmntConnDescriptor::WMaxMacAddMngmntConnDescriptor() : cClassDescriptor("WMaxMacAddMngmntConn", "cPacket")
{
}

WMaxMacAddMngmntConnDescriptor::~WMaxMacAddMngmntConnDescriptor()
{
}

bool WMaxMacAddMngmntConnDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxMacAddMngmntConn *>(obj)!=NULL;
}

const char *WMaxMacAddMngmntConnDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxMacAddMngmntConnDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int WMaxMacAddMngmntConnDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *WMaxMacAddMngmntConnDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "cid",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int WMaxMacAddMngmntConnDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "cid")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxMacAddMngmntConnDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *WMaxMacAddMngmntConnDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxMacAddMngmntConnDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMacAddMngmntConn *pp = (WMaxMacAddMngmntConn *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string WMaxMacAddMngmntConnDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMacAddMngmntConn *pp = (WMaxMacAddMngmntConn *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getCid());
        default: return "";
    }
}

bool WMaxMacAddMngmntConnDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMacAddMngmntConn *pp = (WMaxMacAddMngmntConn *)object; (void)pp;
    switch (field) {
        case 0: pp->setCid(string2long(value)); return true;
        default: return false;
    }
}

const char *WMaxMacAddMngmntConnDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *WMaxMacAddMngmntConnDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMacAddMngmntConn *pp = (WMaxMacAddMngmntConn *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(WMaxEvent_DelConn);

WMaxEvent_DelConn::WMaxEvent_DelConn(const char *name, int kind) : cPacket(name,kind)
{
    this->cid_var = 0;
    this->isBasic_var = 0;
}

WMaxEvent_DelConn::WMaxEvent_DelConn(const WMaxEvent_DelConn& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

WMaxEvent_DelConn::~WMaxEvent_DelConn()
{
}

WMaxEvent_DelConn& WMaxEvent_DelConn::operator=(const WMaxEvent_DelConn& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->cid_var = other.cid_var;
    this->isBasic_var = other.isBasic_var;
    return *this;
}

void WMaxEvent_DelConn::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->cid_var);
    doPacking(b,this->isBasic_var);
}

void WMaxEvent_DelConn::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->cid_var);
    doUnpacking(b,this->isBasic_var);
}

int WMaxEvent_DelConn::getCid() const
{
    return cid_var;
}

void WMaxEvent_DelConn::setCid(int cid_var)
{
    this->cid_var = cid_var;
}

bool WMaxEvent_DelConn::getIsBasic() const
{
    return isBasic_var;
}

void WMaxEvent_DelConn::setIsBasic(bool isBasic_var)
{
    this->isBasic_var = isBasic_var;
}

class WMaxEvent_DelConnDescriptor : public cClassDescriptor
{
  public:
    WMaxEvent_DelConnDescriptor();
    virtual ~WMaxEvent_DelConnDescriptor();

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

Register_ClassDescriptor(WMaxEvent_DelConnDescriptor);

WMaxEvent_DelConnDescriptor::WMaxEvent_DelConnDescriptor() : cClassDescriptor("WMaxEvent_DelConn", "cPacket")
{
}

WMaxEvent_DelConnDescriptor::~WMaxEvent_DelConnDescriptor()
{
}

bool WMaxEvent_DelConnDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxEvent_DelConn *>(obj)!=NULL;
}

const char *WMaxEvent_DelConnDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxEvent_DelConnDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int WMaxEvent_DelConnDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *WMaxEvent_DelConnDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "cid",
        "isBasic",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int WMaxEvent_DelConnDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "cid")==0) return base+0;
    if (fieldName[0]=='i' && strcmp(fieldName, "isBasic")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxEvent_DelConnDescriptor::getFieldTypeString(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *WMaxEvent_DelConnDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxEvent_DelConnDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxEvent_DelConn *pp = (WMaxEvent_DelConn *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string WMaxEvent_DelConnDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxEvent_DelConn *pp = (WMaxEvent_DelConn *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getCid());
        case 1: return bool2string(pp->getIsBasic());
        default: return "";
    }
}

bool WMaxEvent_DelConnDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxEvent_DelConn *pp = (WMaxEvent_DelConn *)object; (void)pp;
    switch (field) {
        case 0: pp->setCid(string2long(value)); return true;
        case 1: pp->setIsBasic(string2bool(value)); return true;
        default: return false;
    }
}

const char *WMaxEvent_DelConnDescriptor::getFieldStructName(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *WMaxEvent_DelConnDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxEvent_DelConn *pp = (WMaxEvent_DelConn *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(WMaxEvent_FlowEnable);

WMaxEvent_FlowEnable::WMaxEvent_FlowEnable(const char *name, int kind) : cPacket(name,kind)
{
}

WMaxEvent_FlowEnable::WMaxEvent_FlowEnable(const WMaxEvent_FlowEnable& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

WMaxEvent_FlowEnable::~WMaxEvent_FlowEnable()
{
}

WMaxEvent_FlowEnable& WMaxEvent_FlowEnable::operator=(const WMaxEvent_FlowEnable& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    return *this;
}

void WMaxEvent_FlowEnable::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
}

void WMaxEvent_FlowEnable::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
}

class WMaxEvent_FlowEnableDescriptor : public cClassDescriptor
{
  public:
    WMaxEvent_FlowEnableDescriptor();
    virtual ~WMaxEvent_FlowEnableDescriptor();

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

Register_ClassDescriptor(WMaxEvent_FlowEnableDescriptor);

WMaxEvent_FlowEnableDescriptor::WMaxEvent_FlowEnableDescriptor() : cClassDescriptor("WMaxEvent_FlowEnable", "cPacket")
{
}

WMaxEvent_FlowEnableDescriptor::~WMaxEvent_FlowEnableDescriptor()
{
}

bool WMaxEvent_FlowEnableDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxEvent_FlowEnable *>(obj)!=NULL;
}

const char *WMaxEvent_FlowEnableDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxEvent_FlowEnableDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int WMaxEvent_FlowEnableDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *WMaxEvent_FlowEnableDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int WMaxEvent_FlowEnableDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxEvent_FlowEnableDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *WMaxEvent_FlowEnableDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxEvent_FlowEnableDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxEvent_FlowEnable *pp = (WMaxEvent_FlowEnable *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string WMaxEvent_FlowEnableDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxEvent_FlowEnable *pp = (WMaxEvent_FlowEnable *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool WMaxEvent_FlowEnableDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxEvent_FlowEnable *pp = (WMaxEvent_FlowEnable *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *WMaxEvent_FlowEnableDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *WMaxEvent_FlowEnableDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxEvent_FlowEnable *pp = (WMaxEvent_FlowEnable *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(WMaxEvent_FlowDisable);

WMaxEvent_FlowDisable::WMaxEvent_FlowDisable(const char *name, int kind) : cPacket(name,kind)
{
}

WMaxEvent_FlowDisable::WMaxEvent_FlowDisable(const WMaxEvent_FlowDisable& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

WMaxEvent_FlowDisable::~WMaxEvent_FlowDisable()
{
}

WMaxEvent_FlowDisable& WMaxEvent_FlowDisable::operator=(const WMaxEvent_FlowDisable& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    return *this;
}

void WMaxEvent_FlowDisable::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
}

void WMaxEvent_FlowDisable::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
}

class WMaxEvent_FlowDisableDescriptor : public cClassDescriptor
{
  public:
    WMaxEvent_FlowDisableDescriptor();
    virtual ~WMaxEvent_FlowDisableDescriptor();

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

Register_ClassDescriptor(WMaxEvent_FlowDisableDescriptor);

WMaxEvent_FlowDisableDescriptor::WMaxEvent_FlowDisableDescriptor() : cClassDescriptor("WMaxEvent_FlowDisable", "cPacket")
{
}

WMaxEvent_FlowDisableDescriptor::~WMaxEvent_FlowDisableDescriptor()
{
}

bool WMaxEvent_FlowDisableDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxEvent_FlowDisable *>(obj)!=NULL;
}

const char *WMaxEvent_FlowDisableDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxEvent_FlowDisableDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int WMaxEvent_FlowDisableDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *WMaxEvent_FlowDisableDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int WMaxEvent_FlowDisableDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxEvent_FlowDisableDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *WMaxEvent_FlowDisableDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxEvent_FlowDisableDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxEvent_FlowDisable *pp = (WMaxEvent_FlowDisable *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string WMaxEvent_FlowDisableDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxEvent_FlowDisable *pp = (WMaxEvent_FlowDisable *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool WMaxEvent_FlowDisableDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxEvent_FlowDisable *pp = (WMaxEvent_FlowDisable *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *WMaxEvent_FlowDisableDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *WMaxEvent_FlowDisableDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxEvent_FlowDisable *pp = (WMaxEvent_FlowDisable *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(WMaxMacTerminateAllConns);

WMaxMacTerminateAllConns::WMaxMacTerminateAllConns(const char *name, int kind) : cPacket(name,kind)
{
}

WMaxMacTerminateAllConns::WMaxMacTerminateAllConns(const WMaxMacTerminateAllConns& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

WMaxMacTerminateAllConns::~WMaxMacTerminateAllConns()
{
}

WMaxMacTerminateAllConns& WMaxMacTerminateAllConns::operator=(const WMaxMacTerminateAllConns& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    return *this;
}

void WMaxMacTerminateAllConns::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
}

void WMaxMacTerminateAllConns::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
}

class WMaxMacTerminateAllConnsDescriptor : public cClassDescriptor
{
  public:
    WMaxMacTerminateAllConnsDescriptor();
    virtual ~WMaxMacTerminateAllConnsDescriptor();

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

Register_ClassDescriptor(WMaxMacTerminateAllConnsDescriptor);

WMaxMacTerminateAllConnsDescriptor::WMaxMacTerminateAllConnsDescriptor() : cClassDescriptor("WMaxMacTerminateAllConns", "cPacket")
{
}

WMaxMacTerminateAllConnsDescriptor::~WMaxMacTerminateAllConnsDescriptor()
{
}

bool WMaxMacTerminateAllConnsDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<WMaxMacTerminateAllConns *>(obj)!=NULL;
}

const char *WMaxMacTerminateAllConnsDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int WMaxMacTerminateAllConnsDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int WMaxMacTerminateAllConnsDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *WMaxMacTerminateAllConnsDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int WMaxMacTerminateAllConnsDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *WMaxMacTerminateAllConnsDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *WMaxMacTerminateAllConnsDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int WMaxMacTerminateAllConnsDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMacTerminateAllConns *pp = (WMaxMacTerminateAllConns *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string WMaxMacTerminateAllConnsDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMacTerminateAllConns *pp = (WMaxMacTerminateAllConns *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool WMaxMacTerminateAllConnsDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMacTerminateAllConns *pp = (WMaxMacTerminateAllConns *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *WMaxMacTerminateAllConnsDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *WMaxMacTerminateAllConnsDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    WMaxMacTerminateAllConns *pp = (WMaxMacTerminateAllConns *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


