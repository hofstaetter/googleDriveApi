//
// Created by Matthias Hofstätter on 14.09.17.
//

#ifndef PLEXDRIVE_CHANGES_H
#define PLEXDRIVE_CHANGES_H


#include <ctime>
#include "classes/file.h"
#include "teamDrive.h"

class change {
public:
    change();

private:
    string kind;
    string type;
    time_t datetime;
    bool removed;
    string fileId;
    file file;
    string teamDriveId;
    teamDrive teamDrive;
};


#endif //PLEXDRIVE_CHANGES_H
