#ifndef POST_LOGIN_H
#define POST_LOGIN_H

#include "controller.h"

class PostLogin : public Controller
{
public:
    PostLogin();
    Response* callback(Request* req);
};

#endif