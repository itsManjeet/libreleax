#ifndef CONFIG_HH
#define CONFIG_HH

#include "releax.hh"

class Config {
private:
    std::fstream file_prt;
public:
    error load_config(std::string filename); 
    std::string get_value_of(std::string variable);  

    ~Config(); 
};

#endif