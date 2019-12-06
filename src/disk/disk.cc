#include <releax/disk.hh>
#include <blkid/blkid.h>

Disk::Disk(std::string disk_name) 
{
    this->disk_name = disk_name;
}

error
Disk::load()
{
    blkid_probe pr = blkid_new_probe_from_filename(this->disk_name.c_str());
    if (pr == NULL) {
        error(1,"failed to open " + disk_name);
    }

    blkid_partlist partlist;
    int npart, i;
    
    partlist = blkid_probe_get_partitions(pr);
    npart = blkid_partlist_numof_partitions(partlist);

    if (npart <= 0) {
        return error(2,"invalid disk name " + disk_name);
    }

    
    const char *uuid;
    const char *label;
    const char *type;

    for (int i = 0; i < npart; i++) {
        std::string dev_name = disk_name + std::to_string(i+1);

        pr = blkid_new_probe_from_filename(dev_name.c_str());
        blkid_do_probe(pr);

        blkid_probe_lookup_value(pr,"UUID", &uuid, NULL);
        blkid_probe_lookup_value(pr,"LABEL",&label,NULL);
        blkid_probe_lookup_value(pr,"TYPE",&type, NULL);

        Part prt = Part(
            dev_name,
            uuid,
            label,
            type
        );
        uuid = ""; label = ""; type = "";
        this->parts.push_back(prt);
    }

    blkid_free_probe(pr);
    return error(0,"success");
}

void
Disk::display()
{
    std::cout << "Disk: " << this->disk_name << std::endl;
    for (auto part:this->parts) {
        std::cout << "   |- " << part.display() << std::endl;
    }
}

Part::Part (std::string part_name,
            std::string uuid,
            std::string label,
            std::string type)
{
    this->part_name = part_name;
    this->uuid      = uuid;
    this->label     = label;
    this->type      = type;
}

std::string
Part::display()
{
    return "Part: " + this->part_name + 
          " UUID: " + this->uuid +
          " Label: " + this->label +
          " Type: " + this->type;
}