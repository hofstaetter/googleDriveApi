//
// Created by Matthias Hofstätter on 20.08.17.
//

#ifndef GOOGLEDRIVEAPI_GOOGLEDRIVEAPI_H
#define GOOGLEDRIVEAPI_GOOGLEDRIVEAPI_H

#include <curl/curl.h>
#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>
#include "classes/filesResource.h"
#include "classes/generateIdsResponse.h"
#include "classes/listResponse.h"
#include "classes/watchResponse.h"
#include <string>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

class googleDriveApi {
private:
    static long request(string host, string path, string type, map<string, string> querystring, map<string, string> header, map<string, string> postfields, string body, rapidjson::Document& response);
public:
    static bool getAuthCode(string code, string clientId, string clientSecret, string redirectUri, string grantType);

    static class filesResource copy(std::string fileId, bool ignoreDefaultVisibility = false, bool keepRevisionForever = false, std::string ocrLanguage = "", bool supportsTeamDrives = false,
                              bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "", filesResource *fr = NULL);
    static class filesResource create(std::string uploadType, bool ignoreDefaultVisibility = false, bool keepRevisionForever = false, std::string ocrLanguage = "", bool supportsTeamDrives = false, bool useContentAsIndexableText = false,
                                bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static bool del(string fileId, bool supportsTeamDrives,
                    bool alt = false, string fields = "", bool prettyPrint = false, string quotaUser = "", string userId = "");
    static bool emptyTrash(bool alt = false, string fields = "", bool prettyPrint = false, string quotaUser = "", string userId = "");
    static filesResource exp(string fileId, string mimeType = "", bool alt = false, string fields = "", bool prettyPrint = false, string quotaUser = "", string userId = "");
    static class generateIdsResponse generateIds(int count = 10, string space = "", bool alt = false, string fields = "", bool prettyPrint = false, string quotaUser = "", string userId = "");
    static filesResource get(string fileId, bool acknowledgeAbuse = false, bool supportsTeamDrives = false,
                             bool alt = false, string fields = "", bool prettyPrint = false, string quotaUser = "", string userId = "");
    static class listResponse list(string corpora = "", string corpus = "", bool includeTeamDriveItems = false, string orderBy = "", int pageSize = 100,
                                      string pageToken = "", string q = "", string spaces = "", bool supportsTeamDrives = false, string teamDriveId = "",
                                      bool alt = false, string fields = "", bool prettyPrint = false, string quotaUser = "", string userId = "");
    static filesResource update(string fileId, string Parents = "", bool keepRevisionForever = false, string ocrLanguage = "", string removeParents = "", bool supportsTeamDrives = false, bool useContentAsIndexableText = false,
                                bool alt = false, string fields = "", bool prettyPrint = false, string quotaUser = "", string userId = "");
    static class watchResponse watch(string fileId, bool acknowledgeAbuse = false, bool supportsTeamDrives = false,
                               bool alt = false, string fields = "", bool prettyPrint = false, string quotaUser = "", string userId = "");
};


#endif //GOOGLEDRIVEAPI_GOOGLEDRIVEAPI_H
