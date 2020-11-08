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

void User::follow_publisher(Publisher* publisher)
{
    followed_publishers.push_back(publisher);
    cout << "OK" << endl;
}

void User::add_money(int amount)
{
    cash += amount;
}

void User::search_films(string name , float min_rate , int min_year , int price , int max_year , string director , vector <Film*> all_films)
{
    vector <Film*> filtered = filter_films(name ,min_rate ,min_year ,price ,max_year ,director ,all_films);
    cout << "#. Film Id | Film Name | Film Length | Film price | Rate | Production Year | Film Director" << endl;
    for(int i=0 ; i<filtered.size() ; i++)
    {
        cout << i+1 << ". " << filtered[i]->return_id() << " | " << filtered[i]->name << " | " << filtered[i]->length << " | ";
        cout << filtered[i]->return_price() << " | "<< filtered[i]->return_rate() << " | " << filtered[i]->year << " | ";
        cout << filtered[i]->director << endl;
    }
}

vector <Film*> User::filter_films(string name , float min_rate , int min_year , int price , int max_year , string director , vector <Film*> all_films)
{
    vector <Film*> new1 , new2 , new3 , new4 , new5 , new6;

    if(name.compare("") != 0)
        new1 = filter_name(all_films , name);
    if(name.compare("") == 0)
        new1 = all_films;
    if(min_rate != -1)
        new2.resize(filter_rate(new1 , min_rate).size());
        new2 = filter_rate(new1 , min_rate);
    if(min_rate == -1)
        new2 = new1;
    if(min_year != -1)
        new3.resize(filter_year1(new2 , min_year).size());
        new3 = filter_year1(new2 , min_year);
    if(min_year == -1)
        new3 = new2;
    if(max_year != -1)
        new4.resize(filter_year2(new3 , max_year).size());
        new4 = filter_year2(new3 , max_year);
    if(max_year == -1)
        new4 = new3;
    if(price != -1)
        new5.resize(filter_price(new4 , price).size());
        new5 = filter_price(new4 , price);
    if(price == -1)
        new5 = new4;
    if(director.compare("") != 0)
        new6.resize(filter_director(new5 , director).size());
        new6 = filter_director(new5 , director);
    if(director.compare("") == 0)
        new6 = new5;
    return new6;
}

vector <Film*> User::filter_name(vector <Film*> before_filtering , string name)
{
    vector <Film*> after_filtering;
    for(int i=0; i<before_filtering.size(); i++)
        if((before_filtering[i]->name).compare(name) == 0)
            after_filtering.push_back(before_filtering[i]);
    return after_filtering;        
}

vector <Film*> User::filter_rate(vector <Film*> before_filtering , float min_rate)
{
    vector <Film*> after_filtering;
    for(int i=0; i<before_filtering.size(); i++)
        if(before_filtering[i]->return_rate() >= min_rate)
            after_filtering.push_back(before_filtering[i]);
    return after_filtering;
}
vector <Film*> User::filter_year1(vector <Film*> before_filtering , int min_year)
{
    vector <Film*> after_filtering;
    for(int i=0; i<before_filtering.size(); i++)
        if(before_filtering[i]->year >= min_year)
            after_filtering.push_back(before_filtering[i]);
    return after_filtering;
}
vector <Film*> User::filter_year2(vector <Film*> before_filtering , int max_year)
{
    vector <Film*> after_filtering;
    for(int i=0; i<before_filtering.size(); i++)
        if(before_filtering[i]->year <= max_year)
            after_filtering.push_back(before_filtering[i]);
    return after_filtering;
}
vector <Film*> User::filter_price(vector <Film*> before_filtering , int price)
{
    vector <Film*> after_filtering;
    for(int i=0; i<before_filtering.size(); i++)
        if(before_filtering[i]->return_price() <= price)
            after_filtering.push_back(before_filtering[i]);
    return after_filtering;
}
vector <Film*> User::filter_director(vector <Film*> before_filtering , string director)
{
    vector <Film*> after_filtering;
    for(int i=0; i<before_filtering.size(); i++)
        if((before_filtering[i]->director).compare(director) == 0)
            after_filtering.push_back(before_filtering[i]);
    return after_filtering;
}

void User::show_film_details(int film_id , vector <Film*> all_films)
{
    for(int i=0 ; i<all_films.size() ; i++)
        if(all_films[i]->return_id() == film_id)
        {
            cout << "Details of Film " << all_films[i]->name << endl << "Id = " << all_films[i]->return_id() << endl;
            cout << "Director = " << all_films[i]->director << endl << "Length = " << all_films[i]->length << endl;
            cout << "Year = " << all_films[i]->year << endl << "Summary = " << all_films[i]->summary << endl;
            cout << "Rate = " << all_films[i]->return_rate() << endl << "Price = " << all_films[i]->return_price() << endl << endl;

            cout << "Comments" << endl;

                for(int j=0; j< (all_films[i]->return_comments()).size() ; j++)
                {
                    cout << (all_films[i]->return_comments()[j])->return_comment_id();
                    //  << "." << (all_films[i]->return_comments()[j])->return_comment() <<endl;
                    // cout << (all_films[i]->return_comments()[j])->return_comment_id() << ".1. " << (all_films[i]->return_comments()[j])->return_reply() << endl;
                }
        }
}

void User::buy_film(int film_id ,vector<Film*> all_films)
{
    for (int i=0; i<all_films.size(); i++)
        if (all_films[i]->return_id() == film_id)
        {
            if(all_films[i]->return_price() > cash)
                throw PermissionDenied();
            else
            {
                films.push_back(all_films[i]);
                cash = cash - all_films[i]->return_price();
                cout << "OK" << endl;
            }
        }
}

void User::rate_film(int film_id , int score , vector<Film*> all_films)
{
    for (int i=0; i<all_films.size(); i++)
        if (all_films[i]->return_id() == film_id)
            all_films[i]->calculate_rate(score);
    cout << "OK" << endl;
}

void User::post_comment(int film_id , string content ,int comment_id , vector<Film*> all_films)
{
    for (int i=0; i<all_films.size(); i++)
        if (all_films[i]->return_id() == film_id)
            all_films[i]->add_comment(content , this->return_id());
    cout << "OK" << endl;
}

void User::get_purchased_films(string name , int price , int min_year , int max_year , string director)
{
    vector <Film*> filtered = filter_films(name , -1 ,min_year ,price ,max_year ,director , films);
    cout << "#. Film Id | Film Name | Film Length | Film price | Rate | Production Year | Film Director" << endl;
    for(int i=0 ; i<filtered.size() ; i++)
    {
        cout << i+1 << ". " << filtered[i]->return_id() << " | " << filtered[i]->name << " | " << filtered[i]->length << " | ";
        cout << filtered[i]->return_price() << " | "<< filtered[i]->return_rate() << " | " << filtered[i]->year << " | ";
        cout << filtered[i]->director << endl;
    }
}

void User::add_notifications(std::string notif)
{
    unread_notifications.push_back(notif);
}

void User::show_unread_notifications()
{
    cout << "#. Notification Message" << endl;
    for (int i=unread_notifications.size() - 1; i>=0 ; i--)
        cout << unread_notifications.size() - i << ". " << unread_notifications[i] << endl;
    unread_notifications.clear();
    unread_notifications.resize(0);
}

void User::show_read_notifications(int limit)
{
    cout << "#. Notification Message" << endl;
    for (int i=read_notifications.size() - 1; i<= read_notifications.size() - limit ; i--)
        cout << read_notifications.size() - i << ". " << read_notifications[i] << endl;
}