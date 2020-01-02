#include <releax/sys.hh>
#include <errno.h>
#include <unistd.h>

std::string
sys::execute(std::string cmd)
{
    std::cout << "Executing: " << cmd << std::endl;
    int status = system(cmd.c_str());
    std::cout << "Exit Code: " << status << std::endl;
    return "";
}

int
sys::execute(std::string cmd, 
             std::string dir)
{
    std::cout << "Executing " << cmd << std::endl;
    std::cout << "at " << dir << std::endl;
    std::string cmpltcmd = "cd " + dir + " && " + cmd;
    return system(cmpltcmd.c_str());
}