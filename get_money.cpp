#include "get_money.h"

using namespace std;

GetMoney::GetMoney() : Controller() {}

void GetMoney::do_get_money(vector<string> order)
{
    set_data_bases();
    try{
        if(order.size() > 2)
            throw BadRequest();
        if(admin_status)
            cout << Admin::get_admin_instance()->return_cash() << endl;
        if(!admin_status)
        {
            check_if_user_is_online(1);
            if(online_publisher != NULL)
                cout << online_publisher->return_cash() << endl;
            if(online_publisher == NULL)
                cout << online_user->return_cash() << endl;
        }
    } catch(const exception& e) {
        cout << e.what() << endl;
    }
}
