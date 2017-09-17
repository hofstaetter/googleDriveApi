//
// Created by Matthias Hofstätter on 15.09.17.
//

#include <document.h>
#include <classes/jsonObject.h>
#include "classes/permission.h"

permission::permission() {
    jsonObject::jsonObject();
}

permission::permission(rapidjson::Document &document) {
    jsonObject::jsonObject(document);
}
