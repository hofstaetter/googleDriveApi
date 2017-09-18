//
// Created by Matthias Hofstätter on 21.08.17.
//

#include <document.h>
#include <classes/fileList.h>

string fileList::getKind() {
    return this->getString("kind");
}

void fileList::setKind(string kind) {
    this->setString("kind", kind);
}

string fileList::getNextPageToken() {
    return this->getString("nextPageToken");
}

void fileList::setNextPageToken(string nextPageToken) {
    this->setString("nextPageToken", nextPageToken);
}

bool fileList::isIncompleteSearch() {
    return this->getBool("incompleteSearch");
}

void fileList::setIncompleteSearch(bool incompleteSearch) {
    this->setBool("incompleteSearch", incompleteSearch);
}

vector<class file> fileList::getFiles() {
    vector<file> result;
    vector<file> docs = this->getObjectArray<file>("files");

    for(int i = 0; i < docs.size(); i++) {
        jsonObject::debugJson((*docs[i].document));
        result.push_back(docs[i]);
    }

    return result;
}

void fileList::setFiles(vector<class file> files) {
    this->setObjectArray<file>("files", files);
}

fileList::fileList() {
    this->document = new rapidjson::Document;
}

fileList::fileList(rapidjson::Document &document) {
    this->document = new rapidjson::Document;
    (this->document)->CopyFrom(document, (this->document)->GetAllocator());
}
