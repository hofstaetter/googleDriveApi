//
// Created by Matthias Hofstätter on 15.09.17.
//

#ifndef PLEXDRIVE_PERMISSIONSLISTRESPONSE_H
#define PLEXDRIVE_PERMISSIONSLISTRESPONSE_H

#include <string>
#include <vector>
#include "permission.h"

using namespace std;

class permissionList {
private:
    string kind;
    string nextPageToken;
    vector<permission> permissions;
};


#endif //PLEXDRIVE_PERMISSIONSLISTRESPONSE_H
