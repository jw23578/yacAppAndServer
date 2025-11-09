#ifndef CURRENTCONTEXT_H
#define CURRENTCONTEXT_H

#include "ormpersistenceinterface.h"

class CurrentContext
{
private:
    CurrentContext() = delete;
    bool mIgnoreAppId = false;
public:
    static const ORMString superUserFstname;
    static const ORMString superUserSurname;

    bool ignoreAppId();
    ORMPersistenceInterface &opi;
    const ORMUuid appId;
    ORMUuid userId;
    CurrentContext(ORMPersistenceInterface &opi,
                   const ORMUuid &appId,
                   const ORMUuid &userId);

    class IgnoreAppIdGuard
    {
        CurrentContext &context;
    public:
        IgnoreAppIdGuard(CurrentContext &context);
        ~IgnoreAppIdGuard();
    };
};

#endif // CURRENTCONTEXT_H
