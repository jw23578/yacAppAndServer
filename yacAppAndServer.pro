QT -= gui

DEFINES += YACAPPServer
#DEFINES += ORMCPPTypes
DEFINES += ORMQTTypes

CONFIG += c++17 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
  container/indexedpointercontainer.cpp \
  main.cpp \
  orm/ormfactory.cpp \
  orm/ormobjectinterface.cpp \
  orm/ormpropertybool.cpp \
  orm/ormpropertyint.cpp \
  orm/ormpropertyinterface.cpp \
  orm/ormpropertyoid.cpp \
  orm/ormpropertysizet.cpp \
  orm/ormpropertydatetime.cpp \
  orm/ormpropertystring.cpp \
  orm/ormpropertyuuid.cpp \
  orm/ormtemplatedpropertyinterface.cpp \
  orm_implementions/t0002_apps.cpp \
  orm_implementions/t0009_appuser_logintoken.cpp \
  orm_implementions/t0021_right_group.cpp \
  orm_implementions/t0022_right_group2appuser.cpp \
  orm_implementions/t0023_right2rightgroup.cpp \
  orm_implementions/t0026_appuser_tag.cpp \
  orm_implementions/t0027_app_images.cpp \
  orm_implementions/yacbaseobject.cpp \
  orm_implementions/yacormfactory.cpp \
  rightnumbers.cpp \
  sole/sole.cpp \
  utils/extstring.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
  container/indexedpointercontainer.h \
  orm/ormdefinitions.h \
  orm/ormfactory.h \
  orm/ormobjectinterface.h \
  orm/ormpropertybool.h \
  orm/ormpropertydatetime.h \
  orm/ormpropertyint.h \
  orm/ormpropertyinterface.h \
  orm/ormpropertyoid.h \
  orm/ormpropertysizet.h \
  orm/ormpropertystring.h \
  orm/ormpropertyuuid.h \
  orm/ormtemplatedpropertyinterface.h \
  orm_implementions/t0002_apps.h \
  orm_implementions/t0009_appuser_logintoken.h \
  orm_implementions/t0021_right_group.h \
  orm_implementions/t0022_right_group2appuser.h \
  orm_implementions/t0023_right2rightgroup.h \
  orm_implementions/t0026_appuser_tag.h \
  orm_implementions/t0027_app_images.h \
  orm_implementions/yacbaseobject.h \
  orm_implementions/yacormfactory.h \
  rightnumbers.h \
  sole/sole.hpp \
  tablefields.h \
  utils/extstring.h \
  yacappandservermacros.h \
  yacappservermethodnames.h

DISTFILES += \
  yacAppAndServer.pri
