#include "put_films.h"

using namespace std;

PutFilms::PutFilms() : Controller() {}

void PutFilms::do_put_films(vector<string> order)
{
    set_data_bases();
    seperate_put_films_items(order);
    try {
        check_if_user_is_online(0);
        check_numbers_validity(information[FILM_ID]);
        check_numbers_validity(information[YEAR]);
        check_numbers_validity(information[LENGTH]);
        check_if_publishers_matches();
        is_input_complete();
        filter_films();
        online_publisher->edit_film(stoi(information[FILM_ID]) ,information[NAME] ,year , length, information[SUMMARY] , information[DIRECTOR]);
        DataBase::get_instance()->set_publishers(publishers);
        DataBase::get_instance()->set_data_base_films(exert_edit_film(data_base_films));
        DataBase::get_instance()->set_accessible_films(exert_edit_film(accessible_films));
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

}

void PutFilms::is_input_complete()
{
    if(information[FILM_ID] == "")
        throw BadRequest();
}

void PutFilms::filter_films()
{
    year = -1;
    length = -1;
    if(information[YEAR] != "")
        year = stoi(information[YEAR]);
    if(information[LENGTH] != "")
        length = stoi(information[LENGTH]);
}

vector<Film*> PutFilms::exert_edit_film(vector<Film*> films)
{
    for(int i=0; i<films.size(); i++)
        if(films[i]->return_id() == stoi(information[FILM_ID]))
        {
            if(information[NAME] != "")
                films[i]->name = information[NAME];
            if(year != -1)
                films[i]->year = year;
            if(length != -1)
                films[i]->length = length;
            if(information[SUMMARY] != "")
                films[i]->summary = information[SUMMARY];
            if(information[DIRECTOR] != "")
                films[i]->director = information[DIRECTOR];
        }
    return films;
}