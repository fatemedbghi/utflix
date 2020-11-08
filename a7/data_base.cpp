#include "data_base.h"

using namespace std;

DataBase::DataBase()
{
    is_publisher = false;
    if_anyone_online_status = false;
    admin_status = false;
    last_film_id = 0;
    last_user_id = 1;
}

DataBase::~DataBase()
{
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

void DataBase::set_if_publisher(bool _is_publisher)
{
    is_publisher = _is_publisher;
}

void DataBase::set_data_base_films(std::vector <Film*> _data_base_films)
{
    data_base_films = _data_base_films;
}

void DataBase::set_online_status(bool online_status)
{
    if_anyone_online_status = online_status;
}

void DataBase::set_admin_status(bool admin)
{
    admin_status = admin;
}

void DataBase::set_accessible_films(std::vector <Film*> _accessible_films)
{
    accessible_films.resize(0);
    accessible_films = _accessible_films;
}

void DataBase::set_publishers(Publisher* publisher)
{
    publishers.push_back(publisher);
}

void DataBase::set_users(User* user)
{
    users.push_back(user);
}

void DataBase::set_last_film_id(int _last_film_id)
{
    last_film_id = _last_film_id;
    resize_recommendation();
}

void DataBase::set_last_user_id(int _last_user_id)
{
    last_user_id = _last_user_id;
}

void DataBase::resize_recommendation()
{
    recommendation.resize(last_film_id);
    for(int i=0;i<last_film_id ; i++)
        recommendation[i].resize(last_film_id);
}

void DataBase::update_recommender_system(int film_id , int user_id)
{
    for(int i=0;i<users.size();i++)
        if(users[i]->return_id() == user_id)
            for (int j=0;j<users[i]->return_bought_films().size();j++)
            {
                recommendation[film_id - 1][users[i]->return_bought_films()[j]->return_id() - 1]++;
                recommendation[users[i]->return_bought_films()[j]->return_id() - 1][film_id - 1]++;
            }
}

std::vector<int> DataBase::sort_weighted_graph(int film_id)
{
    vector<int> temp = recommendation[film_id - 1];
    sort(temp.begin(), temp.end()); 
    vector <int> sorted;
    for(int i=temp.size() - 1;i>=0;i--)
    	sorted.push_back(temp[i]);
    return sorted;
}

vector<Film*> DataBase::recommended_films(int film_id)
{
    vector <int> sorted = sort_weighted_graph(film_id);
    vector <bool> temp(recommendation.size() , false);
    vector <Film*> recommended;
    for(int i=0;i<sorted.size();i++)
        for(int j=0;j<sorted.size();j++)
            if(recommendation[film_id - 1][j] == sorted[i])
                if(!temp[j])
                {
                    recommended.push_back(data_base_films[j]);
                    temp[j] = true;
                    break;
                }
    return recommended;
}

vector<Film*> DataBase::check_deleted_films(vector <Film*> recommended_films)
{
    vector<bool> if_deleted(recommended_films.size() , false);
    for(int i=0;i<accessible_films.size();i++)
        for(int j=0;j<recommended_films.size();j++)
            if(accessible_films[i]->return_id() == recommended_films[j]->return_id())
                if_deleted[j] = true;
    for(int i=0;i<if_deleted.size();i++)
        if(if_deleted[i] == false)
            recommended_films.erase(recommended_films.begin() + i , recommended_films.end() - (recommended_films.size() - i - 1));
    return recommended_films;
}

vector<Film*> DataBase::recommender_system(int film_id , int user_id)
{
    vector <Film*> recommended = recommended_films(film_id);
    for(int k=0;k<users.size();k++)
        if(users[k]->return_id() == user_id)
            for(int j=0;j<users[k]->return_bought_films().size();j++)
                for(int i=0;i<recommended.size();i++)
                    if(recommended[i]->return_id() == users[k]->return_bought_films()[j]->return_id())
                        recommended.erase(recommended.begin() + i , recommended.end() - (recommended.size() - i - 1));
    return recommended;
}

void DataBase::print_recommended_films(vector <Film*> recommended)
{
    cout << endl << "Recommendation Film" << endl << "#. Film Id | Film Name | Film Length | Film Director" << endl;

}

bool DataBase::get_if_publisher()
{
    return is_publisher;
}

bool DataBase::show_if_anyone_online_status()
{
    return if_anyone_online_status;
}

bool DataBase::show_if_admin_is_online()
{
    return admin_status;
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