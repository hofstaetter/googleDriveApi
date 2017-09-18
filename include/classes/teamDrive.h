//
// Created by Matthias Hofstätter on 14.09.17.
//

#ifndef PLEXDRIVE_TEAMDRIVESRESOURCE_H
#define PLEXDRIVE_TEAMDRIVESRESOURCE_H

#include <string>
#include "backgroundImageFile.h"
#include "capabilities.h"

using namespace std;

class teamDrive: public jsonObject {
public:
    string getKind();

    void setKind(string kind);

    string getName();

    void setName(string name);

    string getThemeId();

    void setThemeId(string themeId);

    string getColorRgb();

    void setColorRgb(string colorRgb);

    backgroundImageFile getBackgroundImageFile();

    void setBackgroundImageFile(backgroundImageFile backgroundImageFile);

    string getBackgroundImageLink();

    void setBackgroundImageLink(string backgroundImageLink);

    capabilities getCapabilities();

    void setCapabilities(capabilities capabilities);

    teamDrive();
    teamDrive(rapidjson::Document &document);
private:
    /*string kind;
    string name;
    string themeId;
    string colorRgb;
    struct backgroundImageFile backgroundImageFile;
    string backgroundImageLink;
    struct capabilities capabilities;*/
};


#endif //PLEXDRIVE_TEAMDRIVESRESOURCE_H
