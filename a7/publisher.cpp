#include "publisher.h"

using namespace std;

Publisher::Publisher(string _email ,string _username ,string _password , int _age , bool _is_publisher , int _id)
    : User(_email , _username , _password , _age , true , _id)
{
    unsetteled_money = 0;
}

Publisher::~Publisher()
{
    for(int i=0;i<published_films.size();i++)
        delete published_films[i];
    for(int i=0;i<followers.size();i++)
        delete followers[i];
}

void Publisher::add_followers(User* new_follower)
{
    followers.push_back(new_follower);
}

void Publisher::upload_film(string name , int year , int length , int price , string summary , string director , int film_id)
{
    Film* new_film = new Film(name , year , length , price , summary , director , film_id , this->return_id());
    published_films.push_back(new_film);
}

void Publisher::delete_film(int id)
{
    for(int i=0; i<published_films.size(); i++)
        if (published_films[i]->return_id() == id)
            published_films.erase(published_films.begin() + i , published_films.end() - (published_films.size() - i - 1));
}


void Publisher::calculate_unsetteled_money(int amount , int status)
{
    unsetteled_money = unsetteled_money + (amount*status)/100;
}

void Publisher::get_money_from_media_service()
{
    add_money(unsetteled_money);
    unsetteled_money = 0;
}

vector<Film*> Publisher::show_published_films(string director)
{
    vector <Film*> filtered;
        if(director == "")
            filtered = published_films;
    else
        for(int i=0;i<published_films.size();i++)
            if(published_films[i]->director == director)
                filtered.push_back(published_films[i]);
    return filtered;
}