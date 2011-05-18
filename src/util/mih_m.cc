//
// Generated file, do not edit! Created by opp_msgc 4.1 from util/mih.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "mih_m.h"

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




Register_Class(MihEvent_EntryStart);

MihEvent_EntryStart::MihEvent_EntryStart(const char *name, int kind) : cPacket(name,kind)
{
}

MihEvent_EntryStart::MihEvent_EntryStart(const MihEvent_EntryStart& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

MihEvent_EntryStart::~MihEvent_EntryStart()
{
}

MihEvent_EntryStart& MihEvent_EntryStart::operator=(const MihEvent_EntryStart& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    return *this;
}

void MihEvent_EntryStart::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
}

void MihEvent_EntryStart::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
}

class MihEvent_EntryStartDescriptor : public cClassDescriptor
{
  public:
    MihEvent_EntryStartDescriptor();
    virtual ~MihEvent_EntryStartDescriptor();

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

Register_ClassDescriptor(MihEvent_EntryStartDescriptor);

MihEvent_EntryStartDescriptor::MihEvent_EntryStartDescriptor() : cClassDescriptor("MihEvent_EntryStart", "cPacket")
{
}

MihEvent_EntryStartDescriptor::~MihEvent_EntryStartDescriptor()
{
}

bool MihEvent_EntryStartDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MihEvent_EntryStart *>(obj)!=NULL;
}

