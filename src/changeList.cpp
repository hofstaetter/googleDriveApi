//
// Created by Matthias Hofstätter on 14.09.17.
//

#include "classes/changeList.h"

string changeList::getKind() {
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
}

changeList::changeList() {
    this->document = new rapidjson::Document;
}

changeList::changeList(rapidjson::Document &document) {
    this->document = new rapidjson::Document;
    this->document->CopyFrom(document, (this->document)->GetAllocator());
}
