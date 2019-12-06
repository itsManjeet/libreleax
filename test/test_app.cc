#include <releax/releax.hh>
#include <releax/app.hh>

using namespace std;

error
arg1_exec(vector<string> args,
          vector<string> flags) {
    
    cout << "flags: ";
    for (auto f: flags) {
        cout << f << ", ";
    }
    cout << endl;
    cout << "args: " ;
    for (auto a: args) {
        cout << a << ", ";
    }
    cout << endl;
    error err;
    return err;
}

int main(int argc, char** argv) {
    App test_app = App(
        "testApp",
        0.1, 'a',
        "this is a sample app"
    );

    test_app.add_author(
        "Manjeet Saini",
        "itsmanjeet@releax.in",
        "Lead Developer"
    );

    test_app.add_author(
        "another author",
        "another@releax.in",
        "Side Developer"
    );
    test_app.add_sub(
        "arg1",
        "Sample argument",
        "[ARGS] filename",
        arg1_exec
    );

    error err = test_app.execute(argc, argv);
    if (err.first != 0) {
        cout << err.second << endl;
    }
}

