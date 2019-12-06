#include <releax/releax.hh>

using namespace std;

error func() {
    return error(5, "status");
}

int main() {
    error err = func();
    cout << err.status << " " << err.message << endl;
}

