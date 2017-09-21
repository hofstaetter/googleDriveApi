//
// Created by Matthias Hofstätter on 14.09.17.
//

#include "classes/change.h"
#include "classes/file.h"
#include "classes/teamDrive.h"

change::change() {
    //this->document = new rapidjson::Document;
}

change::change(rapidjson::Document &document) : jsonObject(document) {
    /*this->document = new rapidjson::Document;
    this->document->CopyFrom(document, (this->document)->GetAllocator());*/
    if(document.HasMember("kind"))
        this->kind = document["kind"].GetString();
    if(document.HasMember("type"))
        this->type = document["type"].GetString();
    if(document.HasMember("datetime"))
        this->datetime = time(NULL);
    if(document.HasMember("removed"))
        this->removed = document["removed"].GetBool();
    if(document.HasMember("fileId"))
        this->fileId = document["fileId"].GetString();
    if(document.HasMember("file")) {
        rapidjson::Document d(rapidjson::kObjectType);
        d.CopyFrom(document["file"], d.GetAllocator());
        this->file = file::file(d);
    }
    if(document.HasMember("teamDriveId"))
        this->teamDriveId = document["teamDriveId"].GetString();
    if(document.HasMember("teamDrive")) {
        rapidjson::Document document(rapidjson::kObjectType);
        document.CopyFrom(document["teamDrive"], document.GetAllocator());
        this->teamDrive = teamDrive::teamDrive(document);
    }

}

string &change::getKind() {
    return kind;
}

void change::setKind(string &kind) {
    this->kind = kind;
}

string &change::getType() {
    return type;
}

void change::setType(string &type) {
    this->type = type;
}

time_t change::getDatetime() {
    return datetime;
}

void change::setDatetime(time_t datetime) {
    this->datetime = datetime;
}

bool change::isRemoved() {
    return removed;
}

void change::setRemoved(bool removed) {
    this->removed = removed;
}

string &change::getFileId() {
    return fileId;
}

void change::setFileId(string &fileId) {
    this->fileId = fileId;
}

class file &change::getFile() {
    return file;
}

void change::setFile(class file file) {
    this->file = file;
}

string &change::getTeamDriveId() {
    return teamDriveId;
}

void change::setTeamDriveId(string &teamDriveId) {
    this->teamDriveId = teamDriveId;
}

class teamDrive &change::getTeamDrive() {
    return teamDrive;
}

void change::setTeamDrive(class teamDrive teamDrive) {
    this->teamDrive = teamDrive;
}

/*string change::getKind() {
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
}*/
