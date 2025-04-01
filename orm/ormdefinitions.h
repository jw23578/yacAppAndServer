#ifndef ORMDEFINITIONS_H
#define ORMDEFINITIONS_H


enum ORMPropertyDetails
{
    DetailDB,
    DetailID,
    DetailDBIndex,
    DetailOnlyTransfer,
    DetailDontTransfer
};

#ifdef ORMQTTypes
#include <QString>
#include <QDateTime>
typedef QString ORMString;
typedef QDateTime ORMDateTime;
typedef QString ORMUuid;
#define MACRO_ORM_STRING_2_STD_STRING(s) \
    s.toStdString()

#define MACRO_STD_STRING_2_ORM_STRING(s) \
    s.c_str()

#endif

#ifdef ORMCPPTypes
#include <string>
#include <chrono>
#include "utils/reducedsole.h"
typedef std::string ORMString;
typedef std::chrono::system_clock::time_point ORMDateTime;
typedef reducedsole::uuid ORMUuid;
#define MACRO_ORM_STRING_2_STD_STRING(s) s
#define MACRO_STD_STRING_2_ORM_STRING(s) s
#define Q_OBJECT
#endif

#endif // ORMDEFINITIONS_H
