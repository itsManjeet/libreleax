#include <releax/filesys.hh>
#include <sys/stat.h>

int
filesys::makedir(std::string path, mode_t mode)
{
    size_t pos = 0;
    std::string dir;
    int mdret;

    if (path[path.size()-1] != '/') {
        path += '/';
    }

    while((pos = path.find_first_of('/',pos)) != std::string::npos) {
        dir = path.substr(0,pos++);
        if (dir.size() == 0 ) continue;
        if ((mdret  = mkdir(dir.c_str(),mode)) && errno != EEXIST) {
            return mdret;
        }
    }

    return mdret;
}


bool
filesys::exist(std::string path)
{

    struct stat sb;
    if (stat(path.c_str(), &sb) != -1)
        return true;
    return false;
}