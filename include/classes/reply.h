//
// Created by Matthias Hofstätter on 17.09.17.
//

#ifndef PLEXDRIVE_REPLIESRESOURCE_H
#define PLEXDRIVE_REPLIESRESOURCE_H


#include <ctime>
#include <classes/user.h>

class reply {
public:
    string kind;
    string id;
    time_t createdTime;
    time_t modifiedTime;
    user author;
    string htmlContent;
    string content;
    bool deleted;
    string action;
};


#endif //PLEXDRIVE_REPLIESRESOURCE_H
