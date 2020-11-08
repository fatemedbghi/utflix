#ifndef GET_MONEY_H
#define GET_MONEY_H

#include "controller.h"

class GetMoney : public Controller
{
public:
    GetMoney();
    void do_get_money(std::vector<std::string> order);
};

#endif