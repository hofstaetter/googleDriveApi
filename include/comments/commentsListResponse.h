//
// Created by Matthias Hofstätter on 15.09.17.
//

#ifndef PLEXDRIVE_COMMENTSLISTRESPONSE_H
#define PLEXDRIVE_COMMENTSLISTRESPONSE_H

#include <string>
#include "commentsResource.h"

using namespace std;

class commentsListResponse {
private:
    string kind;
    string nextPageToken;
    commentsResource comments;
};


#endif //PLEXDRIVE_COMMENTSLISTRESPONSE_H
