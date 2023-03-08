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
    MACRO_ConstString(fetchRightGroup);

    MACRO_ConstString(setRightGroupRights);
    MACRO_ConstString(insertRightGroupMember);
    MACRO_ConstString(deleteRightGroupMember);

    MACRO_ConstString(fetchSpaces);
    MACRO_ConstString(insertSpace);
    MACRO_ConstString(updateSpace);
    MACRO_ConstString(deleteSpace);
    MACRO_ConstString(fetchSpace);

    MACRO_ConstString(requestSpaceAccess);
    MACRO_ConstString(fetchSpaceRequests);
    MACRO_ConstString(approveSpaceAccess);
    MACRO_ConstString(denySpaceAccess);

    MACRO_ConstString(getWorktimeState);
    MACRO_ConstString(fetchWorktimes);

    YACAPPServerMethodNames() {}
};

#endif // YACAPPSERVERMETHODNAMES_H
