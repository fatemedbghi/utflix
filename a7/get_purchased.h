#ifndef GET_PURCHASED_H
#define GET_PURCHASED_H

#include "controller.h"

class GetPurchased : public Controller
{
public:
    GetPurchased();
    Response* callback(Request* req);
};

#endif