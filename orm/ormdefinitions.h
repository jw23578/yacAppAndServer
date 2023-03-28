#ifndef ORMDEFINITIONS_H
#define ORMDEFINITIONS_H

#ifdef ORMQTTypes
#include <QString>
#include <QDateTime>
typedef QString ORMString;
typedef QDateTime ORMDateTime;
#endif

#ifdef ORMCPPTypes
#include <string>
#include <chrono>
typedef std::string ORMString;
typedef std::chrono::system_clock::time_point ORMDateTime;
#endif


#endif // ORMDEFINITIONS_H
