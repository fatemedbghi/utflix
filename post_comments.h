#ifndef POST_COMMENTS_H
#define POST_COMMENTS_H

#include "controller.h"

class PostComments : public Controller
{
public:
    PostComments();
    void do_post_comments(std::vector<std::string> order);
    void is_input_complete();
    int return_comment_id();
    void exert_comments(std::vector <Film*> films);
    void send_notification();
};

#endif