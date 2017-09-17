//
// Created by Matthias Hofstätter on 17.09.17.
//

#include <document.h>
#include <classes/jsonObject.h>
#include "classes/imageMediaMetadata.h"

imageMediaMetadata::imageMediaMetadata() {
    jsonObject::jsonObject();
}

imageMediaMetadata::imageMediaMetadata(rapidjson::Document &document) {
    jsonObject::jsonObject(document);
}
