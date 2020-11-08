#ifndef POST_SIGNUP_H
#define POST_SIGNUP_H

#include "controller.h"
#include <regex>

class PostSignup : public Controller
{
public:
    PostSignup();
    void do_signup(std::vector <std::string> order);
    void if_username_exists(std::string username);
    bool is_user_publishr();
    void is_input_complete();
    void is_email_valid();
    bool email(const std::string& email);
private:
    int user_id;

};

#endif