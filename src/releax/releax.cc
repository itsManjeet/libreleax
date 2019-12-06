#include <releax/releax.hh>

error::
error(int status,
      std::string message)
{
    this->message = message;
    this->status = status;
}