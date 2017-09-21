//
// Created by Matthias Hofstätter on 11.09.17.
//

#include <fstream>
#include "oauth/googleOAuth.h"

using namespace std;

string googleOAuth::clientId;
string googleOAuth::clientSecret;
string googleOAuth::authorizationCode;
string googleOAuth::refreshToken;
string googleOAuth::accessToken;
time_t googleOAuth::expire;

void googleOAuth::requestAuthorizationCode(string clientId, string redirectUri, string responseType, string scope, string state, string includeGrantedScopes,
                                           string loginHint, string prompt) {
    string responseBody;
    string responseHeaders;
    long httpcode = https::request("https://accounts.google.com", "/o/oauth2/v2/auth", "POST", { make_pair("response_type", responseType), make_pair("client_id", clientId), make_pair("redirect_uri", redirectUri),
                                                                                                 make_pair("scope", scope) },
                                            { make_pair("content-type", "application/x-www-form-urlencoded") },
                                            {}, //{ make_pair("code", authCode), make_pair("client_id", clientId), make_pair("client_secret", clientSecret), make_pair("redirect_uri", "urn:ietf:wg:oauth:2.0:oob"), make_pair("grant_type", "authorization_code") },
                                            "", responseHeaders, responseBody);

    if(httpcode != 302) { throw -1; }

    cout << "Please visit following URL and paste the AuthCode below: " << responseHeaders.substr(responseHeaders.find("Location", 0) + 10, responseHeaders.find("\r\n", responseHeaders.find("Location", 0)) - responseHeaders.find("Location", 0) - 10) << endl;
    cin >> googleOAuth::authorizationCode;

    googleOAuth::clientId = clientId;
}

void googleOAuth::requestTokens(string clientId, string clientSecret) {
    if(googleOAuth::authorizationCode.empty() || googleOAuth::clientId.empty()) {
        throw -1;
    }

    string responseHeaders;
    string responseBody;
    long httpcode = https::request("https://www.googleapis.com", "/oauth2/v4/token", "POST", { },
                                            { make_pair("content-type", "application/x-www-form-urlencoded") },
                                            { make_pair("grant_type", "authorization_code"), make_pair("code", googleOAuth::authorizationCode), make_pair("redirect_uri", "urn:ietf:wg:oauth:2.0:oob"), make_pair("client_id", clientId), make_pair("client_secret", clientSecret) }, //{ make_pair("code", authCode), make_pair("client_id", clientId), make_pair("client_secret", clientSecret), make_pair("redirect_uri", "urn:ietf:wg:oauth:2.0:oob"), make_pair("grant_type", "authorization_code") },
                                            "", responseHeaders, responseBody);
    //{ make_pair("grant_type", "authorization_code"), make_pair("code", authCode), make_pair("redirect_uri", "urn:ietf:wg:oauth:2.0:oob"), make_pair("client_id", clientId), make_pair("client_secret", clientSecret) }

    if(httpcode != 200) { throw responseBody; }

    rapidjson::Document responseJson;
    rapidjson::ParseResult pr = responseJson.Parse(responseBody.c_str());
    if(!pr) {
        printf("PARSE ERROR");
    }

    if(responseJson.IsObject() && responseJson.HasMember("refresh_token") && responseJson.HasMember("access_token")) {
        googleOAuth::refreshToken = responseJson["refresh_token"].GetString();
        googleOAuth::accessToken = responseJson["access_token"].GetString();
        googleOAuth::expire = time(NULL) + 3600;
    } else { throw responseJson; }
}

void googleOAuth::refreshAccessToken(string clientSecret, string grantType, string refreshToken, string clientId) {
    if(googleOAuth::authorizationCode.empty() || googleOAuth::clientId.empty() || googleOAuth::refreshToken.empty()) {
        throw -1;
    }

    if(!googleOAuth::refreshToken.empty() && googleOAuth::expire > time(NULL)) {
        return;
    }

    string responseHeaders;
    string responseBody;

    long httpcode = https::request("https://www.googleapis.com", "/oauth2/v4/token", "POST", { },
                                   { make_pair("content-type", "application/x-www-form-urlencoded") },
                                   { make_pair("grant_type", "refresh_token"), make_pair("refresh_token", googleOAuth::refreshToken), make_pair("client_id", clientId), make_pair("client_secret", clientSecret) }, //{ make_pair("code", authCode), make_pair("client_id", clientId), make_pair("client_secret", clientSecret), make_pair("redirect_uri", "urn:ietf:wg:oauth:2.0:oob"), make_pair("grant_type", "authorization_code") },
                                   "", responseHeaders, responseBody);

    rapidjson::Document responseJson;
    rapidjson::ParseResult pr = responseJson.Parse(responseBody.c_str());
    if(!pr) {
        printf("PARSE ERROR");
    }

    if(responseJson.IsObject() && responseJson.HasMember("access_token")) {
        googleOAuth::accessToken = responseJson["access_token"].GetString();
        googleOAuth::expire = time(NULL) + 3600;
    } else { throw responseJson; }
}

