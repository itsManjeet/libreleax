#include <releax/releax.hh>
#include <releax/app.hh>

/* test_app : sample app to demonstracte the usage of app.hh
 * app.hh is a releax api to easily build cli apps for releax os
 */

using namespace std;

error
wget_main(vector<string> args,
         vector<string> flags)
{
    cout << "download from url: " << endl;

    return error(0,"success");
}


error
wget_sub_from_ftp(vector<string> args,
                  vector<string> flags)
{
    cout << "download ftp from url: " <<  endl;
    return error(0,"success");
}

int
main (int   argc, 
     char** argv)
{
    /* Declare new app */
    auto wget = App(
        "wget",                       // app name
        0.1 , 'a',                    // 0.1 = major.minor version |  'a' = release [a = alpha, b = beta, s = stable]
        "wget is a simple implementation of unix wget with app.hh releax api"  // descriptions for app
    );

    /* Add Authors 
     * add_author can add any number of authors for the app
     */
    wget.add_author(
        "Manjeet Saini",
        "itsmanjeet@releax.in",
        "Lead Developer at releax os"
    );

    wget.add_author(
        "Another Author",
        "another@releax.in",
        "Another Author for testing"
    );

    /* Main Function */
    wget.func = wget_main;

    /* Sub commands */
    wget.add_sub(
        "from-ftp",                                 // Argument name from which you want to call
        "to Download all file from ftp addresss",   // Sub Command description
        "[URL] -o [OUTPUT]",                        // Usage for help
        wget_sub_from_ftp
    );
    // Similarly more sub commands can be add

    /* Execute Command*/
    error err = wget.execute(argc,argv);
    if (err.status != 0) {
        cout << "err: " << err.message << endl;
    }
}