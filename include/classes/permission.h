//
// Created by Matthias Hofstätter on 15.09.17.
//

#ifndef PLEXDRIVE_PERMISSIONSRESOURCE_H
#define PLEXDRIVE_PERMISSIONSRESOURCE_H


#include <ctime>
#include <string>
#include <vector>
#include "jsonObject.h"

using namespace std;

class permission: public jsonObject {
public:
    struct teamDrivePermissionDetails {
        string teamDrivePermissionType;
        string role;
        string inheritedFrom;
        bool inherited;
    };

    permission();
    permission(rapidjson::Document &doc);
private:
    string kind;
    string id;
    string type;
    string emailAddress;
    string domain;
    string role;
    bool allowFileDiscovery;
    string displayName;
    string photoLink;
    time_t expirationTime;
    vector<struct teamDrivePermissionDetails> teamDrivePermissionDetails;
    bool deleted;
};


#endif //PLEXDRIVE_PERMISSIONSRESOURCE_H
