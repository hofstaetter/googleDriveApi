//
// Created by Matthias Hofstätter on 14.09.17.
//

#ifndef PLEXDRIVE_CHANGES_H
#define PLEXDRIVE_CHANGES_H


#include <ctime>
#include "classes/file.h"
#include "teamDrive.h"

class change: public jsonObject {
public:
    change();
    change(rapidjson::Document &document);
private:
    string kind;
    string type;
    time_t datetime;
    bool removed;
    string fileId;
    class file file;
    string teamDriveId;
    class teamDrive teamDrive;
public:
    string &getKind();

    void setKind(string &kind);

    string &getType();

    void setType(string &type);

    time_t getDatetime();

    void setDatetime(time_t datetime);

    bool isRemoved();

    void setRemoved(bool removed);

    string &getFileId();

    void setFileId(string &fileId);

    class file &getFile();

    void setFile(class file file);

    string &getTeamDriveId();

    void setTeamDriveId(string &teamDriveId);

    class teamDrive &getTeamDrive();

    void setTeamDrive(class teamDrive teamDrive);
};


#endif //PLEXDRIVE_CHANGES_H
