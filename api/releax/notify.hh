#ifndef __NOTIFY_HH__
#define __NOTIFY_HH__

#include <libnotify/notify.h>
#include <iostream>

class Notification {

    NotifyNotification * notify_ptr;
public:
    Notification(std::string AppName,
                 std::string Heading,
                 std::string Message);

    int timeout(int time);
    int send();
};

#endif