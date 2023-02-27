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
    MACRO_ConstString(deleteAppointmentTemplate);
    MACRO_ConstString(fetchAppointmentTemplates);
    MACRO_ConstString(insertAppointment);
    MACRO_ConstString(deleteAppointment);
    MACRO_ConstString(fetchAppointments);

    MACRO_ConstString(fetchRightGroups);
    MACRO_ConstString(insertRightGroup);
    MACRO_ConstString(updateRightGroup);
    MACRO_ConstString(deleteRightGroup);

    MACRO_ConstString(insertRight);
    MACRO_ConstString(deleteRight);
    YACAPPServerMethodNames() {}
};

#endif // YACAPPSERVERMETHODNAMES_H
