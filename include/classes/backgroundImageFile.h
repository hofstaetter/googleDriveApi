//
// Created by Matthias Hofstätter on 17.09.17.
//

#ifndef PLEXDRIVE_BACKGROUNDIMAGEFILE_H
#define PLEXDRIVE_BACKGROUNDIMAGEFILE_H

#include <string>
#include <document.h>
#include "jsonObject.h"

using namespace std;

class backgroundImageFile: public jsonObject {
public:
    backgroundImageFile();
    backgroundImageFile(rapidjson::Document &document);

    string getId();

    void setId(string id);

    float getXCoordinate();

    void setXCoordinate(float xCoordinate);

    float getYCoordinate();

    void setYCoordinate(float yCoordinate);

    float getWidth();

    void setWidth(float width);
private:
    /*string id;
    float xCoordinate;
    float yCoordinate;
    float width;*/
};


#endif //PLEXDRIVE_BACKGROUNDIMAGEFILE_H
