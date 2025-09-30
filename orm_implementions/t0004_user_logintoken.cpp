#include "t0004_user_logintoken.h"

void t0004_user_logintoken::loginSuccessful(CurrentContext &context,
                                           const reducedsole::uuid &userId)
{
    int validHours(24 * 7);
    user_id.set(userId);
    login_token = ExtUuid::generateUuid().str();
    login_token_valid_until.set(std::chrono::system_clock::now() + std::chrono::hours(1) * validHours);
    store(context);
}

