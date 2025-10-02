#include "t0004_user_logintoken.h"
#include "t0002_user.h"

void t0004_user_logintoken::loginSuccessful(CurrentContext &context,
                                            const ORMUuid &userId)
{
    int validHours(24 * 7);
    setuser_id(userId);
    setlogin_token(ExtUuid::uuidToString(ExtUuid::generateUuid()));
    setlogin_token_valid_until(std::chrono::system_clock::now() + std::chrono::hours(1) * validHours);
    store(context);
}

void t0004_user_logintoken::disableLoginTokenByUserId(CurrentContext &context,
                                                      const ORMUuid &userId)
{
    t0004_user_logintoken logintoken;
    ORMVector<t0004_user_logintoken> logintokenVector;
    logintoken.fetchObjects(context, {{logintoken.user_idORM().name(), ExtUuid::uuidToString(userId)}}, logintokenVector);
    for (size_t i(0); logintokenVector.size(); ++i)
    {
        logintokenVector[i].erase(context);
    }
}

bool t0004_user_logintoken::logoutUserByLoginToken(CurrentContext &context,
                                                   const ORMString logintoken)
{
    t0004_user_logintoken loginToken;
    if (!loginToken.load(context, {{loginToken.login_tokenORM().name(), logintoken}}))
    {
        return false;
    }
    loginToken.erase(context);
    return true;
}

bool t0004_user_logintoken::userLoggedIn(CurrentContext &context,
                                         const ORMString &loginEMail,
                                         const ORMString &loginToken)
{
    std::string ignored;
    t0002_user user;
    if (!user.lookupUser(context, loginEMail, ignored))
    {
        return false;
    }
    return load(context, {{user_idORM().name(), user.user_idORM().asString()},
                          {login_tokenORM().name(), loginToken}});
}

void t0004_user_logintoken::refresh(CurrentContext &context,
                                    const ORMString &loginToken)
{
    if (!load(context, {{user_idORM().name(), ExtUuid::uuidToString(context.userId)},
                        {login_tokenORM().name(), loginToken}}))
    {
        return;
    }
    setlogin_token_valid_until(std::chrono::system_clock::now() + std::chrono::hours(24 *7));
    store(context);
}


