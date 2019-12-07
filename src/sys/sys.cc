#include <releax/sys.hh>

std::string
sys::execute(std::string cmd)
{
    std::array<char,128> buffer;
    std::string result;
    std::cout << "Executing : " << cmd << std::endl;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(),"r"),pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }

    return result;
}