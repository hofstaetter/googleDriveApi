//
// Created by Matthias Hofstätter on 15.09.17.
//

#ifndef PLEXDRIVE_GOOGLEDRIVEAPICOMMENTS_H
#define PLEXDRIVE_GOOGLEDRIVEAPICOMMENTS_H


#include <string>
#include "classes/comment.h"
#include "classes/commentList.h"

class comments {
    static comment create(string fileId, comment requestBody = {},
                                   bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static void del(string commentId, string fileId,
                    bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static comment get(string commentId, string fileId, bool includeDeleted = false,
                                bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static commentList list(string fileId, bool includeDeleted = false, int pageSize = 20, string pageToken = "", string startModifiedTime = "",
                                     bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static comment update(string fileId, string commentId, comment requestBody,
                                   bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
};


#endif //PLEXDRIVE_GOOGLEDRIVEAPICOMMENTS_H
