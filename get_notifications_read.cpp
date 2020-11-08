#include "get_notifications_read.h"

using namespace std;

GetNotificationsRead::GetNotificationsRead() : Controller() {}

void GetNotificationsRead::do_get_notifications_read(vector<string> order)
{
    set_data_bases();
    seperate_get_notifications_read_items(order);
    try {
        check_if_user_is_online(1);
        check_numbers_validity(information[LIMIT]);
        is_input_complete();
        online_user->show_read_notifications(stoi(information[LIMIT]));
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}

void GetNotificationsRead::is_input_complete()
{
    if(information[LIMIT] == "")
        throw BadRequest();
}