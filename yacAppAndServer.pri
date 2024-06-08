INCLUDEPATH += $$PWD

HEADERS += \
  $$PWD/orm_implementions/t0002_apps.h \
  $$PWD/orm_implementions/t0003_appuser_profiles.h \
  $$PWD/orm_implementions/t0009_appuser_logintoken.h \
  $$PWD/orm_implementions/t0016_appointment_templates.h \
  $$PWD/orm_implementions/t0018_appointment.h \
  $$PWD/orm_implementions/t0021_right_group.h \
  $$PWD/orm_implementions/t0022_right_group2appuser.h \
  $$PWD/orm_implementions/t0023_right2rightgroup.h \
  $$PWD/orm_implementions/t0026_appuser_tag.h \
  $$PWD/orm_implementions/t0027_app_images.h \
  $$PWD/orm_implementions/t0028_message_images.h \
  $$PWD/orm_implementions/t0029_third_party_user_data.h \
  $$PWD/orm_implementions/t0030_documents.h \
  $$PWD/orm_implementions/t0031_catchphrases.h \
  $$PWD/orm_implementions/t0032_catchphrase2document.h \
  $$PWD/orm_implementions/t0033_words.h \
  $$PWD/orm_implementions/t0034_word2document.h \
  $$PWD/orm_implementions/yacormfactory.h \
  $$PWD/orm_implementions/yacbaseobject.h \
  $$PWD/orm_implementions/sqlstring.h \
  $$PWD/orm/ormfactory.h \
  $$PWD/orm/ormmap.h \
  $$PWD/orm/ormdefinitions.h \
  $$PWD/orm/ormsqlinterface.h \
  $$PWD/orm/ormobjectinterface.h \
  $$PWD/orm/ormpersistenceinterface.cpp \
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
  $$PWD/tablenames.h \
  $$PWD/utils/extuuid.h \
  $$PWD/yacappandservermacros.h \
  $$PWD/container/indexedpointercontainer.h \
  $$PWD/yacappservermethodnames.h

SOURCES += \
  $$PWD/orm_implementions/t0009_appuser_logintoken.cpp \
  $$PWD/orm_implementions/t0002_apps.cpp \
  $$PWD/orm_implementions/t0003_appuser_profiles.cpp \
  $$PWD/orm_implementions/t0016_appointment_templates.cpp \
  $$PWD/orm_implementions/t0018_appointment.cpp \
  $$PWD/orm_implementions/t0021_right_group.cpp \
  $$PWD/orm_implementions/t0022_right_group2appuser.cpp \
  $$PWD/orm_implementions/t0023_right2rightgroup.cpp \
  $$PWD/orm_implementions/t0026_appuser_tag.cpp \
  $$PWD/orm_implementions/t0027_app_images.cpp \
  $$PWD/orm_implementions/t0028_message_images.cpp \
  $$PWD/orm_implementions/t0029_third_party_user_data.cpp \
  $$PWD/orm_implementions/t0030_documents.cpp \
  $$PWD/orm_implementions/t0031_catchphrases.cpp \
  $$PWD/orm_implementions/t0032_catchphrase2document.cpp \
  $$PWD/orm_implementions/t0033_words.cpp \
  $$PWD/orm_implementions/t0034_word2document.cpp \
  $$PWD/orm_implementions/yacbaseobject.cpp \
  $$PWD/orm_implementions/yacormfactory.cpp \
  $$PWD/orm_implementions/sqlstring.cpp \
  $$PWD/orm/ormfactory.cpp \
  $$PWD/orm/ormmap.cpp \
  $$PWD/orm/ormsqlinterface.cpp \
  $$PWD/orm/ormobjectinterface.cpp \
  $$PWD/orm/ormpersistenceinterface.cpp \
  $$PWD/orm/ormpropertyinterface.cpp \
  $$PWD/orm/ormpropertysizet.cpp \
  $$PWD/orm/ormpropertydatetime.cpp \
  $$PWD/orm/ormpropertystring.cpp \
  $$PWD/orm/ormpropertyuuid.cpp \
  $$PWD/orm/ormpropertybool.cpp \
  $$PWD/orm/ormpropertyint.cpp \
  $$PWD/orm/ormpropertyoid.cpp \
  $$PWD/orm/ormtemplatedpropertyinterface.cpp \
  $$PWD/rightnumbers.cpp \
  $$PWD/utils/extuuid.cpp

contains(DEFINES, ORMCPPTypes){
SOURCES += \
  $$PWD/sole/sole.cpp \
  $$PWD/utils/extstring.cpp

HEADERS += \
  $$PWD/sole/sole.hpp \
  $$PWD/utils/extstring.h \
  $$PWD/utils/definitions.h
}
