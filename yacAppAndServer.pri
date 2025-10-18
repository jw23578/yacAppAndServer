INCLUDEPATH += $$PWD
QMAKE_CXXFLAGS += -std=c++2a

HEADERS += \
  $$PWD/orm_implementions/appbaseobject.h \
  $$PWD/orm_implementions/currentcontext.h \
  $$PWD/orm_implementions/t0001_apps.h \
  $$PWD/orm_implementions/t0002_user.h \
  $$PWD/orm_implementions/t0003_user_passwordhashes.h \
  $$PWD/orm_implementions/t0004_user_logintoken.h \
  $$PWD/orm_implementions/t0005_group_of_appusers.h \
  $$PWD/orm_implementions/t0006_appuser2group.h \
  $$PWD/orm_implementions/t0007_messages.h \
  $$PWD/orm_implementions/t0008_message_received.h \
  $$PWD/orm_implementions/t0009_largeobject.h \
  $$PWD/orm_implementions/t0010_largeobject2object.h \
  $$PWD/orm_implementions/t0010_task.h \
  $$PWD/orm_implementions/t0011_task_time.h \
  $$PWD/orm_implementions/t0012_worktime.h \
  $$PWD/orm_implementions/t0015_user_devicetoken.h \
  $$PWD/orm_implementions/t0016_appointment_templates.h \
  $$PWD/orm_implementions/t0018_appointment.h \
  $$PWD/orm_implementions/t0021_right_group.h \
  $$PWD/orm_implementions/t0022_right_group2user.h \
  $$PWD/orm_implementions/t0023_right2rightgroup.h \
  $$PWD/orm_implementions/t0026_appuser_tag.h \
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
  $$PWD/orm_implementions/currentcontext.cpp \
  $$PWD/orm_implementions/t0001_apps.cpp \
  $$PWD/orm_implementions/t0002_user.cpp \
  $$PWD/orm_implementions/t0003_user_passwordhashes.cpp \
  $$PWD/orm_implementions/t0004_user_logintoken.cpp \
  $$PWD/orm_implementions/t0005_group_of_appusers.cpp \
  $$PWD/orm_implementions/t0006_appuser2group.cpp \
  $$PWD/orm_implementions/t0007_messages.cpp \
  $$PWD/orm_implementions/t0008_message_received.cpp \
  $$PWD/orm_implementions/t0009_largeobject.cpp \
  $$PWD/orm_implementions/t0010_largeobject2object.cpp \
  $$PWD/orm_implementions/t0010_task.cpp \
  $$PWD/orm_implementions/t0011_task_time.cpp \
  $$PWD/orm_implementions/t0012_worktime.cpp \
  $$PWD/orm_implementions/t0015_user_devicetoken.cpp \
  $$PWD/orm_implementions/t0016_appointment_templates.cpp \
  $$PWD/orm_implementions/t0018_appointment.cpp \
  $$PWD/orm_implementions/t0021_right_group.cpp \
  $$PWD/orm_implementions/t0022_right_group2user.cpp \
  $$PWD/orm_implementions/t0023_right2rightgroup.cpp \
  $$PWD/orm_implementions/t0026_appuser_tag.cpp \
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
