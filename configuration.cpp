//
// Created by Matthias Hofstätter on 22.08.17.
//

#include <fstream>
#include "configuration.h"

configuration::configuration(string fileName) {
    this->fileName = fileName;
    string line;
    ifstream file(this->fileName);
    if(file.is_open()) {
        if(getline(file, line)) {
            configuration::settings.insert(make_pair(line.substr(0, line.find("=")), line.substr(line.find("=") + 1)));
        }
        file.close();
    }
}

void configuration::writeSetting(string key, string value) {
    ofstream file(this->fileName, ios::out | ios::app);
    file << key << "=" << value << endl;
}
