#ifndef ORMPROPERTYDATETIME_H
#define ORMPROPERTYDATETIME_H

#include "ormtemplatedpropertyinterface.h"

class ORMPropertyDateTime : public ORMTemplatedPropertyInterface<ORMDateTime>
{
public:
    ORMPropertyDateTime(ORMString const &name);

    ORMString asString() const override;
    void fromString(const ORMString &value) override;
    ORMString asJson() const override;

    ORMPropertyDateTime &operator=(const ORMDateTime value)
    {
        set(value);
        return *this;
    }

};

bool operator!=(ORMPropertyDateTime const &a, ORMDateTime const &b);


#endif // ORMPROPERTYDATETIME_H
