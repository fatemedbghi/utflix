#ifndef GET_PUBLISHED_H
#define GET_PUBLISHED_H

#include "controller.h"

class GetPublished : public Controller
{
public:
    GetPublished();
    void do_get_published(std::vector<std::string> order);
public:
    int min_rate;
    int min_year;
    int price;
    int max_year;
};

#endif