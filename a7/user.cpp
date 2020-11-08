#include "user.h"

using namespace std;

User::User(string _email , string _username ,string _password , int _age , bool _is_publisher , int _id)
{
    email = _email;
    username = _username;
    password = _password;
    age = _age;
    is_publisher = _is_publisher;
    id = _id;
    cash = 0;
}

User::~User()
{
    for(int i=0;i<films.size();i++)
        delete films[i];
}

void User::add_money(int amount)
{
    cash += amount;
}

void User::buy_film(int film_id ,vector<Film*> all_films)
{
    for (int i=0; i<all_films.size(); i++)
        if (all_films[i]->return_id() == film_id)
        {
            films.push_back(all_films[i]);
            cash = cash - all_films[i]->return_price();
        }
}