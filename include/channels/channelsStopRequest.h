//
// Created by Matthias Hofstätter on 15.09.17.
//

#ifndef PLEXDRIVE_CHANNELSSTOPREQUEST_H
#define PLEXDRIVE_CHANNELSSTOPREQUEST_H

#include <string>
#include <map>

using namespace std;

class channelsStopRequest {
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


#endif //PLEXDRIVE_CHANNELSSTOPREQUEST_H
