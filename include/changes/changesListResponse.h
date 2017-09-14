//
// Created by Matthias Hofstätter on 14.09.17.
//

#ifndef PLEXDRIVE_CHANGESLISTRESPNSE_H
#define PLEXDRIVE_CHANGESLISTRESPNSE_H

#include <string>
#include "changesResource.h"

using namespace std;

class changesListResponse {
private:
    string kind;
    string nextPageToken;
    string newStartPageToken;
    changesResource changes;
};


#endif //PLEXDRIVE_CHANGESLISTRESPNSE_H
