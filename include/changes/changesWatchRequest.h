//
// Created by Matthias Hofstätter on 15.09.17.
//

#ifndef PLEXDRIVE_CHANGESWATCHREQUEST_H
#define PLEXDRIVE_CHANGESWATCHREQUEST_H

#include <string>
#include <map>

using namespace std;

class changesWatchRequest {
private:
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
};


#endif //PLEXDRIVE_CHANGESWATCHREQUEST_H
