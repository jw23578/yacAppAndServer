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

#ifdef ORMCPPTypes
#define MACRO_DECLARE_ORMPROPERTY(ormtype, type, name) \
    public: \
    ormtype name;
#endif
#ifdef ORMQTTypes
#include <QObject>
#define MACRO_DECLARE_ORMPROPERTY(ormtype, type, name) \
    private: \
    ormtype name; \
    public: \
    Q_PROPERTY(type name READ get##name WRITE set##name NOTIFY name##Changed) \
    type get##name() const {return name.get();} \
    void set##name(type n){if (name.get() == n) return; name.set(n); emit name##Changed();} \
    Q_SIGNAL \
    void name##Changed(); \
    private:
#endif

#define MACRO_BOOL_PROPERTY(name) \
    MACRO_DECLARE_ORMPROPERTY(ORMPropertyBool, bool, name)

#define MACRO_UUID_PROPERTY(name) \
    MACRO_DECLARE_ORMPROPERTY(ORMPropertyUuid, ORMUuid, name)

#define MACRO_DATETIME_PROPERTY(name) \
    MACRO_DECLARE_ORMPROPERTY(ORMPropertyDateTime, ORMDateTime, name)

#define MACRO_STRING_PROPERTY(name) \
    MACRO_DECLARE_ORMPROPERTY(ORMPropertyString, ORMString, name)

#define MACRO_SIZET_PROPERTY(name) \
    MACRO_DECLARE_ORMPROPERTY(ORMPropertySizeT, size_t, name)

#define MACRO_ADD_PROPERTY(name) \
    addProperty(#name, name)

#ifdef ORMQTTypes
class ORMObjectInterface: public QObject
{
#endif
#ifdef ORMCPPTypes
    class ORMObjectInterface
    {
#endif

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

        ORMString getPropertyToString(const ORMString &propertyName) const;
        void setPropertyFromString(const ORMString &propertyName,
                                   const ORMString &value);


        void getPropertyNames(std::set<ORMString> &propertyNames) const;
    };

#endif // ORMOBJECTINTERFACE_H
