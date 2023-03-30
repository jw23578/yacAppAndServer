INCLUDEPATH += $$PWD

HEADERS += \
  $$PWD/orm_implementions/t0009_appuser_logintoken.h \
  $$PWD/orm_implementions/t0026_appuser_tag.h \
  $$PWD/orm/ormdefinitions.h \
  $$PWD/orm/ormobjectinterface.h \
  $$PWD/orm/ormpropertyinterface.h \
  $$PWD/orm/ormpropertysizet.h \
  $$PWD/orm/ormpropertydatetime.h \
  $$PWD/orm/ormpropertystring.h \
  $$PWD/orm/ormpropertyuuid.h \
  $$PWD/orm/ormtemplatedpropertyinterface.h \
  $$PWD/rightnumbers.h \
  $$PWD/tablefields.h \
  $$PWD/yacappandservermacros.h \
  $$PWD/yacappservermethodnames.h

SOURCES += \
  $$PWD/orm_implementions/t0009_appuser_logintoken.cpp \
  $$PWD/orm_implementions/t0026_appuser_tag.cpp \
  $$PWD/orm/ormobjectinterface.cpp \
  $$PWD/orm/ormpropertyinterface.cpp \
  $$PWD/orm/ormpropertysizet.cpp \
  $$PWD/orm/ormpropertydatetime.cpp \
  $$PWD/orm/ormpropertystring.cpp \
  $$PWD/orm/ormpropertyuuid.cpp \
  $$PWD/orm/ormtemplatedpropertyinterface.cpp \
  $$PWD/rightnumbers.cpp

contains(DEFINES, ORMCPPTypes){
SOURCES += \
  $$PWD/sole/sole.cpp \
  $$PWD/utils/extstring.cpp

HEADERS += \
  $$PWD/sole/sole.hpp \
  $$PWD/utils/extstring.h
}
