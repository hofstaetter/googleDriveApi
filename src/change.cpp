//
// Created by Matthias Hofstätter on 14.09.17.
//

#include "classes/change.h"

change::change() {
    this->document = new rapidjson::Document;
}

change::change(rapidjson::Document &document) : jsonObject(document) {
    this->document = new rapidjson::Document;
    this->document->CopyFrom(document, (this->document)->GetAllocator());
}

string change::getKind() {
    return this->getString("kind");
}

void change::setKind(string kind) {
    this->setString("kind", kind);
}

string change::getType() {
    return this->getString("type");
}

void change::setType(string type) {
    this->setString("type", type);
}

time_t change::getDatetime() {
    return 0; //TODO
}

void change::setDatetime(time_t datetime) {
    //TODO
}

bool change::isRemoved() {
    return this->getBool("removed");
}

void change::setRemoved(bool removed) {
    this->setBool("removed", removed);
}

string change::getFileId() {
    return this->getString("fileId");
}

void change::setFileId(string fileId) {
    this->setString("fileId", fileId);
}

file change::getFile() {
    return this->getObject<file>("file");
}

void change::setFile(file file) {
    this->setObject<class file>("file", file);
}

string change::getTeamDriveId() {
    return this->getString("teamDriveId");
}

void change::setTeamDriveId(string teamDriveId) {
    this->setString("teamDriveId", teamDriveId);
}

class teamDrive change::getTeamDrive() {
    return this->getObject<class teamDrive>("teamDrive");
}

void change::setTeamDrive(class teamDrive teamDrive) {
    this->setObject<class teamDrive>("teamDrive", teamDrive);
}
