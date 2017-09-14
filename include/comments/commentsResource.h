//
// Created by Matthias Hofstätter on 15.09.17.
//

#ifndef PLEXDRIVE_COMMENTSRESOURCE_H
#define PLEXDRIVE_COMMENTSRESOURCE_H


#include <ctime>
#include <user.h>

class commentsResource {
private:
    string kind;
    string id;
    time_t createdTime;
    time_t modifiedTime;
    user author;
    string htmlContent;
    string content;
    bool deleted;
    bool resolved;
    //TODO
};


#endif //PLEXDRIVE_COMMENTSRESOURCE_H
