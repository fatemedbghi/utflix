#include "controller.h"

using namespace std;

Controller::Controller()
{
    online_publisher = NULL;
    online_user = NULL;
    last_film_id = 0;
    last_user_id = 1;
    if_anyone_online = false;
    admin_status = false;
    information = map<string, string>();
}

void Controller::pair(string paired, int count , vector <string> order)
{
    if (order[count] == paired)
        information.insert(make_pair(order[count], order[count + 1]));
}

void Controller::seperate_signup_items(vector <string> order)
{
    information.clear();
    for(int i = 3 ; i<order.size() - 1; )
    {
        if(order[i] == EMAIL)
            pair(EMAIL , i , order);
        if(order[i] == USERNAME)
            pair(USERNAME , i , order);
        if(order[i] == PASSWORD)
            pair(PASSWORD , i , order);
        if(order[i] == AGE)
            pair(AGE , i , order);

        i=i+2;
    }
    pair_if_publisher(order);
}

void Controller::pair_if_publisher(vector<string> order)
{
    int count = 3;
    bool x = true;
    while(x)
    {
        if (order[count].compare(PUBLISHER) == 0)
        {
            pair(PUBLISHER , count , order);
            x = false;
        }
        if (count == order.size() - 1)
        {
            x = false;
            information[PUBLISHER] = "false";
        }
        if ( x == true)
            count++;
    }
}

void Controller::seperate_login_items(vector <string> order)
{
    information.clear();
    for(int i = 3 ; i<order.size(); i++)
    {
        pair(USERNAME , i , order);
        pair(PASSWORD , i , order);
    }
}

void Controller::seperate_post_films_items(vector <string> order)
{
    information.clear();
    for(int i = 3 ; i<order.size(); i++)
    {
        pair(NAME , i , order);
        pair(YEAR , i , order);
        pair(LENGTH , i , order);
        pair(PRICE , i , order);
        pair(SUMMARY , i , order);
        pair(DIRECTOR , i , order);
    }
}

void Controller::seperate_put_films_items(vector <string> order)
{
    information.clear();
    for(int i = 3 ; i<order.size(); i++)
    {
        pair(FILM_ID , i , order);
        pair(NAME , i , order);
        pair(YEAR , i , order);
        pair(LENGTH , i , order);
        pair(SUMMARY , i , order);
        pair(DIRECTOR , i , order);
    }
}

void Controller::seperate_delete_films_items(vector <string> order)
{
    information.clear();
    for(int i = 3 ; i<order.size(); i++)
    {
        pair(FILM_ID , i , order);
    }
}

void Controller::seperate_get_published_items(vector <string> order)
{
    information.clear();
    for(int i = 3 ; i<order.size(); i++)
    {
        pair(NAME , i , order);
        pair(MIN_RATE , i , order);
        pair(MIN_YEAR , i , order);
        pair(PRICE , i , order);
        pair(MAX_YEAR , i , order);
        pair(DIRECTOR , i , order);
    }
}

void Controller::seperate_post_replies_items(vector <string> order)
{
    information.clear();
    for(int i = 3 ; i<order.size(); i++)
    {
        pair(FILM_ID , i , order);
        pair(COMMENT_ID , i , order);
        pair(CONTENT , i , order);
    }
}

void Controller::seperate_delete_comments_items(vector <string> order)
{
    information.clear();
    for(int i = 3 ; i<order.size(); i++)
    {
        pair(FILM_ID , i , order);
        pair(COMMENT_ID , i , order);
    }
}

void Controller::seperate_post_followers_items(vector <string> order)
{
    information.clear();
    for(int i = 3 ; i<order.size(); i++)
    {
        pair(USER_ID , i , order);
    }
}

void Controller::seperate_post_money_items(vector <string> order)
{
    information.clear();
    for(int i = 3 ; i<order.size(); i++)
    {
        pair(AMOUNT , i , order);
    }
}

void Controller::seperate_get_films_items(vector <string> order)
{
    information.clear();
    if(order[3] == FILM_ID)
    {
        for(int i = 3 ; i<order.size(); i++)
        {
            pair(FILM_ID , i , order);
        }
    }
    else
    {
        for(int i = 3 ; i<order.size(); i++)
        {
            pair(NAME , i , order);
            pair(MIN_RATE , i , order);
            pair(MIN_YEAR , i , order);
            pair(PRICE , i , order);
            pair(MAX_YEAR , i , order);
            pair(DIRECTOR , i , order);
        }
    }
}

void Controller::seperate_post_buy_items(vector <string> order)
{
    information.clear();
    for(int i = 3 ; i<order.size(); i++)
    {
        pair(FILM_ID , i , order);
    }
}

