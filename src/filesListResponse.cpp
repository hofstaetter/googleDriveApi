//
// Created by Matthias Hofstätter on 21.08.17.
//

#include <document.h>
#include <files/filesListResponse.h>

filesListResponse::filesListResponse(rapidjson::Document& document) {
    if(document.HasMember("kind"))
        this->kind = document["kind"].GetString();
    if(document.HasMember("nextPageToken"))
        this->nextPageToken = document["nextPageToken"].GetString();
    if(document.HasMember("incompleteSearch"))
        this->nextPageToken = document["incompleteSearch"].GetBool();
    if(document.HasMember("files")) {
        for(auto& v : document["files"].GetArray()) {
            rapidjson::Document part;
            part.CopyFrom(v, part.GetAllocator());
            filesResource fr(part);

            this->files.push_back(fr);
        }
    }
}

const string &filesListResponse::getKind() const {
    return kind;
}

void filesListResponse::setKind(const string &kind) {
    filesListResponse::kind = kind;
}

const string &filesListResponse::getNextPageToken() const {
    return nextPageToken;
}

void filesListResponse::setNextPageToken(const string &nextPageToken) {
    filesListResponse::nextPageToken = nextPageToken;
}

bool filesListResponse::isIncompleteSearch() const {
    return incompleteSearch;
}

void filesListResponse::setIncompleteSearch(bool incompleteSearch) {
    filesListResponse::incompleteSearch = incompleteSearch;
}

const vector<filesResource> &filesListResponse::getFiles() const {
    return files;
}

void filesListResponse::setFiles(const vector<filesResource> &files) {
    filesListResponse::files = files;
}

filesListResponse::filesListResponse() {

}
