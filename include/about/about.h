//
// Created by Matthias Hofstätter on 18.09.17.
//

#ifndef PLEXDRIVE_ABOUT_H
#define PLEXDRIVE_ABOUT_H


#include <classes/user.h>
#include "storageQuota.h"

class about {
public:
    string kind;
    user user;
    storageQuota storageQuota;
    //TODO importFormats
    //TODO exportFormats
    map<string, long> maxImportSizes;
    long maxUploadSize;
    bool appInstalled;
    vector<string> folderColorPalette;

};


#endif //PLEXDRIVE_ABOUT_H
