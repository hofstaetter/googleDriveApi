//
// Created by Matthias Hofstätter on 21.08.17.
//

#ifndef GOOGLEDRIVEAPI_WATCHRESPONSE_H
#define GOOGLEDRIVEAPI_WATCHRESPONSE_H


#include "files/files.h"
#include <string>
#include <map>

using namespace std;

class channel: rapidjson::Document {
public:
    const string &getKind() const;

    void setKind(const string &kind);

    const string &getId() const;

    void setId(const string &id);

    const string &getResourceId() const;

    void setResourceId(const string &resourceId);

    const string &getResourceUri() const;

    void setResourceUri(const string &resourceUri);

    const string &getToken() const;

    void setToken(const string &token);

    long getExpiration() const;

    void setExpiration(long expiration);

    const string &getType() const;

    void setType(const string &type);

    const string &getAddress() const;

    void setAddress(const string &address);

    bool isPayload() const;

    void setPayload(bool payload);

    const map<string, string> &getParams() const;

    void setParams(const map<string, string> &params);

public:
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

    channel();
    channel(rapidjson::Document& document);

    string toString();
};


#endif //GOOGLEDRIVEAPI_WATCHRESPONSE_H
