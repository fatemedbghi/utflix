#include "get_purchased.h"

using namespace std;

GetPurchased::GetPurchased() : Controller() {}

void GetPurchased::do_get_purchased(vector<string> order)
{
    set_data_bases();
    try {
        check_if_user_is_online(1);
        seperate_get_purchased_items(order);
        check_numbers_validity(information[MIN_YEAR]);
        check_numbers_validity(information[MAX_YEAR]);
        check_numbers_validity(information[PRICE]);
        min_year = max_year = price = -1;
        if(information[MIN_YEAR] != "")
            min_year = stoi(information[MIN_YEAR]);
        if(information[MAX_YEAR] != "")
            max_year = stoi(information[MAX_YEAR]);
        if(information[PRICE] != "")
            price = stoi(information[PRICE]);
        online_user->get_purchased_films(information[NAME] , price, min_year, max_year, information[DIRECTOR]);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}