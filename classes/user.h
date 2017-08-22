//
// Created by Matthias Hofstätter on 21.08.17.
//

#ifndef GOOGLEDRIVEAPI_USER_H
#define GOOGLEDRIVEAPI_USER_H

#include <string>

using namespace std;

class user {
public:
    string kind;
    string displayName;
    string photoLink;
    bool me;
    string permissionId;
    string emailAddress;
};


#endif //GOOGLEDRIVEAPI_USER_H
