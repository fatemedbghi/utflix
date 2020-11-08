#include "post_login.h"

using namespace std;

PostLogin::PostLogin() : Controller() {}

void PostLogin::do_login(vector <string> order)
{
    set_data_bases();
    online_user = NULL;
    online_publisher = NULL;
    seperate_login_items(order);
    try{
        is_input_complete();
        does_username_exists();
        is_password_valid();
        for (int i=0; i<users.size() ; i++)
        {
            if(information[USERNAME]==users[i]->return_username())
            {
                online_user = users[i];
                DataBase::get_instance()->set_online_user(online_user);
                if(users[i]->return_if_publisher())
                    for(int j=0;j<publishers.size();j++)
                        if(information[USERNAME] == publishers[j]->return_username())
                        {
                            online_publisher = publishers[j];
                            DataBase::get_instance()->set_online_publisher(online_publisher);
                        }
            }
        }
        cout << "OK" << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}

void PostLogin::is_input_complete()
{
    if(information[USERNAME] == "" || information[PASSWORD] == "")
        throw BadRequest();
}

void PostLogin::does_username_exists()
{
    int flag = 0;
    for(int i=0;i<users.size();i++)
    {
        if(users[i]->return_username() == information[USERNAME])
            flag=1;
    }
    if(flag == 0)
        throw NotFound();
}

void PostLogin::is_password_valid()
{
    for(int i=0;i<users.size();i++)
        if(users[i]->return_username() == information[USERNAME])
            if(users[i]->return_password() != encodePass(information[PASSWORD]))
                throw BadRequest();
}