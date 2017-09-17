//
// Created by Matthias Hofstätter on 15.09.17.
//

#ifndef PLEXDRIVE_PERMISSIONSGOOGLEDRIVEAPI_H
#define PLEXDRIVE_PERMISSIONSGOOGLEDRIVEAPI_H


#include "classes/permission.h"
#include "classes/permissionList.h"

class permissions {
public:
    static permission create(string fileId, string emailMessage = "", bool sendNotificationEmail = false, bool suportsTeamDrives = false, bool transferOwnership = false, permission requestBody = {},
                                      bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static void del(string fileId, string permissionId, bool supportsTeamDrives = false,
                    bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static permission get(string fileId, string permissionId, bool supportsTeamDrives = false,
                                   bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static permissionList list(string fileId, int pageSize = 100, string pageToken = "", bool supportsTeamDrives = false,
                                        bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static permission update(string fileId, string permissionId, bool removeExpiration = false, bool supportsTeamDrives = false, bool transferOwnership = false,
                                      bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
};


#endif //PLEXDRIVE_PERMISSIONSGOOGLEDRIVEAPI_H
