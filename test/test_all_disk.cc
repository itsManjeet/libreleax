#include <releax/disk.hh>

using namespace std;

int
main()
{
    list<string> all_disk = disk::get_disk();
    for (auto i : all_disk) {
        cout << "-> " << i << endl;
    }
}