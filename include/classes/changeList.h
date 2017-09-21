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
private:
    string kind;
    string nextPageToken;
    string newStartPageToken;
    vector<change> changes;
public:
    /*string getKind();

    void setKind(string kind);

    string getNextPageToken();

    void setNextPageToken(string nextPageToken);

    string getNewStartPageToken();

    void setNewStartPageToken(string newStartPageToken);

    vector<change> getChanges();

    void setChanges(vector<change> changes);*/

    changeList();

    const string &getKind() const;

    void setKind(const string &kind);

    const string &getNextPageToken() const;

    void setNextPageToken(const string &nextPageToken);

    const string &getNewStartPageToken() const;

    void setNewStartPageToken(const string &newStartPageToken);

    const vector<change> &getChanges() const;

    void setChanges(const vector<change> &changes);

    changeList(rapidjson::Document &document);
};


#endif //PLEXDRIVE_CHANGESLISTRESPNSE_H
