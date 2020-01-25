#include <releax/releax.hh>
#include <releax/http.hh>

Http::
Http()
{
    this->curl = curl_easy_init();
    if (curl) {
        this->status = 0;
    } else {
        this->status = 1;
    }
}

Http::
~Http()
{
    if (this->curl) {
        curl_easy_cleanup(this->curl);
    }
}

size_t
write_data(void  *ptr,
           size_t size,
           size_t nmemb,
           FILE  *fptr)
{
    size_t written = fwrite(ptr, size, nmemb, fptr);
    return written;
}

void
Http::
download(std::string url,
         std::string aout)
{
    if (!this->status) {
        FILE* fptr = fopen(aout.c_str(), "wb");
        curl_easy_setopt(this->curl,CURLOPT_URL, url.c_str());
        curl_easy_setopt(this->curl, CURLOPT_WRITEFUNCTION,write_data);
        curl_easy_setopt(this->curl, CURLOPT_WRITEDATA, fptr);
        this->res = curl_easy_perform(this->curl);
        fclose(fptr);
    }
}

void
Http::
set_usrpwd(std::string usrpwd)
{
    curl_easy_setopt(this->curl,CURLOPT_USERPWD, usrpwd.c_str());
}


size_t 
get_write_func(void  *ptr,
               size_t size,
               size_t nmemb,
               std::string* data)
{
    data->append((char*)ptr, size * nmemb);
    return size * nmemb;
}

response
Http::get(std::string url)
{
    std::string header, data;
    curl_easy_setopt(this->curl,CURLOPT_URL, url.c_str());
    curl_easy_setopt(this->curl, CURLOPT_WRITEFUNCTION, get_write_func);
    curl_easy_setopt(this->curl, CURLOPT_WRITEDATA, &data);
    curl_easy_setopt(this->curl, CURLOPT_HEADERDATA, &header);
    curl_easy_perform(this->curl);
    return response(data,header);
}