#ifndef ORMVECTOR_H
#define ORMVECTOR_H

#include <vector>

template <class T>
class ORMVector
{
    std::vector<T*> objects;
public:
    ORMVector();
    ~ORMVector();

    T *createObject() const;

    T &append();

    std::size_t size();
    T &operator[](const std::size_t i);
};

#include "ormvector.cpp"

#endif // ORMVECTOR_H
