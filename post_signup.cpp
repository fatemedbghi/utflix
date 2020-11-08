#include "post_signup.h"

using namespace std;

PostSignup::PostSignup() : Controller (), user_id(0) {}

void PostSignup::do_signup(vector <string> order)
{
    set_data_bases();
    online_user = NULL;
    online_publisher = NULL;
    seperate_signup_items(order); 
    try {
        if_username_exists(information[USERNAME]);
        is_input_complete();
        is_email_valid();
        user_id++;
        check_numbers_validity(information[AGE]);
        int age = stoi(information[AGE]);
        bool is_publisher = false;
        is_publisher = is_user_publishr();
        if (is_publisher)
        {
            publishers.push_back(new Publisher(information[EMAIL] , information[USERNAME] , encodePass(information[PASSWORD]) ,age ,is_publisher , user_id));
            DataBase::get_instance()->set_publishers(publishers);
            online_publisher = publishers[publishers.size() - 1];
            DataBase::get_instance()->set_online_publisher(online_publisher);
        } 
        users.push_back(new User(information[EMAIL] , information[USERNAME] , encodePass(information[PASSWORD]) ,age ,is_publisher , user_id));
        DataBase::get_instance()->set_users(users);
        online_user = users[users.size() - 1];
        DataBase::get_instance()->set_online_user(online_user);
        DataBase::get_instance()->set_last_user_id(user_id);
        cout << "OK" << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}

void PostSignup::if_username_exists(string username)
{
    for(int i=0;i<users.size(); i++)
        if(users[i]->return_username() == username)
            throw BadRequest();
}

void PostSignup::is_email_valid()
{
    if(!email(information[EMAIL]))
        throw BadRequest();
}

bool PostSignup::email(const string& email)
{
   const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
   return std::regex_match(email, pattern);
}

bool PostSignup::is_user_publishr()
{
    if (information[PUBLISHER] == "true")
        return true;
}

void PostSignup::is_input_complete()
{
    if(information[EMAIL] == "" || information[USERNAME] == "" || information[PASSWORD] == "" || information[AGE] == "")
        throw BadRequest();
}
