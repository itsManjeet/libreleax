#include <releax/releax.hh>
#include <releax/app.hh>

/* test_app : sample app to demonstracte the usage of app.hh
 * app.hh is a releax api to easily build cli apps for releax os
 */

using namespace std;

int
wget_main(App* app)
{
    cout << "download from url: "  << endl;

    return 0;
}


int
wget_sub_from_ftp(App* app)
{
    cout << "download ftp from url: " <<  endl;
    return 0;
}

int
main (int   argc, 
     char** argv)
{
    auto app = new App();

    app->name("Sample app")
       ->version(0.1)
       ->release('a')
       ->desc("This is a sample app")
       ->author("Manjeet Saini","itsmanjeet@releax.in","-")
       ->author("Another Author","another@releax.in","-")
       ->main_func(wget_sub_from_ftp)
       ->sub("download",
             "to download file",
             "[URL]",
             wget_main);


    /* Execute Command*/
    int err = app->execute(argc,argv);
    if (err != 0) {
        cout << "err: " << err << endl;
    }
}