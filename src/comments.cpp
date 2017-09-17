//
// Created by Matthias Hofstätter on 15.09.17.
//

#include "comments/comments.h"

comment
comments::create(string fileId, comment requestBody, bool alt, string fields, bool prettyPrint,
                               string quotaUser, string userId) {
    return comment();
}

void comments::del(string commentId, string fileId, bool alt, string fields, bool prettyPrint,
                                 string quotaUser, string userId) {

}

comment
comments::get(string commentId, string fileId, bool includeDeleted, bool alt, string fields,
                            bool prettyPrint, string quotaUser, string userId) {
    return comment();
}

commentList comments::list(string fileId, bool includeDeleted, int pageSize, string pageToken,
                                                  string startModifiedTime, bool alt, string fields, bool prettyPrint,
                                                  string quotaUser, string userId) {
    return commentList();
}

comment
comments::update(string fileId, string commentId, comment requestBody, bool alt, string fields,
                               bool prettyPrint, string quotaUser, string userId) {
    return comment();
}
