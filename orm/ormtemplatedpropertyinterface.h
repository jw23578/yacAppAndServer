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
        setNull(false);
        this->value = value;
    }

    T get() const
    {
        return value;
    }

    T operator()() const
    {
        return value;
    }
};

#endif // ORMTEMPLATEDPROPERTYINTERFACE_H
