//
// Created by Matthias Hofstätter on 11.09.17.
//

#include "oauth/googleOAuth.h"

using namespace std;

string googleOAuth::clientId;
string googleOAuth::authorizationCode;
string googleOAuth::refreshToken;
string googleOAuth::accessToken;
time_t googleOAuth::expire;

void googleOAuth::requestAuthorizationCode(string clientId, string redirectUri, string responseType, string scope, string state, string includeGrantedScopes,
                                           string loginHint, string prompt) {
    rapidjson::Document responseBody;
    string responseHeaders;
    long httpcode = https::request("https://accounts.google.com", "/o/oauth2/v2/auth", "POST", { make_pair("response_type", responseType), make_pair("client_id", clientId), make_pair("redirect_uri", redirectUri),
                                                                                                 make_pair("scope", scope) },
                                            { make_pair("content-type", "application/x-www-form-urlencoded") },
                                            {}, //{ make_pair("code", authCode), make_pair("client_id", clientId), make_pair("client_secret", clientSecret), make_pair("redirect_uri", "urn:ietf:wg:oauth:2.0:oob"), make_pair("grant_type", "authorization_code") },
                                            "", responseHeaders, responseBody);

    if(httpcode != 302) { throw responseBody; }

    cout << "Please visit following URL and paste the AuthCode below: " << responseHeaders.substr(responseHeaders.find("Location", 0) + 10, responseHeaders.find("\r\n", responseHeaders.find("Location", 0)) - responseHeaders.find("Location", 0) - 10) << endl;
    cin >> googleOAuth::authorizationCode;

    googleOAuth::clientId = clientId;
}

void googleOAuth::requestTokens(string clientId, string clientSecret) {
    if(googleOAuth::authorizationCode.empty() || googleOAuth::clientId.empty()) {
        throw -1;
    }

    string responseHeaders;
    rapidjson::Document responseBody;
    long httpcode = https::request("https://www.googleapis.com", "/oauth2/v4/token", "POST", { },
                                            { make_pair("content-type", "application/x-www-form-urlencoded") },
                                            { make_pair("grant_type", "authorization_code"), make_pair("code", googleOAuth::authorizationCode), make_pair("redirect_uri", "urn:ietf:wg:oauth:2.0:oob"), make_pair("client_id", clientId), make_pair("client_secret", clientSecret) }, //{ make_pair("code", authCode), make_pair("client_id", clientId), make_pair("client_secret", clientSecret), make_pair("redirect_uri", "urn:ietf:wg:oauth:2.0:oob"), make_pair("grant_type", "authorization_code") },
                                            "", responseHeaders, responseBody);
    //{ make_pair("grant_type", "authorization_code"), make_pair("code", authCode), make_pair("redirect_uri", "urn:ietf:wg:oauth:2.0:oob"), make_pair("client_id", clientId), make_pair("client_secret", clientSecret) }

    if(httpcode != 200) { throw responseBody; }

    googleOAuth::refreshToken = responseBody["refresh_token"].GetString();
    googleOAuth::accessToken = responseBody["access_token"].GetString();
    googleOAuth::expire = time(NULL) + 3600;
}

void googleOAuth::refreshAccessToken(string clientSecret, string grantType, string refreshToken, string clientId) {
    if(googleOAuth::authorizationCode.empty() || googleOAuth::clientId.empty() || googleOAuth::refreshToken.empty()) {
        throw -1;
    }

    if(!googleOAuth::refreshToken.empty() && googleOAuth::expire <= time(NULL)) {
        return;
    }

    string responseHeaders;
    rapidjson::Document responseBody;

    long httpcode = https::request("https://www.googleapis.com", "/oauth2/v4/token", "POST", { },
                                   { make_pair("content-type", "application/x-www-form-urlencoded") },
                                   { make_pair("grant_type", "refresh_token"), make_pair("refresh_token", googleOAuth::refreshToken), make_pair("client_id", clientId), make_pair("client_secret", clientSecret) }, //{ make_pair("code", authCode), make_pair("client_id", clientId), make_pair("client_secret", clientSecret), make_pair("redirect_uri", "urn:ietf:wg:oauth:2.0:oob"), make_pair("grant_type", "authorization_code") },
                                   "", responseHeaders, responseBody);

    googleOAuth::accessToken = responseBody["access_token"].GetString();
    googleOAuth::expire = time(NULL) + 3600;
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
    if(!googleOAuth::getRefreshToken().empty()) { //access token only expired
        googleOAuth::refreshAccessToken("XI1bBfoU5AXAFq-h5SqSas1M", "refresh_token", googleOAuth::getRefreshToken(), "590194775230-snrhmjb562msv07a5rvg8mj6l5tiiq0i.apps.googleusercontent.com");
    } else {
        if(googleOAuth::getAuthorizationCode().empty()) {
            googleOAuth::requestAuthorizationCode("590194775230-snrhmjb562msv07a5rvg8mj6l5tiiq0i.apps.googleusercontent.com", "urn:ietf:wg:oauth:2.0:oob", "code", "https://www.googleapis.com/auth/drive", "", "", "", "");
        }
        googleOAuth::requestTokens("590194775230-snrhmjb562msv07a5rvg8mj6l5tiiq0i.apps.googleusercontent.com", "XI1bBfoU5AXAFq-h5SqSas1M");
    }
}

