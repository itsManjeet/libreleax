#include <releax/app.hh>

App::App(std::string name,
         float       version,
         char        release,
         std::string desc)
{
    this->name    = name;
    this->version = version;
    this->release = release;
    this->desc    = desc;
}


void
App::add_sub(std::string name,
             std::string desc,
             std::string usage,
             error (*func)(std::vector<std::string> args,
                           std::vector<std::string> flags))
{
    Sub new_sub;
    new_sub.name = name;
    new_sub.desc = desc;
    new_sub.usage = usage;
    new_sub.func = func;

    this->subs.push_back(new_sub);
}


void
App::add_author(std::string name,
                std::string email,
                std::string about)
{
    Author new_author(name, email,about);
    this->authors.push_back(new_author);
}

void
App::print_help()
{
    std::cout << this->name << " " << this->version  << "." << this->release << " [ ";
    for (Author author: this->authors) {
        std::cout << author.display() << ", ";
    }
    std::cout << "\b\b ]" << std::endl;
    std::cout << std::endl << "Description: " << this->desc << std::endl;

    std::cout << "\nUsage:" << std::endl;
    for (Sub sub: this->subs) {
        std::cout << sub.display() << std::endl;
    }
}


error
App::execute(int argc, char** argv)
{
    bool task_found = false;
    Sub task;
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];

        if (arg == "--version" || 
            arg == "-v") {
                std::cout << "Version: " << this->version << "." << this->release << std::endl;
                return error(0,"success");
        }

        if (arg == "--help" || 
            arg == "-h") {
                this->print_help();
                return error(0,"success");
        }

        if (argv[i][0] == '-') {
            
            this->flags.push_back(argv[i]);
            continue;
        }

        for (auto sub: this->subs) {
            if (sub.name == argv[i] &&
                ! task_found) {
                task_found = true;
                task = sub;
            } else {
                this->args.push_back(argv[i]);
            }
        }
    }

    if (!task_found && this->func == nullptr) {
        this->print_help();
        return error(1,"invalid task");

    } else {
        if (task_found) {
            return task.func(this->args,this->flags);
        } else {
            return this->func(this->args,this->flags);
        }
    }
    this->print_help();
    return error(1,"invalid task");
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