#ifndef POST_MONEY_H
#define POST_MONEY_H

#include "controller.h"

class PostMoney : public Controller
{
public:
    PostMoney();
    Response* callback(Request* req);
};

#endif