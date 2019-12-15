#ifndef DISK_HH
#define DISK_HH

#include "releax.hh"

class Part {
public:
    std::string part_name,
                uuid,
                label,
                type;
    int status = 1;
    unsigned long long int size;
    Part(std::string part_name,
              std::string uuid,
              std::string label,
              std::string type,
              unsigned long long int size);

    Part();

    std::string display();
};

namespace disk {
    std::list<std::string> get_all_part();
    Part load_part(std::string part_name);
}

#endif