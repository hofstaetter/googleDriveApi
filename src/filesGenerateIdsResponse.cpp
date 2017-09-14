//
// Created by Matthias Hofstätter on 21.08.17.
//

#include "files/filesGenerateIdsResponse.h"

filesGenerateIdsResponse::filesGenerateIdsResponse() {

}

filesGenerateIdsResponse::filesGenerateIdsResponse(rapidjson::Document &document) {
    if(document.HasMember("kind"))
        this->kind = document["kind"].GetString();
    if(document.HasMember("space"))
        this->space = document["space"].GetString();
    if(document.HasMember("ids"))
        for(auto& v : document["ids"].GetArray()) {
            this->ids.push_back(v.GetString());
        }
}
