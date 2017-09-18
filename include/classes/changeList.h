//
// Created by Matthias Hofstätter on 14.09.17.
//

#ifndef PLEXDRIVE_CHANGESLISTRESPNSE_H
#define PLEXDRIVE_CHANGESLISTRESPNSE_H

#include <string>
#include <vector>
#include "change.h"

using namespace std;

class changeList: public jsonObject {
public:
    string getKind();

    void setKind(string kind);

    string getNextPageToken();

    void setNextPageToken(string nextPageToken);

    string getNewStartPageToken();

    void setNewStartPageToken(string newStartPageToken);

    vector<change> getChanges();

    void setChanges(vector<change> changes);

    changeList();
    changeList(rapidjson::Document &document);
};


#endif //PLEXDRIVE_CHANGESLISTRESPNSE_H
