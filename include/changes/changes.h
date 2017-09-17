//
// Created by Matthias Hofstätter on 14.09.17.
//

#ifndef PLEXDRIVE_GOOGLEDRIVEAPICHANGES_H
#define PLEXDRIVE_GOOGLEDRIVEAPICHANGES_H


#include "classes/startPageToken.h"
#include "classes/changeList.h"
#include "classes/channel.h"

class changes {
public:
    static startPageToken getStartPageToken(bool supportsTeamDrives = false, string teamDriveId = "",
                                                       bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static changeList list(string pageToken, bool includeCorpusRemovals = false, bool includeRemoved = true, bool includeTeamDriveItems = false, int pageSize = 100, bool restrictToMyDrive = false, string spaces = "", bool supportsTeamDrives = false,
                                    string teamDriveId = "",
                                    bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static channel watch(string pageToken, bool includeCorpusRemovals = false, bool includeRemoved = true, bool includeTeamDriveItems = false, int pageSize = 100, bool restrictToMyDrive = false, string spaces = "", bool supportsTeamDrives = false,
                                      string teamDriveId = "", channel requestBody = {},
                                      bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
};


#endif //PLEXDRIVE_GOOGLEDRIVEAPICHANGES_H
