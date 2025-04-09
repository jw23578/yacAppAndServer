#include "ormvector.h"

template <class T>
ORMVector<T>::ORMVector() {}

template<class T>
ORMVector<T>::~ORMVector()
{
    for (auto o: objects)
    {
        delete o;
    }
}

template<class T>
T *ORMVector<T>::createObject() const
{
    return new T;
}

template<class T>
T &ORMVector<T>::append()
{
    objects.push_back(new T);
    return *objects.back();
}

template<class T>
std::size_t ORMVector<T>::size() const
{
    return objects.size();
}

template<class T>
T &ORMVector<T>::operator[](const std::size_t i)
{
    return *objects[i];
}

template<class T>
const T &ORMVector<T>::getConst(const std::size_t i) const
{
    return *objects[i];
}

