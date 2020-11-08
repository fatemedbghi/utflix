#include "data_base.h"

using namespace std;

DataBase::DataBase()
{
    online_publisher = NULL;
    online_user = NULL;
    last_film_id = 0;
    last_user_id = 0;
}

DataBase::~DataBase()
{
    delete online_user;
    delete online_publisher;
    for(int i=0;i<data_base_films.size();i++)
        delete data_base_films[i];
    for(int i=0;i<accessible_films.size();i++)
        delete accessible_films[i];
    for(int i=0;i<users.size();i++)
        delete users[i];
    for(int i=0;i<publishers.size();i++)
        delete publishers[i];
}

DataBase* DataBase::instance = NULL;

void DataBase::set_online_user(User* _online_user)
{
    online_user = _online_user;
}

void DataBase::set_online_publisher(Publisher* _online_publisher)
{
    online_publisher = _online_publisher;
}

void DataBase::set_data_base_films(std::vector <Film*> _data_base_films)
{
    data_base_films = _data_base_films;
}

void DataBase::set_accessible_films(std::vector <Film*> _accessible_films)
{
    accessible_films = _accessible_films;
}

void DataBase::set_publishers(std::vector <Publisher*> _publishers)
{
    publishers = _publishers;
}

void DataBase::set_users(std::vector <User*> _users)
{
    users = _users;
}

void DataBase::set_last_film_id(int _last_film_id)
{
    last_film_id = _last_film_id;
}

void DataBase::set_last_user_id(int _last_user_id)
{
    last_user_id = _last_user_id;
}

User* DataBase::get_online_user()
{
    return online_user;
}

Publisher* DataBase::get_online_publisher()
{
    return online_publisher;
}

vector <Film*> DataBase::get_data_base_films()
{
    return data_base_films;
}

vector <Film*> DataBase::get_accessible_films()
{
    return accessible_films;
}

vector <Publisher*> DataBase::get_publishers()
{
    return publishers;
}

vector <User*> DataBase::get_users()
{
    return users;
}

int DataBase::get_last_film_id()
{
    return last_film_id;
}

int DataBase::get_last_user_id()
{
    return last_user_id;
}