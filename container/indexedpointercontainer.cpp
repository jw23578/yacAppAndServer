#include "indexedpointercontainer.h"


template<typename Type, typename IDType>
IndexedPointerContainer<Type, IDType>::IndexedPointerContainer(bool containerIsOwner):
    containerIsOwner(containerIsOwner)
{

}

template<typename Type, typename IDType>
IndexedPointerContainer<Type, IDType>::~IndexedPointerContainer()
{
    if (containerIsOwner)
    {
        for (auto t: data)
        {
            delete t;
        }
    }
}

template<typename Type, typename IDType>
void IndexedPointerContainer<Type, IDType>::add(const IDType &id, Type *t)
{
    data.push_back(t);
    id2Data[id] = t;
}

template<typename Type, typename IDType>
Type *IndexedPointerContainer<Type, IDType>::getByIndex(const size_t index)
{
    return data[index];
}

template<typename Type, typename IDType>
Type *IndexedPointerContainer<Type, IDType>::getById(const IDType &id)
{
    auto it(id2Data.find(id));
    if (it == id2Data.end())
    {
        return 0;
    }
    return it->second;
}

template<typename Type, typename IDType>
void IndexedPointerContainer<Type, IDType>::deleteByIndex(const size_t index)
{
    Type *t(data[index]);
    data.erase(t);
    for (auto it: id2Data)
    {
        if (it->second == t)
        {
            id2Data.erase(it);
            break;
        }
    }
    delete t;
}

template<typename Type, typename IDType>
void IndexedPointerContainer<Type, IDType>::deleteById(const IDType &id)
{
    Type *t(id2Data[id]);
    id2Data.erase(id);
    for (auto it: data)
    {
        if (*it == t)
        {
            data.erase(it);
        }
    }
    delete t;
}

template<typename Type, typename IDType>
size_t IndexedPointerContainer<Type, IDType>::size() const
{
    return data.size();
}
