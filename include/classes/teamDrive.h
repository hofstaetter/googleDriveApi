//
// Created by Matthias Hofstätter on 14.09.17.
//

#ifndef PLEXDRIVE_TEAMDRIVESRESOURCE_H
#define PLEXDRIVE_TEAMDRIVESRESOURCE_H

#include <string>
#include "backgroundImageFile.h"
#include "capabilities.h"

using namespace std;

class teamDrive {
public:
    string kind;
    string name;
    string themeId;
    string colorRgb;
    struct backgroundImageFile backgroundImageFile;
    string backgroundImageLink;
    struct capabilities capabilities;

    teamDrive();
};


#endif //PLEXDRIVE_TEAMDRIVESRESOURCE_H
