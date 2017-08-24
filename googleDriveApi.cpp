//
// Created by Matthias Hofstätter on 20.08.17.
//

#include <iostream>
#include "googleDriveApi.h"

using namespace std;

string buffer;

size_t
writeBuffer( void *ptr, size_t size, size_t nmemb, void *stream)
{
    buffer.append((char*)ptr, size*nmemb);
    return size*nmemb;
}

long
googleDriveApi::request(string host, string path, string type, map<string, string> querystring, map<string, string> header, map<string, string> postfields, string body, rapidjson::Document& response) {
    CURL *req = curl_easy_init();

    //debug
    curl_easy_setopt(req, CURLOPT_VERBOSE, 1L);

    //build & set url
    stringstream url;
    bool first = true;

    url << "https://" << host; //url static
    url << path;
    for(auto p : querystring) {
        if(first) {
            url << "?";
            first = !first;
        } else url << "&";
        url << p.first << "=" << p.second;
    }
    curl_easy_setopt(req, CURLOPT_URL, url.str().c_str());

    //set HTTP 1.1
    curl_easy_setopt(req, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_1_1);

    //set postfields
    stringstream pf;
    if(type.compare("POST") == 0) {
        first = true;

        for(auto p : postfields) {

            pf << ((first) ? "" : "&") << p.first << "=" << p.second;
        }
    }

    //write response to buffer
    curl_easy_setopt(req, CURLOPT_WRITEFUNCTION, writeBuffer);

    //get http status code
    long statuscode = 0;
    //curl_easy_setopt(req, CURLINFO_RESPONSE_CODE, &statuscode);

    //set headers
    struct curl_slist *headers=NULL;
    headers = curl_slist_append(headers, ("Host: " + host).c_str());

    long contentlength = pf.str().length() + body.length();
    headers = curl_slist_append(headers, ("Content-length: " + to_string(contentlength)).c_str());
    headers = curl_slist_append(headers, "Connection: close");
    for(auto p : header) {
        headers = curl_slist_append(headers, (p.first + ": " + p.second).c_str());
    }
    curl_easy_setopt(req, CURLOPT_HTTPHEADER, headers);

    CURLcode result = curl_easy_perform(req);

    curl_slist_free_all(headers);

    curl_easy_cleanup(req);

    response.Parse(buffer.c_str());

    cout << buffer.c_str() << endl;

    return statuscode;
}

listResponse
googleDriveApi::list(string corpora, string corpus, bool includeTeamDriveItems, string orderBy, int pageSize,
                     string pageToken, string q, string spaces, bool supportsTeamDrives, string teamDriveId, bool alt,
                     string fields, bool prettyPrint, string quotaUser, string userId) {
    rapidjson::Document response;
    map<string, string> querystring = { make_pair("corpora", corpora), /*make_pair("corpus", corpus),*/ /*make_pair("includeTeamDriveItems", includeTeamDriveItems ? "true" : "false"),*/ make_pair("orderBy", orderBy),
                                  make_pair("pageSize", to_string(pageSize)), make_pair("pageToken", pageToken), make_pair("q", q), make_pair("spaces", spaces), make_pair("supportsTeamDrives", supportsTeamDrives ? "true" : "false"), /*make_pair("teamDriveId", teamDriveId),*/ make_pair("alt", alt  ? "" : "json"),
                                  make_pair("fields", fields), make_pair("prettyPrint", prettyPrint ? "true" : "false"), make_pair("quotaUser", quotaUser), make_pair("userId", userId) };
    map<string, string> headers = { make_pair("Authorization", "Bearer ya29.GluuBKMPpAhDjpugsB2Ysn4WXeyEjIREg92O0J3lENu1o3LdGIO1OsErErr-QicIBrua_D2AvkBYQBeyc9g5_lzh_-VCIxl___NKTiXReiUc2Ewwjf2N2t48hxUZ") };
    long responseCode = googleDriveApi::request("www.googleapis.com", "/drive/v3/files", "GET", querystring,
                                                headers, {}, "", response);

    if(responseCode == 403) { throw response; }

    listResponse lr;
    lr.kind = response["kind"].GetString();
    lr.nextPageToken = response["nextPageToken"].GetString();
    lr.incompleteSearch = response["incompleteSearch"].GetBool();

    for(auto& v : response["files"].GetArray()) {
        filesResource fr;
        fr.kind = v["kind"].GetString();
        fr.id = v["id"].GetString();
        fr.name = v["name"].GetString();
        fr.mimeType = v["mimeType"].GetString();

        lr.files.push_back(fr);
    }

    return lr;
}

