#include "post_money.h"

using namespace std;

PostMoney::PostMoney() : Controller() {}

void PostMoney::do_post_money(vector <string> order)
{
    set_data_bases();
    if(order.size() > 2)
    {
        seperate_post_money_items(order);
        try {
            check_numbers_validity(information[AMOUNT]);
            is_input_complete();
            online_user->add_money(stoi(information[AMOUNT]));
            if(online_publisher != NULL)
            {
                online_publisher->add_money(stoi(information[AMOUNT]));
            }
            cout << "OK" <<endl;
        } catch(const exception& e) {
            cout << e.what() << endl;
        }
    }
    else
    {
        check_if_user_is_online(0);
        Admin::get_admin_instance()->add_cash_from_profit(online_publisher->return_unsetteled_money() , -1);
        online_publisher->get_money_from_media_service();
        online_user->add_money(online_publisher->return_unsetteled_money());
    }
    DataBase::get_instance()->set_online_user(online_user);
    DataBase::get_instance()->set_online_publisher(online_publisher);
    DataBase::get_instance()->set_publishers(publishers);
    DataBase::get_instance()->set_users(users);
}

void PostMoney::is_input_complete()
{
    if(information[AMOUNT] == "")
        throw BadRequest();
}