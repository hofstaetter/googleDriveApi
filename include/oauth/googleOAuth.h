//
// Created by Matthias Hofstätter on 11.09.17.
//

#ifndef GOOGLEDRIVEAPI_GOOGLEAPIAUTH_H
#define GOOGLEDRIVEAPI_GOOGLEAPIAUTH_H

#include <string>
#include <rapidjson.h>
#include <document.h>
#include "files/filesGoogleDriveApi.h"
#include "https.h"

using namespace std;

class googleOAuth {
public:
    static const string &getAuthorizationCode();

    static const string &getRefreshToken();

    static const string &getAccessToken();

    static time_t getExpire();

    static void requestAuthorizationCode(string clientId, string redirectUri, string responseType, string scope, string state, string includeGrantedScopes, string loginHint, string prompt);
    static void requestTokens(string clientId, string clientSecret);
    static void refreshAccessToken(string clientSecret, string grantType, string refreshToken, string clientId);
    static void authenticate();
private:
    static string clientId;
    static string clientSecret;
    static string authorizationCode;
    static string refreshToken;
    static string accessToken;
    static time_t expire;
};


#endif //GOOGLEDRIVEAPI_GOOGLEAPIAUTH_H
