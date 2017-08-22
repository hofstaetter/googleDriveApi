//
// Created by Matthias Hofstätter on 21.08.17.
//

#ifndef GOOGLEDRIVEAPI_GENERATEIDSRESPONSE_H
#define GOOGLEDRIVEAPI_GENERATEIDSRESPONSE_H

#include "../googleDriveApi.h"
#include <string>
#include <vector>

using namespace std;

class generateIdsResponse {
public:
    string kind;
    string space;
    vector<string> ids;
};


#endif //GOOGLEDRIVEAPI_GENERATEIDSRESPONSE_H
