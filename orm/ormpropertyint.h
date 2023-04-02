#ifndef ORMPROPERTYINT_H
#define ORMPROPERTYINT_H

#include "ormtemplatedpropertyinterface.h"

class ORMPropertyInt : public ORMTemplatedPropertyInterface<int>
{    
public:
    ORMPropertyInt();

    ORMString asString() const override;
    void fromString(const ORMString &value) override;

    ORMPropertyInt &operator=(const int value)
    {
        set(value);
    }

};

#endif // ORMPROPERTYINT_H
