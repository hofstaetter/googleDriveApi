//
// Created by Matthias Hofstätter on 14.09.17.
//

#include "classes/changeList.h"

/*string changeList::getKind() {
    return this->getString("kind");
}

void changeList::setKind(string kind) {
    this->setString("kind", kind);
}

string changeList::getNextPageToken() {
    return this->getString("nextPageToken");
}

void changeList::setNextPageToken(string nextPageToken) {
    this->setString("nextPageToken", nextPageToken);
}

string changeList::getNewStartPageToken() {
    return this->getString("newStartPageToken");
}

void changeList::setNewStartPageToken(string newStartPageToken) {
    this->setString("newStartPageToken", newStartPageToken);
}

vector<change> changeList::getChanges() {
    return this->getObjectArray<change>("changes");
}

void changeList::setChanges(vector<change> changes) {
    this->setObjectArray("changes", changes);
}*/

changeList::changeList() {
    //this->document = new rapidjson::Document;
}

changeList::changeList(rapidjson::Document &document) {
    /*this->document = new rapidjson::Document;
    this->document->CopyFrom(document, (this->document)->GetAllocator());*/
    if(document.HasMember("kind"))
        this->kind = document["kind"].GetString();
    if(document.HasMember("nextPageToken"))
        this->nextPageToken = document["nextPageToken"].GetString();
    if(document.HasMember("newStartPageToken"))
        this->newStartPageToken = document["newStartPageToken"].GetString();
    if(document.HasMember("changes")) {
        rapidjson::Document d(rapidjson::kObjectType);
        for(auto &c : document["changes"].GetArray()) {
            d.CopyFrom(c, d.GetAllocator());
            this->changes.push_back(change(d));
        }
    }
}

const string &changeList::getKind() const {
    return kind;
}

void changeList::setKind(const string &kind) {
    changeList::kind = kind;
}

const string &changeList::getNextPageToken() const {
    return nextPageToken;
}

void changeList::setNextPageToken(const string &nextPageToken) {
    changeList::nextPageToken = nextPageToken;
}

const string &changeList::getNewStartPageToken() const {
    return newStartPageToken;
}

void changeList::setNewStartPageToken(const string &newStartPageToken) {
    changeList::newStartPageToken = newStartPageToken;
}

const vector<change> &changeList::getChanges() const {
    return changes;
}

void changeList::setChanges(const vector<change> &changes) {
    changeList::changes = changes;
}
