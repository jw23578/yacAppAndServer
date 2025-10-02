#ifndef CURRENTCONTEXT_H
#define CURRENTCONTEXT_H

#include "reducedsole.h"
#include "ormpersistenceinterface.h"

class CurrentContext
{
private:
    CurrentContext() = delete;
public:
    static constexpr std::string superUserFstname = "superUser";
    static constexpr std::string superUserSurname = "superUser";

    ORMPersistenceInterface &opi;
    const ORMUuid &appId;
    ORMUuid userId;
    CurrentContext(ORMPersistenceInterface &opi,
                   const ORMUuid &appId,
                   const ORMUuid &userId);
};

#endif // CURRENTCONTEXT_H
