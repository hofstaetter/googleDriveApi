//
// Created by Matthias Hofstätter on 21.08.17.
//

#include "classes/file.h"
#include <vector>

file::file() {
    //this->document = new rapidjson::Document;
}

file::file(rapidjson::Document& document) {
    /*this->document = new rapidjson::Document;
    (*this->document).CopyFrom(document, (this->document)->GetAllocator());*/
    if(document.HasMember("kind"))
        this->kind = document["kind"].GetString();
    if(document.HasMember("id"))
        this->id = document["id"].GetString();
    if(document.HasMember("name"))
        this->name = document["name"].GetString();
    if(document.HasMember("mimeType"))
        this->mimeType = document["mimeType"].GetString();
    if(document.HasMember("description"))
        this->description = document["description"].GetString();
    if(document.HasMember("starred"))
        this->starred = document["starred"].GetBool();
    if(document.HasMember("trashed"))
        this->trashed = document["trashed"].GetBool();
    if(document.HasMember("trashingUser")) {
        rapidjson::Document d(rapidjson::kObjectType);
        d.CopyFrom(document["trashingUser"], d.GetAllocator());
        this->trashingUser = user(d);
    }
    if(document.HasMember("trashedTime")) {
        this->trashedTime = document["trashedTime"].GetString();
    }
    if(document.HasMember("parents")) {
        for(auto &p : document["parents"].GetArray()) {
            this->parents.push_back(p.GetString());
        }
    }
    if(document.HasMember("properties")) {
        for(rapidjson::Value::ConstMemberIterator itr = document["properties"].MemberBegin(); itr == document["properties"].MemberEnd(); itr++) {
            this->properties.insert(make_pair(itr->name.GetString(), itr->value.GetString()));
        }
    }
    if(document.HasMember("appProperties")) {
        for(rapidjson::Value::ConstMemberIterator itr = document["appProperties"].MemberBegin(); itr == document["appProperties"].MemberEnd(); itr++) {
            this->appProperties.insert(make_pair(itr->name.GetString(), itr->value.GetString()));
        }
    }
    if(document.HasMember("spaces")) {
        for(auto &p : document["spaces"].GetArray()) {
            this->spaces.push_back(p.GetString());
        }
    }
    if(document.HasMember("version"))
        this->version = stol(document["version"].GetString());
    if(document.HasMember("webContentLink"))
        this->webContentLink = document["webContentLink"].GetString();
    if(document.HasMember("webViewLink"))
        this->webViewLink = document["webViewLink"].GetString();
    if(document.HasMember("iconLink"))
        this->iconLink = document["iconLink"].GetString();
    if(document.HasMember("hasThumbnail"))
        this->hasThumbnail = document["hasThumbnail"].GetBool();
    if(document.HasMember("thumbnailLink"))
        this->thumbnailLink = document["thumbnailLink"].GetString();

    if(document.HasMember("modifiedTime"))
        this->modifiedTime = document["modifiedTime"].GetString();

    if(document.HasMember("size"))
        this->size = stol(document["size"].GetString());
}

string &file::getKind() {
    return kind;
}

void file::setKind(string &kind) {
    file::kind = kind;
}

string &file::getId() {
    return id;
}

void file::setId(string &id) {
    file::id = id;
}

string &file::getName() {
    return name;
}

void file::setName(string &name) {
    file::name = name;
}

string &file::getMimeType() {
    return mimeType;
}

void file::setMimeType(string &mimeType) {
    file::mimeType = mimeType;
}

string &file::getDescription() {
    return description;
}

void file::setDescription(string &description) {
    file::description = description;
}

bool file::isStarred() {
    return starred;
}

void file::setStarred(bool starred) {
    file::starred = starred;
}

bool file::isTrashed() {
    return trashed;
}

void file::setTrashed(bool trashed) {
    file::trashed = trashed;
}

bool file::isExplicitlyTrashed() {
    return explicitlyTrashed;
}

void file::setExplicitlyTrashed(bool explicitlyTrashed) {
    file::explicitlyTrashed = explicitlyTrashed;
}

