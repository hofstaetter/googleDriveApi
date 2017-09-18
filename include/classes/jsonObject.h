//
// Created by Matthias Hofstätter on 17.09.17.
//

#ifndef PLEXDRIVE_JSONOBJECT_H
#define PLEXDRIVE_JSONOBJECT_H

#include <string>
#include <document.h>
#include <vector>
#include <map>
#include <stringbuffer.h>
#include <writer.h>
#include <pointer.h>
#include "document.h"
#include "pointer.h"
#include <string>
#include <iostream>

using namespace std;

class jsonObject {
public:
    rapidjson::Document *document;

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
    template <class T>
    void setObject(string key, T object) {
        (this->document)->AddMember(rapidjson::StringRef(key.c_str()), rapidjson::Value((*object.document), (this->document)->GetAllocator()), (this->document)->GetAllocator());
    }
    void setStringArray(string key, vector<string> vec);
    void setStringMap(string key, map<string, string> map);
    template <class T>
    void setObjectArray(string key, vector<T> vec) {
        rapidjson::Value v(rapidjson::kArrayType);
        for(T t : vec) {
            rapidjson::Value v((*t.document), (this->document)->GetAllocator());
            v.PushBack(v, (this->document)->GetAllocator());
        }
        (this->document)->AddMember(rapidjson::StringRef(key.c_str()), v, (this->document)->GetAllocator());
    }

    string getString(string key);
    bool getBool(string key);
    int getInt(string key);
    unsigned getUInt(string key);
    long getLong(string key);
    uint64_t getULong(string key);
    double getDouble(string key);
    float getFloat(string key);
    template <class T>
    T getObject(string key) {
        T result;
        rapidjson::Document &d = *this->document;
        if((this->document)->HasMember(key.c_str()) && d[key.c_str()].IsObject()) {
            (result.document)->CopyFrom(d[key.c_str()], (result.document)->GetAllocator());
        }
        return result;
    }
    vector<string> getStringArray(string key);
    map<string, string> getStringMap(string key);
    template <class T>
    vector<T> getObjectArray(string key) {
        vector<T> result;
        rapidjson::Document &d = *this->document;
        if((this->document)->HasMember(key.c_str()) && d[key.c_str()].IsArray()) {
            for(auto &o : d[key.c_str()].GetArray()) {
                //debugJson(o);
                rapidjson::Document d(rapidjson::kObjectType);
                d.CopyFrom(o, d.GetAllocator());
                T t = T(d);
                result.push_back(t);
            }
        }
        return result;
    }

    virtual string toString();
    static void debugJson(rapidjson::Document &document);
};


#endif //PLEXDRIVE_JSONOBJECT_H
