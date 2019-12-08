#ifndef DISK_HH
#define DISK_HH

#include "releax.hh"

namespace disk {
    std::list<std::string> get_disk();
}

class Part {
    std::string part_name,
                uuid,
                label,
                type;
public:
    Part(std::string part_name,
              std::string uuid,
              std::string label,
              std::string type);

    std::string display();
};

class Disk {
    std::string disk_name;
    std::vector<Part> parts;
public:
    Disk(std::string disk_name);
    void display();
    error load();  
};
#endif