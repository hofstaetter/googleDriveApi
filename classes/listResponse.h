//
// Created by Matthias Hofstätter on 21.08.17.
//

#ifndef GOOGLEDRIVEAPI_LISTRESPONSE_H
#define GOOGLEDRIVEAPI_LISTRESPONSE_H

#include "../googleDriveApi.h"
#include "filesResource.h"
#include <string>
#include <vector>

using namespace std;

class listResponse {
public:
    string kind;
    string nextPageToken;
    bool incompleteSearch;
    vector<class filesResource> files;
};


#endif //GOOGLEDRIVEAPI_LISTRESPONSE_H
