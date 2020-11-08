#ifndef POST_FOLLOWERS_H
#define POST_FOLLOWERS_H

#include "controller.h"

class PostFollowers : public Controller
{
public:
    PostFollowers();
    void do_post_followers(std::vector<std::string> order);
    void is_input_complete();
    void send_notification();
};

#endif