//
// Created by Matthias Hofstätter on 18.09.17.
//

#ifndef PLEXDRIVE_REVISIONLIST_H
#define PLEXDRIVE_REVISIONLIST_H


#include "revision.h"
#include <string>
#include <vector>

using namespace std;

class revisionList {
    string kind;
    string nextPageToken;
    vector<revision> revisions;
};


#endif //PLEXDRIVE_REVISIONLIST_H
