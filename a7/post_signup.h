#ifndef POST_SIGNUP_H
#define POST_SIGNUP_H

#include "controller.h"
class PostSignup : public Controller
{
public:
    PostSignup();
    Response* callback(Request* req);
    bool is_user_publisher(Request* req);
private:
    int user_id;
};

#endif