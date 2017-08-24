//
// Created by Matthias Hofstätter on 22.08.17.
//

#ifndef GOOGLEDRIVEAPI_CONFIGURATION_H
#define GOOGLEDRIVEAPI_CONFIGURATION_H

#include <string>
#include <map>

using namespace std;

class configuration {
private:
    string fileName;
public:
    map<string, string> settings;
    configuration(string file);
    void writeSetting(string key, string value);
};


#endif //GOOGLEDRIVEAPI_CONFIGURATION_H