void Controller::seperate_post_rate_items(vector <string> order)
{
    information.clear();
    for(int i = 3 ; i<order.size(); i++)
    {
        pair(FILM_ID , i , order);
        pair(SCORE , i , order);
    }
}

void Controller::seperate_post_comments_items(vector <string> order)
{
    information.clear();
    for(int i = 3 ; i<order.size(); i++)
    {
        pair(FILM_ID , i , order);
        pair(CONTENT , i , order);
    }
}

void Controller::seperate_get_purchased_items(vector <string> order)
{
    information.clear();
    for(int i = 3 ; i<order.size(); i++)
    {
        pair(NAME , i , order);
        pair(MIN_YEAR , i , order);
        pair(PRICE , i , order);
        pair(MAX_YEAR , i , order);
        pair(DIRECTOR , i , order);
    }
}

void Controller::seperate_get_notifications_read_items(vector <string> order)
{
    information.clear();
    if(order[2].compare(READ) == 0)
        information[LIMIT] = order[5];
}

void Controller::set_data_bases()
{
    online_user = DataBase::get_instance()->get_online_user();
    online_publisher = DataBase::get_instance()->get_online_publisher();
    if_anyone_online = DataBase::get_instance()->show_if_anyone_online_status();
    admin_status = DataBase::get_instance()->show_if_admin_is_online();
    data_base_films = DataBase::get_instance()->get_data_base_films();
    accessible_films = DataBase::get_instance()->get_accessible_films();
    publishers = DataBase::get_instance()->get_publishers();
    users = DataBase::get_instance()->get_users();
    last_film_id = DataBase::get_instance()->get_last_film_id();
    last_user_id = DataBase::get_instance()->get_last_film_id();
}

string Controller::return_film_name()
{
    for(int i=0;i<accessible_films.size(); i++)
        if(accessible_films[i]->return_id() == stoi(information[FILM_ID]))
            return accessible_films[i]->name;
}

void Controller::check_numbers_validity(string str)
{
    for(int i=0;i<str.length();i++)
        if(isalpha(str[i]))
            throw BadRequest();
}

void Controller::check_if_user_is_online(int publisher_needed)
{
    if(publisher_needed == 0){
        if(online_publisher == NULL)
        {
            throw PermissionDenied();
        }
    }
    else
        if(!online_user)
            throw PermissionDenied();
}

void Controller::check_if_signingup_or_loggingin_is_possible()
{
    if(if_anyone_online)
        throw BadRequest();
}

void Controller::check_if_film_is_bought()
{
    int flag = 0;
    for(int i=0;i<online_user->return_bought_films().size(); i++)
        if(online_user->return_bought_films()[i]->return_id() == stoi(information[FILM_ID]))
            flag = 1;
    if(flag == 0)
        throw PermissionDenied();
}

void Controller::check_if_publishers_matches()
{
    int flag = 0;
    for(int i=0;i<online_publisher->return_published_films().size();i++)
        if(online_publisher->return_published_films()[i]->return_id() == stoi(information[FILM_ID]))
            flag = 1;
    if(flag == 0)
        throw PermissionDenied();
}

void Controller::check_validity_of_film_id()
{
    int flag = 0;
    for(int i=0;i<accessible_films.size();i++)
        if(accessible_films[i]->return_id() == stoi(information[FILM_ID]))
            flag = 1;
    if(flag == 0)
        throw NotFound();
}

void Controller::check_validity_of_user_id()
{
    int flag = 0;
    for(int i=0;i<users.size();i++)
        if(users[i]->return_id() == stoi(information[USER_ID]))
            flag = 1;
    if(flag == 0)
        throw NotFound();
}

void Controller::check_validity_of_comment_id()
{
    int flag = 0;
    for(int i=0;i<accessible_films.size();i++)
        if(accessible_films[i]->return_id() == stoi(information[FILM_ID]))
            for(int j=0;j<accessible_films[i]->return_comments().size();j++)
                if(accessible_films[i]->return_comments()[j]->return_comment_id() == stoi(information[COMMENT_ID]))
                    flag = 1;
    if(flag == 0)
        throw NotFound();
}

string Controller::encodePass(string pass)
{
  const int ROT13 = 13, ROT7 = 7;
  string encodedPass = pass;
  for (size_t i = 0; i < encodedPass.size(); i++)
  {
    encodedPass[i] = encodedPass[i] + ROT13;

    if (encodedPass[i] % 5 == 0)
      encodedPass[i] = encodedPass[i] + ROT7;
  }
  return encodedPass;
}