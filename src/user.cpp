//
// Created by Matthias Hofstätter on 21.08.17.
//

#include "classes/user.h"

string user::getKind() {
    return this->getString("kind");
}

void user::setKind(string &kind) {
    this->setString("kind", kind);
}

string user::getDisplayName() {
    return this->getString("displayName");
}

void user::setDisplayName(string &displayName) {
    this->setString("displayName", displayName);
}

string user::getPhotoLink() {
    return this->getString("photoLink");
}

void user::setPhotoLink(string &photoLink) {
    this->setString("photoLink", photoLink);
}

bool user::isMe() {
    return this->getBool("me");
}

void user::setMe(bool me) {
    this->setBool("me", me);
}

string user::getPermissionId() {
    return this->getString("permissionId");
}

void user::setPermissionId(string &permissionId) {
    this->setString("permissionId", permissionId);
}

string user::getEmailAddress() {
    return this->getString("emailAddress");
}

void user::setEmailAddress(string &emailAddress) {
    this->setString("emailAddress", emailAddress);
}

user::user() {
}

user::user(rapidjson::Document &document) {
    this->document.CopyFrom(document, this->document.GetAllocator());
}
