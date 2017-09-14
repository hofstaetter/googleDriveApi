//
// Created by Matthias Hofstätter on 15.09.17.
//

#include "permissionsGoogleDriveApi.h"

permissionsResource permissionsGoogleDriveApi::create(string fileId, string emailMessage, bool sendNotificationEmail,
                                                      bool suportsTeamDrives, bool transferOwnership,
                                                      permissionsResource requestBody, bool alt, string fields,
                                                      bool prettyPrint, string quotaUser, string userId) {
    return permissionsResource();
}

void
permissionsGoogleDriveApi::del(string fileId, string permissionId, bool supportsTeamDrives, bool alt, string fields,
                               bool prettyPrint, string quotaUser, string userId) {

}

permissionsResource
permissionsGoogleDriveApi::get(string fileId, string permissionId, bool supportsTeamDrives, bool alt, string fields,
                               bool prettyPrint, string quotaUser, string userId) {
    return permissionsResource();
}

permissionsListResponse
permissionsGoogleDriveApi::list(string fileId, int pageSize, string pageToken, bool supportsTeamDrives, bool alt,
                                string fields, bool prettyPrint, string quotaUser, string userId) {
    return permissionsListResponse();
}

permissionsResource
permissionsGoogleDriveApi::update(string fileId, string permissionId, bool removeExpiration, bool supportsTeamDrives,
                                  bool transferOwnership, bool alt, string fields, bool prettyPrint, string quotaUser,
                                  string userId) {
    return permissionsResource();
}
