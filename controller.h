#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <string>
#include <map>
#include <cctype>
#include "exception.h"
#include "user.h"
#include "publisher.h"
#include "data_base.h"

#define GET "GET"
#define POST "POST"
#define PUT "PUT"
#define DELETE "DELETE"

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
#define PUBLISHER "publisher"
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

class Controller
{
public:
    Controller();
    void seperate_signup_items(std::vector <std::string> order);
    void pair(std::string paired, int count , std::vector<std::string> order);
    void pair_if_publisher(std::vector <std::string> order);
    void seperate_login_items(std::vector<std::string> order);
    void seperate_post_films_items(std::vector<std::string> order);
    void seperate_put_films_items(std::vector<std::string> order);
    void seperate_delete_films_items(std::vector<std::string> order);
    void seperate_get_published_items(std::vector<std::string> order);
    void seperate_post_replies_items(std::vector<std::string> order);
    void seperate_delete_comments_items(std::vector<std::string> order);
    void seperate_post_followers_items(std::vector<std::string> order);
    void seperate_post_money_items(std::vector<std::string> order);
    void seperate_get_films_items(std::vector<std::string> order);
    void seperate_post_buy_items(std::vector<std::string> order);
    void seperate_post_rate_items(std::vector<std::string> order);
    void seperate_post_comments_items(std::vector<std::string> order);
    void seperate_get_purchased_items(std::vector<std::string> order);
    void seperate_get_notifications_read_items(std::vector<std::string> order);
    void set_data_bases();
    std::string return_film_name();
    void check_numbers_validity(std::string str);
    void check_if_user_is_online(int publisher_needed);
    void check_if_signingup_or_loggingin_is_possible();
    void check_if_film_is_bought();
    void check_if_publishers_matches();
    void check_validity_of_film_id();
    void check_validity_of_user_id();
    void check_validity_of_comment_id();
    std::string encodePass(std::string pass);
    
protected:
    User* online_user;
    Publisher* online_publisher;
    bool if_anyone_online;
    bool admin_status;
    Admin* admin;
    std::vector <Film*> data_base_films;
    std::vector <Film*> accessible_films;
    std::vector <Publisher*> publishers;
    std::vector <User*> users;
    int last_film_id;
    int last_user_id;
    std::map <std::string , std::string> information;
};

#endif