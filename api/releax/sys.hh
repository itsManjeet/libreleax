#ifndef SYS_HH
#define SYS_HH

#include "releax.hh"

namespace sys
{
    std::string execute(std::string cmd);

    bool check_su();
} // namespace sys

#endif