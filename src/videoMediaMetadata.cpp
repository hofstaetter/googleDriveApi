//
// Created by Matthias Hofstätter on 17.09.17.
//

#include <document.h>
#include <classes/jsonObject.h>
#include "classes/videoMediaMetadata.h"

videoMediaMetadata::videoMediaMetadata() {
}

videoMediaMetadata::videoMediaMetadata(rapidjson::Document &document) {
    (this->document)->CopyFrom(document, (this->document)->GetAllocator());
}
