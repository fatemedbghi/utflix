#ifndef POST_BUY_H
#define POST_BUY_H

#include "controller.h"

class PostBuy : public Controller
{
public:
    PostBuy();
    Response* callback(Request* req);
    void send_money(Request* req);
};

#endif