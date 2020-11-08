#ifndef POST_RATE_H
#define POST_RATE_H

#include "controller.h"

class PostRate : public Controller
{
public:
    PostRate();
    void do_post_rate(std::vector<std::string> order);
    void is_input_complete();
    void exert_rate();
    void send_notification();
    void check_score_validity();
};

#endif