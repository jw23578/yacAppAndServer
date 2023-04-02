#ifndef ORMTEMPLATEDPROPERTYINTERFACE_H
#define ORMTEMPLATEDPROPERTYINTERFACE_H

#include "ormpropertyinterface.h"

template <class T>
class ORMTemplatedPropertyInterface : public ORMPropertyInterface
{
    T value;
public:
    ORMTemplatedPropertyInterface(){}

    void set(const T &value)
    {
        if (!isNull() && this->value == value)
        {
            return;
        }
        setNull(false);
        this->value = value;
        callChangeCallback();
    }
    T& operator=(const T& value)
    {
        set(value);
        return *this;
    }

    T get() const
    {
        return value;
    }
};


#endif // ORMTEMPLATEDPROPERTYINTERFACE_H
