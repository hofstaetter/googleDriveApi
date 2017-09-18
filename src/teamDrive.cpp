//
// Created by Matthias Hofstätter on 14.09.17.
//

#include "classes/teamDrive.h"

teamDrive::teamDrive() {
    this->document = new rapidjson::Document;
}

string teamDrive::getKind() {
    return this->getString("kind");
}

void teamDrive::setKind(string kind) {
    this->setString("kind", kind);
}

string teamDrive::getName() {
    return this->getString("name");
}

void teamDrive::setName(string name) {
    this->setString("name", name);
}

string teamDrive::getThemeId() {
    return this->getString("themeId");
}

void teamDrive::setThemeId(string themeId) {
    this->setString("themeId", themeId);
}

string teamDrive::getColorRgb() {
    return this->getString("colorRgb");
}

void teamDrive::setColorRgb(string colorRgb) {
    this->setString("colorRgb", colorRgb);
}

backgroundImageFile teamDrive::getBackgroundImageFile() {
    return this->getObject<class backgroundImageFile>("backgroundImageFile");
}

void teamDrive::setBackgroundImageFile(backgroundImageFile backgroundImageFile) {
    this->setObject<class backgroundImageFile>("backgroundImageFile", backgroundImageFile);
}

string teamDrive::getBackgroundImageLink() {
    return this->getString("backgroundImageLink");
}

void teamDrive::setBackgroundImageLink(string backgroundImageLink) {
    this->setString("backgroundImageLink", backgroundImageLink);
}

capabilities teamDrive::getCapabilities() {
    return this->getObject<class capabilities>("capabilities");
}

void teamDrive::setCapabilities(capabilities capabilities) {
    this->setObject<class capabilities>("capabilities", capabilities);
}

teamDrive::teamDrive(rapidjson::Document &document) : jsonObject(document) {
    this->document = new rapidjson::Document;
    this->document->CopyFrom(document, (this->document)->GetAllocator());
}
