//
// Created by Matthias Hofstätter on 17.09.17.
//

#include "classes/backgroundImageFile.h"

backgroundImageFile::backgroundImageFile() {
    this->document = new rapidjson::Document;
}

backgroundImageFile::backgroundImageFile(rapidjson::Document &document) {
    this->document = new rapidjson::Document;
    this->document->CopyFrom(document, (this->document)->GetAllocator());
}

string backgroundImageFile::getId() {
    if(this->document->HasMember("id"))
        return this->getString("id");
    return "";
}

void backgroundImageFile::setId(string id) {
    this->setString("id", id);
}

float backgroundImageFile::getXCoordinate() {
    if(this->document->HasMember("xCoordinate"))
        return this->getFloat("xCoordinate");
    return 0.0f;
}

void backgroundImageFile::setXCoordinate(float xCoordinate) {
    this->setFloat("xCoordinate", xCoordinate);
}

float backgroundImageFile::getYCoordinate() {
    if(this->document->HasMember("yCoordinate"))
        return this->getFloat("yCoordinate");
    return 0.0f;
}

void backgroundImageFile::setYCoordinate(float yCoordinate) {
    this->setFloat("yCoordinate", yCoordinate);
}

float backgroundImageFile::getWidth() {
    if(this->document->HasMember("width"))
        return this->getFloat("width");
    return 0.0f;
}

void backgroundImageFile::setWidth(float width) {
    this->setFloat("width", width);
}
