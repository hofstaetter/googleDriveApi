//
// Created by Matthias Hofstätter on 14.09.17.
//

#ifndef PLEXDRIVE_CHANGES_H
#define PLEXDRIVE_CHANGES_H


#include <ctime>
#include "files/filesResource.h"
#include "teamdrivesResource.h"

class changesResource {
public:
    changesResource();
    changesResource(const string &kind, const string &type, time_t datetime, bool removed, const string &fileId,
                    const filesResource &file, const string &teamDriveId, const teamdrivesResource &teamDrive);

private:
    string kind;
    string type;
    time_t datetime;
    bool removed;
    string fileId;
    filesResource file;
    string teamDriveId;
    teamdrivesResource teamDrive;
};


#endif //PLEXDRIVE_CHANGES_H
