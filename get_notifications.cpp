#include "get_notifications.h"

using namespace std;

GetNotifications::GetNotifications() : Controller() {}

void GetNotifications::do_get_notifications()
{
    set_data_bases();
    try {
        check_if_user_is_online(1);
        online_user->show_unread_notifications();
        DataBase::get_instance()->set_users(users);
        DataBase::get_instance()->set_publishers(publishers);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}