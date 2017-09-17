//
// Created by Matthias Hofstätter on 17.09.17.
//

#include <document.h>
#include <classes/jsonObject.h>
#include "classes/videoMediaMetadata.h"

videoMediaMetadata::videoMediaMetadata() {
    jsonObject::jsonObject();
}

videoMediaMetadata::videoMediaMetadata(rapidjson::Document &document) {
    jsonObject::jsonObject(document);
}
