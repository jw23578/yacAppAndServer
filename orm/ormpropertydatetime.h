#ifndef ORMPROPERTYDATETIME_H
#define ORMPROPERTYDATETIME_H

#include "ormtemplatedpropertyinterface.h"

class ORMPropertyDateTime : public ORMTemplatedPropertyInterface<ORMDateTime>
{
public:
    ORMPropertyDateTime();

    ORMString asString() const;
    void fromString(const ORMString &value);

    ORMPropertyDateTime &operator=(const ORMDateTime value)
    {
        set(value);
    }

};

#endif // ORMPROPERTYDATETIME_H
