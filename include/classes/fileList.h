//
// Created by Matthias Hofstätter on 21.08.17.
//

#ifndef GOOGLEDRIVEAPI_LISTRESPONSE_H
#define GOOGLEDRIVEAPI_LISTRESPONSE_H

#include "files/files.h"
#include "file.h"
#include <rapidjson.h>
#include <document.h>
#include <writer.h>
#include <pointer.h>
#include <string>
#include <vector>

using namespace std;

class fileList {
private:
    string kind;
    string nextPageToken;
    bool incompleteSearch;
    vector<class file> files;
public:
    const string &getKind() const;

    void setKind(const string &kind);

    const string &getNextPageToken() const;

    void setNextPageToken(const string &nextPageToken);

    bool isIncompleteSearch() const;

    void setIncompleteSearch(bool incompleteSearch);

    const vector<class file> &getFiles() const;

    void setFiles(const vector<class file> &files);

public:
    fileList();
    fileList(rapidjson::Document& document);
};


#endif //GOOGLEDRIVEAPI_LISTRESPONSE_H
