#ifndef RIGHTNUMBERS_H
#define RIGHTNUMBERS_H

#ifdef YACAPPServer
#include <string>
#endif
#ifdef YACAPPApp
#include <QString>
#endif


class RightNumber
{
public:
    int number;

#ifdef YACAPPServer
    std::string meaning;
    RightNumber(int number, const std::string &meaning):number(number), meaning(meaning) {}
#endif
#ifdef YACAPPApp
    QString meaning;
    RightNumber(int number, const QString &meaning):number(number), meaning(meaning) {}
#endif
};

class Rights
{
    const RightNumber RN_addRightNumberToGroup{1, "Add a Right to a Rightgroup"};
    const RightNumber RN_deleteRightNumberToGroup{2, "Delete a Right from a Rightgroup"};
    const RightNumber RN_insertRightGroup{3, "Add a Rightgroup"};
    const RightNumber RN_updateRightGroup{4, "Change a Rightgroup"};
    const RightNumber RN_deleteRightGroup{5, "Delete a Rightgroup"};
};

#endif // RIGHTNUMBERS_H
