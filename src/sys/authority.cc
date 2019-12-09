#include <releax/sys.hh>
#include <unistd.h>

bool
sys::
check_su()
{
    return (geteuid() == 0) ? true : false;
}