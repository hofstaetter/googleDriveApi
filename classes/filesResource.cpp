//
// Created by Matthias Hofstätter on 21.08.17.
//

#include "filesResource.h"
#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>

std::string filesResource::toJSON() {
    rapidjson::Document document;
    rapidjson::StringBuffer sb;
    rapidjson::Writer<rapidjson::StringBuffer> writer(sb);

    writer.StartObject();
    writer.Key("kind");
    writer.String(this->kind.c_str());
    writer.Key("id");
    writer.String(this->id.c_str());
    writer.Key("name");
    writer.String(this->name.c_str());
    writer.Key("mimeType");
    writer.String(this->mimeType.c_str());
    writer.Key("description");
    writer.String(this->description.c_str());
    writer.Key("starred");
    writer.Bool(this->starred);
    writer.Key("trashed");
    writer.Bool(this->trashed);
    writer.Key("explicitlyTrashed");
    writer.Bool(this->explicitlyTrashed);
    writer.Key("trashingUser");
    //user
    writer.StartObject();
    writer.Key("kind");
    writer.String(this->trashingUser.kind.c_str());
    writer.Key("displayName");
    writer.String(this->trashingUser.displayName.c_str());
    writer.Key("photoLink");
    writer.String(this->trashingUser.photoLink.c_str());
    writer.Key("me");
    writer.Bool(this->trashingUser.me);
    writer.Key("permissionId");
    writer.String(this->trashingUser.permissionId.c_str());
    writer.Key("emailAddress");
    writer.String(this->trashingUser.emailAddress.c_str());
    writer.EndObject();
    //user end
    writer.Key("trashedTime");
    writer.String(this->trashedTime.c_str());
    writer.Key("parents");
    writer.StartArray();
    for(auto v : this->parents) {
        writer.String(v.c_str());
    }
    writer.EndArray();
    writer.Key("properties");
    writer.StartObject();
    for(auto v : this->properties) {
        writer.Key(v.first.c_str());
        writer.String(v.second.c_str());
    }
    writer.EndObject();
    writer.Key("appProperties");
    writer.StartObject();
    for(auto v : this->appProperties) {
        writer.Key(v.first.c_str());
        writer.String(v.second.c_str());
    }
    writer.EndObject();
    writer.Key("spaces");
    writer.StartArray();
    for(auto v : this->spaces) {
        writer.String(v.c_str());
    }
    writer.EndArray();
    writer.Key("version");
    writer.Int64(this->version);
    writer.Key("webContentLink");
    writer.String(this->webContentLink.c_str());
    writer.Key("webViewLink");
    writer.String(this->webViewLink.c_str());
    writer.Key("iconLink");
    writer.String(this->iconLink.c_str());
    writer.Key("hasThumbnail");
    writer.Bool(this->hasThumbnail);
    writer.Key("thumbnailLink");
    writer.String(this->thumbneilLink.c_str());
    writer.Key("thumbnailVersion");
    writer.Int64(this->thumbneilVersion);
    writer.Key("viewedByMe");
    writer.Bool(this->viewdByMe);
    writer.Key("viewedByMeTime");
    writer.String(this->viewedByMeTime.c_str());
    writer.Key("createdTime");
    writer.String(this->createdTime.c_str());
    writer.Key("modifiedTime");
    writer.String(this->modifiedTime.c_str());
    writer.Key("modifiedByMeTime");
    writer.String(this->modifiedByMeTime.c_str());
    writer.Key("modifiedByMe");
    writer.Bool(this->modifiedByMe);
    writer.Key("sharedWithMeTime");
    writer.String(this->sharedWithMeTime.c_str());
    writer.Key("sharingUser");
    writer.StartObject();
    writer.Key("kind");
    writer.String(this->trashingUser.kind.c_str());
    writer.Key("displayName");
    writer.String(this->trashingUser.displayName.c_str());
    writer.Key("photoLink");
    writer.String(this->trashingUser.photoLink.c_str());
    writer.Key("me");
    writer.Bool(this->trashingUser.me);
    writer.Key("permissionId");
    writer.String(this->trashingUser.permissionId.c_str());
    writer.Key("emailAddress");
    writer.String(this->trashingUser.emailAddress.c_str());
    writer.EndObject();
    writer.Key("owners");
    writer.StartArray();
    for(auto v : this->owners) {
        writer.StartObject();
        writer.Key("kind");
        writer.String(this->trashingUser.kind.c_str());
        writer.Key("displayName");
        writer.String(this->trashingUser.displayName.c_str());
        writer.Key("photoLink");
        writer.String(this->trashingUser.photoLink.c_str());
        writer.Key("me");
        writer.Bool(this->trashingUser.me);
        writer.Key("permissionId");
        writer.String(this->trashingUser.permissionId.c_str());
        writer.Key("emailAddress");
        writer.String(this->trashingUser.emailAddress.c_str());
        writer.EndObject();
    }
    writer.EndArray();
    writer.Key("teamDriveId");
    writer.String(this->teamDriveId.c_str());
    writer.Key("lastModifyingUser");
    writer.StartObject();
    writer.Key("kind");
    writer.String(this->trashingUser.kind.c_str());
    writer.Key("displayName");
    writer.String(this->trashingUser.displayName.c_str());
    writer.Key("photoLink");
    writer.String(this->trashingUser.photoLink.c_str());
    writer.Key("me");
    writer.Bool(this->trashingUser.me);
    writer.Key("permissionId");
    writer.String(this->trashingUser.permissionId.c_str());
    writer.Key("emailAddress");
    writer.String(this->trashingUser.emailAddress.c_str());
    writer.EndObject();
    writer.Key("shared");
    writer.Bool(this->shared);
    writer.Key("ownedByMe");
    writer.Bool(this->ownedByMe);
    writer.Key("capabilities");
    writer.StartObject();
    writer.Key("canAddChildren");
    writer.Bool(this->capabilities.canAddChildren);
    writer.Key("canChangeViewersCanCopyContent");
    writer.Bool(this->capabilities.canChangeViewersCanCopyContent);
    writer.Key("canComment");
    writer.Bool(this->capabilities.canComment);
    writer.Key("canCopy");
    writer.Bool(this->capabilities.canCopy);
    writer.Key("canDelete");
    writer.Bool(this->capabilities.canDelete);
    writer.Key("canDownload");
    writer.Bool(this->capabilities.canDownload);
    writer.Key("canEdit");
    writer.Bool(this->capabilities.canEdit);
    writer.Key("canLastChildren");
    writer.Bool(this->capabilities.canLastChildren);
    writer.Key("canMoveItemIntoTeamDrive");
    writer.Bool(this->capabilities.canMoveItemIntoTeamDrive);
    writer.Key("canMoveTeamDriveItem");
    writer.Bool(this->capabilities.canMoveTeamDriveItem);
    writer.Key("canReadRevisions");
    writer.Bool(this->capabilities.canReadRevisions);
    writer.Key("canReadTeamDrive");
    writer.Bool(this->capabilities.canReadTeamDrive);
    writer.Key("canRemoveChildren");
    writer.Bool(this->capabilities.canRemoveChildren);
    writer.Key("canRename");
    writer.Bool(this->capabilities.canRename);
    writer.Key("canShare");
    writer.Bool(this->capabilities.canShare);
    writer.Key("canTrash");
    writer.Bool(this->capabilities.canTrash);
    writer.Key("canUntrash");
    writer.Bool(this->capabilities.canUntrash);
    writer.EndObject();

    writer.Key("viewersCanCopyContent");
    writer.Bool(this->viewersCanCopyContent);

    writer.Key("writersCanShare");
    writer.Bool(this->writersCanShare);

    writer.Key("permissions");
    writer.StartArray();
    for(auto v : this->permissions) {
        writer.StartObject();
        writer.Key("kind");
        writer.String(v.kind.c_str());
        writer.Key("id");
        writer.String(v.id.c_str());
        writer.Key("type");
        writer.String(v.type.c_str());
        writer.Key("emailAddress");
        writer.String(v.emailAddress.c_str());
        writer.Key("domain");
        writer.String(v.domain.c_str());
        writer.Key("role");
        writer.String(v.role.c_str());
        writer.Key("allowFileDiscovery");
        writer.Bool(v.allowFileDiscovery);
        writer.Key("displayName");
        writer.String(v.displayName.c_str());
        writer.Key("photoLink");
        writer.String(v.photoLink.c_str());
        writer.Key("expirationTime");
        writer.String(v.expirationTime.c_str());
        writer.Key("teamDrivePermissionDetails");
        writer.StartArray();
        for(auto k : v.teamDrivePermissionDetails) {
            writer.StartObject();
            writer.Key("teamDrivePermissionType");
            writer.String(k.teamDrivePermissionType.c_str());
            writer.Key("role");
            writer.String(k.role.c_str());
            writer.Key("inheritedFrom");
            writer.String(k.inheritedFrom.c_str());
            writer.Key("inherited");
            writer.Bool(k.inherited);
            writer.EndObject();
        }
        writer.EndArray();
        writer.Key("deleted");
        writer.Bool(v.deleted);
        writer.EndObject();
    }
    writer.EndArray();
    writer.Key("hasAugmentedPermissions");
    writer.Bool(this->hasAugmentedPermissions);
    writer.Key("folderColorRgb");
    writer.String(this->folderColorRgb.c_str());
    writer.Key("originalFilename");
    writer.String(this->originalFilename.c_str());
    writer.Key("fullFileExtension");
    writer.String(this->fullFileExtension.c_str());
    writer.Key("fileExtension");
    writer.String(this->fileExtension.c_str());
    writer.Key("md5Checksum");
    writer.String(this->md5Checksum.c_str());
    writer.Key("size");
    writer.Int64(this->size);
    writer.Key("quotaBytesUser");
    writer.Int64(this->quotaBytesUser);
    writer.Key("headRevisionId");
    writer.String(this->headRevisionId.c_str());
    writer.Key("imageMediaMetadata");
    writer.StartObject();
    writer.Key("width");
    writer.Int(this->_imageMediaMetadata.width);
    writer.Key("height");
    writer.Int(this->_imageMediaMetadata.height);
    writer.Key("rotation");
    writer.Int(this->_imageMediaMetadata.rotation);
    writer.Key("location");
    writer.StartObject();
    writer.Key("latitude");
    writer.Double(this->_imageMediaMetadata.location.latitude);
    writer.Key("longitude");
    writer.Double(this->_imageMediaMetadata.location.longitude);
    writer.Key("altitude");
    writer.Double(this->_imageMediaMetadata.location.altitude);
    writer.EndObject();
    writer.Key("time");
    writer.String(this->_imageMediaMetadata.time.c_str());
    writer.Key("cameraMake");
    writer.String(this->_imageMediaMetadata.cameraMake.c_str());
    writer.Key("cameraModel");
    writer.String(this->_imageMediaMetadata.cameraModel.c_str());
    writer.Key("exposureTime");
    writer.Double(this->_imageMediaMetadata.exposureTime);
    writer.Key("aperture");
    writer.Double(this->_imageMediaMetadata.aperture);
    writer.Key("flashUsed");
    writer.Bool(this->_imageMediaMetadata.flashUsed);
    writer.Key("focalLength");
    writer.Double(this->_imageMediaMetadata.focalLength);
    writer.Key("isoSpeed");
    writer.Int(this->_imageMediaMetadata.isoSpeed);
    writer.Key("meteringMode");
    writer.String(this->_imageMediaMetadata.meteringMode.c_str());
    writer.Key("sensor");
    writer.String(this->_imageMediaMetadata.sensor.c_str());
    writer.Key("exposureMode");
    writer.String(this->_imageMediaMetadata.exposureMode.c_str());
    writer.Key("colorSpace");
    writer.String(this->_imageMediaMetadata.colorSpace.c_str());
    writer.Key("whiteBalance");
    writer.String(this->_imageMediaMetadata.whiteBalance.c_str());
    writer.Key("exposureBias");
    writer.Double(this->_imageMediaMetadata.exposureBias);
    writer.Key("maxApertureValue");
    writer.Double(this->_imageMediaMetadata.maxApertureValue);
    writer.Key("subjectDistance");
    writer.Int(this->_imageMediaMetadata.subjectDistance);
    writer.Key("lens");
    writer.String(this->_imageMediaMetadata.lens.c_str());
    writer.EndObject();
    writer.Key("videoMediaMetadata");
    writer.StartObject();
    writer.Key("width");
    writer.Int(this->_videoMediaMetadata.width);
    writer.Key("height");
    writer.Int(this->_videoMediaMetadata.height);
    writer.Key("durationMillis");
    writer.Int64(this->_videoMediaMetadata.durationMillis);
    writer.EndObject();
    writer.Key("isAppAuthorized");
    writer.Bool(this->isAppAuthorized);
    writer.EndObject();

    return sb.GetString();
}

filesResource filesResource::fromJSON(std::string json) {
    rapidjson::Document document;
    document.Parse(json.c_str());

    return filesResource::fromJSON(document);
}

filesResource filesResource::fromJSON(rapidjson::Document& document) {
    filesResource fr;

    fr.kind = document["kind"].GetString();
    fr.id = document["id"].GetString();
    fr.name = document["name"].GetString();
    fr.mimeType = document["mimeType"].GetString();
    fr.description = document["description"].GetString();
    fr.starred = document["starred"].GetBool();
    fr.trashed = document["trashed"].GetBool();
    fr.explicitlyTrashed = document["explicitlyTrashed"].GetBool();

    return filesResource();
}

filesResource::filesResource() {

}
