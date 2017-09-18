//
// Created by Matthias Hofstätter on 18.09.17.
//

#ifndef PLEXDRIVE_ABOUT_H
#define PLEXDRIVE_ABOUT_H


#include <string>

class aboutApi {
public:
    static aboutApi get(bool alt = false, std::string fields = "", bool prettyPrint = false, std::string quotaUser = "", std::string userId = "");
};


#endif //PLEXDRIVE_ABOUT_H
