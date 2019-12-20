#ifndef APP_H
#define APP_H

#include "releax.hh"
#include <glibmm.h>
#include <gtkmm.h>
#include "config.hh"

class Sub;
class UiWindow : public Gtk::ApplicationWindow {
public:
    UiWindow(BaseObjectType* obj, Glib::RefPtr<Gtk::Builder> const& builder)
        : Gtk::ApplicationWindow(obj)
        , builder{builder}
    {
    }

    virtual ~UiWindow() = default;

private:
    Glib::RefPtr<Gtk::Builder> builder;
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
public:
    std::string Name;
    float       Version;
    char        Release;
    std::string Desc;
    Config*     cfg;
    int (*func)(App* this_app);
    std::vector<std::string> flags;
    std::vector<std::string> args;

    Glib::RefPtr<Gtk::Application> ui_app;
    Glib::RefPtr<Gtk::Builder> builder;
    UiWindow *window = nullptr;


    App* name(std::string name);
    App* version(float version);
    App* release(char release);
    App* desc(std::string desc);
    App* main_func(int (*func)(App* this_app));
    App* sub(std::string name,
             std::string desc,
             std::string usage,
             int (*func)(App* this_app));

    void add_ui(std::string app_id,
                std::string ui_file);

    App* author(std::string name,
                std::string email,
                std::string about);

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