const char *MihEvent_EntryStartDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MihEvent_EntryStartDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int MihEvent_EntryStartDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *MihEvent_EntryStartDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int MihEvent_EntryStartDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MihEvent_EntryStartDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *MihEvent_EntryStartDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int MihEvent_EntryStartDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_EntryStart *pp = (MihEvent_EntryStart *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MihEvent_EntryStartDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_EntryStart *pp = (MihEvent_EntryStart *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool MihEvent_EntryStartDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_EntryStart *pp = (MihEvent_EntryStart *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *MihEvent_EntryStartDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *MihEvent_EntryStartDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_EntryStart *pp = (MihEvent_EntryStart *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(MihEvent_EntryEnd);

MihEvent_EntryEnd::MihEvent_EntryEnd(const char *name, int kind) : cPacket(name,kind)
{
}

MihEvent_EntryEnd::MihEvent_EntryEnd(const MihEvent_EntryEnd& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

MihEvent_EntryEnd::~MihEvent_EntryEnd()
{
}

MihEvent_EntryEnd& MihEvent_EntryEnd::operator=(const MihEvent_EntryEnd& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    return *this;
}

void MihEvent_EntryEnd::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
}

void MihEvent_EntryEnd::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
}

class MihEvent_EntryEndDescriptor : public cClassDescriptor
{
  public:
    MihEvent_EntryEndDescriptor();
    virtual ~MihEvent_EntryEndDescriptor();

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

Register_ClassDescriptor(MihEvent_EntryEndDescriptor);

MihEvent_EntryEndDescriptor::MihEvent_EntryEndDescriptor() : cClassDescriptor("MihEvent_EntryEnd", "cPacket")
{
}

MihEvent_EntryEndDescriptor::~MihEvent_EntryEndDescriptor()
{
}

bool MihEvent_EntryEndDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MihEvent_EntryEnd *>(obj)!=NULL;
}

const char *MihEvent_EntryEndDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MihEvent_EntryEndDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int MihEvent_EntryEndDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *MihEvent_EntryEndDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int MihEvent_EntryEndDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MihEvent_EntryEndDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *MihEvent_EntryEndDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int MihEvent_EntryEndDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_EntryEnd *pp = (MihEvent_EntryEnd *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MihEvent_EntryEndDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_EntryEnd *pp = (MihEvent_EntryEnd *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool MihEvent_EntryEndDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_EntryEnd *pp = (MihEvent_EntryEnd *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *MihEvent_EntryEndDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *MihEvent_EntryEndDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_EntryEnd *pp = (MihEvent_EntryEnd *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(MihEvent_HandoverStart);

MihEvent_HandoverStart::MihEvent_HandoverStart(const char *name, int kind) : cPacket(name,kind)
{
    this->targetBS_var = 0;
}

MihEvent_HandoverStart::MihEvent_HandoverStart(const MihEvent_HandoverStart& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

MihEvent_HandoverStart::~MihEvent_HandoverStart()
{
}

MihEvent_HandoverStart& MihEvent_HandoverStart::operator=(const MihEvent_HandoverStart& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->targetBS_var = other.targetBS_var;
    return *this;
}

void MihEvent_HandoverStart::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->targetBS_var);
}

void MihEvent_HandoverStart::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->targetBS_var);
}

int MihEvent_HandoverStart::getTargetBS() const
{
    return targetBS_var;
}

void MihEvent_HandoverStart::setTargetBS(int targetBS_var)
{
    this->targetBS_var = targetBS_var;
}

class MihEvent_HandoverStartDescriptor : public cClassDescriptor
{
  public:
    MihEvent_HandoverStartDescriptor();
    virtual ~MihEvent_HandoverStartDescriptor();

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

Register_ClassDescriptor(MihEvent_HandoverStartDescriptor);

MihEvent_HandoverStartDescriptor::MihEvent_HandoverStartDescriptor() : cClassDescriptor("MihEvent_HandoverStart", "cPacket")
{
}

MihEvent_HandoverStartDescriptor::~MihEvent_HandoverStartDescriptor()
{
}

bool MihEvent_HandoverStartDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MihEvent_HandoverStart *>(obj)!=NULL;
}

const char *MihEvent_HandoverStartDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MihEvent_HandoverStartDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int MihEvent_HandoverStartDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *MihEvent_HandoverStartDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "targetBS",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int MihEvent_HandoverStartDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "targetBS")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MihEvent_HandoverStartDescriptor::getFieldTypeString(void *object, int field) const
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

const char *MihEvent_HandoverStartDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int MihEvent_HandoverStartDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_HandoverStart *pp = (MihEvent_HandoverStart *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MihEvent_HandoverStartDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_HandoverStart *pp = (MihEvent_HandoverStart *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getTargetBS());
        default: return "";
    }
}

bool MihEvent_HandoverStartDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_HandoverStart *pp = (MihEvent_HandoverStart *)object; (void)pp;
    switch (field) {
        case 0: pp->setTargetBS(string2long(value)); return true;
        default: return false;
    }
}

const char *MihEvent_HandoverStartDescriptor::getFieldStructName(void *object, int field) const
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

void *MihEvent_HandoverStartDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_HandoverStart *pp = (MihEvent_HandoverStart *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(MihEvent_HandoverEnd);

MihEvent_HandoverEnd::MihEvent_HandoverEnd(const char *name, int kind) : cPacket(name,kind)
{
}

MihEvent_HandoverEnd::MihEvent_HandoverEnd(const MihEvent_HandoverEnd& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

MihEvent_HandoverEnd::~MihEvent_HandoverEnd()
{
}

MihEvent_HandoverEnd& MihEvent_HandoverEnd::operator=(const MihEvent_HandoverEnd& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    return *this;
}

void MihEvent_HandoverEnd::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
}

void MihEvent_HandoverEnd::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
}

class MihEvent_HandoverEndDescriptor : public cClassDescriptor
{
  public:
    MihEvent_HandoverEndDescriptor();
    virtual ~MihEvent_HandoverEndDescriptor();

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

Register_ClassDescriptor(MihEvent_HandoverEndDescriptor);

MihEvent_HandoverEndDescriptor::MihEvent_HandoverEndDescriptor() : cClassDescriptor("MihEvent_HandoverEnd", "cPacket")
{
}

MihEvent_HandoverEndDescriptor::~MihEvent_HandoverEndDescriptor()
{
}

bool MihEvent_HandoverEndDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MihEvent_HandoverEnd *>(obj)!=NULL;
}

const char *MihEvent_HandoverEndDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MihEvent_HandoverEndDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int MihEvent_HandoverEndDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *MihEvent_HandoverEndDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int MihEvent_HandoverEndDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MihEvent_HandoverEndDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *MihEvent_HandoverEndDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int MihEvent_HandoverEndDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_HandoverEnd *pp = (MihEvent_HandoverEnd *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MihEvent_HandoverEndDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_HandoverEnd *pp = (MihEvent_HandoverEnd *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool MihEvent_HandoverEndDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_HandoverEnd *pp = (MihEvent_HandoverEnd *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *MihEvent_HandoverEndDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *MihEvent_HandoverEndDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_HandoverEnd *pp = (MihEvent_HandoverEnd *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(MihEvent_ReentryStart);

MihEvent_ReentryStart::MihEvent_ReentryStart(const char *name, int kind) : cPacket(name,kind)
{
}

MihEvent_ReentryStart::MihEvent_ReentryStart(const MihEvent_ReentryStart& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

MihEvent_ReentryStart::~MihEvent_ReentryStart()
{
}

MihEvent_ReentryStart& MihEvent_ReentryStart::operator=(const MihEvent_ReentryStart& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    return *this;
}

void MihEvent_ReentryStart::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
}

void MihEvent_ReentryStart::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
}

class MihEvent_ReentryStartDescriptor : public cClassDescriptor
{
  public:
    MihEvent_ReentryStartDescriptor();
    virtual ~MihEvent_ReentryStartDescriptor();

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

Register_ClassDescriptor(MihEvent_ReentryStartDescriptor);

MihEvent_ReentryStartDescriptor::MihEvent_ReentryStartDescriptor() : cClassDescriptor("MihEvent_ReentryStart", "cPacket")
{
}

MihEvent_ReentryStartDescriptor::~MihEvent_ReentryStartDescriptor()
{
}

bool MihEvent_ReentryStartDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MihEvent_ReentryStart *>(obj)!=NULL;
}

const char *MihEvent_ReentryStartDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MihEvent_ReentryStartDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int MihEvent_ReentryStartDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *MihEvent_ReentryStartDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int MihEvent_ReentryStartDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MihEvent_ReentryStartDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *MihEvent_ReentryStartDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int MihEvent_ReentryStartDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_ReentryStart *pp = (MihEvent_ReentryStart *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MihEvent_ReentryStartDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_ReentryStart *pp = (MihEvent_ReentryStart *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool MihEvent_ReentryStartDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_ReentryStart *pp = (MihEvent_ReentryStart *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *MihEvent_ReentryStartDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *MihEvent_ReentryStartDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_ReentryStart *pp = (MihEvent_ReentryStart *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(MihEvent_ReentryEnd);

MihEvent_ReentryEnd::MihEvent_ReentryEnd(const char *name, int kind) : cPacket(name,kind)
{
}

MihEvent_ReentryEnd::MihEvent_ReentryEnd(const MihEvent_ReentryEnd& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

MihEvent_ReentryEnd::~MihEvent_ReentryEnd()
{
}

MihEvent_ReentryEnd& MihEvent_ReentryEnd::operator=(const MihEvent_ReentryEnd& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    return *this;
}

void MihEvent_ReentryEnd::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
}

void MihEvent_ReentryEnd::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
}

class MihEvent_ReentryEndDescriptor : public cClassDescriptor
{
  public:
    MihEvent_ReentryEndDescriptor();
    virtual ~MihEvent_ReentryEndDescriptor();

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

Register_ClassDescriptor(MihEvent_ReentryEndDescriptor);

MihEvent_ReentryEndDescriptor::MihEvent_ReentryEndDescriptor() : cClassDescriptor("MihEvent_ReentryEnd", "cPacket")
{
}

MihEvent_ReentryEndDescriptor::~MihEvent_ReentryEndDescriptor()
{
}

bool MihEvent_ReentryEndDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MihEvent_ReentryEnd *>(obj)!=NULL;
}

const char *MihEvent_ReentryEndDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MihEvent_ReentryEndDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int MihEvent_ReentryEndDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *MihEvent_ReentryEndDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int MihEvent_ReentryEndDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MihEvent_ReentryEndDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *MihEvent_ReentryEndDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int MihEvent_ReentryEndDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_ReentryEnd *pp = (MihEvent_ReentryEnd *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MihEvent_ReentryEndDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_ReentryEnd *pp = (MihEvent_ReentryEnd *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool MihEvent_ReentryEndDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_ReentryEnd *pp = (MihEvent_ReentryEnd *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *MihEvent_ReentryEndDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *MihEvent_ReentryEndDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_ReentryEnd *pp = (MihEvent_ReentryEnd *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(MihEvent_L3AddrConfigured);

MihEvent_L3AddrConfigured::MihEvent_L3AddrConfigured(const char *name, int kind) : cPacket(name,kind)
{
    this->RemoteAutoconf_var = 0;
}

MihEvent_L3AddrConfigured::MihEvent_L3AddrConfigured(const MihEvent_L3AddrConfigured& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

MihEvent_L3AddrConfigured::~MihEvent_L3AddrConfigured()
{
}

MihEvent_L3AddrConfigured& MihEvent_L3AddrConfigured::operator=(const MihEvent_L3AddrConfigured& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->Addr_var = other.Addr_var;
    this->RemoteAutoconf_var = other.RemoteAutoconf_var;
    return *this;
}

void MihEvent_L3AddrConfigured::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->Addr_var);
    doPacking(b,this->RemoteAutoconf_var);
}

void MihEvent_L3AddrConfigured::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->Addr_var);
    doUnpacking(b,this->RemoteAutoconf_var);
}

IPv6Addr& MihEvent_L3AddrConfigured::getAddr()
{
    return Addr_var;
}

void MihEvent_L3AddrConfigured::setAddr(const IPv6Addr& Addr_var)
{
    this->Addr_var = Addr_var;
}

bool MihEvent_L3AddrConfigured::getRemoteAutoconf() const
{
    return RemoteAutoconf_var;
}

void MihEvent_L3AddrConfigured::setRemoteAutoconf(bool RemoteAutoconf_var)
{
    this->RemoteAutoconf_var = RemoteAutoconf_var;
}

class MihEvent_L3AddrConfiguredDescriptor : public cClassDescriptor
{
  public:
    MihEvent_L3AddrConfiguredDescriptor();
    virtual ~MihEvent_L3AddrConfiguredDescriptor();

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

Register_ClassDescriptor(MihEvent_L3AddrConfiguredDescriptor);

MihEvent_L3AddrConfiguredDescriptor::MihEvent_L3AddrConfiguredDescriptor() : cClassDescriptor("MihEvent_L3AddrConfigured", "cPacket")
{
}

MihEvent_L3AddrConfiguredDescriptor::~MihEvent_L3AddrConfiguredDescriptor()
{
}

bool MihEvent_L3AddrConfiguredDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MihEvent_L3AddrConfigured *>(obj)!=NULL;
}

const char *MihEvent_L3AddrConfiguredDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MihEvent_L3AddrConfiguredDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int MihEvent_L3AddrConfiguredDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *MihEvent_L3AddrConfiguredDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "Addr",
        "RemoteAutoconf",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int MihEvent_L3AddrConfiguredDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='A' && strcmp(fieldName, "Addr")==0) return base+0;
    if (fieldName[0]=='R' && strcmp(fieldName, "RemoteAutoconf")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MihEvent_L3AddrConfiguredDescriptor::getFieldTypeString(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *MihEvent_L3AddrConfiguredDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int MihEvent_L3AddrConfiguredDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_L3AddrConfigured *pp = (MihEvent_L3AddrConfigured *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MihEvent_L3AddrConfiguredDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_L3AddrConfigured *pp = (MihEvent_L3AddrConfigured *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getAddr(); return out.str();}
        case 1: return bool2string(pp->getRemoteAutoconf());
        default: return "";
    }
}

bool MihEvent_L3AddrConfiguredDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_L3AddrConfigured *pp = (MihEvent_L3AddrConfigured *)object; (void)pp;
    switch (field) {
        case 1: pp->setRemoteAutoconf(string2bool(value)); return true;
        default: return false;
    }
}

const char *MihEvent_L3AddrConfiguredDescriptor::getFieldStructName(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *MihEvent_L3AddrConfiguredDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_L3AddrConfigured *pp = (MihEvent_L3AddrConfigured *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getAddr()); break;
        default: return NULL;
    }
}

Register_Class(MihEvent_L3RoutingConfigured);

MihEvent_L3RoutingConfigured::MihEvent_L3RoutingConfigured(const char *name, int kind) : cPacket(name,kind)
{
}

MihEvent_L3RoutingConfigured::MihEvent_L3RoutingConfigured(const MihEvent_L3RoutingConfigured& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

MihEvent_L3RoutingConfigured::~MihEvent_L3RoutingConfigured()
{
}

MihEvent_L3RoutingConfigured& MihEvent_L3RoutingConfigured::operator=(const MihEvent_L3RoutingConfigured& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    return *this;
}

void MihEvent_L3RoutingConfigured::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
}

void MihEvent_L3RoutingConfigured::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
}

class MihEvent_L3RoutingConfiguredDescriptor : public cClassDescriptor
{
  public:
    MihEvent_L3RoutingConfiguredDescriptor();
    virtual ~MihEvent_L3RoutingConfiguredDescriptor();

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

Register_ClassDescriptor(MihEvent_L3RoutingConfiguredDescriptor);

MihEvent_L3RoutingConfiguredDescriptor::MihEvent_L3RoutingConfiguredDescriptor() : cClassDescriptor("MihEvent_L3RoutingConfigured", "cPacket")
{
}

MihEvent_L3RoutingConfiguredDescriptor::~MihEvent_L3RoutingConfiguredDescriptor()
{
}

bool MihEvent_L3RoutingConfiguredDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MihEvent_L3RoutingConfigured *>(obj)!=NULL;
}

const char *MihEvent_L3RoutingConfiguredDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MihEvent_L3RoutingConfiguredDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int MihEvent_L3RoutingConfiguredDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *MihEvent_L3RoutingConfiguredDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int MihEvent_L3RoutingConfiguredDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MihEvent_L3RoutingConfiguredDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *MihEvent_L3RoutingConfiguredDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int MihEvent_L3RoutingConfiguredDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_L3RoutingConfigured *pp = (MihEvent_L3RoutingConfigured *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MihEvent_L3RoutingConfiguredDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_L3RoutingConfigured *pp = (MihEvent_L3RoutingConfigured *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool MihEvent_L3RoutingConfiguredDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_L3RoutingConfigured *pp = (MihEvent_L3RoutingConfigured *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *MihEvent_L3RoutingConfiguredDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *MihEvent_L3RoutingConfiguredDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_L3RoutingConfigured *pp = (MihEvent_L3RoutingConfigured *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(MihEvent_L3LocationUpdated);

MihEvent_L3LocationUpdated::MihEvent_L3LocationUpdated(const char *name, int kind) : cPacket(name,kind)
{
}

MihEvent_L3LocationUpdated::MihEvent_L3LocationUpdated(const MihEvent_L3LocationUpdated& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

MihEvent_L3LocationUpdated::~MihEvent_L3LocationUpdated()
{
}

MihEvent_L3LocationUpdated& MihEvent_L3LocationUpdated::operator=(const MihEvent_L3LocationUpdated& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    return *this;
}

void MihEvent_L3LocationUpdated::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
}

void MihEvent_L3LocationUpdated::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
}

class MihEvent_L3LocationUpdatedDescriptor : public cClassDescriptor
{
  public:
    MihEvent_L3LocationUpdatedDescriptor();
    virtual ~MihEvent_L3LocationUpdatedDescriptor();

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

Register_ClassDescriptor(MihEvent_L3LocationUpdatedDescriptor);

MihEvent_L3LocationUpdatedDescriptor::MihEvent_L3LocationUpdatedDescriptor() : cClassDescriptor("MihEvent_L3LocationUpdated", "cPacket")
{
}

MihEvent_L3LocationUpdatedDescriptor::~MihEvent_L3LocationUpdatedDescriptor()
{
}

bool MihEvent_L3LocationUpdatedDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MihEvent_L3LocationUpdated *>(obj)!=NULL;
}

const char *MihEvent_L3LocationUpdatedDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MihEvent_L3LocationUpdatedDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int MihEvent_L3LocationUpdatedDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *MihEvent_L3LocationUpdatedDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int MihEvent_L3LocationUpdatedDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MihEvent_L3LocationUpdatedDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *MihEvent_L3LocationUpdatedDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int MihEvent_L3LocationUpdatedDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_L3LocationUpdated *pp = (MihEvent_L3LocationUpdated *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MihEvent_L3LocationUpdatedDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_L3LocationUpdated *pp = (MihEvent_L3LocationUpdated *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool MihEvent_L3LocationUpdatedDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_L3LocationUpdated *pp = (MihEvent_L3LocationUpdated *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *MihEvent_L3LocationUpdatedDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *MihEvent_L3LocationUpdatedDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MihEvent_L3LocationUpdated *pp = (MihEvent_L3LocationUpdated *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


