//
// Created by Matthias Hofstätter on 17.09.17.
//

#include <stringbuffer.h>
#include <writer.h>
#include "jsonObject.h"

string jsonObject::toString() {
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    this->document.Accept(writer);

    return buffer.GetString();
}

jsonObject::jsonObject() {

}

jsonObject::jsonObject(rapidjson::Document &document) {
    this->document.CopyFrom(document, this->document.GetAllocator());
}

void jsonObject::setString(string key, string value) {
    this->document.AddMember(rapidjson::StringRef(key.c_str()), rapidjson::StringRef(value.c_str()), this->document.GetAllocator());
}

void jsonObject::setBool(string key, bool b) {
    this->document.AddMember(rapidjson::StringRef(key.c_str()), rapidjson::Value(b), this->document.GetAllocator());
}

void jsonObject::setInt(string key, int i) {
    this->document.AddMember(rapidjson::StringRef(key.c_str()), rapidjson::Value(i), this->document.GetAllocator());
}

void jsonObject::setLong(string key, int64_t l) {
    this->document.AddMember(rapidjson::StringRef(key.c_str()), rapidjson::Value(l), this->document.GetAllocator());
}

void jsonObject::setDouble(string key, double d) {
    this->document.AddMember(rapidjson::StringRef(key.c_str()), rapidjson::Value(d), this->document.GetAllocator());
}

void jsonObject::setUInt(string key, unsigned ui) {
    this->document.AddMember(rapidjson::StringRef(key.c_str()), rapidjson::Value(ui), this->document.GetAllocator());
}

void jsonObject::setULong(string key, uint64_t ul) {
    this->document.AddMember(rapidjson::StringRef(key.c_str()), rapidjson::Value(ul), this->document.GetAllocator());
}

void jsonObject::setFloat(string key, float f) {
    this->document.AddMember(rapidjson::StringRef(key.c_str()), rapidjson::Value(f), this->document.GetAllocator());
}

string jsonObject::getString(string key) {
    if(this->document.HasMember(key.c_str()))
        return this->document[key.c_str()].GetString();
    return "";
}

bool jsonObject::getBool(string key) {
    if(this->document.HasMember(key.c_str()))
        return this->document[key.c_str()].GetBool();
    return false;
}

int jsonObject::getInt(string key) {
    if(this->document.HasMember(key.c_str()))
        return this->document[key.c_str()].GetInt();
    return 0;
}

unsigned jsonObject::getUInt(string key) {
    if(this->document.HasMember(key.c_str()))
        return this->document[key.c_str()].GetUint();
    return 0;
}

long jsonObject::getLong(string key) {
    if(this->document.HasMember(key.c_str()))
        return this->document[key.c_str()].GetInt64();
    return 0;
}

uint64_t jsonObject::getULong(string key) {
    if(this->document.HasMember(key.c_str()))
        return this->document[key.c_str()].GetUint64();
    return 0;
}

double jsonObject::getDouble(string key) {
    if(this->document.HasMember(key.c_str()))
        return this->document[key.c_str()].GetDouble();
    return 0.0;
}

float jsonObject::getFloat(string key) {
    if(this->document.HasMember(key.c_str()))
        return this->document[key.c_str()].GetFloat();
    return 0.0;
}

void jsonObject::setObject(string key, jsonObject object) {
    this->document.AddMember(rapidjson::StringRef(key.c_str()), rapidjson::Value(object.document, this->document.GetAllocator()), this->document.GetAllocator());
}

jsonObject jsonObject::getObject(string key) {
    if(this->document.HasMember(key.c_str()) && this->document[key.c_str()].IsObject()) {
        rapidjson::Document result;
        result.CopyFrom(this->document[key.c_str()], result.GetAllocator());
        return jsonObject(result);
    }
    return NULL;
}

void jsonObject::setStringArray(string key, vector<string> vec) {
    rapidjson::Value v(rapidjson::kArrayType);
    for(string s : vec) {
        v.PushBack(rapidjson::StringRef(s.c_str()), this->document.GetAllocator());
    }
    this->document.AddMember(rapidjson::StringRef(key.c_str()), v, this->document.GetAllocator());
}

vector<string> jsonObject::getStringArray(string key) {
    if(this->document.HasMember(key.c_str()) && this->document[key.c_str()].IsArray()) {
        vector<string> result;
        for (auto &s : this->document[key.c_str()].GetArray()) {
            result.push_back(s.GetString());
        }
        return vector<string>();
    }
    return NULL;
}

void jsonObject::setStringMap(string key, map<string, string> map) {
    rapidjson::Value v(rapidjson::kObjectType);
    for(auto &p : map) {
        v.AddMember(rapidjson::StringRef(p.first.c_str()), rapidjson::StringRef(p.second.c_str()), this->document.GetAllocator());
    }
    this->document.AddMember(rapidjson::StringRef(key.c_str()), v, this->document.GetAllocator());
}

map<string, string> jsonObject::getStringMap(string key) {
    if(this->document.HasMember(key.c_str()) && this->document[key.c_str()].IsObject()) {
        map<string, string> result;
        for(rapidjson::Value::ConstMemberIterator itr = this->document[key.c_str()].MemberBegin(); itr != this->document[key.c_str()].MemberEnd(); itr++) {
            result.insert(itr->name.GetString(), itr->value.GetString());
        }
        return result;
    }
    return NULL;
}

void jsonObject::setObjectArray(string key, vector<jsonObject> vec) {
    rapidjson::Value v(rapidjson::kArrayType);
    for(jsonObject jo : vec) {
        v.PushBack(jo.document, this->document.GetAllocator());
    }
    this->document.AddMember(rapidjson::StringRef(key.c_str()), v, this->document.GetAllocator());
}

vector<jsonObject> jsonObject::getObjectArray(string key) {
    if(this->document.HasMember(key.c_str()) && this->document[key.c_str()].IsArray()) {
        vector<jsonObject> result;
        for(auto &o : this->document[key.c_str()].GetArray()) {
            rapidjson::Document d;
            d.CopyFrom(o, d.GetAllocator());
            result.push_back(jsonObject(d));
        }
        return result;
    }
    return NULL;
}
