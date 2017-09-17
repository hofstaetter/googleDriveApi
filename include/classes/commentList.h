//
// Created by Matthias Hofstätter on 15.09.17.
//

#ifndef PLEXDRIVE_COMMENTSLISTRESPONSE_H
#define PLEXDRIVE_COMMENTSLISTRESPONSE_H

#include <string>
#include "comment.h"

using namespace std;

class commentList {
private:
    string kind;
    string nextPageToken;
    comment comments;
};


#endif //PLEXDRIVE_COMMENTSLISTRESPONSE_H
