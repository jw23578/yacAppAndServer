#ifndef ORMOBJECTINTERFACE_H
#define ORMOBJECTINTERFACE_H

#include <set>
#include <map>
#include "ormdefinitions.h"
#include "ormpropertyinterface.h"
#include "ormpropertysizet.h"
#include "ormpropertyuuid.h"
#include "ormpropertystring.h"
#include "ormpropertydatetime.h"
#include "ormpropertybool.h"
#include "ormpropertyint.h"
#include "ormpropertyoid.h"

#ifdef ORMCPPTypes
#define MACRO_DECLARE_ORMPROPERTY(ormtype, type, name) \
    public: \
    ormtype name;

#define MACRO_ADD_PROPERTY(name) \
    addProperty(#name, name)

#define MACRO_BOOL_PROPERTY(name) \
    MACRO_DECLARE_ORMPROPERTY(ORMPropertyBool, ignored, name)

#define MACRO_UUID_PROPERTY(name) \
    MACRO_DECLARE_ORMPROPERTY(ORMPropertyUuid, ignored, name)

#define MACRO_DATETIME_PROPERTY(name) \
    MACRO_DECLARE_ORMPROPERTY(ORMPropertyDateTime, ignored, name)

#define MACRO_STRING_PROPERTY(name) \
    MACRO_DECLARE_ORMPROPERTY(ORMPropertyString, ignored, name)

#define MACRO_SIZET_PROPERTY(name) \
    MACRO_DECLARE_ORMPROPERTY(ORMPropertySizeT, ignored, name)

#define MACRO_INT_PROPERTY(name) \
    MACRO_DECLARE_ORMPROPERTY(ORMPropertyInt, ignored, name)

#define MACRO_OID_PROPERTY(name) \
    MACRO_DECLARE_ORMPROPERTY(ORMPropertyOID, ignored, name)

#endif
#ifdef ORMQTTypes
#include <QObject>
#define MACRO_DECLARE_ORMPROPERTY(ormtype, type, name) \
    private: \
    ormtype m_##name; \
    public: \
    Q_PROPERTY(type name READ name WRITE set##name NOTIFY name##Changed) \
    type name() const {return m_##name.get();} \
    void set##name(type n){if (m_##name.get() == n) return; m_##name.set(n); emit name##Changed();} \
    Q_SIGNAL \
    void name##Changed(); \
    private:

#define MACRO_ADD_PROPERTY(name) \
    addProperty(#name, m_##name); \
    m_##name.setChangeCallback([this]{emit name##Changed();})

#define MACRO_BOOL_PROPERTY(name) \
    MACRO_DECLARE_ORMPROPERTY(ORMPropertyBool, bool, name)

#define MACRO_UUID_PROPERTY(name) \
    MACRO_DECLARE_ORMPROPERTY(ORMPropertyUuid, QString, name)

#define MACRO_DATETIME_PROPERTY(name) \
    MACRO_DECLARE_ORMPROPERTY(ORMPropertyDateTime, QDateTime, name)

#define MACRO_STRING_PROPERTY(name) \
    MACRO_DECLARE_ORMPROPERTY(ORMPropertyString, QString, name)

#define MACRO_SIZET_PROPERTY(name) \
    MACRO_DECLARE_ORMPROPERTY(ORMPropertySizeT, size_t, name)

#define MACRO_INT_PROPERTY(name) \
    MACRO_DECLARE_ORMPROPERTY(ORMPropertyInt, int, name)

#define MACRO_OID_PROPERTY(name) \
    MACRO_DECLARE_ORMPROPERTY(ORMPropertyOID, int, name)

#endif

#ifdef ORMQTTypes
class   ORMObjectInterface: public QObject
{
    Q_OBJECT
#endif
#ifdef ORMCPPTypes
    class ORMObjectInterface
    {
#endif

        static std::map<ORMString, std::set<ORMString>> allPropertySets;

        typedef std::map<ORMString, ORMPropertyInterface*> PropertyMap;
        PropertyMap properties;
    protected:
        void addProperty(ORMString propertyName, ORMPropertyInterface &property);
    public:
        ORMObjectInterface()
#ifdef ORMQTTypes
            :QObject()
    #endif
        {}
        virtual ~ORMObjectInterface() {}
        virtual const ORMString getORMName() const = 0;
        virtual ORMObjectInterface *create() const = 0;

        bool propertyExists(const ORMString &propertyName) const;
        bool propertyIsNull(const ORMString &propertyName) const;
        void setPropertyNull(const ORMString &propertyName,
                             const bool n);

        bool proptertyIsBool(const ORMString &propertyName) const;
        bool proptertyIsUuid(const ORMString &propertyName) const;
        bool proptertyIsInt(const ORMString &propertyName) const;
        bool proptertyIsSizeT(const ORMString &propertyName) const;
        bool proptertyIsDateTime(const ORMString &propertyName) const;
        bool proptertyIsString(const ORMString &propertyName) const;

        ORMString getPropertyToString(const ORMString &propertyName) const;
        void setPropertyFromString(const ORMString &propertyName,
                                   const ORMString &value);


        const std::set<ORMString> &propertyNames() const;
    };

#endif // ORMOBJECTINTERFACE_H
