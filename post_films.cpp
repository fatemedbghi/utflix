#include "post_films.h"

using namespace std;

PostFilms::PostFilms() : Controller() {
}

void PostFilms::do_post_films(vector <string> order)
{
    set_data_bases();
    last_film_id++;
    seperate_post_films_items(order);
    try {
        check_if_user_is_online(0);
        is_input_complete();
        check_numbers_validity(information[YEAR]);
        check_numbers_validity(information[LENGTH]);
        check_numbers_validity(information[PRICE]);
        int year = stoi(information[YEAR]);
        int length = stoi(information[LENGTH]);
        int price = stoi(information[PRICE]);
        data_base_films.push_back(new Film(information[NAME] , year , length , price , information[SUMMARY] , information[DIRECTOR] , last_film_id , online_publisher->return_id()));
        accessible_films.push_back(new Film(information[NAME] , year , length , price , information[SUMMARY] , information[DIRECTOR] , last_film_id , online_publisher->return_id()));
        DataBase::get_instance()->set_data_base_films(data_base_films);
        DataBase::get_instance()->set_accessible_films(accessible_films);
        online_publisher->upload_film(information[NAME] , year , length , price , information[SUMMARY] , information[DIRECTOR] , last_film_id);
        send_notification();
        DataBase::get_instance()->set_publishers(publishers);
        DataBase::get_instance()->set_last_film_id(last_film_id);
        DataBase::get_instance()->set_users(users);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}

void PostFilms::is_input_complete()
{
    if(information[NAME] == "" || information[YEAR] == "" || information[LENGTH] == "" ||
    information[PRICE] == "" || information[SUMMARY] == "" || information[DIRECTOR] == "")
        throw BadRequest();
}

void PostFilms::send_notification()
{
    for(int i=0;i<online_publisher->return_followers().size() ; i++)
        {
            string notif;
            notif = "Publisher ";
            notif.append(online_publisher->return_username());
            notif.append(" with id ");
            notif.append(to_string(online_publisher->return_id()));
            notif.append(" register new film.");
            online_publisher->return_followers()[i]->add_notifications(notif);
        }
}