#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <string>
#include <cctype>
#include "user.h"
#include "publisher.h"
#include "data_base.h"
#include "../server/server.hpp"

#define GET "GET"
#define POST "POST"

#define SIGNUP "signup"
#define LOGIN "login"
#define COMMENTS "comments"
#define FILMS "films"
#define FOLLOWERS "followers"
#define NOTIFICATIONS "notifications"
#define READ "read"
#define PUBLISHED "published"
#define PURCHASED "purchased"
#define BUY "buy"
#define MONEY "money"
#define RATE "rate"
#define REPLIES "replies"

#define EMAIL "email"
#define USERNAME "username"
#define PASSWORD "password"
#define AGE "age"
#define PUBLISHER "if_publisher"
#define NAME "name"
#define YEAR "year"
#define LENGTH "length"
#define PRICE "price"
#define SUMMARY "summary"
#define DIRECTOR "director"
#define FILM_ID "film_id"
#define COMMENT_ID "comment_id"
#define CONTENT "content"
#define USER_ID "user_id"
#define AMOUNT "amount"
#define RATE "rate"
#define MIN_RATE "min_rate"
#define MIN_YEAR "min_year"
#define MAX_YEAR "max_year"
#define SCORE "score"
#define READ "read"
#define LIMIT "limit"

class Film;

class Controller : public RequestHandler
{
public:
    Controller();
    virtual Response *callback(Request *req) = 0;
    void set_data_bases();
    std::string encodePass(std::string pass);
protected:
    bool is_publisher;
    bool if_anyone_online;
    bool admin_status;
    Admin* admin;
    std::vector <Film*> data_base_films;
    std::vector <Film*> accessible_films;
    std::vector <Publisher*> publishers;
    std::vector <User*> users;
    int last_film_id;
    int last_user_id;
};

#endif