//
// Created by Matthias Hofstätter on 11.09.17.
//

#include <iostream>
#include "classes/https.h"

using namespace std;

string bodyBuffer;
string headerBuffer;

size_t
writeBodyBuffer(char *ptr, size_t size, size_t nmemb, void *stream)
{
    bodyBuffer.append(ptr, size*nmemb);
    return size*nmemb;
}

size_t
writeHeaderBuffer(char *ptr, size_t size, size_t nmemb, void *stream)
{
    headerBuffer.append(ptr, size*nmemb);
    return size*nmemb;
}

long
https::request(string host, string path, string type, map<string, string> querystring, map<string, string> header, map<string, string> postfields, string body, string& responseHeaders, string& responseBody) {
    CURL *req = curl_easy_init();

    //debug
    curl_easy_setopt(req, CURLOPT_VERBOSE, 1L);

    //build & set url
    string url;
    bool first = true;

    url.append(host); //url static
    url.append(path);
    for(auto p : querystring) {
        if(p.second.compare("") == 0) continue;
        if(first) {
            url.append("?");
            first = false;
        } else url.append("&");
        url.append(curl_easy_escape(req, p.first.c_str(), p.first.length())).append("=").append(curl_easy_escape(req, p.second.c_str(), p.second.length()));
    }
    curl_easy_setopt(req, CURLOPT_URL, url.c_str());

    //set HTTP 1.1
    curl_easy_setopt(req, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_1_1);

    //set postfields
    string pf;
    first = true;
    if(type.compare("POST") == 0) {
        for(auto p : postfields) {
            if(!first) {
                pf.append("&");
            }
            pf.append(p.first);
            pf.append("=");
            pf.append(p.second.c_str());
            first = false;
        }
        cout << pf.c_str() << endl;
        curl_easy_setopt(req, CURLOPT_POSTFIELDS, pf.c_str());
        curl_easy_setopt(req, CURLOPT_POSTFIELDSIZE, pf.length());
    }

    //write response to buffer
    curl_easy_setopt(req, CURLOPT_WRITEFUNCTION, writeBodyBuffer);
    curl_easy_setopt(req, CURLOPT_HEADERFUNCTION, writeHeaderBuffer);

    //set headers
    struct curl_slist *headers=NULL;
    headers = curl_slist_append(headers, ("Host: " + host.substr(host.find("://", 0) + 3, host.length() - host.find("://", 0))).c_str());

    long contentlength = pf.length() + body.length();
    headers = curl_slist_append(headers, ("Content-length: " + to_string(contentlength)).c_str());
    headers = curl_slist_append(headers, "Connection: close");
    for(auto p : header) {
        headers = curl_slist_append(headers, (p.first + ": " + p.second).c_str());
    }
    curl_easy_setopt(req, CURLOPT_HTTPHEADER, headers);

    CURLcode result = curl_easy_perform(req);

    long statuscode;
    //if(result == CURLE_OK) {
        //get http status code
        curl_easy_getinfo(req, CURLINFO_RESPONSE_CODE, &statuscode);

        responseBody = bodyBuffer;

        responseHeaders = headerBuffer;
    //}

    curl_slist_free_all(headers);

    curl_easy_cleanup(req);

    //debug
    cout << bodyBuffer << endl;

    bodyBuffer.clear();
    headerBuffer.clear();

    return statuscode;
}
