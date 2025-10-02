#ifndef RIGHTNUMBERS_H
#define RIGHTNUMBERS_H

#include "definitions.h"
#include <set>
#ifdef YACAPPServer
#include <string>
#include <map>
#endif
#ifdef YACAPPApp
#include <map>
#include <QString>
#endif

class RightNumber;

namespace Rights
{
extern const ORMString Administrator;
extern std::set<int> allRightNumbers;
extern std::map<int, RightNumber*> allRightNumberObjects;
}

class RightNumber
{
public:
    int number;

#ifdef YACAPPServer
    std::string meaning;
    RightNumber(int number, const std::string &meaning):number(number), meaning(meaning)
    {
        if (number <= 0)
        {
            return;
        }
        Rights::allRightNumbers.insert(number);
        Rights::allRightNumberObjects[number] = this;
    }
#endif
#ifdef YACAPPApp
    QString meaning;
    RightNumber(int number, const QString &meaning):number(number), meaning(meaning)
    {
        if (number == -1)
        {
            return;
        }
        Rights::allRightNumbers.insert(number);
        Rights::allRightNumberObjects[number] = this;
    }

#endif
};

namespace Rights
{
extern const RightNumber RN_noOne;
extern const RightNumber RN_everybody;
extern const RightNumber RN_changeRightsGroups;
extern const RightNumber RN_changeSpaces;
};

#endif // RIGHTNUMBERS_H
