//
// Created by Matthias Hofstätter on 12.09.17.
//

#ifndef GOOGLEDRIVEAPI_WATCHREQUEST_H
#define GOOGLEDRIVEAPI_WATCHREQUEST_H

#include <string>
#include <map>

using namespace std;

class filesWatchRequest {
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
public:
    filesWatchRequest();
    filesWatchRequest(const string &kind, const string &id, const string &resourceId, const string &resourceUri,
                 const string &token, long expiration, const string &type, const string &address, bool payload,
                 const map<string, string> &params);

    string toString();
};


#endif //GOOGLEDRIVEAPI_WATCHREQUEST_H
