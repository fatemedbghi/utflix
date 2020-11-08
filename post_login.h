#ifndef POST_LOGIN_H
#define POST_LOGIN_H

#include "controller.h"

class PostLogin : public Controller
{
public:
    PostLogin();
    void do_login(std::vector<std::string> order);
    void is_input_complete();
    void does_username_exists();
    void is_password_valid();
};

#endif