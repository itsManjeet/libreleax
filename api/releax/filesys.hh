#ifndef FILESYS_HH
#define FILESYS_HH

#include "releax.hh"

namespace filesys {
    class file {
    public:
        std::string filename;
        int status = -1;
        long size;
        int perm;
        unsigned int mode,
                     gid,
                     uid;
        file(std::string loc);

    };
    int makedir(std::string path, mode_t mode);
    int copy(std::string source, std::string dest);
    bool exist(std::string path);
    std::list<std::string> list_all(std::string path);
}

#endif