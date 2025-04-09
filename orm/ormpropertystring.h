#ifndef ORMPROPERTYSTRING_H
#define ORMPROPERTYSTRING_H

#include "ormtemplatedpropertyinterface.h"

class ORMPropertyString: public ORMTemplatedPropertyInterface<ORMString>
{
public:
    ORMPropertyString(ORMString const &name);

    ORMString asString() const override;
    void fromString(const ORMString &value) override;
    ORMString asJson() const override;

    ORMPropertyString &operator=(const ORMString &value)
    {
        set(value);
        return *this;
    }

    bool operator!=(const ORMString &other)
    {
        return getRef() != other;
    }

    size_t size() const;
};

#endif // ORMPROPERTYSTRING_H
