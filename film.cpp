#include "film.h"

using namespace std;

Film::Film(string _name , int _year ,int _length, int _price , string _summary , string _director , int _id , int _user_id)
{
    name = _name;
    year = _year;
    length = _length;
    price = _price;
    summary = _summary;
    director = _director;
    id = _id;
    number_of_people_rated = 0;
    rate = 0;
    last_comment_id = 0;
    user_id = _user_id;
    if(rate < 5)
        status = WEAK;
    else if(rate >= 5 && rate<8)
        status = MEAN;
    else if(rate >= 8)
        status = HIGH;
}

Film::~Film()
{
    for(int i=0;i<comments.size();i++)
        delete comments[i];
}

void Film::add_comment(string new_comment, int comment_id , int user_id)
{
    last_comment_id++;
    Comment com(new_comment , id , user_id);
    comments.push_back(&com);
}

void Film::calculate_rate(float _rate)
{
    number_of_people_rated++;
    rate = (rate * (number_of_people_rated - 1) + _rate)/number_of_people_rated;
}

