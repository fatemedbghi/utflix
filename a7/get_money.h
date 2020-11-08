#ifndef GET_MONEY_H
#define GET_MONEY_H

#include "controller.h"

class GetMoney : public Controller
{
public:
    GetMoney();
    Response* callback(Request* req);
};

#endif