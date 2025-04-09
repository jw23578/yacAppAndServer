QT -= gui

DEFINES += YACAPPServer
DEFINES += ORMCPPTypes
#DEFINES += ORMQTTypes

CONFIG += console
QMAKE_CXXFLAGS += -std=c++2a
CONFIG -= app_bundle

include("../JWUtils/JWUtils.pri")

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
  main.cpp \
  orm/ormfactory.cpp \
  orm/ormmap.cpp \
  orm/ormobjectinterface.cpp \
  orm/ormpersistenceinterface.cpp \
  orm/ormpropertybool.cpp \
  orm/ormpropertyint.cpp \
  orm/ormpropertyinterface.cpp \
  orm/ormpropertyoid.cpp \
  orm/ormpropertysizet.cpp \
  orm/ormpropertydatetime.cpp \
  orm/ormpropertystring.cpp \
  orm/ormpropertyuuid.cpp \
  orm/ormsqlinterface.cpp \
  orm/ormtemplatedpropertyinterface.cpp \
  orm_implementions/appbaseobject.cpp \
  orm_implementions/t0001_users.cpp \
  orm_implementions/t0002_apps.cpp \
  orm_implementions/t0003_appuser_profiles.cpp \
  orm_implementions/t0004_appuser_passwordhashes.cpp \
  orm_implementions/t0009_appuser_logintoken.cpp \
  orm_implementions/t0016_appointment_templates.cpp \
  orm_implementions/t0018_appointment.cpp \
  orm_implementions/t0021_right_group.cpp \
  orm_implementions/t0022_right_group2appuser.cpp \
  orm_implementions/t0023_right2rightgroup.cpp \
  orm_implementions/t0026_appuser_tag.cpp \
  orm_implementions/t0027_app_images.cpp \
  orm_implementions/t0028_message_images.cpp \
  orm_implementions/t0029_third_party_user_data.cpp \
  orm_implementions/t0030_documents.cpp \
  orm_implementions/t0031_catchphrases.cpp \
  orm_implementions/t0032_catchphrase2document.cpp \
  orm_implementions/t0033_words.cpp \
  orm_implementions/t0034_word2document.cpp \
  orm_implementions/yacbaseobject.cpp \
  orm_implementions/yacormfactory.cpp \
  rightnumbers.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
  container/indexedpointercontainer.h \
  orm/ormdefinitions.h \
  orm/ormfactory.h \
  orm/ormmap.h \
  orm/ormobjectinterface.h \
  orm/ormpersistenceinterface.h \
  orm/ormpropertybool.h \
  orm/ormpropertydatetime.h \
  orm/ormpropertyint.h \
  orm/ormpropertyinterface.h \
  orm/ormpropertyoid.h \
  orm/ormpropertysizet.h \
  orm/ormpropertystring.h \
  orm/ormpropertyuuid.h \
  orm/ormsqlinterface.h \
  orm/ormtemplatedpropertyinterface.h \
  orm_implementions/appbaseobject.h \
  orm_implementions/t0001_users.h \
  orm_implementions/t0002_apps.h \
  orm_implementions/t0003_appuser_profiles.h \
  orm_implementions/t0004_appuser_passwordhashes.h \
  orm_implementions/t0009_appuser_logintoken.h \
  orm_implementions/t0016_appointment_templates.h \
  orm_implementions/t0018_appointment.h \
  orm_implementions/t0021_right_group.h \
  orm_implementions/t0022_right_group2appuser.h \
  orm_implementions/t0023_right2rightgroup.h \
  orm_implementions/t0026_appuser_tag.h \
  orm_implementions/t0027_app_images.h \
  orm_implementions/t0028_message_images.h \
  orm_implementions/t0029_third_party_user_data.h \
  orm_implementions/t0030_documents.h \
  orm_implementions/t0031_catchphrases.h \
  orm_implementions/t0032_catchphrase2document.h \
  orm_implementions/t0033_words.h \
  orm_implementions/t0034_word2document.h \
  orm_implementions/yacbaseobject.h \
  orm_implementions/yacormfactory.h \
  rightnumbers.h \
  tablefields.h \
  tablenames.h \
  yacappandservermacros.h \
  yacappservermethodnames.h

DISTFILES += \
  yacAppAndServer.pri
