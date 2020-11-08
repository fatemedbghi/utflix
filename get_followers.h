#ifndef GET_FOLLOWERS_H
#define GET_FOLLOWERS_H

#include "controller.h"

class GetFollowers : public Controller
{
public:
    GetFollowers();
    void do_get_followers();
};

#endif