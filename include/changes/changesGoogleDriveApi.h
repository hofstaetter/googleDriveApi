//
// Created by Matthias Hofstätter on 14.09.17.
//

#ifndef PLEXDRIVE_GOOGLEDRIVEAPICHANGES_H
#define PLEXDRIVE_GOOGLEDRIVEAPICHANGES_H


#include "changesGetStartPageTokenResponse.h"
#include "changesListResponse.h"
#include "changesWatchResponse.h"
#include "changesWatchRequest.h"

class changesGoogleDriveApi {
public:
    static changesGetStartPageTokenResponse getStartPageToken(bool supportsTeamDrives = false, string teamDriveId = "",
                                                       bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static changesListResponse list(string pageToken, bool includeCorpusRemovals = false, bool includeRemoved = true, bool includeTeamDriveItems = false, int pageSize = 100, bool restrictToMyDrive = false, string spaces = "", bool supportsTeamDrives = false,
                                    string teamDriveId = "",
                                    bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
    static changesWatchResponse watch(string pageToken, bool includeCorpusRemovals = false, bool includeRemoved = true, bool includeTeamDriveItems = false, int pageSize = 100, bool restrictToMyDrive = false, string spaces = "", bool supportsTeamDrives = false,
                                      string teamDriveId = "", changesWatchRequest changesWatchRequest = {},
                                      bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
};


#endif //PLEXDRIVE_GOOGLEDRIVEAPICHANGES_H
