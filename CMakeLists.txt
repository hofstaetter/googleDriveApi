cmake_minimum_required(VERSION 3.8)
project(googleDriveApi)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_VERBOSE_MAKEFILE ON)

#include dependencies
include_directories(include rapidjson/include/rapidjson curl/include/curl)

set(SOURCE_FILES src/Files.cpp include/files/Files.h src/File.cpp include/files/File.h src/GeneratedIds.cpp include/files/GeneratedIds.h src/User.cpp include/global/User.h src/Channel.cpp include/channels/Channel.h src/FileList.cpp include/files/FileList.h src/googleOAuth.cpp include/oauth/googleOAuth.h src/API.cpp include/global/API.h src/Channel.cpp include/channels/Channel.h src/ChangesApi.cpp include/changes/ChangesApi.h src/ChangeList.cpp include/changes/ChangeList.h src/Change.cpp include/changes/Change.h src/TeamDrive.cpp include/teamdrives/TeamDrive.h src/StartPageToken.cpp include/changes/StartPageToken.h src/ChannelsApi.cpp include/channels/ChannelsApi.h src/Comments.cpp include/comments/Comments.h src/Comment.cpp include/comments/Comment.h src/GoogleDriveApi.cpp include/GoogleDriveApi.h src/CommentList.cpp include/comments/CommentList.h src/Permissions.cpp include/permissions/Permissions.h src/Permission.cpp include/permissions/Permission.h src/PermissionList.cpp include/permissions/PermissionList.h src/Replies.cpp include/replies/Replies.h src/Reply.cpp include/replies/Reply.h src/ReplyList.cpp include/replies/ReplyList.h src/BackgroundImageFile.cpp include/global/BackgroundImageFile.h src/capabilities.cpp include/global/capabilities.h src/VideoMediaMetadata.cpp include/files/VideoMediaMetadata.h src/ImageMediaMetadata.cpp include/files/ImageMediaMetadata.h src/Location.cpp include/global/Location.h src/ContentHint.cpp include/files/ContentHint.h src/Thumbnail.cpp include/files/Thumbnail.h include/global/DateTime.h src/Revisions.cpp include/revisions/Revisions.h src/Revision.cpp include/revisions/Revision.h src/RevisionList.cpp include/revisions/RevisionList.h src/Teamdrives.cpp include/teamdrives/Teamdrives.h src/TeamDriveList.cpp include/teamdrives/TeamDriveList.h src/AboutApi.cpp include/about/AboutApi.h src/About.cpp include/about/About.h src/StorageQuota.cpp include/about/StorageQuota.h src/TeamDriveThemes.cpp include/about/TeamDriveThemes.h src/TeamDrivePermissionDetails.cpp include/permissions/TeamDrivePermissionDetails.h)
add_library(googleDriveApi ${SOURCE_FILES})

target_link_libraries(googleDriveApi /usr/local/lib/libcurl.dylib)