#include "post_buy.h"

using namespace std;

PostBuy::PostBuy() : Controller() {}

void PostBuy::do_post_buy(vector<string> order)
{
    set_data_bases();
    seperate_post_buy_items(order);
    try {
        check_if_user_is_online(1);
        check_numbers_validity(information[FILM_ID]);
        is_input_complete();
        check_validity_of_film_id();
        online_user->buy_film(stoi(information[FILM_ID]), accessible_films);
        send_notification();
        DataBase::get_instance()->set_users(users);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}

void PostBuy::is_input_complete()
{
    if(information[FILM_ID] == "")
        throw BadRequest();
}

void PostBuy::send_notification()
{
    for(int i=0;i < users.size();i++)
        for(int j=0;j<accessible_films.size();j++)
            if(accessible_films[j]->return_id() == stoi(information[FILM_ID]))
                if(accessible_films[j]->return_user_id() == users[i]->return_id())
                {
                    string notif;
                    notif = "User ";
                    notif.append(online_user->return_username());
                    notif.append(" with id ");
                    notif.append(to_string(online_user->return_id()));
                    notif.append(" buy your film ");
                    notif.append(return_film_name());
                    notif.append(" with id ");
                    notif.append(information[FILM_ID]);
                    notif.append(".");
                    users[i]->add_notifications(notif);
                }
}