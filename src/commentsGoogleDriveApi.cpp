//
// Created by Matthias Hofstätter on 15.09.17.
//

#include "comments/commentsGoogleDriveApi.h"

commentsResource
commentsGoogleDriveApi::create(string fileId, commentsResource requestBody, bool alt, string fields, bool prettyPrint,
                               string quotaUser, string userId) {
    return commentsResource();
}

void commentsGoogleDriveApi::del(string commentId, string fileId, bool alt, string fields, bool prettyPrint,
                                 string quotaUser, string userId) {

}

commentsResource
commentsGoogleDriveApi::get(string commentId, string fileId, bool includeDeleted, bool alt, string fields,
                            bool prettyPrint, string quotaUser, string userId) {
    return commentsResource();
}

commentsListResponse commentsGoogleDriveApi::list(string fileId, bool includeDeleted, int pageSize, string pageToken,
                                                  string startModifiedTime, bool alt, string fields, bool prettyPrint,
                                                  string quotaUser, string userId) {
    return commentsListResponse();
}

commentsResource
commentsGoogleDriveApi::update(string fileId, string commentId, commentsResource requestBody, bool alt, string fields,
                               bool prettyPrint, string quotaUser, string userId) {
    return commentsResource();
}
