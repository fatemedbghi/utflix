#ifndef MEDIA_SERVICE_H
#define MEDIA_SERVICE_H

#include <bits/stdc++.h> 
#include <iostream>
#include <string>
#include <vector>
#include "exception.h"
#include "controller.h"
#include "delete_comments.h"
#include "delete_films.h"
#include "get_films.h"
#include "get_followers.h"
#include "get_notifications.h"
#include "get_notifications_read.h"
#include "get_published.h"
#include "get_purchased.h"
#include "post_buy.h"
#include "post_comments.h"
#include "post_films.h"
#include "post_followers.h"
#include "post_login.h"
#include "post_money.h"
#include "post_rate.h"
#include "post_replies.h"
#include "post_signup.h"
#include "put_films.h"
#include "data_base.h"



class MediaService
{
public:
    MediaService();
    ~MediaService();
    void run();
    std::vector <std::string> remove_extra_spaces(std::string str);
    void check_controllers(std::string controller);
    void check_url();
    void check_get_url();
    void check_post_url();
    void check_put_url();
    void check_delete_url();
    void call_each_url(std::vector <std::string> input);

private:
    std::vector <std::string> order;
    PostSignup* post_signup;
    PostLogin* post_login;
    DeleteComments* delete_comments;
    DeleteFilms* delete_films;
    GetFilms* get_films;
    GetFollowers* get_followers;
    GetNotifications* get_notifications;
    GetNotificationsRead* get_notifications_read;
    GetPublished* get_published;
    GetPurchased* get_purchased;
    PostBuy* post_buy;
    PostComments* post_comments;
    PostFilms* post_films;
    PostFollowers* post_followers;
    PostMoney* post_money;
    PostRate* post_rate;
    PostReplies* post_replies;
    PutFilms* put_films;
};

#endif