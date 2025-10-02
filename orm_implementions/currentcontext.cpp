#include "currentcontext.h"

CurrentContext::CurrentContext(ORMPersistenceInterface &opi,
                               const ORMUuid &appId,
                               const ORMUuid &userId):
    opi(opi),
    appId(appId),
    userId(userId)
{

}
