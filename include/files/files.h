//
// Created by Matthias Hofstätter on 20.08.17.
//

#ifndef GOOGLEDRIVEAPI_GOOGLEDRIVEAPI_H
#define GOOGLEDRIVEAPI_GOOGLEDRIVEAPI_H

#include <curl/curl.h>
#include <rapidjson.h>
#include <document.h>
#include "classes/file.h"
#include "classes/generatedIds.h"
#include "classes/fileList.h"
#include "classes/channel.h"
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <iostream>
#include "files.h"
#include "classes/https.h"
#include "oauth/googleOAuth.h"
#include "classes/channel.h"

using namespace std;

class files {
public:
    static class file copy(std::string fileId, bool ignoreDefaultVisibility, bool keepRevisionForever, std::string ocrLanguage, bool supportsTeamDrives, file& requestBody,
                                    bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static class file create(std::string uploadType, bool ignoreDefaultVisibility, bool keepRevisionForever, std::string ocrLanguage, bool supportsTeamDrives, bool useContentAsIndexableText, file& requestBody,
                                      bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static bool del(string fileId, bool supportsTeamDrives,
                    bool alt = false, string fields = "", bool prettyPrint = false, string quotaUser = "", string userId = "");
    static bool emptyTrash(bool alt = false, string fields = "", bool prettyPrint = false, string quotaUser = "", string userId = "");
    static file exp(string fileId, string mimeType = "",
                             bool alt = false, string fields = "", bool prettyPrint = false, string quotaUser = "", string userId = "");
    static class generatedIds generateIds(int count = 10, string space = "",
                                                 bool alt = false, string fields = "", bool prettyPrint = false, string quotaUser = "", string userId = "");
    static file get(string fileId, bool acknowledgeAbuse = false, bool supportsTeamDrives = false,
                             bool alt = false, string fields = "", bool prettyPrint = false, string quotaUser = "", string userId = "");
    static class fileList list(string corpora = "", string corpus = "", bool includeTeamDriveItems = false, string orderBy = "", int pageSize = 100, string pageToken = "", string q = "", string spaces = "", bool supportsTeamDrives = false,
                                   string teamDriveId = "",
                                   bool alt = false, string fields = "", bool prettyPrint = false, string quotaUser = "", string userId = "");
    static file update(string fileId, string uploadType,  string addParents, bool keepRevisionForever, string ocrLanguage, string removeParents, bool supportsTeamDrives, bool useContentAsIndexableText, file& requestBody,
                                bool alt = false, string fields = "", bool prettyPrint = false, string quotaUser = "", string userId = "");
    static class channel watch(string fileId, bool acknowledgeAbuse, bool supportsTeamDrives, channel& requestBody,
                                     bool alt = false, string fields = "", bool prettyPrint = false, string quotaUser = "", string userId = "");
};


#endif //GOOGLEDRIVEAPI_GOOGLEDRIVEAPI_H
