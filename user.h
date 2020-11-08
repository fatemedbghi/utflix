#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "film.h"
#include "exception.h"

class Publisher;

class User
{
public:
    User(std::string _email , std::string _username , std::string _password , int _age , bool _is_publisher , int _id);
    ~User();
    int return_id() {return id;};
    std::string return_username() {return username;};
    std::string return_password() {return password;};
    std::string return_email() {return email;};
    bool return_if_publisher() {return is_publisher;};
    int return_cash() {return cash;};
    std::vector <Film*> return_bought_films() {return films;};
    void follow_publisher(Publisher* publisher);
    void add_money(int amount);
    void search_films(std::string name , float min_rate , int min_year , int price , int max_year , std::string director , std::vector <Film*> all_films);
    std::vector <Film*> filter_films(std::string name , float min_rate , int min_year , int price , int max_year , std::string director , std::vector <Film*> all_films);
    std::vector <Film*> filter_name(std::vector <Film*> before_filtering , std::string name);
    std::vector <Film*> filter_rate(std::vector <Film*> before_filtering , float min_rate);
    std::vector <Film*> filter_year1(std::vector <Film*> before_filtering , int min_year);
    std::vector <Film*> filter_year2(std::vector <Film*> before_filtering , int max_year);
    std::vector <Film*> filter_price(std::vector <Film*> before_filtering , int price);
    std::vector <Film*> filter_director(std::vector <Film*> before_filtering , std::string director);
    void show_film_details(int film_id , std::vector <Film*> all_films);
    void buy_film(int film_id ,std::vector<Film*> all_films);
    void rate_film (int film_id , int score , std::vector<Film*> all_films);
    void post_comment (int film_id , std::string content , int commnet_id , std::vector<Film*> all_films);
    void get_purchased_films (std::string name , int price , int min_year , int max_year , std::string director);
    void add_notifications(std::string notif);
    void show_unread_notifications();
    void show_read_notifications(int limit);

    std::vector <std::string> return_unread_notifications() {return unread_notifications;};
    

protected:
    std::string email;
    std::string username;
    std::string password;
    int age;
    bool is_publisher;
    int id;
    std::vector <Film*> films;
    int cash;
    std::vector <std::string> unread_notifications;
    std::vector <std::string> read_notifications;
    std::vector <Publisher*> followed_publishers;
};

#endif