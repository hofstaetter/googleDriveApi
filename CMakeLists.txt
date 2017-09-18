cmake_minimum_required(VERSION 3.8)
project(googleDriveApi)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_VERBOSE_MAKEFILE ON)

find_package(CURL)
if(CURL_FOUND)
    #message(${CURL_INCLUDE_DIR})
    include_directories(${CURL_INCLUDE_DIR})
    #message(${CURL_LIBRARIES})
else(CURL_FOUND)
    MESSAGE(FATAL_ERROR "Could not find the CURL library and development files.")
endif(CURL_FOUND)

#include dependencies
set(GOOGLEDRIVEAPI_INCLUDE_DIR include rapidjson/include/rapidjson ${CURL_INCLUDE_DIR})
include_directories(${GOOGLEDRIVEAPI_INCLUDE_DIR})
message("${GOOGLEDRIVEAPI_INCLUDE_DIR}")

set(SOURCE_FILES src/files.cpp include/files/files.h src/file.cpp include/classes/file.h src/generatedIds.cpp include/classes/generatedIds.h src/user.cpp include/classes/user.h src/channel.cpp include/classes/channel.h src/fileList.cpp include/classes/fileList.h src/googleOAuth.cpp include/oauth/googleOAuth.h src/https.cpp include/classes/https.h src/channel.cpp include/classes/channel.h include/changes/changes.cpp include/changes/changes.h src/changeList.cpp include/classes/changeList.h src/change.cpp include/classes/change.h src/teamDrive.cpp include/classes/teamDrive.h src/startPageToken.cpp include/classes/startPageToken.h src/channels.cpp include/channels/channels.h src/comments.cpp include/comments/comments.h src/comment.cpp include/classes/comment.h src/googleDriveApi.cpp include/googleDriveApi.h src/commentList.cpp include/classes/commentList.h src/permissions.cpp include/permissions/permissions.h src/permission.cpp include/classes/permission.h src/permissionList.cpp include/classes/permissionList.h src/replies.cpp include/replies/replies.h src/reply.cpp include/classes/reply.h src/replyList.cpp include/classes/replyList.h src/backgroundImageFile.cpp include/classes/backgroundImageFile.h src/capabilities.cpp include/classes/capabilities.h src/videoMediaMetadata.cpp include/classes/videoMediaMetadata.h src/imageMediaMetadata.cpp include/classes/imageMediaMetadata.h src/location.cpp include/classes/location.h src/contentHint.cpp include/classes/contentHint.h src/thumbnail.cpp include/classes/thumbnail.h src/jsonObject.cpp include/classes/jsonObject.h include/classes/dateTime.h src/revisions.cpp include/revisions/revisions.h src/revision.cpp include/revisions/revision.h src/revisionList.cpp include/revisions/revisionList.h src/teamdrives.cpp include/teamdrives/teamdrives.h src/teamDriveList.cpp include/classes/teamDriveList.h src/aboutApi.cpp include/about/aboutApi.h src/about.cpp include/about/about.h src/storageQuota.cpp include/about/storageQuota.h src/teamDriveThemes.cpp include/about/teamDriveThemes.h)
add_library(googleDriveApi ${SOURCE_FILES})

if(CURL_FOUND)
    target_link_libraries(googleDriveApi curl)
endif(CURL_FOUND)