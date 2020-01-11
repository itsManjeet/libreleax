#include <releax/disk.hh>
#include <releax/filesys.hh>
#include <releax/sys.hh>
#include <cstdlib>

#ifdef __GNUC__
	#include <features.h>
	#if __GNUC_PREREQ(8,0)
		#include <filesystem>
		namespace fs = std::filesystem
	#else
		#include <experimental/filesystem>
		namespace fs = std::experimental::filesystem;
	#endif
#endif

std::list<std::string>
disk::get_all_part()
{
    std::list<std::string> all_disk;
    std::string path = "/sys/class/block/";
    for (const auto &entry : fs::directory_iterator(path)) {
        std::string disk_name = entry.path().filename();
        if (filesys::exist(path + "/" + disk_name + "/partition")) {      // list all with partition
            all_disk.push_front(entry.path().filename());
        }
    }
    all_disk.sort();
    return all_disk;
}

Part
disk::load_part(std::string part_name)
{
    std::string path = "/sys/class/block/" + part_name;
    if (!filesys::exist(path)) return Part();
    
    std::string size = sys::execute("cat " + path + "/size");
    std::stringstream ss(size);
    size_t size_int =  0;
    ss >> size_int;
    auto prt = Part("/dev/" + part_name,
        "",
        "",
        "",
        size_int);
    
    return prt;
}


Part::Part (std::string part_name,
            std::string uuid,
            std::string label,
            std::string type,
            unsigned long long int size)
{
    this->part_name = part_name;
    this->uuid      = uuid;
    this->label     = label;
    this->type      = type;
    this->size      = size;
    this->status    = 0;
}

Part::Part()
{
    this->status = -1;
}

std::string
Part::display()
{
    return "Part: " + this->part_name + 
          " UUID: " + this->uuid +
          " Label: " + this->label +
          " Type: " + this->type;
}
