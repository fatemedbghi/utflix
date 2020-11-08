#ifndef POST_BUY_H
#define POST_BUY_H

#include "controller.h"

class PostBuy : public Controller
{
public:
    PostBuy();
    void do_post_buy(std::vector<std::string> order);
    void is_input_complete();
    void send_notification();
};

#endif