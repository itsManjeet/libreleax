#ifndef APP_H
#define APP_H

#include "releax.hh"
#include "config.hh"

class Sub;

class Author {
public:
    std::string name,
                email,
                about;

    Author(std::string name,
           std::string email,
           std::string about);
    
    std::string display();
};

class App {

private:
    std::vector<Sub>         subs;
    std::vector<Author>      authors;
public:
    std::string Name;
    float       Version;
    char        Release;
    std::string Desc;
    Config*     cfg;
    int (*func)(App* this_app);
    std::vector<std::string> flags;
    std::vector<std::string> args;

    ~App();
    App* name(std::string name);
    App* version(float version);
    App* release(char release);
    App* desc(std::string desc);
    App* main_func(int (*func)(App* this_app));
    App* sub(std::string name,
             std::string desc,
             std::string usage,
             int (*func)(App* this_app));

    App* ui(std::string app_id,
            std::string ui_file);

    App* author(std::string name,
                std::string email,
                std::string about);
    
    App* config_file(std::string file_loc);

    void print_help();


    int execute(int argc, char** argv);
};

class Sub {
public:
    std::string name,
                desc,
                usage;
    int (*func)(App* this_app);

    std::string display();
};

#endif