const string &googleOAuth::getAuthorizationCode() {
    return authorizationCode;
}

const string &googleOAuth::getRefreshToken() {
    return refreshToken;
}

const string &googleOAuth::getAccessToken() {
    return accessToken;
}

time_t googleOAuth::getExpire() {
    return expire;
}

void googleOAuth::authenticate() {
    rapidjson::Document configuration(rapidjson::kObjectType);
    ifstream file("config.json");
    if(file.is_open()) {
        string configurationstring;
        file >> configurationstring;
        file.close();

        configuration.Parse(configurationstring.c_str());
        if (configuration.IsObject()) {
            if (configuration.HasMember("clientId"))
                googleOAuth::clientId = configuration["clientId"].GetString();
            if (configuration.HasMember("clientSecret"))
                googleOAuth::clientSecret = configuration["clientSecret"].GetString();
            if (configuration.HasMember("authorizationCode"))
                googleOAuth::authorizationCode = configuration["authorizationCode"].GetString();
            if (configuration.HasMember("accessToken"))
                googleOAuth::accessToken = configuration["accessToken"].GetString();
            if (configuration.HasMember("refreshToken"))
                googleOAuth::refreshToken = configuration["refreshToken"].GetString();
        }
    }

    if(!googleOAuth::getRefreshToken().empty()) { //access token only expired
        googleOAuth::refreshAccessToken(googleOAuth::clientSecret, "refresh_token", googleOAuth::getRefreshToken(), googleOAuth::clientId);
    } else {
        if(googleOAuth::getAuthorizationCode().empty()) {
            printf("Please enter your client ID: ");
            cin >> googleOAuth::clientId;
            printf("Please enter your client secret: ");
            cin >> googleOAuth::clientSecret;
            googleOAuth::requestAuthorizationCode(googleOAuth::clientId, "urn:ietf:wg:oauth:2.0:oob", "code", "https://www.googleapis.com/auth/drive", "", "", "", "");
        }
        googleOAuth::requestTokens(googleOAuth::clientId, googleOAuth::clientSecret);
    }

    if(googleOAuth::isAuthenticated()) {
        rapidjson::Document configuration(rapidjson::kObjectType);
        configuration.AddMember(rapidjson::StringRef("clientId"), rapidjson::StringRef(googleOAuth::clientId.c_str()), configuration.GetAllocator());
        configuration.AddMember(rapidjson::StringRef("clientSecret"), rapidjson::StringRef(googleOAuth::clientSecret.c_str()), configuration.GetAllocator());
        configuration.AddMember(rapidjson::StringRef("authorizationCode"), rapidjson::StringRef(googleOAuth::authorizationCode.c_str()), configuration.GetAllocator());
        configuration.AddMember(rapidjson::StringRef("accessToken"), rapidjson::StringRef(googleOAuth::accessToken.c_str()), configuration.GetAllocator());
        configuration.AddMember(rapidjson::StringRef("refreshToken"), rapidjson::StringRef(googleOAuth::refreshToken.c_str()), configuration.GetAllocator());

        rapidjson::StringBuffer buffer;
        rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
        configuration.Accept(writer);

        string configurationstring = buffer.GetString();
        ofstream file("config.json");
        file << configurationstring;
        file.close();
    }
}

bool googleOAuth::isAuthenticated() {
    if(!googleOAuth::accessToken.empty() && googleOAuth::expire > time(NULL)) {
        string responseHeaders;
        string responseBody;

        long httpcode = https::request("https://www.googleapis.com", "/oauth2/v3/tokeninfo", "POST", { },
                                       { make_pair("content-type", "application/x-www-form-urlencoded") },
                                       { make_pair("access_token", googleOAuth::accessToken) }, //, make_pair("refresh_token", googleOAuth::refreshToken), make_pair("client_id", clientId), make_pair("client_secret", clientSecret) }, //{ make_pair("code", authCode), make_pair("client_id", clientId), make_pair("client_secret", clientSecret), make_pair("redirect_uri", "urn:ietf:wg:oauth:2.0:oob"), make_pair("grant_type", "authorization_code") },
                                       "", responseHeaders, responseBody);

        rapidjson::Document responseJson;
        rapidjson::ParseResult pr = responseJson.Parse(responseBody.c_str());
        if(!pr) {
            printf("PARSE ERROR");
        }

        if(responseJson.IsObject() && responseJson.HasMember("azp") && responseJson.HasMember("expires_in")) {
            if(responseJson["azp"].GetString() != googleOAuth::clientId || atoi(responseJson["expires_in"].GetString()) <= 0) return false;
        } else { throw responseJson; }

        return true;
    }
    return false;
}

