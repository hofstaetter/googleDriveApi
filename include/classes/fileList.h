//
// Created by Matthias Hofstätter on 21.08.17.
//

#ifndef GOOGLEDRIVEAPI_LISTRESPONSE_H
#define GOOGLEDRIVEAPI_LISTRESPONSE_H

#include "files/files.h"
#include "file.h"
#include "jsonObject.h"
#include <rapidjson.h>
#include <document.h>
#include <writer.h>
#include <pointer.h>
#include <string>
#include <vector>

using namespace std;

class fileList: public jsonObject {
public:
    string getKind();

    void setKind(string kind);

    string getNextPageToken();

    void setNextPageToken(string nextPageToken);

    bool isIncompleteSearch();

    void setIncompleteSearch(bool incompleteSearch);

    vector<class file> getFiles();

    void setFiles(vector<class file> files);

public:
    fileList();
    fileList(rapidjson::Document& document);
};


#endif //GOOGLEDRIVEAPI_LISTRESPONSE_H
