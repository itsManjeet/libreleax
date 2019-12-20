#include <releax/app.hh>

App*
App::name(std::string name)
{
    this->Name = name;
    return this;
}

App*
App::version(float version)
{
    this->Version = version;
    return this;
}

App*
App::release(char release)
{
    this->Release = release;
    return this;
}

App*
App::desc(std::string desc)
{
    this->Desc = desc;
    return this;
}

App*
App::sub(std::string name,
         std::string desc,
         std::string usage,
         int (*func)(App* this_app))
{
    Sub new_sub;
    new_sub.name = name;
    new_sub.desc = desc;
    new_sub.usage = usage;
    new_sub.func = func;

    this->subs.push_back(new_sub);
    return this;

}


App*
App::author(std::string name,
            std::string email,
            std::string about)
{
    Author new_author(name,email,about);
    this->authors.push_back(new_author);
    return this;
}

App*
App::main_func(int (*func)(App* this_app))
{
    this->func = func;
    return this;
}

void
App::print_help()
{
    std::cout << this->Name << " " << this->Version  << "." << this->Release << " [ ";
    for (Author author: this->authors) {
        std::cout << author.display() << ", ";
    }
    std::cout << "\b\b ]" << std::endl;
    std::cout << std::endl << "Description: " << this->Desc << std::endl;

    std::cout << "\nUsage:" << std::endl;
    for (Sub sub: this->subs) {
        std::cout << sub.display() << std::endl;
    }
}


int
App::execute(int argc, char** argv)
{
    bool task_found = false;
    Sub task;
    if (argc <= 1) {
        if (this->window != nullptr)
            this->ui_app->run(*window);
        else {
            if (this->func != nullptr) {
                this->func(this);
            }
                
            else
                this->print_help();
        }
        return 0;
    } else {
         for (int i = 1; i < argc; i++) {
            std::string arg = argv[i];

            if (arg == "--version" || 
                arg == "-v") {
                    std::cout << "Version: " << this->Version << "." << this->Release << std::endl;
                    return 0;
            }

            if (arg == "--help" || 
                arg == "-h") {
                    this->print_help();
                    return 0;
            }

            if (argv[i][0] == '-') {
                
                this->flags.push_back(argv[i]);
                continue;
            }
            
            bool is_task = false;
            for (auto sub: this->subs) {
                if (sub.name == argv[i] &&
                    ! task_found) {
                    task_found = true;
                    is_task = true;
                    task = sub;
                    break;
                }
            }

            if (!is_task) {
                this->args.push_back(argv[i]);
            }
        }
    }
    

    if (task_found) {
        return task.func(this);
    } else {
        if (this->func != nullptr)
            this->func(this);
        else
            print_help();
        
        return 0;
    }
}

Author::Author(std::string name,
               std::string email,
               std::string about)
{
    this->name = name;
    this->email = email;
    this->about = about;
}

std::string
Author::display()
{
    return this->name + " <" + this->email + ">";
}

std::string
Sub::display()
{
    return "    " + this->name + " " + this->usage  + "\t\t" + this->desc;
}

void
App::add_ui(std::string app_id,
            std::string ui_file)
{
    int argc = 1;
    char** argv = (char**)malloc(1*sizeof(char*));
    argv[0] = "apportunity";
    this->ui_app = Gtk::Application::create(argc, argv, app_id);
    this->builder = Gtk::Builder::create();
    this->builder->add_from_file(ui_file);
    this->builder->get_widget_derived("main_window",window);
}