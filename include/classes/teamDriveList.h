//
// Created by Matthias Hofstätter on 18.09.17.
//

#ifndef PLEXDRIVE_TEAMDRIVELIST_H
#define PLEXDRIVE_TEAMDRIVELIST_H


#include <classes/teamDrive.h>
#include <string>
#include <vector>

using namespace std;

class teamDriveList {
public:
    string kind;
    string nextPageToken;
    vector<teamDrive> teamDrives;
};


#endif //PLEXDRIVE_TEAMDRIVELIST_H
