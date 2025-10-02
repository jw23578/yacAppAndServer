#include "t0004_user_logintoken.h"
#include "t0002_user.h"

void t0004_user_logintoken::loginSuccessful(CurrentContext &context,
                                            const reducedsole::uuid &userId)
{
    int validHours(24 * 7);
    user_id.set(userId);
    login_token = ExtUuid::generateUuid().str();
    login_token_valid_until.set(std::chrono::system_clock::now() + std::chrono::hours(1) * validHours);
    store(context);
}

void t0004_user_logintoken::disableLoginTokenByUserId(CurrentContext &context,
                                                      const reducedsole::uuid &userId)
{
    t0004_user_logintoken logintoken;
    ORMVector<t0004_user_logintoken> logintokenVector;
    logintoken.fetchObjects(context, {{logintoken.user_id.name(), userId.str()}}, logintokenVector);
    for (size_t i(0); logintokenVector.size(); ++i)
    {
        logintokenVector[i].erase(context);
    }
}

bool t0004_user_logintoken::logoutUserByLoginToken(CurrentContext &context,
                                                   const std::string logintoken)
{
    t0004_user_logintoken loginToken;
    if (!loginToken.load(context, {{loginToken.login_token.name(), logintoken}}))
    {
        return false;
    }
    loginToken.erase(context);
    return true;
}

bool t0004_user_logintoken::userLoggedIn(CurrentContext &context,
                                         const std::string &loginEMail,
                                         const std::string &loginToken)
{
    std::string ignored;
    t0002_user user;
    if (!user.lookupUser(context, loginEMail, ignored))
    {
        return false;
    }
    return load(context, {{user_id.name(), user.user_id.asString()},
                          {login_token.name(), loginToken}});
}

void t0004_user_logintoken::refresh(CurrentContext &context,
                                    const std::string &loginToken)
{
    if (!load(context, {{user_id.name(), context.userId.str()},
                        {login_token.name(), loginToken}}))
    {
        return;
    }
    login_token_valid_until = std::chrono::system_clock::now() + std::chrono::hours(24 *7);
    store(context);
}


