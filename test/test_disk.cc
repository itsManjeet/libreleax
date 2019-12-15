#include <releax/disk.hh>
#include <iostream>

using namespace std;

int main() {
    
    auto all_part = disk::get_all_part();
    for (auto prt : all_part) {
        auto p = disk::load_part(prt);
        cout << p.display() << endl;
    }

    cout << "Done" << endl;
    return 0;
}