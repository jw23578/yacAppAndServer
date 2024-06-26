#ifndef ORMPROPERTYSTRING_H
#define ORMPROPERTYSTRING_H

#include "ormtemplatedpropertyinterface.h"

class ORMPropertyString: public ORMTemplatedPropertyInterface<ORMString>
{
public:
    ORMPropertyString();

    ORMString asString() const override;
    void fromString(const ORMString &value) override;
    ORMString asJson() const override;

    ORMPropertyString &operator=(const ORMString &value)
    {
        set(value);
        return *this;
    }

    size_t size() const;
};

bool operator==(const ORMPropertyString &a, const ORMString &b);

#endif // ORMPROPERTYSTRING_H
