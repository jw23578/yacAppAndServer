#ifndef EXTUUID_H
#define EXTUUID_H

#include "orm/ormdefinitions.h"

class ExtUuid
{
public:
    ExtUuid();
    static ORMUuid generateUuid();
    static ORMString uuidToString(ORMUuid const &id);
};

#endif // EXTUUID_H
