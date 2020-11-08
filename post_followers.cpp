#include "post_followers.h"

using namespace std;

PostFollowers::PostFollowers() : Controller() {}

void PostFollowers::do_post_followers(vector <string> order)
{
    set_data_bases();
    seperate_post_followers_items(order);
    try {
        check_if_user_is_online(1);
        check_numbers_validity(information[USER_ID]);
        is_input_complete();
        check_validity_of_user_id();
        for(int i=0;i<publishers.size();i++)
            if(publishers[i]->return_id() == stoi(information[USER_ID]))
            {
                online_user->follow_publisher(publishers[i]);
                publishers[i]->add_followers(online_user);
                send_notification();
                DataBase::get_instance()->set_users(users);
                DataBase::get_instance()->set_publishers(publishers);
            }
    } catch(const exception& e) {
        cout << e.what() << endl;
    }
}

void PostFollowers::is_input_complete()
{
    if(information[USER_ID] == "")
        throw BadRequest();
}

void PostFollowers::send_notification()
{
    for(int i=0;i < users.size();i++)
        if(stoi(information[USER_ID]) == users[i]->return_id())
        {
            string notif;
            notif = "User ";
            notif.append(online_user->return_username());
            notif.append(" with id ");
            notif.append(to_string(online_user->return_id()));
            notif.append(" follow you.");
            users[i]->add_notifications(notif);
        }
}