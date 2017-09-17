//
// Created by Matthias Hofstätter on 21.08.17.
//

#ifndef GOOGLEDRIVEAPI_GENERATEIDSRESPONSE_H
#define GOOGLEDRIVEAPI_GENERATEIDSRESPONSE_H

#include "files/files.h"
#include <string>
#include <vector>
#include <document.h>

using namespace std;

class generatedIds {
public:
    string kind;
    string space;
    vector<string> ids;

    generatedIds();
    generatedIds(rapidjson::Document& document);
};


#endif //GOOGLEDRIVEAPI_GENERATEIDSRESPONSE_H
