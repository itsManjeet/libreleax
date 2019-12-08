#ifndef DISK_HH
#define DISK_HH

#include "releax.hh"

namespace disk {
    std::list<std::string> get_disk();
}

class Part {
public:
    std::string part_name,
                uuid,
                label,
                type;
    unsigned long long int size;
    Part(std::string part_name,
              std::string uuid,
              std::string label,
              std::string type,
              unsigned long long int size);

    std::string display();
};

class Disk {
public:
    std::string disk_name;
    std::list<Part> parts;
    Disk(std::string disk_name);
    void display();
    error load();  
};
#endif