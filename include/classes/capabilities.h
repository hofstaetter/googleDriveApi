//
// Created by Matthias Hofstätter on 17.09.17.
//

#ifndef PLEXDRIVE_CAPABILITIES_H
#define PLEXDRIVE_CAPABILITIES_H

#include "jsonObject.h"

class capabilities: public jsonObject {
public:
    bool canAddChildren;
    bool canChangeTeamDriveBackground;
    bool canComment;
    bool canCopy;
    bool canDeleteTeamDrive;
    bool canDownloader;
    bool canEdit;
    bool canListChildren;
    bool canManageMembers;
    bool canReadRevisions;
    bool canRemoveChildren;
    bool canRename;
    bool canRenameTeamDrive;
    bool canShare;

    capabilities();
    capabilities(rapidjson::Document &document);
};


#endif //PLEXDRIVE_CAPABILITIES_H
