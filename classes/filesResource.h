//
// Created by Matthias Hofstätter on 21.08.17.
//

#ifndef GOOGLEDRIVEAPI_FILESRESOURCE_H
#define GOOGLEDRIVEAPI_FILESRESOURCE_H


#include "../googleDriveApi.h"
#include "user.h"

#include <string>
#include <map>
#include <vector>

using namespace std;

class teamDrivePermissionDetail {
public:
    std::string teamDrivePermissionType;
    std::string role;
    std::string inheritedFrom;
    bool inherited;
};

class permission {
public:
    std::string kind;
    std::string id;
    std::string type;
    std::string emailAddress;
    std::string domain;
    std::string role;
    bool allowFileDiscovery;
    std::string displayName;
    std::string photoLink;
    std::string expirationTime;
    std::vector<teamDrivePermissionDetail> teamDrivePermissionDetails;
    bool deleted;
};

class thumbnail {
public:
    char image;
    std::string mimeType;
};

class contentHint {
public:
    struct thumbnail thumbnail;
    std::string indexableText;
};

class capability {
public:
    bool canAddChildren;
    bool canChangeViewersCanCopyContent;
    bool canComment;
    bool canCopy;
    bool canDelete;
    bool canDownload;
    bool canEdit;
    bool canLastChildren;
    bool canMoveItemIntoTeamDrive;
    bool canMoveTeamDriveItem;
    bool canReadRevisions;
    bool canReadTeamDrive;
    bool canRemoveChildren;
    bool canRename;
    bool canShare;
    bool canTrash;
    bool canUntrash;
};

class location {
public:
    double latitude;
    double longitude;
    double altitude;
};

class imageMediaMetadata {
public:
    int width;
    int height;
    int rotation;
    struct location location;
    std::string time;
    std::string cameraMake;
    std::string cameraModel;
    float exposureTime;
    float aperture;
    bool flashUsed;
    float focalLength;
    int isoSpeed;
    std::string meteringMode;
    std::string sensor;
    std::string exposureMode;
    std::string colorSpace;
    std::string whiteBalance;
    float exposureBias;
    float maxApertureValue;
    int subjectDistance;
    std::string lens;
};

class videoMediaMetadata {
public:
    int width;
    int height;
    long durationMillis;
};

class filesResource {
public:
    std::string kind;
    std::string id;
    std::string name;
    std::string mimeType;
    std::string description;
    bool starred;
    bool trashed;
    bool explicitlyTrashed;
    user trashingUser;
    std::string trashedTime;
    std::vector<std::string> parents;
    std::map<std::string, std::string> properties;
    std::map<std::string, std::string> appProperties;
    std::vector<std::string> spaces;
    long version;
    std::string webContentLink;
    std::string webViewLink;
    std::string iconLink;
    bool hasThumbnail;
    std::string thumbneilLink;
    long thumbneilVersion;
    bool viewdByMe;
    std::string viewedByMeTime;
    std::string createdTime;
    std::string modifiedTime;
    std::string modifiedByMeTime;
    bool modifiedByMe;
    std::string sharedWithMeTime;
    user sharingUser;
    vector<user> owners;
    std::string teamDriveId;
    user lastModifyingUser;
    bool shared;
    bool ownedByMe;
    capability capabilities;
    bool viewersCanCopyContent;
    bool writersCanShare;
    std::vector<permission> permissions;
    bool hasAugmentedPermissions;
    std::string folderColorRgb;
    std::string originalFilename;
    std::string fullFileExtension;
    std::string fileExtension;
    std::string md5Checksum;
    long size;
    long quotaBytesUser;
    std::string headRevisionId;
    imageMediaMetadata imageMediaMetadata;
    videoMediaMetadata videoMediaMetadata;
    bool isAppAuthorized;

    filesResource();

    std::string toJSON();
    static filesResource fromJSON(std::string json);
    static filesResource fromJSON(rapidjson::Document& document);
};


#endif //GOOGLEDRIVEAPI_FILESRESOURCE_H
