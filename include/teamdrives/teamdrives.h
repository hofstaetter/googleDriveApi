//
// Created by Matthias Hofstätter on 18.09.17.
//

#ifndef PLEXDRIVE_TEAMDRIVES_H
#define PLEXDRIVE_TEAMDRIVES_H


#include <classes/teamDrive.h>
#include "classes/teamDriveList.h"

class teamdrives {
public:
    static teamDrive create(string requestId, teamDrive requestBody,
                            bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static void del(string teamDriveId,
                    bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static teamDrive get(string teamDriveId,
                         bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static teamDriveList list(int pageSize = 10, string pageToken = "",
                              bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static teamDrive update(string teamDriveId, teamDrive requestBody,
                            bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
};


#endif //PLEXDRIVE_TEAMDRIVES_H
