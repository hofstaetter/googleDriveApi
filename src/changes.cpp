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

    map<string, string> querystring = { make_pair("supportsTeamDrives", supportsTeamDrives ? "true" : "false"), make_pair("teamDriveId", teamDriveId),
                                        make_pair("alt", alt  ? "" : "json"), make_pair("fields", fields), make_pair("prettyPrint", prettyPrint ? "true" : "false"), make_pair("quotaUser", quotaUser), make_pair("userId", userId) };
    map<string, string> headers = { make_pair("Authorization", string("Bearer ").append(googleOAuth::getAccessToken())) };

    long responseCode = https::request("https://www.googleapis.com", "/drive/v3/changes/startPageToken", "GET", querystring, headers, {}, "", responseHeaders, responseBody);

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
    if(googleOAuth::getAccessToken().empty() || googleOAuth::getExpire() <= time(NULL)) {
        googleOAuth::authenticate();
    }

    string responseBody;
    string responseHeaders;

    map<string, string> querystring = { make_pair("pageToken", pageToken), make_pair("includeCorpusRemovals", includeCorpusRemovals ? "true" : "false"), make_pair("includeRemoved", includeRemoved ? "true" : "false"),
                                        make_pair("includeTeamDriveItems", includeTeamDriveItems ? "true" : "false"), make_pair("pageSize", to_string(pageSize)), make_pair("restrictToMyDrive", restrictToMyDrive ? "true" : "false"),
                                        make_pair("spaces", spaces), make_pair("supportsTeamDrives", supportsTeamDrives ? "true" : "false"), make_pair("teamDriveId", teamDriveId),
                                        make_pair("alt", alt  ? "" : "json"), make_pair("fields", fields), make_pair("prettyPrint", prettyPrint ? "true" : "false"), make_pair("quotaUser", quotaUser), make_pair("userId", userId) };
    map<string, string> headers = { make_pair("Authorization", string("Bearer ").append(googleOAuth::getAccessToken())) };

    long responseCode = https::request("https://www.googleapis.com", "/drive/v3/changes", "GET", querystring, headers, {}, "", responseHeaders, responseBody);

    rapidjson::Document responseJson;
    rapidjson::ParseResult pr = responseJson.Parse(responseBody.c_str());
    if(!pr) {
        printf("PARSE ERROR");
    }

    if(responseCode != 200) throw responseJson;

    return changeList(responseJson);
}

channel changes::watch(string pageToken, bool includeCorpusRemovals, bool includeRemoved, bool includeTeamDriveItems,
                       int pageSize, bool restrictToMyDrive, string spaces, bool supportsTeamDrives, string teamDriveId,
                       channel requestBody, bool alt, string fields, bool prettyPrint, string quotaUser,
                       string userId) {
    return channel();
}