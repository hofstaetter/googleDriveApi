//
// Created by Matthias Hofstätter on 15.09.17.
//

#ifndef PLEXDRIVE_PERMISSIONSLISTRESPONSE_H
#define PLEXDRIVE_PERMISSIONSLISTRESPONSE_H

#include <string>
#include <vector>
#include "permissionsResource.h"

using namespace std;

class permissionsListResponse {
private:
    string kind;
    string nextPageToken;
    vector<permissionsResource> permissions;
};


#endif //PLEXDRIVE_PERMISSIONSLISTRESPONSE_H
