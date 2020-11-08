#include "get_published.h"

using namespace std;

GetPublished::GetPublished() : Controller() {}

void GetPublished::do_get_published(vector<string> order)
{
    set_data_bases();
    try {
        check_if_user_is_online(0);
        seperate_get_published_items(order);
        check_numbers_validity(information[MIN_RATE]);
        check_numbers_validity(information[MIN_YEAR]);
        check_numbers_validity(information[PRICE]);
        check_numbers_validity(information[MAX_YEAR]);
        min_rate = min_year = max_year = price = -1;
        if(information[MIN_RATE] != "")
            min_rate = stoi(information[MIN_RATE]);
        if(information[MIN_YEAR] != "")
            min_year = stoi(information[MIN_YEAR]);
        if(information[MAX_YEAR] != "")
            max_year = stoi(information[MAX_YEAR]);
        if(information[PRICE] != "")
            price = stoi(information[PRICE]);
        online_publisher->show_published_films(information[NAME] , min_rate, min_year,price , max_year,information[DIRECTOR]);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}