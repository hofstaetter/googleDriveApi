//
// Created by Matthias Hofstätter on 17.09.17.
//

#ifndef PLEXDRIVE_VIDEOMEDIAMETADATA_H
#define PLEXDRIVE_VIDEOMEDIAMETADATA_H


class videoMediaMetadata: public jsonObject {
public:
    int width;
    int height;
    long durationMillis;

    videoMediaMetadata();
    videoMediaMetadata(rapidjson::Document &document);
};


#endif //PLEXDRIVE_VIDEOMEDIAMETADATA_H
