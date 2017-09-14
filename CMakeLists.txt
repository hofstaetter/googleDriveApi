cmake_minimum_required(VERSION 3.8)
project(GoogleDriveApi)

set(CMAKE_CXX_STANDARD 11)

#set(CMAKE_VERBOSE_MAKEFILE ON)

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

set(SOURCE_FILES src/filesGoogleDriveApi.cpp include/files/filesGoogleDriveApi.h src/filesResource.cpp include/files/filesResource.h src/filesGenerateIdsResponse.cpp include/files/filesGenerateIdsResponse.h src/user.cpp include/user.h src/filesWatchResponse.cpp include/files/filesWatchResponse.h src/filesListResponse.cpp include/files/filesListResponse.h src/googleOAuth.cpp include/oauth/googleOAuth.h src/https.cpp include/https.h src/filesWatchRequest.cpp include/files/filesWatchRequest.h src/changesGoogleDriveApi.cpp include/changes/changesGoogleDriveApi.h src/changesListResponse.cpp include/changes/changesListResponse.h src/changesResource.cpp include/changes/changesResource.h src/teamdrivesResource.cpp include/changes/teamdrivesResource.h src/changesGetStartPageTokenResponse.cpp include/changes/changesGetStartPageTokenResponse.h src/changesWatchResponse.cpp include/changes/changesWatchResponse.h src/changesWatchRequest.cpp include/changes/changesWatchRequest.h src/channelsGoogleDriveApi.cpp include/channels/channelsGoogleDriveApi.h src/channelsStopRequest.cpp include/channels/channelsStopRequest.h src/commentsGoogleDriveApi.cpp include/comments/commentsGoogleDriveApi.h src/commentsResource.cpp include/comments/commentsResource.h src/googleDriveApi.cpp include/googleDriveApi.h src/commentsListResponse.cpp include/comments/commentsListResponse.h include/permissions/permissionsGoogleDriveApi.cpp include/permissions/permissionsGoogleDriveApi.h include/permissions/permissionsResource.cpp include/permissions/permissionsResource.h include/permissions/permissionsListResponse.cpp include/permissions/permissionsListResponse.h)
add_library(GoogleDriveApi ${SOURCE_FILES})

if(CURL_FOUND)
    target_link_libraries(GoogleDriveApi curl)
endif(CURL_FOUND)