#ifndef RIGHTNUMBERS_H
#define RIGHTNUMBERS_H

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
extern const std::string Administrator;
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
        Rights::allRightNumbers.insert(number);
        Rights::allRightNumberObjects[number] = this;
    }
#endif
#ifdef YACAPPApp
    QString meaning;
    RightNumber(int number, const QString &meaning):number(number), meaning(meaning)
    {
        Rights::allRightNumbers.insert(number);
        Rights::allRightNumberObjects[number] = this;
    }

#endif
};

namespace Rights
{
extern const RightNumber RN_addRightNumberToGroup;
extern const RightNumber RN_deleteRightNumberToGroup;
extern const RightNumber RN_insertRightGroup;
extern const RightNumber RN_updateRightGroup;
extern const RightNumber RN_deleteRightGroup;
};

#endif // RIGHTNUMBERS_H
