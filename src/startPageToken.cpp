//
// Created by Matthias Hofstätter on 14.09.17.
//

#include "classes/startPageToken.h"

startPageToken::startPageToken() {
    this->document = new rapidjson::Document;
}

startPageToken::startPageToken(rapidjson::Document &document) {
    this->document = new rapidjson::Document;
    this->document->CopyFrom(document, (this->document)->GetAllocator());
}

string startPageToken::getKind() {
    return this->getString("kind");
}

void startPageToken::setKind(string kind) {
    this->setString("kind", kind);
}

string startPageToken::getStartPageToken() {
    return this->getString("startPageToken");
}

void startPageToken::setStartPageToken(string startPageToken) {
    this->setString("startPageToken", startPageToken);
}
