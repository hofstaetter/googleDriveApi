//
// Created by Matthias Hofstätter on 20.08.17.
//

#include "files/files.h"

using namespace std;

fileList
files::list(string corpora, string corpus, bool includeTeamDriveItems, string orderBy, int pageSize, string pageToken, string q, string spaces, bool supportsTeamDrives, string teamDriveId,
                     bool alt, string fields, bool prettyPrint, string quotaUser, string userId) {
    if(googleOAuth::getAccessToken().empty() || googleOAuth::getExpire() <= time(NULL)) {
        googleOAuth::authenticate();
    }

    rapidjson::Document responseBody;
    string responseHeaders;
    map<string, string> querystring = { make_pair("corpora", corpora), /*make_pair("corpus", corpus),*/ /*make_pair("includeTeamDriveItems", includeTeamDriveItems ? "true" : "false"),*/ make_pair("orderBy", orderBy),
                                        make_pair("pageSize", to_string(pageSize)), make_pair("pageToken", pageToken), make_pair("q", q), make_pair("spaces", spaces), make_pair("supportsTeamDrives", supportsTeamDrives ? "true" : "false"),
                                        /*make_pair("teamDriveId", teamDriveId),*/
                                        make_pair("alt", alt  ? "" : "json"), make_pair("fields", fields), make_pair("prettyPrint", prettyPrint ? "true" : "false"), make_pair("quotaUser", quotaUser), make_pair("userId", userId) };
    map<string, string> headers = { make_pair("Authorization", string("Bearer ").append(googleOAuth::getAccessToken())) };
    long responseCode = https::request("https://www.googleapis.com", "/drive/v3/files", "GET", querystring,
                                                headers, {}, "", responseHeaders, responseBody);

    if(responseCode != 200) { throw -1; }

    fileList lr(responseBody);

    return lr;
}

file
files::copy(string fileId, bool ignoreDefaultVisibility, bool keepRevisionForever, string ocrLanguage, bool supportsTeamDrives, file& requestBody,
                     bool alt, string fields, bool prettyPrint, string quotaUser, string userId) {
    if(googleOAuth::getAccessToken().empty() || googleOAuth::getExpire() <= time(NULL)) {
        googleOAuth::authenticate();
    }

    rapidjson::Document responseBody;
    string responseHeaders;

    long responseCode = https::request("https://www.googleapis.com", string("/drive/v3/files/").append(fileId).append("/copy"), "POST", {}, {}, {}, requestBody.toString(), responseHeaders, responseBody);

    if(responseCode != 200) throw -1;

    file fr(responseBody);

    return fr;
}

file
files::create(string uploadType, bool ignoreDefaultVisibility, bool keepRevisionForever, string ocrLanguage, bool supportsTeamDrives, bool useContentAsIndexableText, file& requestBody,
                       bool alt, string fields, bool prettyPrint, string quotaUser, string userId) {
    if(!(uploadType.compare("media") == 0 || uploadType.compare("multipart") == 0 || uploadType.compare("resumable") == 0)) {
        throw -1;
    }

    if(googleOAuth::getAccessToken().empty() || googleOAuth::getExpire() <= time(NULL)) {
        googleOAuth::authenticate();
    }

    map<string, string> querystring = { make_pair("uploadType", uploadType), make_pair("ignoreDefaultVisibility", ignoreDefaultVisibility ? "true" : "false"), make_pair("keepRevisionForever", keepRevisionForever ? "true" : "false"),
                                        make_pair("ocrLanguage", ocrLanguage), make_pair("supportsTeamDrives", supportsTeamDrives ? "true" : "false"), make_pair("useContentAsIndexableText", useContentAsIndexableText ? "true" : "false"),
                                        make_pair("alt", alt  ? "" : "json"), make_pair("fields", fields), make_pair("prettyPrint", prettyPrint ? "true" : "false"), make_pair("quotaUser", quotaUser), make_pair("userId", userId) };
    map<string, string> headers = { make_pair("Authorization", string("Bearer ").append(googleOAuth::getAccessToken())) };

    rapidjson::Document responseBody;
    string responseHeaders;

    long responseCode = https::request("https://www.googleapis.com", "/drive/v3/files/", "POST", querystring, headers, {}, requestBody.toString(), responseHeaders, responseBody);

    if(responseCode != 200) throw -1;

    file fr(responseBody);

    return fr;
}

