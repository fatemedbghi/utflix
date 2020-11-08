#include "get_films.h"

using namespace std;

GetFilms::GetFilms() : Controller() {}

void GetFilms::do_get_films(vector<string> order)
{
    set_data_bases();
    seperate_get_films_items(order);
    try {
        check_if_user_is_online(1);
        if(order[3] == FILM_ID)
        {
            check_validity_of_film_id();
            check_numbers_validity(information[FILM_ID]);
            if(order.size() != 5)
                throw BadRequest();
            online_user->show_film_details(stoi(information[FILM_ID]) , accessible_films);
        }
        else
        {
            min_rate = min_year = max_year = price = -1;
            check_numbers_validity(information[MIN_RATE]);
            check_numbers_validity(information[MIN_YEAR]);
            check_numbers_validity(information[MAX_YEAR]);
            check_numbers_validity(information[PRICE]);
            set_inputs();
            online_user->search_films(information[NAME] , min_rate, min_year, price, max_year, information[DIRECTOR] , accessible_films);
        }
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

}

void GetFilms::set_inputs()
{
    if(information[MIN_RATE] != "")
        min_rate = stoi(information[MIN_RATE]);
    if(information[MIN_YEAR] != "")
        min_year = stoi(information[MIN_YEAR]);
    if(information[MAX_YEAR] != "")
        max_year = stoi(information[MAX_YEAR]);
    if(information[PRICE] != "")
        price = stoi(information[PRICE]);
}