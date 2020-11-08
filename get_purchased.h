#ifndef GET_PURCHASED_H
#define GET_PURCHASED_H

#include "controller.h"

class GetPurchased : public Controller
{
public:
    GetPurchased();
    void do_get_purchased(std::vector<std::string> order);
private:
    int min_year;
    int max_year;
    int price;
};

#endif