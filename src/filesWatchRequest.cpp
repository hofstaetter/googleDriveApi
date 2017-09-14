//
// Created by Matthias Hofstätter on 12.09.17.
//

#include "files/filesWatchRequest.h"

filesWatchRequest::filesWatchRequest() {}

filesWatchRequest::filesWatchRequest(const string &kind, const string &id, const string &resourceId, const string &resourceUri,
                           const string &token, long expiration, const string &type, const string &address,
                           bool payload, const map<string, string> &params) : kind(kind), id(id),
                                                                              resourceId(resourceId),
                                                                              resourceUri(resourceUri), token(token),
                                                                              expiration(expiration), type(type),
                                                                              address(address), payload(payload),
                                                                              params(params) {}

string filesWatchRequest::toString() {
    return std::string();
}
