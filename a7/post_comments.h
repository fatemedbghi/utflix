#ifndef POST_COMMENTS_H
#define POST_COMMENTS_H

#include "controller.h"

class PostComments : public Controller
{
public:
    PostComments();
    Response* callback(Request* req);
    int return_comment_id(Request* req);
    void exert_comments(std::vector <Film*> films , Request* req);
};

#endif