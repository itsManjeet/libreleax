#include <releax/releax.hh>

int main()
{
    
    auto osdata = osinfo::get_info();
    std::cout << osdata.version << std::endl;
    return 0;
}