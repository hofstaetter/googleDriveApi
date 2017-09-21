//
// Created by Matthias Hofstätter on 21.08.17.
//

#ifndef GOOGLEDRIVEAPI_FILESRESOURCE_H
#define GOOGLEDRIVEAPI_FILESRESOURCE_H

#include "files/files.h"
#include "user.h"
#include "imageMediaMetadata.h"
#include "videoMediaMetadata.h"
#include "capabilities.h"
#include "permission.h"
#include "jsonObject.h"
#include <rapidjson.h>
#include <document.h>
#include <writer.h>

#include <string>
#include <map>
#include <vector>

using namespace std;

class file: public jsonObject {
private:
    string kind;
    string id;
    string name;
    string mimeType;
    string description;
    bool starred;
    bool trashed;
    bool explicitlyTrashed;
    user trashingUser;
    string trashedTime;
    vector<string> parents;
    map<string, string> properties;
    map<string, string> appProperties;
    vector<string> spaces;
    long version;
    string webContentLink;
    string webViewLink;
    string iconLink;
    bool hasThumbnail;
    string thumbnailLink;
    //TODO
    string modifiedTime;
    //TODO
    long size;
    //TODO
public:
    void setTrashedTime(string &trashedTime);

    string &getModifiedTime();

    void setModifiedTime(string &modifiedTime);

public:
    long getSize();

    void setSize(long size);
    //TODO
public:
    /*string getKind();

    void setKind(string &kind);

    string getId();

    void setId(string &id);

    string getName();

    void setName(string &name);

    string getMimeType();

    void setMimeType(string &mimeType);

    string getDescription();

    void setDescription(string &description);

    bool isStarred();

    void setStarred(bool starred);

    bool isTrashed();

    void setTrashed(bool trashed);

    bool isExplicitlyTrashed();

    void setExplicitlyTrashed(bool explicitlyTrashed);

    user getTrashingUser();

    void setTrashingUser(user trashingUser);

    string getTrashedTime();

    void setTrashedTime(string &trashedTime);

    vector<string> getParents();

    void setParents(vector<string> &parents);

    map<string, string> getProperties();

    void setProperties(map<string, string> &properties);

    map<string, string> getAppProperties();

    void setAppProperties(map<string, string> &appProperties);

    vector<string> getSpaces();

    void setSpaces(vector<string> &spaces);

    long getVersion();

    void setVersion(long version);

    string getWebContentLink();

    void setWebContentLink(string &webContentLink);

    string getWebViewLink();

    void setWebViewLink(string &webViewLink);

    string getIconLink();

    void setIconLink(string &iconLink);

    bool isHasThumbnail();

    void setHasThumbnail(bool hasThumbnail);

    string getThumbneilLink();

    void setThumbneilLink(string &thumbneilLink);

    long getThumbneilVersion();

    void setThumbneilVersion(long thumbneilVersion);

    bool isViewedByMe();

    void setViewedByMe(bool viewedByMe);

    string getViewedByMeTime();

    void setViewedByMeTime(string &viewedByMeTime);

    string getCreatedTime();

    void setCreatedTime(string &createdTime);

    string getModifiedTime();

    void setModifiedTime(string &modifiedTime);

    string getModifiedByMeTime();

    void setModifiedByMeTime(string &modifiedByMeTime);

    bool isModifiedByMe();

    void setModifiedByMe(bool modifiedByMe);

    string getSharedWithMeTime();

    void setSharedWithMeTime(string &sharedWithMeTime);

    user getSharingUser();

    void setSharingUser(user sharingUser);

    vector<user> getOwners();

    void setOwners(vector<user> &owners);

    string getTeamDriveId();

    void setTeamDriveId(string &teamDriveId);

    user getLastModifyingUser();

    void setLastModifyingUser(user &lastModifyingUser);

    bool isShared();

    void setShared(bool shared);

    bool isOwnedByMe();

    void setOwnedByMe(bool ownedByMe);

    class capabilities getCapabilities();

    void setCapabilities(class capabilities &capabilities);

    bool isViewersCanCopyContent();

    void setViewersCanCopyContent(bool viewersCanCopyContent);

    bool isWritersCanShare();

    void setWritersCanShare(bool writersCanShare);

    vector<permission> getPermissions();

    void setPermissions(vector<permission> &permissions);

    bool isHasAugmentedPermissions();

    void setHasAugmentedPermissions(bool hasAugmentedPermissions);

    string getFolderColorRgb();

    void setFolderColorRgb(string &folderColorRgb);

    string getOriginalFilename();

    void setOriginalFilename(string &originalFilename);

    string getFullFileExtension();

    void setFullFileExtension(string &fullFileExtension);

    string getFileExtension();

    void setFileExtension(string &fileExtension);

    string getMd5Checksum();

    void setMd5Checksum(string &md5Checksum);

    long getSize();

    void setSize(long size);

    long getQuotaBytesUser();

    void setQuotaBytesUser(long quotaBytesUser);

    string getHeadRevisionId();

    void setHeadRevisionId(string &headRevisionId);

    class imageMediaMetadata getImageMediaMetadata();

    void setImageMediaMetadata(class imageMediaMetadata &imageMediaMetadata);

    class videoMediaMetadata getVideoMediaMetadata();

    void setVideoMediaMetadata(class videoMediaMetadata &videoMediaMetadata);

    bool isIsAppAuthorized();

    void setIsAppAuthorized(bool isAppAuthorized);

    bool isAppAuthorized;*/

    file();

    string &getKind();

    void setKind(string &kind);

    string &getId();

    void setId(string &id);

    string &getName();

    void setName(string &name);

    string &getMimeType();

    void setMimeType(string &mimeType);

    string &getDescription();

    void setDescription(string &description);

    bool isStarred();

    void setStarred(bool starred);

    bool isTrashed();

    void setTrashed(bool trashed);

    bool isExplicitlyTrashed();

    void setExplicitlyTrashed(bool explicitlyTrashed);

    user &getTrashingUser();

    void setTrashingUser(user &trashingUser);

    time_t getTrashedTime();

    void setTrashedTime(time_t trashedTime);

    vector<string> &getParents();

    void setParents(vector<string> &parents);

    map<string, string> &getProperties();

    void setProperties(map<string, string> &properties);

    map<string, string> &getAppProperties();

    void setAppProperties(map<string, string> &appProperties);

    vector<string> &getSpaces();

    void setSpaces(vector<string> &spaces);

    long getVersion();

    void setVersion(long version);

    string &getWebContentLink();

    void setWebContentLink(string &webContentLink);

    string &getWebViewLink();

    void setWebViewLink(string &webViewLink);

    string &getIconLink();

    void setIconLink(string &iconLink);

    bool isHasThumbnail();

    void setHasThumbnail(bool hasThumbnail);

    string &getThumbnailLink();

    void setThumbnailLink(string &thumbnailLink);

    file(rapidjson::Document& document);
};


#endif //GOOGLEDRIVEAPI_FILESRESOURCE_H
