//
// Created by Matthias Hofstätter on 21.08.17.
//

#ifndef GOOGLEDRIVEAPI_GENERATEIDSRESPONSE_H
#define GOOGLEDRIVEAPI_GENERATEIDSRESPONSE_H

#include "files/filesGoogleDriveApi.h"
#include <string>
#include <vector>
#include <document.h>

using namespace std;

class filesGenerateIdsResponse {
public:
    string kind;
    string space;
    vector<string> ids;

    filesGenerateIdsResponse();
    filesGenerateIdsResponse(rapidjson::Document& document);
};


#endif //GOOGLEDRIVEAPI_GENERATEIDSRESPONSE_H
