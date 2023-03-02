#ifndef RIGHTNUMBERS_H
#define RIGHTNUMBERS_H

#include <set>
#ifdef YACAPPServer
#include <string>
#endif
#ifdef YACAPPApp
#include <QString>
#endif

namespace Rights
{
    extern std::set<int> allRightNumbers;
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
    }
#endif
#ifdef YACAPPApp
    QString meaning;
    RightNumber(int number, const QString &meaning):number(number), meaning(meaning)
    {
        Rights::allRightNumbers.insert(number);
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
