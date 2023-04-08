INCLUDEPATH += $$PWD

HEADERS += \
  $$PWD/orm_implementions/t0002_apps.h \
  $$PWD/orm_implementions/t0009_appuser_logintoken.h \
  $$PWD/orm_implementions/t0021_right_group.h \
  $$PWD/orm_implementions/t0022_right_group2appuser.h \
  $$PWD/orm_implementions/t0023_right2rightgroup.h \
  $$PWD/orm_implementions/t0026_appuser_tag.h \
  $$PWD/orm_implementions/t0027_app_images.h \
  $$PWD/orm_implementions/yacormfactory.h \
  $$PWD/orm_implementions/yacbaseobject.h \
  $$PWD/orm/ormfactory.h \
  $$PWD/orm/ormdefinitions.h \
  $$PWD/orm/ormobjectinterface.h \
  $$PWD/orm/ormpropertyinterface.h \
  $$PWD/orm/ormpropertysizet.h \
  $$PWD/orm/ormpropertydatetime.h \
  $$PWD/orm/ormpropertystring.h \
  $$PWD/orm/ormpropertyuuid.h \
  $$PWD/orm/ormpropertybool.h \
  $$PWD/orm/ormpropertyint.h \
  $$PWD/orm/ormpropertyoid.h \
  $$PWD/orm/ormtemplatedpropertyinterface.h \
  $$PWD/rightnumbers.h \
  $$PWD/tablefields.h \
  $$PWD/yacappandservermacros.h \
  $$PWD/container/indexedpointercontainer.h \
  $$PWD/yacappservermethodnames.h

SOURCES += \
  $$PWD/orm_implementions/t0009_appuser_logintoken.cpp \
  $$PWD/orm_implementions/t0002_apps.cpp \
  $$PWD/orm_implementions/t0021_right_group.cpp \
  $$PWD/orm_implementions/t0022_right_group2appuser.cpp \
  $$PWD/orm_implementions/t0023_right2rightgroup.cpp \
  $$PWD/orm_implementions/t0026_appuser_tag.cpp \
  $$PWD/orm_implementions/yacbaseobject.cpp \
  $$PWD/orm_implementions/yacormfactory.cpp \
  $$PWD/orm_implementions/t0027_app_images.cpp \
  $$PWD/orm/ormfactory.cpp \
  $$PWD/orm/ormobjectinterface.cpp \
  $$PWD/orm/ormpropertyinterface.cpp \
  $$PWD/orm/ormpropertysizet.cpp \
  $$PWD/orm/ormpropertydatetime.cpp \
  $$PWD/orm/ormpropertystring.cpp \
  $$PWD/orm/ormpropertyuuid.cpp \
  $$PWD/orm/ormpropertybool.cpp \
  $$PWD/orm/ormpropertyint.cpp \
  $$PWD/orm/ormpropertyoid.cpp \
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
