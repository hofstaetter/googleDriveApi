//
// Created by Matthias Hofstätter on 21.08.17.
//

#include "files/filesWatchResponse.h"

filesWatchResponse::filesWatchResponse(rapidjson::Document& document) {
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
