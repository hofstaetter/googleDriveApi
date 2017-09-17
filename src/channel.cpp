//
// Created by Matthias Hofstätter on 21.08.17.
//

#include "classes/channel.h"

channel::channel(rapidjson::Document& document) {
    if(document.HasMember("kind"))
        this->kind = document["kind"].GetString();
    if(document.HasMember("id"))
        this->id = document["id"].GetString();
    if(document.HasMember("resourceId"))
        this->resourceId = document["resourceId"].GetString();
    if(document.HasMember("resourceUri"))
        this->resourceUri = document["resourceUri"].GetString();
    if(document.HasMember("token"))
        this->token = document["token"].GetString();
    if(document.HasMember("expiration"))
        this->expiration = document["expiration"].GetInt64();
    if(document.HasMember("type"))
        this->type = document["type"].GetString();
    if(document.HasMember("address"))
        this->address = document["address"].GetString();
    if(document.HasMember("payload"))
        this->payload = document["payload"].GetBool();
    if(document.HasMember("params")) {
        for(auto& v : document["params"].GetArray()) {
            this->params.insert(pair<string, string>(v[0].GetString(), v[1].GetString()));
        }
    }
}

channel::channel() {}

string channel::toString() {


    return std::string();
}

const string &channel::getKind() const {
    return kind;
}

void channel::setKind(const string &kind) {
    channel::kind = kind;
}

const string &channel::getId() const {
    return id;
}

void channel::setId(const string &id) {
    channel::id = id;
}

const string &channel::getResourceId() const {
    return resourceId;
}

void channel::setResourceId(const string &resourceId) {
    channel::resourceId = resourceId;
}

const string &channel::getResourceUri() const {
    return resourceUri;
}

void channel::setResourceUri(const string &resourceUri) {
    channel::resourceUri = resourceUri;
}

const string &channel::getToken() const {
    return token;
}

void channel::setToken(const string &token) {
    channel::token = token;
}

long channel::getExpiration() const {
    return expiration;
}

void channel::setExpiration(long expiration) {
    channel::expiration = expiration;
}

const string &channel::getType() const {
    return type;
}

void channel::setType(const string &type) {
    channel::type = type;
}

const string &channel::getAddress() const {
    return address;
}

void channel::setAddress(const string &address) {
    channel::address = address;
}

bool channel::isPayload() const {
    return payload;
}

void channel::setPayload(bool payload) {
    channel::payload = payload;
}

const map<string, string> &channel::getParams() const {
    return params;
}

void channel::setParams(const map<string, string> &params) {
    channel::params = params;
}
