#ifndef YACAPPSERVERMETHODNAMES_H
#define YACAPPSERVERMETHODNAMES_H

#include "yacappandservermacros.h"

class YACAPPServerMethodNames
{
public:
    MACRO_ConstString(updateDeviceToken);
    MACRO_ConstString(updateAppUserProfile);
    MACRO_ConstString(requestVerifyToken);
    MACRO_ConstString(registerAppUser);
    MACRO_ConstString(fetchProfile);
    MACRO_ConstString(fetchMyProfile);
    MACRO_ConstString(insertAppointmentTemplate);
    MACRO_ConstString(updateAppointmentTemplate);
    MACRO_ConstString(fetchAppointmentTemplates);
    YACAPPServerMethodNames();
};

#endif // YACAPPSERVERMETHODNAMES_H
