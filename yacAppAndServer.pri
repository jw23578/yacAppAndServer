INCLUDEPATH += $$PWD
QMAKE_CXXFLAGS += -std=c++2a

HEADERS += \
  $$PWD/orm_implementions/appbaseobject.h \
  $$PWD/orm_implementions/t0001_users.h \
  $$PWD/orm_implementions/t0002_apps.h \
  $$PWD/orm_implementions/t0003_appuser_profiles.h \
  $$PWD/orm_implementions/t0004_appuser_passwordhashes.h \
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
  $$PWD/orm_implementions/t0035_blobs.h \
  $$PWD/orm_implementions/t0036_rythm.h \
  $$PWD/orm_implementions/t0037_fee.h \
  $$PWD/orm_implementions/yacormfactory.h \
  $$PWD/orm_implementions/yacbaseobject.h \
  $$PWD/rightnumbers.h \
  $$PWD/tablefields.h \
  $$PWD/tablenames.h \
  $$PWD/yacappandservermacros.h \
  $$PWD/container/indexedpointercontainer.h \
  $$PWD/yacappservermethodnames.h

SOURCES += \
  $$PWD/orm_implementions/appbaseobject.cpp \
  $$PWD/orm_implementions/t0001_users.cpp \
  $$PWD/orm_implementions/t0004_appuser_passwordhashes.cpp \
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
  $$PWD/orm_implementions/t0035_blobs.cpp \
  $$PWD/orm_implementions/t0036_rythm.cpp \
  $$PWD/orm_implementions/t0037_fee.cpp \
  $$PWD/orm_implementions/yacbaseobject.cpp \
  $$PWD/orm_implementions/yacormfactory.cpp \
  $$PWD/rightnumbers.cpp

contains(DEFINES, ORMCPPTypes){
SOURCES +=


HEADERS +=
}
