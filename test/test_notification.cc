#include <releax/notify.hh>

int main()
{
    Notification n(
        "sample",
        "Testing",
        "this is testing message"
    );

    n.send();
}