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
T &ORMVector<T>::append()
{
    objects.push_back(new T);
    return *objects.back();
}

template<class T>
std::size_t ORMVector<T>::size()
{
    return objects.size();
}

template<class T>
T &ORMVector<T>::operator[](const std::size_t i)
{
    return *objects[i];
}
