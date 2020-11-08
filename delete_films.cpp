#include "delete_films.h"

using namespace std;

DeleteFilms::DeleteFilms() : Controller() {}

void DeleteFilms::do_delete_films(vector<string> order)
{
    set_data_bases();
    seperate_delete_films_items(order);
    try {
        is_input_complete();
        check_if_user_is_online(0);
        check_numbers_validity(information[FILM_ID]);
        check_if_publishers_matches();
        online_publisher->delete_film(stoi(information[FILM_ID]));
        DataBase::get_instance()->set_publishers(publishers);
        update_accessible_films();
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}

void DeleteFilms::is_input_complete()
{
    if(information[FILM_ID] == "")
        throw BadRequest();
}

void DeleteFilms::update_accessible_films()
{
    for(int i=0;i<accessible_films.size() ; i++)
        if(accessible_films[i]->return_id() == stoi(information[FILM_ID]))
            accessible_films.erase(accessible_films.begin() + i , accessible_films.end() - (accessible_films.size() - i -1));
    DataBase::get_instance()->set_accessible_films(accessible_films);
}