#ifndef FILM_H
#define FILM_H

#include <string>
#include <vector>
#include <iostream>
#include "comment.h"

#define WEAK 80
#define MEAN 90
#define HIGH 95


class Film
{
public:
    Film(std::string _name , int _year ,int _length, int _price , std::string _summary , std::string _director , int _id , int _user_id);
    ~Film();
    void calculate_rate(float _rate);
    void add_comment(std::string new_comment, int comment_id , int user_id);
    std::vector <Comment*> return_comments() {return comments;};
    int return_id() {return id;};
    float return_rate() {return rate;};
    int return_price() {return price;};
    int return_last_comment_id() {return last_comment_id;};
    int return_status() {return status;};
    int return_user_id() {return user_id;};
    std::string name;
    int year;
    int length;
    std::string summary;
    std::string director;

private:
    int price;
    int id;
    float rate;
    int last_comment_id;
    int number_of_people_rated;
    std::vector <Comment*> comments;
    int status;
    int user_id;
};

#endif