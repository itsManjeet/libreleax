#ifndef FILESYS_HH
#define FILESYS_HH

#include "releax.hh"

namespace filesys {
    int makedir(std::string path, mode_t mode);
    int copy(std::string source, std::string dest);
    bool exist(std::string path);
    std::list<std::string> list_all(std::string path);
}

#endif