filesResource
googleDriveApi::copy(string fileId, bool ignoreDefaultVisibility, bool keepRevisionForever, string ocrLanguage,
                     bool supportsTeamDrives, bool alt, string fields, bool prettyPrint, string quotaUser,
                     string userId, filesResource* fr) {
    rapidjson::Document response;

    //prepare uri
    /*stringstream ss;
    ss << "/drive/v3/files/" << fileId << "/copy";

    //prepare body
    ss.clear();

    long responseCode = googleDriveApi::request(ss.str(), "POST", {}, "", response);

    if(responseCode == 403) { throw response; }*/

    return filesResource();
}

filesResource
googleDriveApi::create(string uploadType, bool ignoreDefaultVisibility, bool keepRevisionForever, string ocrLanguage,
                       bool supportsTeamDrives, bool useContentAsIndexableText, bool alt, string fields,
                       bool prettyPrint, string quotaUser, string userId) {
    return filesResource();
}

bool
googleDriveApi::del(string fileId, bool supportsTeamDrives, bool alt, string fields, bool prettyPrint, string quotaUser,
                    string userId) {
    return false;
}

bool googleDriveApi::emptyTrash(bool alt, string fields, bool prettyPrint, string quotaUser, string userId) {
    return false;
}

filesResource
googleDriveApi::exp(string fileId, string mimeType, bool alt, string fields, bool prettyPrint, string quotaUser,
                       string userId) {
    return filesResource();
}

generateIdsResponse
googleDriveApi::generateIds(int count, string space, bool alt, string fields, bool prettyPrint, string quotaUser,
                            string userId) {
    return generateIdsResponse();
}

filesResource
googleDriveApi::get(string fileId, bool acknowledgeAbuse, bool supportsTeamDrives, bool alt, string fields,
                    bool prettyPrint, string quotaUser, string userId) {
    return filesResource();
}

filesResource googleDriveApi::update(string fileId, string Parents, bool keepRevisionForever, string ocrLanguage,
                                     string removeParents, bool supportsTeamDrives, bool useContentAsIndexableText,
                                     bool alt, string fields, bool prettyPrint, string quotaUser, string userId) {
    return filesResource();
}

watchResponse
googleDriveApi::watch(string fileId, bool acknowledgeAbuse, bool supportsTeamDrives, bool alt, string fields,
                      bool prettyPrint, string quotaUser, string userId) {
    return watchResponse();
}

bool googleDriveApi::getAuthCode(string authCode, string clientId, string clientSecret, string redirectUri, string grantType) {
    rapidjson::Document document;
    long httpCode = googleDriveApi::request("accounts.google.com", "/o/oauth2/v2/auth", "POST", { make_pair("response_type", "code"), make_pair("client_id", "590194775230-snrhmjb562msv07a5rvg8mj6l5tiiq0i.apps.googleusercontent.com"), make_pair("redirect_uri", "urn:ietf:wg:oauth:2.0:oob"), make_pair("scope", "https://www.googleapis.com/auth/drive") },
                                            { make_pair("content-type", "application/x-www-form-urlencoded") },
                                            {}, //{ make_pair("code", authCode), make_pair("client_id", clientId), make_pair("client_secret", clientSecret), make_pair("redirect_uri", "urn:ietf:wg:oauth:2.0:oob"), make_pair("grant_type", "authorization_code") },
                                            "", document);

    return 0;
}
