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

error
Config::
load_config(string file_name)
{
    this->file_prt.open(file_name);

    if (file_prt.good()) {
        return error(0,"");
    } else {
        return error(1,"error while loading config");
    }
}

string
Config::
get_value_of(string variable)
{
    string line;
    while(getline(this->file_prt, line)) {
        int pos = line.find("=");
        if (pos == string::npos) {
            return "";
        }

        string var = trim(line.substr(0,pos));
        if (var == variable) {
            return trim(line.substr(pos + 1, line.length() ));
        }
        
    }

    return "";
}

Config::
~Config()
{
    this->file_prt.close();
}


