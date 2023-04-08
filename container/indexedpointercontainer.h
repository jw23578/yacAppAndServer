#ifndef INDEXEDPOINTERCONTAINER_H
#define INDEXEDPOINTERCONTAINER_H

#include <vector>
#include <map>

template<typename Type, typename IDType>
class IndexedPointerContainer
{
    std::vector<Type*> data;
    std::map<IDType, Type*> id2Data;
    bool containerIsOwner;
public:
    IndexedPointerContainer(bool containerIsOwner);
    ~IndexedPointerContainer();

    void add(IDType const &id, Type *t);

    Type *getByIndex(const size_t index);
    Type *getById(const IDType &id);

    void deleteByIndex(const size_t index);
    size_t deleteById(const IDType &id);

    void swap(const size_t indexA,
              const size_t indexB);

    size_t size() const;

    void clear();
};

#endif // INDEXEDPOINTERCONTAINER_H