bool
files::del(string fileId, bool supportsTeamDrives,
                    bool alt, string fields, bool prettyPrint, string quotaUser, string userId) {
    if(googleOAuth::getAccessToken().empty() || googleOAuth::getExpire() <= time(NULL)) {
        googleOAuth::authenticate();
    }

    map<string, string> querystring = { make_pair("supportsTeamDrives", supportsTeamDrives ? "true" : "false"),
                                        make_pair("alt", alt  ? "" : "json"), make_pair("fields", fields), make_pair("prettyPrint", prettyPrint ? "true" : "false"), make_pair("quotaUser", quotaUser), make_pair("userId", userId) };
    map<string, string> headers = { make_pair("Authorization", string("Bearer ").append(googleOAuth::getAccessToken())) };

    rapidjson::Document responseBody;
    string responseHeaders;

    long responseCode = https::request("https://www.googleapis.com", string("/drive/v3/files/").append(fileId), "DELETE", querystring, headers, {}, "", responseHeaders, responseBody);

    if(responseCode != 204) return false;

    return true;
}

bool files::emptyTrash(bool alt, string fields, bool prettyPrint, string quotaUser, string userId) {
    if(googleOAuth::getAccessToken().empty() || googleOAuth::getExpire() <= time(NULL)) {
        googleOAuth::authenticate();
    }

    map<string, string> querystring = { make_pair("alt", alt  ? "" : "json"), make_pair("fields", fields), make_pair("prettyPrint", prettyPrint ? "true" : "false"), make_pair("quotaUser", quotaUser), make_pair("userId", userId) };
    map<string, string> headers = { make_pair("Authorization", string("Bearer ").append(googleOAuth::getAccessToken())) };

    rapidjson::Document responseBody;
    string responseHeaders;

    long responseCode = https::request("https://www.googleapis.com", "/drive/v3/files/trash", "DELETE", querystring, headers, {}, "", responseHeaders, responseBody);

    if(responseCode == 204) return true;
    return false;
}

file
files::exp(string fileId, string mimeType,
                    bool alt, string fields, bool prettyPrint, string quotaUser, string userId) {
    if(googleOAuth::getAccessToken().empty() || googleOAuth::getExpire() <= time(NULL)) {
        googleOAuth::authenticate();
    }

    map<string, string> querystring = { make_pair("mimeType", mimeType),
                                        make_pair("alt", alt  ? "" : "json"), make_pair("fields", fields), make_pair("prettyPrint", prettyPrint ? "true" : "false"), make_pair("quotaUser", quotaUser), make_pair("userId", userId) };
    //map<string, string> headers = { make_pair("Authorization", string("Bearer ").append(googleOAuth::getAccessToken())) };

    rapidjson::Document responseBody;
    string responseHeaders;

    long responseCode = https::request("https://www.googleapis.com", string("/drive/v3/files/").append(fileId).append("/export"), "GET", querystring, {}, {}, "", responseHeaders, responseBody);

    if(responseCode == 200) throw -1;

    return file();
}

generatedIds
files::generateIds(int count, string space, bool alt, string fields, bool prettyPrint, string quotaUser,
                            string userId) {
    if(googleOAuth::getAccessToken().empty() || googleOAuth::getExpire() <= time(NULL)) {
        googleOAuth::authenticate();
    }

    map<string, string> querystring = { make_pair("count", to_string(count)), make_pair("space", space),
                                        make_pair("alt", alt  ? "" : "json"), make_pair("fields", fields), make_pair("prettyPrint", prettyPrint ? "true" : "false"), make_pair("quotaUser", quotaUser), make_pair("userId", userId) };
    map<string, string> headers = { make_pair("Authorization", string("Bearer ").append(googleOAuth::getAccessToken())) };

    rapidjson::Document responseBody;
    string responseHeaders;

    long responseCode = https::request("https://www.googleapis.com", "/drive/v3/files/generateIds", "GET", querystring, headers, {}, "", responseHeaders, responseBody);

    if(responseCode != 200) {
        throw -1;
    }

    generatedIds gir(responseBody);

    return gir;
}

