#ifndef EXTUUID_H
#define EXTUUID_H

#include "orm/ormdefinitions.h"

class ExtUuid
{
public:
    ExtUuid();
    static const ORMUuid NullUuid;
    static ORMUuid generateUuid();
    static ORMString uuidToString(ORMUuid const &id);
    static ORMUuid stringToUuid(ORMString const &str);
};

#endif // EXTUUID_H
