//
// Created by Matthias Hofstätter on 14.09.17.
//

#ifndef PLEXDRIVE_GETSTARTPAGETOKENRESPONSE_H
#define PLEXDRIVE_GETSTARTPAGETOKENRESPONSE_H

#include <string>
#include <document.h>
#include "jsonObject.h"

using namespace std;

class startPageToken: public jsonObject {
public:
    string getKind();

    void setKind(string kind);

    string getStartPageToken();

    void setStartPageToken(string startPageToken);

    startPageToken();
    startPageToken(rapidjson::Document &document);
};


#endif //PLEXDRIVE_GETSTARTPAGETOKENRESPONSE_H
