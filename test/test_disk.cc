#include <releax/disk.hh>
#include <iostream>

using namespace std;

int main() {
    Disk d = Disk("/dev/sda");
    error err = d.load();
    if (err.status != 0) {
        cout << err.message << endl;
    }

    d.display();
}