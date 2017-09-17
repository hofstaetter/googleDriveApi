//
// Created by Matthias Hofstätter on 21.08.17.
//

#include <document.h>
#include <classes/fileList.h>

fileList::fileList(rapidjson::Document& document) {
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
            file fr(part);

            this->files.push_back(fr);
        }
    }
}

const string &fileList::getKind() const {
    return kind;
}

void fileList::setKind(const string &kind) {
    fileList::kind = kind;
}

const string &fileList::getNextPageToken() const {
    return nextPageToken;
}

void fileList::setNextPageToken(const string &nextPageToken) {
    fileList::nextPageToken = nextPageToken;
}

bool fileList::isIncompleteSearch() const {
    return incompleteSearch;
}

void fileList::setIncompleteSearch(bool incompleteSearch) {
    fileList::incompleteSearch = incompleteSearch;
}

const vector<file> &fileList::getFiles() const {
    return files;
}

void fileList::setFiles(const vector<file> &files) {
    fileList::files = files;
}

fileList::fileList() {

}
