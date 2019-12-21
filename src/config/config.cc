#include <releax/config.hh>

using namespace std;

string
trim(const string& str)
{
    const auto string_begin = str.find_first_not_of(" \t");
    if (string_begin == string::npos)
        return "";
    
    const auto string_end = str.find_last_not_of(" \t");
    const auto string_range = string_end - string_begin + 1;
    return str.substr(string_begin,string_range);
}


Config::
Config(std::string filename)
{
    this->filename = filename;
}

string
Config::
get(string variable, string dflt)
{
    ifstream fptr;
    fptr.open(this->filename);
    if (fptr.good()) {
        string line;
        while(getline(fptr, line)) {
            int pos = line.find("=");
            if (pos == string::npos) {
                return dflt;
            }

            string var = trim(line.substr(0,pos));
            if (var == variable) {
                return trim(line.substr(pos + 1, line.length() ));
            }
            
        }

    }
    return dflt;
}




string
Config::
get(string variable)
{
    ifstream fptr;
    fptr.open(this->filename);
    if (fptr.good()) {
        string line;
        while(getline(fptr, line)) {
            int pos = line.find("=");
            if (pos == string::npos) {
                return "";
            }

            string var = trim(line.substr(0,pos));
            if (var == variable) {
                return trim(line.substr(pos + 1, line.length() ));
            }
            
        }

    }
    return "";
}

