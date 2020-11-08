#include "post_rate.h"

using namespace std;

PostRate::PostRate() : Controller() {}

void PostRate::do_post_rate(vector<string> order)
{
    set_data_bases();
    seperate_post_rate_items(order);
    try {
        check_if_user_is_online(1);
        check_numbers_validity(information[FILM_ID]);
        check_numbers_validity(information[SCORE]);
        check_if_film_is_bought();
        is_input_complete();
        check_validity_of_film_id();
        check_score_validity();
        online_user->rate_film(stoi(information[FILM_ID]) , stoi(information[SCORE]) , accessible_films);
        exert_rate();
        send_notification();
        DataBase::get_instance()->set_accessible_films(accessible_films);
        DataBase::get_instance()->set_data_base_films(data_base_films);
        DataBase::get_instance()->set_users(users);
        DataBase::get_instance()->set_publishers(publishers);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}

void PostRate::is_input_complete()
{
    if(information[FILM_ID] == "" || information[SCORE] == "")
        throw BadRequest();
}

void PostRate::exert_rate()
{
    for(int i=0;i<accessible_films.size();i++)
    if(accessible_films[i]->return_id() == stoi(information[FILM_ID]))
    {
        accessible_films[i]->calculate_rate(stof(information[SCORE]));
        for(int j=0;j<data_base_films.size();j++)
            if(data_base_films[j]->return_id() == stoi(information[FILM_ID]))
                data_base_films[i]->calculate_rate(stof(information[SCORE]));
    DataBase::get_instance()->set_accessible_films(accessible_films);
    DataBase::get_instance()->set_data_base_films(data_base_films);
    }
}

void PostRate::send_notification()
{
    for(int i=0;i<users.size();i++)
        for(int j=0;j<accessible_films.size();j++)
            if(accessible_films[j]->return_id() == stoi(information[FILM_ID]))
                if(accessible_films[j]->return_user_id() == users[i]->return_id())
                {
                    string notif;
                    notif = "User ";
                    notif.append(online_user->return_username());
                    notif.append(" with id ");
                    notif.append(to_string(online_user->return_id()));
                    notif.append(" rate your film ");
                    notif.append(return_film_name());
                    notif.append(" with id ");
                    notif.append(information[FILM_ID]);
                    notif.append(".");
                    users[i]->add_notifications(notif);
                }
}

void PostRate::check_score_validity()
{
    int film_score = stoi(information[SCORE]);
    if(film_score > 10 || film_score < 1)
        throw BadRequest();
}