file
files::get(string fileId, bool acknowledgeAbuse, bool supportsTeamDrives, bool alt, string fields,
                    bool prettyPrint, string quotaUser, string userId) {
    if(googleOAuth::getAccessToken().empty() || googleOAuth::getExpire() <= time(NULL)) {
        googleOAuth::authenticate();
    }

    map<string, string> querystring = { make_pair("acknowledgeAbuse", acknowledgeAbuse ? "true" : "false"), make_pair("supportsTeamDrives", supportsTeamDrives ? "true" : "false"),
                                        make_pair("alt", alt  ? "" : "json"), make_pair("fields", fields), make_pair("prettyPrint", prettyPrint ? "true" : "false"), make_pair("quotaUser", quotaUser), make_pair("userId", userId) };
    map<string, string> headers = { make_pair("Authorization", string("Bearer ").append(googleOAuth::getAccessToken())) };

    rapidjson::Document responseBody;
    string responseHeaders;

    long responseCode = https::request("https://www.googleapis.com", string("/drive/v3/files/").append(fileId), "GET", querystring, headers, {}, "", responseHeaders, responseBody);

    if(responseCode != 200) {
        throw -1;
    }

    file fr(responseBody);

    return fr;
}

file files::update(string fileId, string uploadType,  string addParents, bool keepRevisionForever, string ocrLanguage, string removeParents, bool supportsTeamDrives, bool useContentAsIndexableText, file& requestBody,
                                     bool alt, string fields, bool prettyPrint, string quotaUser, string userId) {
    if(googleOAuth::getAccessToken().empty() || googleOAuth::getExpire() <= time(NULL)) {
        googleOAuth::authenticate();
    }

    map<string, string> querystring = { make_pair("uploadType", uploadType), make_pair("addParents", addParents), make_pair("keepRevisionForever", keepRevisionForever ? "true" : "false"), make_pair("ocrLanguage", ocrLanguage),
                                        make_pair("removeParents", removeParents), make_pair("supportsTeamDrives", supportsTeamDrives ? "true" : "false"), make_pair("useContentAsIndexableText", useContentAsIndexableText ? "true" : "false"),
                                        make_pair("alt", alt  ? "" : "json"), make_pair("fields", fields), make_pair("prettyPrint", prettyPrint ? "true" : "false"), make_pair("quotaUser", quotaUser), make_pair("userId", userId) };
    map<string, string> headers = { make_pair("Authorization", string("Bearer ").append(googleOAuth::getAccessToken())) };

    rapidjson::Document responseBody;
    string responseHeaders;

    long responseCode = https::request("https://www.googleapis.com", string("/drive/v3/files/").append(fileId), "GET", querystring, headers, {}, "", responseHeaders, responseBody);

    if(responseCode != 200) {
        throw -1;
    }

    file fr(responseBody);

    return fr;
}

channel
files::watch(string fileId, bool acknowledgeAbuse, bool supportsTeamDrives, channel& requestBody,
                      bool alt, string fields, bool prettyPrint, string quotaUser, string userId) {
    if(googleOAuth::getAccessToken().empty() || googleOAuth::getExpire() <= time(NULL)) {
        googleOAuth::authenticate();
    }

    map<string, string> querystring = { make_pair("acknowledgeAbuse", acknowledgeAbuse ? "true" : "false"), make_pair("supportsTeamDrives", supportsTeamDrives ? "true" : "false"),
                                        make_pair("alt", alt  ? "" : "json"), make_pair("fields", fields), make_pair("prettyPrint", prettyPrint ? "true" : "false"), make_pair("quotaUser", quotaUser), make_pair("userId", userId) };
    map<string, string> headers = { make_pair("Authorization", string("Bearer ").append(googleOAuth::getAccessToken())) };

    rapidjson::Document responseBody;
    string responseHeaders;

    long responseCode = https::request("https://www.googleapis.com", string("/drive/v3/files/").append(fileId), "GET", querystring, headers, {}, requestBody.toString(), responseHeaders, responseBody);

    if(responseCode != 200) throw -1;

    channel wr(responseBody);

    return wr;
}