user &file::getTrashingUser() {
    return trashingUser;
}

void file::setTrashingUser(user &trashingUser) {
    file::trashingUser = trashingUser;
}

vector<string> &file::getParents() {
    return parents;
}

void file::setParents(vector<string> &parents) {
    file::parents = parents;
}

map<string, string> &file::getProperties() {
    return properties;
}

void file::setProperties(map<string, string> &properties) {
    file::properties = properties;
}

map<string, string> &file::getAppProperties() {
    return appProperties;
}

void file::setAppProperties(map<string, string> &appProperties) {
    file::appProperties = appProperties;
}

vector<string> &file::getSpaces() {
    return spaces;
}

void file::setSpaces(vector<string> &spaces) {
    file::spaces = spaces;
}

long file::getVersion() {
    return version;
}

void file::setVersion(long version) {
    file::version = version;
}

string &file::getWebContentLink() {
    return webContentLink;
}

void file::setWebContentLink(string &webContentLink) {
    file::webContentLink = webContentLink;
}

string &file::getWebViewLink() {
    return webViewLink;
}

void file::setWebViewLink(string &webViewLink) {
    file::webViewLink = webViewLink;
}

string &file::getIconLink() {
    return iconLink;
}

void file::setIconLink(string &iconLink) {
    file::iconLink = iconLink;
}

bool file::isHasThumbnail() {
    return hasThumbnail;
}

void file::setHasThumbnail(bool hasThumbnail) {
    file::hasThumbnail = hasThumbnail;
}

string &file::getThumbnailLink() {
    return thumbnailLink;
}

void file::setThumbnailLink(string &thumbnailLink) {
    file::thumbnailLink = thumbnailLink;
}

long file::getSize() {
    return size;
}

void file::setSize(long size) {
    file::size = size;
}

void file::setTrashedTime(string &trashedTime) {
    file::trashedTime = trashedTime;
}

string &file::getModifiedTime() {
    return modifiedTime;
}

void file::setModifiedTime(string &modifiedTime) {
    file::modifiedTime = modifiedTime;
}

