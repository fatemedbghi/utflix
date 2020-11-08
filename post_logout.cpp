#include "post_logout.h"

using namespace std;

PostLogout::PostLogout() : Controller() {}

void PostLogout::do_logout(vector<string> order)
{
    set_data_bases();
    try{
        if(order.size() > 2)
            throw BadRequest();
        if(!if_anyone_online)
            throw BadRequest();
        online_user = NULL;
        online_publisher = NULL;
        if_anyone_online = false;
        admin_status = false;
        DataBase::get_instance()->set_online_user(online_user);
        DataBase::get_instance()->set_online_publisher(online_publisher);
        DataBase::get_instance()->set_online_status(if_anyone_online);
        cout << "OK" << endl;
    } catch(const exception& e) {
        cout << e.what() << endl;
    }
}
