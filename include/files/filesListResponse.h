//
// Created by Matthias Hofstätter on 21.08.17.
//

#ifndef GOOGLEDRIVEAPI_LISTRESPONSE_H
#define GOOGLEDRIVEAPI_LISTRESPONSE_H

#include "filesGoogleDriveApi.h"
#include "filesResource.h"
#include <rapidjson.h>
#include <document.h>
#include <writer.h>
#include <pointer.h>
#include <string>
#include <vector>

using namespace std;

class filesListResponse {
private:
    string kind;
    string nextPageToken;
    bool incompleteSearch;
    vector<class filesResource> files;
public:
    const string &getKind() const;

    void setKind(const string &kind);

    const string &getNextPageToken() const;

    void setNextPageToken(const string &nextPageToken);

    bool isIncompleteSearch() const;

    void setIncompleteSearch(bool incompleteSearch);

    const vector<class filesResource> &getFiles() const;

    void setFiles(const vector<class filesResource> &files);

public:
    filesListResponse();
    filesListResponse(rapidjson::Document& document);
};


#endif //GOOGLEDRIVEAPI_LISTRESPONSE_H