/*string file::getKind() {
    return this->getString("kind");
}

void file::setKind(string &kind) {
    this->setString("kind", kind);
}

string file::getId() {
    return this->getString("id");
}

void file::setId(string &id) {
    this->setString("id", id);
}

string file::getName() {
    return this->getString("name");
}

void file::setName(string &name) {
    this->setString("name", name);
}

string file::getMimeType() {
    return this->getString("mimeType");
}

void file::setMimeType(string &mimeType) {
    this->setString("mimeType", mimeType);
}

string file::getDescription() {
    return this->getString("description");
}

void file::setDescription(string &description) {
    this->setString("description", description);
}

bool file::isStarred() {
    return this->getBool("starred");
}

void file::setStarred(bool starred) {
    this->setBool("starred", starred);
}

bool file::isTrashed() {
    return this->getBool("trashed");
}

void file::setTrashed(bool trashed) {
    this->setBool("trashed", trashed);
}

bool file::isExplicitlyTrashed() {
    return this->getBool("explicitlyTrashed");
}

void file::setExplicitlyTrashed(bool explicitlyTrashed) {
    this->setBool("explicitlyTrashed", explicitlyTrashed);
}

user file::getTrashingUser() {
    return this->getObject<user>("trashingUser");
}

void file::setTrashingUser(user trashingUser) {
    this->setObject("trashingUser", trashingUser);
}

string file::getTrashedTime() {
    return this->getString("trashedTime");
}

void file::setTrashedTime(string &trashedTime) {
    this->setString("trashedTime", trashedTime);
}

vector<string> file::getParents() {
    return this->getStringArray("parents");
}

void file::setParents(vector<string> &parents) {
    this->setStringArray("parents", parents);
}

map<string, string> file::getProperties() {
    return this->getStringMap("properties");
}

void file::setProperties(map<string, string> &properties) {
    this->setStringMap("properties", properties);
}

map<string, string> file::getAppProperties() {
    return this->getStringMap("appProperties");
}

void file::setAppProperties(map<string, string> &appProperties) {
    this->setStringMap("appProperties", appProperties);
}

vector<string> file::getSpaces() {
    return this->getStringArray("spaces");
}

void file::setSpaces(vector<string> &spaces) {
    this->setStringArray("spaces", spaces);
}

long file::getVersion() {
    return this->getLong("version");
}

void file::setVersion(long version) {
    this->setLong("version", version);
}

string file::getWebContentLink() {
    return this->getString("webContentLink");
}

void file::setWebContentLink(string &webContentLink) {
    this->setString("webContentLink", webContentLink);
}

string file::getWebViewLink() {
    return this->getString("webViewLink");
}

void file::setWebViewLink(string &webViewLink) {
    this->setString("webViewLink", webViewLink);
}

string file::getIconLink() {
    return this->getString("iconLink");
}

void file::setIconLink(string &iconLink) {
    this->setString("iconLink", iconLink);
}

bool file::isHasThumbnail() {
    return this->getBool("hasThumbnail");
}

void file::setHasThumbnail(bool hasThumbnail) {
    this->setBool("hasThumbnail", hasThumbnail);
}

string file::getThumbneilLink() {
    return this->getString("thumbneilLink");
}

void file::setThumbneilLink(string &thumbneilLink) {
    this->setString("thumbneilLink", thumbneilLink);
}

long file::getThumbneilVersion() {
    return this->getLong("thumbneilVersion");
}

void file::setThumbneilVersion(long thumbneilVersion) {
    this->setLong("thumbneilVersion", thumbneilVersion);
}

bool file::isViewedByMe() {
    return this->getBool("viewedByMe");
}

void file::setViewedByMe(bool viewedByMe) {
    this->setBool("viewedByMe", viewedByMe);
}

string file::getViewedByMeTime() {
    return this->getString("viewedByMeTime");
}

void file::setViewedByMeTime(string &viewedByMeTime) {
    this->setString("viewedByMeTime", viewedByMeTime);
}

string file::getCreatedTime() {
    return this->getString("createdTime");
}

void file::setCreatedTime(string &createdTime) {
    this->setString("createdTime", createdTime);
}

string file::getModifiedTime() {
    return this->getString("modifiedTime");
}

void file::setModifiedTime(string &modifiedTime) {
    this->setString("modifiedTime", modifiedTime);
}

string file::getModifiedByMeTime() {
    return this->getString("modifiedByMeTime");
}

void file::setModifiedByMeTime(string &modifiedByMeTime) {
    this->setString("modifiedByMeTime", modifiedByMeTime);
}

bool file::isModifiedByMe() {
    return this->getBool("modifiedByMe");
}

void file::setModifiedByMe(bool modifiedByMe) {
    this->setBool("modifiedByMe", modifiedByMe);
}

string file::getSharedWithMeTime() {
    return this->getString("sharedWithMeTime");
}

void file::setSharedWithMeTime(string &sharedWithMeTime) {
    this->setString("sharedWithMeTime", sharedWithMeTime);
}

user file::getSharingUser() {
    return user(this->getObject<user>("sharingUser"));
}

void file::setSharingUser(user sharingUser) {
    this->setObject("sharingUser", sharingUser);
}

vector<user> file::getOwners() {
    vector<user> result;
    vector<rapidjson::Document> vec = this->getObjectArray("owners");
    for(auto &d : ) {
        result.push_back(user(d));
    }
    return result;
}

void file::setOwners(vector<user> &owners) {
    std::vector<rapidjson::Document> v;
    for(user &u : owners) {
        v.push_back(u.document);
    }
    this->setObjectArray("owners", v);
}

string file::getTeamDriveId() {
    return this->getString("teamDriveId");
}

void file::setTeamDriveId(string &teamDriveId) {
    this->setString("teamDriveId", teamDriveId);
}

user file::getLastModifyingUser() {
    return this->getObject<user>("lastModifyingUser");
}

void file::setLastModifyingUser(user &lastModifyingUser) {
    this->setObject("lastModifyingUser", lastModifyingUser);
}

bool file::isShared() {
    return this->getBool("shared");
}

void file::setShared(bool shared) {
    this->setBool("shared", shared);
}

bool file::isOwnedByMe() {
    return this->getBool("ownedByMe");
}

void file::setOwnedByMe(bool ownedByMe) {
    this->setBool("ownedByMe", ownedByMe);
}

capabilities file::getCapabilities() {
    return this->getObject<capabilities>("capabilities");
}

void file::setCapabilities(class capabilities &capabilities) {
    this->setObject("capabilities", capabilities);
}

bool file::isViewersCanCopyContent() {
    return this->getBool("viewersCanCopyContent");
}

void file::setViewersCanCopyContent(bool viewersCanCopyContent) {
    this->setBool("viewersCanCopyContent", viewersCanCopyContent);
}

bool file::isWritersCanShare() {
    return this->getBool("writersCanShare");
}

void file::setWritersCanShare(bool writersCanShare) {
    this->setBool("writersCanShare", writersCanShare);
}

vector<permission> file::getPermissions() {
    vector<permission> result;
    for(auto d : this->getObjectArray("permissions")) {
        result.push_back(permission(d));
    }
    return result;
}

void file::setPermissions(vector<permission> &permissions) {
    vector<rapidjson::Document> v;
    for(permission &p : permissions) {
        v.push_back(p.document);
    }
    this->setObjectArray("permissions", v);
}

bool file::isHasAugmentedPermissions() {
    return this->getBool("hasAugmentedPermissions");
}

void file::setHasAugmentedPermissions(bool hasAugmentedPermissions) {
    this->setBool("hasAugmentedPermissions", hasAugmentedPermissions);
}

string file::getFolderColorRgb() {
    return this->getString("folderColorRgb");
}

void file::setFolderColorRgb(string &folderColorRgb) {
    this->setString("folderColorRgb", folderColorRgb);
}

string file::getOriginalFilename() {
    return this->getString("riginalFilename");
}

void file::setOriginalFilename(string &originalFilename) {
    this->setString("riginalFilename", originalFilename);
}

string file::getFullFileExtension() {
    return this->getString("fullFileExtension");
}

void file::setFullFileExtension(string &fullFileExtension) {
    this->setString("fullFileExtension", fullFileExtension);
}

string file::getFileExtension() {
    return this->getString("fileExtension");
}

void file::setFileExtension(string &fileExtension) {
    this->setString("fileExtension", fileExtension);
}

string file::getMd5Checksum() {
    return this->getString("md5Checksum");
}

void file::setMd5Checksum(string &md5Checksum) {
    this->setString("md5Checksum", md5Checksum);
}

long file::getSize() {
    return this->getLong("size");
}

void file::setSize(long size) {
    this->setLong("size", size);
}

long file::getQuotaBytesUser() {
    return this->getLong("quotaBytesUser");
}

void file::setQuotaBytesUser(long quotaBytesUser) {
    this->setLong("quotaBytesUser", quotaBytesUser);
}

string file::getHeadRevisionId() {
    return this->getString("headRevisionId");
}

void file::setHeadRevisionId(string &headRevisionId) {
    this->setString("headRevisionId", headRevisionId);
}

imageMediaMetadata file::getImageMediaMetadata() {
    return this->getObject<imageMediaMetadata>("imageMediaMetadata");
}

void file::setImageMediaMetadata(class imageMediaMetadata &imageMediaMetadata) {
    this->setObject("imageMediaMetadata", imageMediaMetadata);
}

class videoMediaMetadata file::getVideoMediaMetadata() {
    return this->getObject<videoMediaMetadata>("videoMediaMetadata");
}

void file::setVideoMediaMetadata(class videoMediaMetadata &videoMediaMetadata) {
    this->setObject("videoMediaMetadata", videoMediaMetadata);
}

bool file::isIsAppAuthorized() {
    return this->getBool("isAppAuthorized");
}

void file::setIsAppAuthorized(bool isAppAuthorized) {
    this->setBool("isAppAuthorized", isAppAuthorized);
}*/
