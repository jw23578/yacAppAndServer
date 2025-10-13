#ifndef CURRENTCONTEXT_H
#define CURRENTCONTEXT_H

#include "ormpersistenceinterface.h"

class CurrentContext
{
private:
    CurrentContext() = delete;
public:
    static const ORMString superUserFstname;
    static const ORMString superUserSurname;

    ORMPersistenceInterface &opi;
    const ORMUuid appId;
    ORMUuid userId;
    CurrentContext(ORMPersistenceInterface &opi,
                   const ORMUuid &appId,
                   const ORMUuid &userId);
};

#endif // CURRENTCONTEXT_H
