#ifndef APP_H
#define APP_H

#include "releax.hh"

class Sub {
public:
    std::string name,
                desc,
                usage;
    error (*func)(std::vector<std::string> args,
                  std::vector<std::string> flags);

    std::string display();
};

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
    std::vector<std::string> flags;
    std::vector<std::string> args;
public:
    std::string name;
    float       version;
    char        release;
    std::string desc;
    error (*func)(std::vector<std::string> args,
                  std::vector<std::string> flags);

    App(std::string name, 
        float       version,
        char        release,
        std::string desc);

    void add_sub(std::string name,
                 std::string desc,
                 std::string usage,
                 error (*func)(std::vector<std::string> args,
                               std::vector<std::string> flags));

    void add_author(std::string name,
                    std::string email,
                    std::string about);

    void print_help();


    error execute(int argc, char** argv);
};

#endif