#include "get_followers.h"

using namespace std;

GetFollowers::GetFollowers() : Controller() {}

void GetFollowers::do_get_followers()
{
    set_data_bases();
    try{
        check_if_user_is_online(0);
        online_publisher->show_followers();
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}