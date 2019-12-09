#ifndef __http__
#define __http__

#include "releax.hh"
#include <curl/curl.h>

class Http {

CURL *curl;
CURLcode res;


public:
    int status = 0;
    Http();
    ~Http();
    void download(std::string url, std::string aout);
};
#endif