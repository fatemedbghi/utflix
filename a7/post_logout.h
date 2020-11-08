#ifndef POST_LOGOUT_H
#define POST_LOGOUT_H

#include "controller.h"

class PostLogout : public Controller
{
public:
    PostLogout();
    Response* callback(Request* req);
};

#endif