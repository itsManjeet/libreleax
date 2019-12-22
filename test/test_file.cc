#include <releax/filesys.hh>
#include <iostream>

using namespace std;

int 
main()
{
    auto f = filesys::file("test/test_file.cc");
    if (f.status != 0) {
        cout << "file not exist" << endl;
    }
}