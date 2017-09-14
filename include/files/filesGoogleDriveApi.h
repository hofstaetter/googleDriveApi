//
// Created by Matthias Hofstätter on 20.08.17.
//

#ifndef GOOGLEDRIVEAPI_GOOGLEDRIVEAPI_H
#define GOOGLEDRIVEAPI_GOOGLEDRIVEAPI_H

#include <curl/curl.h>
#include <rapidjson.h>
#include <document.h>
#include "filesResource.h"
#include "filesGenerateIdsResponse.h"
#include "filesListResponse.h"
#include "filesWatchResponse.h"
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <iostream>
#include "filesGoogleDriveApi.h"
#include "https.h"
#include "oauth/googleOAuth.h"
#include "filesWatchRequest.h"

using namespace std;

class filesGoogleDriveApi {
public:
    static class filesResource copy(std::string fileId, bool ignoreDefaultVisibility, bool keepRevisionForever, std::string ocrLanguage, bool supportsTeamDrives, filesResource& requestBody,
                                    bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static class filesResource create(std::string uploadType, bool ignoreDefaultVisibility, bool keepRevisionForever, std::string ocrLanguage, bool supportsTeamDrives, bool useContentAsIndexableText, filesResource& requestBody,
                                      bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static bool del(string fileId, bool supportsTeamDrives,
                    bool alt = false, string fields = "", bool prettyPrint = false, string quotaUser = "", string userId = "");
    static bool emptyTrash(bool alt = false, string fields = "", bool prettyPrint = false, string quotaUser = "", string userId = "");
    static filesResource exp(string fileId, string mimeType = "",
                             bool alt = false, string fields = "", bool prettyPrint = false, string quotaUser = "", string userId = "");
    static class filesGenerateIdsResponse generateIds(int count = 10, string space = "",
                                                 bool alt = false, string fields = "", bool prettyPrint = false, string quotaUser = "", string userId = "");
    static filesResource get(string fileId, bool acknowledgeAbuse = false, bool supportsTeamDrives = false,
                             bool alt = false, string fields = "", bool prettyPrint = false, string quotaUser = "", string userId = "");
    static class filesListResponse list(string corpora = "", string corpus = "", bool includeTeamDriveItems = false, string orderBy = "", int pageSize = 100, string pageToken = "", string q = "", string spaces = "", bool supportsTeamDrives = false,
                                   string teamDriveId = "",
                                   bool alt = false, string fields = "", bool prettyPrint = false, string quotaUser = "", string userId = "");
    static filesResource update(string fileId, string uploadType,  string addParents, bool keepRevisionForever, string ocrLanguage, string removeParents, bool supportsTeamDrives, bool useContentAsIndexableText, filesResource& requestBody,
                                bool alt = false, string fields = "", bool prettyPrint = false, string quotaUser = "", string userId = "");
    static class filesWatchResponse watch(string fileId, bool acknowledgeAbuse, bool supportsTeamDrives, filesWatchRequest& requestBody,
                                     bool alt = false, string fields = "", bool prettyPrint = false, string quotaUser = "", string userId = "");
};


#endif //GOOGLEDRIVEAPI_GOOGLEDRIVEAPI_H
