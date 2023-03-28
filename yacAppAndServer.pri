HEADERS += \
  $$PWD/orm/ormdefinitions.h \
  $$PWD/orm/ormobjectinterface.h \
  $$PWD/orm/ormpropertyinterface.h \
  $$PWD/orm/ormpropertysizet.h \
  $$PWD/orm/ormtemplatedpropertyinterface.h \
  $$PWD/rightnumbers.h \
  $$PWD/tablefields.h \
  $$PWD/yacappandservermacros.h \
  $$PWD/yacappservermethodnames.h

SOURCES += \
  $$PWD/orm/ormobjectinterface.cpp \
  $$PWD/orm/ormpropertyinterface.cpp \
  $$PWD/orm/ormpropertysizet.cpp \
  $$PWD/orm/ormtemplatedpropertyinterface.cpp \
  $$PWD/rightnumbers.cpp

contains(DEFINES, ORMCPPTypes){
SOURCES += \
  $$PWD/sole/sole.cpp

HEADERS += \
  $$PWD/sole/sole.hpp
}
