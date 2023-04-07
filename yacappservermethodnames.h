#ifndef YACAPPSERVERMETHODNAMES_H
#define YACAPPSERVERMETHODNAMES_H

#include "yacappandservermacros.h"

class YACAPPServerMethodNames
{
public:
    MACRO_ConstString(getAllAPPs);
    MACRO_ConstString(getAPP);

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

    MACRO_ConstString(deleteRightGroup);
    MACRO_ConstString(fetchRightGroup);
    MACRO_ConstString(rightGroupRequestResultSeen);
    MACRO_ConstString(fetchRightGroupMember);

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
    MACRO_ConstString(spaceRequestResultSeen);

    MACRO_ConstString(getWorktimeState);
    MACRO_ConstString(fetchWorktimes);
    MACRO_ConstString(insertWorktime);
    MACRO_ConstString(insertWorktimeBeginEnd);
    MACRO_ConstString(deleteWorktime);

    YACAPPServerMethodNames() {}
};

#endif // YACAPPSERVERMETHODNAMES_H
