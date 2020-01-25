#include <ostream>
#include <releax/io.hh>

std::string
io::set(color::code tcode)
{
    return "\033["  + std::to_string(tcode) + "m";
}

std::string 
io::err()
{
    return io::set(color::bold) + "=>" + io::set(color::fg_red) + " error" + io::set(color::reset) + io::set(color::bold) + " : ";
}

std::string 
io::warn()
{
    return io::set(color::bold) + "=>" + io::set(color::fg_yellow) + " warning" + io::set(color::reset) + io::set(color::bold) + " : ";
}

std::string 
io::proc()
{
    return io::set(color::bold) + "=>" + io::set(color::fg_green) + " process" + io::set(color::reset) + io::set(color::bold) + " : ";
}

std::string 
io::msg()
{
    return io::set(color::bold) + "=>" + io::set(color::fg_blue) + " message" + io::set(color::reset) + io::set(color::bold) + " : ";
}

std::string
io::end()
{
    return io::set(color::reset) + "\n";
}