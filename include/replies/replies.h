//
// Created by Matthias Hofstätter on 17.09.17.
//

#ifndef PLEXDRIVE_REPLIESGOOGLEDRIVEAPI_H
#define PLEXDRIVE_REPLIESGOOGLEDRIVEAPI_H


#include "classes/reply.h"
#include "classes/replyList.h"

class replies {
public:
    static reply create(string fileId, string commentId, reply requestBody,
                                  bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static void del(string fileId, string commentId, string replyId,
                    bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static reply get(string fileId, string commentId, string replyId, bool includeDeleted = false,
                               bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static replyList list(string fileId, string commentId, bool includeDeleted = false, int pageSize = 20, string pageToken = "",
                          bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static reply update(string fileId, string commentId, string replyId, reply requestBody,
                        bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
};


#endif //PLEXDRIVE_REPLIESGOOGLEDRIVEAPI_H
