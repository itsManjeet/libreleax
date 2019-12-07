#include <releax/releax.hh>
#include <releax/config.hh>

using namespace std;

int
main(int ac, char** av)
{
    Config cfg;
    cfg.load_config("build/test.cfg");
    cout << "name: " << cfg.get_value_of("name");
}