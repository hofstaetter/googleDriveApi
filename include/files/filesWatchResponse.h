//
// Created by Matthias Hofstätter on 21.08.17.
//

#ifndef GOOGLEDRIVEAPI_WATCHRESPONSE_H
#define GOOGLEDRIVEAPI_WATCHRESPONSE_H


#include "files/filesGoogleDriveApi.h"
#include <string>
#include <map>

using namespace std;

class filesWatchResponse {
public:
    string kind;
    string id;
    string resourceId;
    string resourceUri;
    string token;
    long expiration;
    string type;
    string address;
    bool payload;
    map<string, string> params;

    filesWatchResponse(rapidjson::Document& document);
};


#endif //GOOGLEDRIVEAPI_WATCHRESPONSE_H
