//
// Created by Matthias Hofstätter on 18.09.17.
//

#ifndef PLEXDRIVE_REVISION_H
#define PLEXDRIVE_REVISION_H


#include <ctime>
#include <classes/user.h>

class revision {
public:
    string kind;
    string id;
    string mimeType;
    time_t modifiedTime;
    bool keepForever;
    bool publishAuto;
    bool publishedOutsideDomain;
    user lastModifyingUser;
    string originalFilename;
    string md5Checksum;
    long size;
};


#endif //PLEXDRIVE_REVISION_H
