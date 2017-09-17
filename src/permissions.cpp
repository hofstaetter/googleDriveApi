//
// Created by Matthias Hofstätter on 15.09.17.
//

#include "permissions/permissions.h"

permission permissions::create(string fileId, string emailMessage, bool sendNotificationEmail,
                                                      bool suportsTeamDrives, bool transferOwnership,
                                                      permission requestBody, bool alt, string fields,
                                                      bool prettyPrint, string quotaUser, string userId) {
    return permission();
}

void
permissions::del(string fileId, string permissionId, bool supportsTeamDrives, bool alt, string fields,
                               bool prettyPrint, string quotaUser, string userId) {

}

permission
permissions::get(string fileId, string permissionId, bool supportsTeamDrives, bool alt, string fields,
                               bool prettyPrint, string quotaUser, string userId) {
    return permission();
}

permissionList
permissions::list(string fileId, int pageSize, string pageToken, bool supportsTeamDrives, bool alt,
                                string fields, bool prettyPrint, string quotaUser, string userId) {
    return permissionList();
}

permission
permissions::update(string fileId, string permissionId, bool removeExpiration, bool supportsTeamDrives,
                                  bool transferOwnership, bool alt, string fields, bool prettyPrint, string quotaUser,
                                  string userId) {
    return permission();
}
