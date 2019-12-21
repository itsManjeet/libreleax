#ifndef CONFIG_HH
#define CONFIG_HH

#include "releax.hh"

class Config {
private:
    std::string filename;
public:
    Config(std::string filename);
    std::string get(std::string variable, std::string dflt);  
    std::string get(std::string variable); 
};

#endif