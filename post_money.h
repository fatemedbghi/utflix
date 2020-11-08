#ifndef POST_MONEY_H
#define POST_MONEY_H

#include "controller.h"

class PostMoney : public Controller
{
public:
    PostMoney();
    void do_post_money(std::vector<std::string> order);
    void is_input_complete();
};

#endif