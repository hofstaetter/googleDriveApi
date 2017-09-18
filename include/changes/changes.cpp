//
// Created by Matthias Hofstätter on 14.09.17.
//

#include "changes/changes.h"

startPageToken
changes::getStartPageToken(bool supportsTeamDrives, string teamDriveId, bool alt, string fields, bool prettyPrint,
                           string quotaUser, string userId) {
    if(googleOAuth::getAccessToken().empty() || googleOAuth::getExpire() <= time(NULL)) {
        googleOAuth::authenticate();
    }

    string responseBody;
    string responseHeaders;

    long responseCode = https::request("https://www.googleapis.com", "/drive/v3/changes/startPageToken", "GET", {}, {}, {}, "", responseHeaders, responseBody);

    rapidjson::Document responseJson;
    rapidjson::ParseResult pr = responseJson.Parse(responseBody.c_str());
    if(!pr) {
        printf("PARSE ERROR");
    }

    if(responseCode != 200) throw responseJson;

    return startPageToken(responseJson);
}

changeList changes::list(string pageToken, bool includeCorpusRemovals, bool includeRemoved, bool includeTeamDriveItems,
                         int pageSize, bool restrictToMyDrive, string spaces, bool supportsTeamDrives,
                         string teamDriveId, bool alt, string fields, bool prettyPrint, string quotaUser,
                         string userId) {
    return changeList();
}

channel changes::watch(string pageToken, bool includeCorpusRemovals, bool includeRemoved, bool includeTeamDriveItems,
                       int pageSize, bool restrictToMyDrive, string spaces, bool supportsTeamDrives, string teamDriveId,
                       channel requestBody, bool alt, string fields, bool prettyPrint, string quotaUser,
                       string userId) {
    return channel();
}