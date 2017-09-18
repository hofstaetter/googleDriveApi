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

    string getKind();

    void setKind(string kind);

    string getType();

    void setType(string type);

    time_t getDatetime();

    void setDatetime(time_t datetime);

    bool isRemoved();

    void setRemoved(bool removed);

    string getFileId();

    void setFileId(string fileId);

    file getFile();

    void setFile(file file);

    string getTeamDriveId();

    void setTeamDriveId(string teamDriveId);

    teamDrive getTeamDrive();

    void setTeamDrive(teamDrive teamDrive);

/*private:
    string kind;
    string type;
    time_t datetime;
    bool removed;
    string fileId;
    file file;
    string teamDriveId;
    teamDrive teamDrive;*/
};


#endif //PLEXDRIVE_CHANGES_H
