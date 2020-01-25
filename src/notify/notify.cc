#include <releax/notify.hh>

Notification::Notification(std::string AppName,
                           std::string Heading,
                           std::string Message)
{
    notify_init(AppName.c_str());
    this->notify_ptr = notify_notification_new(
        Heading.c_str(),
        Message.c_str(),
        0
    );

}

int
Notification::timeout(int time)
{
    notify_notification_set_timeout(this->notify_ptr,time);
}

int
Notification::send()
{
    return notify_notification_show(this->notify_ptr,0);
}