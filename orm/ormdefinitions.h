#ifndef ORMDEFINITIONS_H
#define ORMDEFINITIONS_H

#ifdef ORMQTTypes
#include <QString>
#include <QDateTime>
typedef QString ORMString;
typedef QDateTime ORMDateTime;
typedef QString ORMUuid;
ORMUuid generateUuid() {return QUuid::createUuid().toString(QUuid::WithoutBraces);}
ORMString uuidToString(ORMUuid const &id) {return id;}
#endif

#ifdef ORMCPPTypes
#include <string>
#include <chrono>
#include "sole/sole.hpp"
typedef std::string ORMString;
typedef std::chrono::system_clock::time_point ORMDateTime;
typedef sole::uuid ORMUuid;
ORMUuid generateUuid() {return sole::uuid4();}
ORMString uuidToString(ORMUuid const &id) {return id.str();}
#define Q_OBJECT
#endif


#endif // ORMDEFINITIONS_H
