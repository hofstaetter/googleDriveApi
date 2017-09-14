//
// Created by Matthias Hofstätter on 14.09.17.
//

#ifndef PLEXDRIVE_TEAMDRIVESRESOURCE_H
#define PLEXDRIVE_TEAMDRIVESRESOURCE_H

#include <string>

using namespace std;

class teamdrivesResource {
public:
    struct backgroundImageFile {
        string id;
        float xCoordinate;
        float yCoordinate;
        float width;
    };

    struct capabilities {
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
    };

    teamdrivesResource();

private:
    string kind;
    string name;
    string themeId;
    string colorRgb;
    struct backgroundImageFile backgroundImageFile;
    string backgroundImageLink;
    struct capabilities capabilities;
};


#endif //PLEXDRIVE_TEAMDRIVESRESOURCE_H
