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
    cout << "OK" << endl;
}

void Publisher::edit_film(int film_id , string name , int year , int length , string summary , string director)
{
    for(int i=0; i<published_films.size(); i++)
        if(published_films[i]->return_id() == film_id)
        {
            if(name.compare("") != 0)
                published_films[i]->name = name;
            if(year != -1)
                published_films[i]->year = year;
            if(length != -1)
                published_films[i]->length = length;
            if(summary.compare("") != 0)
                published_films[i]->summary = summary;
            if(director.compare("") != 0)
                published_films[i]->director = director;
        }
    cout << "OK" << endl;
}

void Publisher::delete_film(int id)
{
    for(int i=0; i<published_films.size(); i++)
        if (published_films[i]->return_id() == id)
            published_films.erase(published_films.begin() + i , published_films.end() - (published_films.size() - i - 1));
    cout << "OK" << endl;
}

void Publisher::show_followers()
{
    cout << "List of Followers" << endl << "#. User Id | User Username | User Email" << endl;
    for (int i=0; i<followers.size() ; i++)
        cout << i+1 <<". " << followers[i]->return_id() << " | " << followers[i]->return_username() << " | " << followers[i]->return_email() << endl;
}

void Publisher::calculate_unsetteled_money(int amount , int status)
{
    unsetteled_money = unsetteled_money + (amount*status)/100;
}

void Publisher::get_money_from_media_service()
{
    add_money(unsetteled_money);
    unsetteled_money = 0;
    cout << "OK" << endl;
}

void Publisher::show_published_films(string name , int min_rate , int min_year , int price , int max_year , string director)
{
    vector <Film*> filtered = filter_films(name ,min_rate ,min_year ,price ,max_year ,director ,published_films);
    cout << "#. Film Id | Film Name | Film Length | Film price | Rate | Production Year | Film Director" << endl;
    for(int i=0 ; i<filtered.size() ; i++)
    {
        cout << i+1 << ". " << filtered[i]->return_id() << " | " << filtered[i]->name << " | " << filtered[i]->length << " | ";
        cout << filtered[i]->return_price() << " | "<< filtered[i]->return_rate() << " | " << filtered[i]->year << " | ";
        cout << filtered[i]->director << endl;
    }
}

void Publisher::reply_comments(int film_id , int comment_id , string content)
{
    for(int i=0;i<published_films.size() ; i++)
        if(published_films[i]->return_id() == film_id)
            for (int j = 0; j< (published_films[i]->return_comments()).size(); j++)
                if (published_films[i]->return_comments()[j]->return_comment_id() == comment_id)
                    published_films[i]->return_comments()[j]->add_reply(content);
    cout << "OK" << endl;
            
}

void Publisher::delete_comment(int film_id , int comment_id)
{
    for(int i=0;i<published_films.size() ; i++)
        if(published_films[i]->return_id() == film_id)
            for (int j = 0; j< (published_films[i]->return_comments()).size(); j++)
                if(published_films[i]->return_comments()[j]->return_comment_id() == comment_id)
                    published_films[i]->return_comments().erase(published_films[i]->return_comments().begin() + j
                     , published_films[i]->return_comments().end() - (published_films[i]->return_comments().size() - j - 1));
    cout << "OK" << endl;
}