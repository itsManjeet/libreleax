#ifndef APP_H
#define APP_H

#include "releax.hh"
#include <glibmm.h>
#include <gtkmm.h>

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

    Glib::RefPtr<Gtk::Application> ui_app;
    Glib::RefPtr<Gtk::Builder> builder;
    UiWindow *window = nullptr;


    App(std::string name, 
        float       version,
        char        release,
        std::string desc);

    void add_sub(std::string name,
                 std::string desc,
                 std::string usage,
                 error (*func)(std::vector<std::string> args,
                               std::vector<std::string> flags));

    void add_ui(std::string app_id,
                std::string ui_file);

    void add_author(std::string name,
                    std::string email,
                    std::string about);

    void print_help();


    error execute(int argc, char** argv);
};

#endif