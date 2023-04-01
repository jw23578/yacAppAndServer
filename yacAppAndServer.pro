QT -= gui

DEFINES += YACAPPServer
DEFINES += ORMCPPTypes

CONFIG += c++17 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
  main.cpp \
  orm/ormobjectinterface.cpp \
  orm/ormpropertybool.cpp \
  orm/ormpropertyinterface.cpp \
  orm/ormpropertysizet.cpp \
  orm/ormpropertydatetime.cpp \
  orm/ormpropertystring.cpp \
  orm/ormpropertyuuid.cpp \
  orm/ormtemplatedpropertyinterface.cpp \
  orm_implementions/ormfactory.cpp \
  orm_implementions/t0009_appuser_logintoken.cpp \
  orm_implementions/t0021_right_group.cpp \
  orm_implementions/t0026_appuser_tag.cpp \
  rightnumbers.cpp \
  sole/sole.cpp \
  utils/extstring.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
  orm/ormdefinitions.h \
  orm/ormobjectinterface.h \
  orm/ormpropertybool.h \
  orm/ormpropertydatetime.h \
  orm/ormpropertyinterface.h \
  orm/ormpropertysizet.h \
  orm/ormpropertystring.h \
  orm/ormpropertyuuid.h \
  orm/ormtemplatedpropertyinterface.h \
  orm_implementions/ormfactory.h \
  orm_implementions/t0009_appuser_logintoken.h \
  orm_implementions/t0021_right_group.h \
  orm_implementions/t0026_appuser_tag.h \
  rightnumbers.h \
  sole/sole.hpp \
  tablefields.h \
  utils/extstring.h \
  yacappandservermacros.h \
  yacappservermethodnames.h

DISTFILES += \
  yacAppAndServer.pri
