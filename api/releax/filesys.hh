#ifndef FILESYS_HH
#define FILESYS_HH

#include "releax.hh"

namespace filesys {
    int makedir(std::string path, mode_t mode);
    bool exist(std::string path);
}

#endif