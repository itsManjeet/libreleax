#include <releax/filesys.hh>
#include <sys/stat.h>

#include <filesystem>

namespace fs = std::filesystem;

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

int
filesys::
copy(std::string source,
     std::string dest)
{
    std::ifstream src(source);
    std::ofstream dst(dest);

    dst << src.rdbuf();

    src.close();
    dst.close();

    return 0;
}

bool
filesys::exist(std::string path)
{

    struct stat sb;
    if (stat(path.c_str(), &sb) != -1)
        return true;
    return false;
}


std::list<std::string>
filesys::list_all(std::string path)
{
    std::list<std::string> all_content;
    for (const auto &entry : fs::directory_iterator(path)) {
        all_content.push_front(entry.path().filename());
    }
    return all_content;
}