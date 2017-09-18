//
// Created by Matthias Hofstätter on 18.09.17.
//

#ifndef PLEXDRIVE_REVISIONS_H
#define PLEXDRIVE_REVISIONS_H


#include <string>
#include "revision.h"
#include "revisionList.h"

using namespace std;

class revisions {
public:
    static void del(string fileId, string revisionId,
                    bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static revision get(string fileId, string revisionId, bool acknowledgeAbuse = false,
                        bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static revisionList list(string fileId, int pageSize = 200, string pageToken = "",
                             bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static revision update(string fileId, string revisionId, revision requestBody,
                           bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
};


#endif //PLEXDRIVE_REVISIONS_H
