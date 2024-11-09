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

    const T &getRef() const
    {
        return value;
    }

    T get() const
    {
        return value;
    }
    operator T() const
    {
        return value;
    }

    bool isEqual(const ORMTemplatedPropertyInterface<T> &other) const
    {
        return value == other.value;
    }
};

template <class T>
bool operator==(const ORMTemplatedPropertyInterface<T> &a, const ORMTemplatedPropertyInterface<T> &b)
{
    return typeid(a) == typeid(a) // Allow compare only instances of the same dynamic type
           && a.isEqual(b);       // If types are the same then do the comparision.
}


#endif // ORMTEMPLATEDPROPERTYINTERFACE_H
