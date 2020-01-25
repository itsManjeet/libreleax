#ifndef __http__
#define __http__

#include "releax.hh"
#include <curl/curl.h>

class response {
public:
    std::string data,
                header;
    response(std::string data, std::string header)
    : data(data),
      header(header) {
    
    }
};
class Http {

CURL *curl;
CURLcode res;


public:
    int status = 0;
    Http();
    ~Http();
    void download(std::string url, std::string aout);
    void set_usrpwd(std::string urspwd);
    response get(std::string url);
};
#endif