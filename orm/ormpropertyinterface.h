#ifndef ORMPROPERTYINTERFACE_H
#define ORMPROPERTYINTERFACE_H

#include "ormdefinitions.h"
#include <set>

class ORMPropertyInterface
{
    bool bNull{true};
    std::function<void()> changeCallback{0};
    std::set<ORMPropertyDetails> details;
    ORMString m_name;
protected:
    void callChangeCallback();
public:
    ORMPropertyInterface(const ORMString &name);
    virtual ~ORMPropertyInterface() {}

    const ORMString &name() const;

    virtual ORMString asString() const = 0;
    virtual void fromString(const ORMString &value) = 0;
    virtual ORMString asJson() const = 0;

    void setNull(const bool n);
    bool isNull() const;

    void setChangeCallback(std::function<void()> cb);

    void clearDetails();
    void addDetail(ORMPropertyDetails const detail);
    bool hasDetail(ORMPropertyDetails const needle);
};

#endif // ORMPROPERTYINTERFACE_H
