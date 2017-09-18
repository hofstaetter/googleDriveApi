//
// Created by Matthias Hofstätter on 17.09.17.
//

#include "classes/capabilities.h"

capabilities::capabilities() {
}

capabilities::capabilities(rapidjson::Document &document) : jsonObject(document) {
    (this->document)->CopyFrom(document, (this->document)->GetAllocator());
}
