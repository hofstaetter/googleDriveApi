//
// Created by Matthias Hofstätter on 15.09.17.
//

#ifndef PLEXDRIVE_GOOGLEDRIVEAPICOMMENTS_H
#define PLEXDRIVE_GOOGLEDRIVEAPICOMMENTS_H


#include <string>
#include "commentsResource.h"
#include "commentsListResponse.h"

class commentsGoogleDriveApi {
    static commentsResource create(string fileId, commentsResource requestBody = {},
                                   bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static void del(string commentId, string fileId,
                    bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static commentsResource get(string commentId, string fileId, bool includeDeleted = false,
                                bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static commentsListResponse list(string fileId, bool includeDeleted = false, int pageSize = 20, string pageToken = "", string startModifiedTime = "",
                                     bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static commentsResource update(string fileId, string commentId, commentsResource requestBody,
                                   bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
};


#endif //PLEXDRIVE_GOOGLEDRIVEAPICOMMENTS_H
