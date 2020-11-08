#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "film.h"

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
    void buy_film(int film_id ,std::vector<Film*> all_films);
    void rate_film (int film_id , int score , std::vector<Film*> all_films);

protected:
    std::string email;
    std::string username;
    std::string password;
    int age;
    bool is_publisher;
    int id;
    std::vector <Film*> films;
    int cash;
    std::vector <Publisher*> followed_publishers;
};

#endif