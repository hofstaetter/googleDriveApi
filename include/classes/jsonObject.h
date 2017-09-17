//
// Created by Matthias Hofstätter on 17.09.17.
//

#ifndef PLEXDRIVE_JSONOBJECT_H
#define PLEXDRIVE_JSONOBJECT_H

#include <string>
#include <document.h>
#include <vector>
#include <map>

using namespace std;

class jsonObject {
public:
    rapidjson::Document document;

    jsonObject();
    jsonObject(rapidjson::Document &document);

    void setString(string key, string value);
    void setBool(string key, bool b);
    void setInt(string key, int i);
    void setUInt(string key, unsigned ui);
    void setLong(string key, int64_t l);
    void setULong(string key, uint64_t ul);
    void setDouble(string key, double d);
    void setFloat(string key, float f);
    void setObject(string key, jsonObject object);
    void setStringArray(string key, vector<string> vec);
    void setStringMap(string key, map<string, string> map);
    void setObjectArray(string key, vector<jsonObject> vec);

    string getString(string key);
    bool getBool(string key);
    int getInt(string key);
    unsigned getUInt(string key);
    long getLong(string key);
    uint64_t getULong(string key);
    double getDouble(string key);
    float getFloat(string key);
    jsonObject getObject(string key);
    vector<string> getStringArray(string key);
    map<string, string> getStringMap(string key);
    vector<jsonObject> getObjectArray(string key);

    virtual string toString();
};


#endif //PLEXDRIVE_JSONOBJECT_H
