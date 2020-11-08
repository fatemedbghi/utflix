#ifndef POST_REPLIES_H
#define POST_REPLIES_H

#include "controller.h"

class PostReplies : public Controller
{
public:
    PostReplies();
    void do_post_replies(std::vector<std::string> order);
    void is_input_complete();
    void save_reply(std::vector <Film*> films);
    void send_notifications();
};

#endif