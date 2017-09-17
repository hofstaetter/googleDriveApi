//
// Created by Matthias Hofstätter on 17.09.17.
//

#include "capabilities.h"

capabilities::capabilities() {
    jsonObject::jsonObject();
}

capabilities::capabilities(rapidjson::Document &document) : jsonObject(document) {
    jsonObject::jsonObject(document);
}
