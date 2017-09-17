//
// Created by Matthias Hofstätter on 14.09.17.
//

#ifndef PLEXDRIVE_CHANGESLISTRESPNSE_H
#define PLEXDRIVE_CHANGESLISTRESPNSE_H

#include <string>
#include "change.h"

using namespace std;

class changeList {
private:
    string kind;
    string nextPageToken;
    string newStartPageToken;
    change changes;
};


#endif //PLEXDRIVE_CHANGESLISTRESPNSE_H
