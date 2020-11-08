#ifndef GET_NOTIFICATIONS_READ_H
#define GET_NOTIFICATIONS_READ_H

#include "controller.h"

class GetNotificationsRead : public Controller
{
public:
    GetNotificationsRead();
    void do_get_notifications_read(std::vector<std::string> order);
    void is_input_complete();
};

#endif