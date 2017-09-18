//
// Created by Matthias Hofstätter on 17.09.17.
//

#include "classes/jsonObject.h"

string jsonObject::toString() {
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    (this->document)->Accept(writer);

    return buffer.GetString();
}

jsonObject::jsonObject() {
}

jsonObject::jsonObject(rapidjson::Document &document) {
    (this->document)->CopyFrom(document, (this->document)->GetAllocator());
}

void jsonObject::setString(string key, string value) {
    (this->document)->AddMember(rapidjson::StringRef(key.c_str()), rapidjson::StringRef(value.c_str()), (this->document)->GetAllocator());
}

void jsonObject::setBool(string key, bool b) {
    (this->document)->AddMember(rapidjson::StringRef(key.c_str()), rapidjson::Value(b), (this->document)->GetAllocator());
}

void jsonObject::setInt(string key, int i) {
    (this->document)->AddMember(rapidjson::StringRef(key.c_str()), rapidjson::Value(i), (this->document)->GetAllocator());
}

void jsonObject::setLong(string key, int64_t l) {
    (this->document)->AddMember(rapidjson::StringRef(key.c_str()), rapidjson::Value(l), (this->document)->GetAllocator());
}

void jsonObject::setDouble(string key, double d) {
    (this->document)->AddMember(rapidjson::StringRef(key.c_str()), rapidjson::Value(d), (this->document)->GetAllocator());
}

void jsonObject::setUInt(string key, unsigned ui) {
    (this->document)->AddMember(rapidjson::StringRef(key.c_str()), rapidjson::Value(ui), (this->document)->GetAllocator());
}

void jsonObject::setULong(string key, uint64_t ul) {
    (this->document)->AddMember(rapidjson::StringRef(key.c_str()), rapidjson::Value(ul), (this->document)->GetAllocator());
}

void jsonObject::setFloat(string key, float f) {
    (this->document)->AddMember(rapidjson::StringRef(key.c_str()), rapidjson::Value(f), (this->document)->GetAllocator());
}

string jsonObject::getString(string key) {
    if((this->document)->HasMember(key.c_str())) {
        rapidjson::Document &d = *this->document;
        return rapidjson::Pointer(string("/").append(key).c_str()).Get(*this->document)->GetString();
    }
    return "";
}

bool jsonObject::getBool(string key) {
    if((this->document)->HasMember(key.c_str()))
        return rapidjson::Pointer(string("/").append(key).c_str()).Get(*this->document)->GetBool();
    return false;
}

int jsonObject::getInt(string key) {
    if((this->document)->HasMember(key.c_str()))
        return rapidjson::Pointer(string("/").append(key).c_str()).Get(*this->document)->GetInt();
    return 0;
}

unsigned jsonObject::getUInt(string key) {
    if((this->document)->HasMember(key.c_str()))
        return rapidjson::Pointer(string("/").append(key).c_str()).Get(*this->document)->GetUint();
    return 0;
}

long jsonObject::getLong(string key) {
    if((this->document)->HasMember(key.c_str()))
        return rapidjson::Pointer(string("/").append(key).c_str()).Get(*this->document)->GetInt64();
    return 0;
}

uint64_t jsonObject::getULong(string key) {
    if((this->document)->HasMember(key.c_str()))
        return rapidjson::Pointer(string("/").append(key).c_str()).Get(*this->document)->GetUint64();
    return 0;
}

double jsonObject::getDouble(string key) {
    if((this->document)->HasMember(key.c_str()))
        return rapidjson::Pointer(string("/").append(key).c_str()).Get(*this->document)->GetDouble();
    return 0.0;
}

float jsonObject::getFloat(string key) {
    if((this->document)->HasMember(key.c_str()))
        return rapidjson::Pointer(string("/").append(key).c_str()).Get(*this->document)->GetFloat();
    return 0.0;
}

void jsonObject::setStringArray(string key, vector<string> vec) {
    rapidjson::Value v(rapidjson::kArrayType);
    for(string s : vec) {
        v.PushBack(rapidjson::StringRef(s.c_str()), (this->document)->GetAllocator());
    }
    (this->document)->AddMember(rapidjson::StringRef(key.c_str()), v, (this->document)->GetAllocator());
}

vector<string> jsonObject::getStringArray(string key) {
    vector<string> result;
    if((this->document)->HasMember(key.c_str()) && rapidjson::Pointer(string("/").append(key).c_str()).Get(*this->document)->IsArray()) {
        for (auto &s : rapidjson::Pointer(string("/").append(key).c_str()).Get(*this->document)->GetArray()) {
            result.push_back(s.GetString());
        }
    }
    return result;
}

void jsonObject::setStringMap(string key, map<string, string> map) {
    rapidjson::Value v(rapidjson::kObjectType);
    for(auto &p : map) {
        v.AddMember(rapidjson::StringRef(p.first.c_str()), rapidjson::StringRef(p.second.c_str()), (this->document)->GetAllocator());
    }
    (this->document)->AddMember(rapidjson::StringRef(key.c_str()), v, (this->document)->GetAllocator());
}

map<string, string> jsonObject::getStringMap(string key) {
    map<string, string> result;
    if((this->document)->HasMember(key.c_str()) && rapidjson::Pointer(string("/").append(key).c_str()).Get(*this->document)->IsObject()) {
        for(rapidjson::Value::ConstMemberIterator itr = rapidjson::Pointer(string("/").append(key).c_str()).Get(*this->document)->MemberBegin(); itr != rapidjson::Pointer(string("/").append(key).c_str()).Get(*this->document)->MemberEnd(); itr++) {
            result.insert(make_pair(itr->name.GetString(), itr->value.GetString()));
        }
    }
    return result;
}

void jsonObject::debugJson(rapidjson::Document &document) {
    if(document.IsObject()) {
        rapidjson::StringBuffer buffer;
        rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);

        document.Accept(writer);

        std::cout << buffer.GetString() << std::endl;
    }
}
