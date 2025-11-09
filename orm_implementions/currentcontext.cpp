#include "currentcontext.h"


const ORMString CurrentContext::superUserFstname = "superUser";
const ORMString CurrentContext::superUserSurname = "superUser";

bool CurrentContext::ignoreAppId()
{
    return mIgnoreAppId;
}

CurrentContext::CurrentContext(ORMPersistenceInterface &opi,
                               const ORMUuid &appId,
                               const ORMUuid &userId):
    opi(opi),
    appId(appId),
    userId(userId)
{

}

CurrentContext::IgnoreAppIdGuard::IgnoreAppIdGuard(CurrentContext &context):context(context)
{
    context.mIgnoreAppId = true;
}

CurrentContext::IgnoreAppIdGuard::~IgnoreAppIdGuard()
{
    context.mIgnoreAppId = false;
}
