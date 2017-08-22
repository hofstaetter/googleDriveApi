cmake_minimum_required(VERSION 3.8)
project(googleDriveApi)

set(CMAKE_CXX_STANDARD 11)

include_directories(rapidjson/include)
include_directories(curl/include)

set(SOURCE_FILES test.cpp googleDriveApi.cpp googleDriveApi.h classes/filesResource.cpp classes/filesResource.h classes/generateIdsResponse.cpp classes/generateIdsResponse.h classes/user.cpp classes/user.h classes/watchResponse.cpp classes/watchResponse.h classes/listResponse.cpp classes/listResponse.h configuration.cpp configuration.h)
#add_library(googleDriveApi ${SOURCE_FILES})
add_executable(googleDriveApi ${SOURCE_FILES})

target_link_libraries(googleDriveApi LINK_PUBLIC curl)