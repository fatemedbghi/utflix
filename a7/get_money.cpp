#include "get_money.h"

using namespace std;

GetMoney::GetMoney() : Controller() {}

Response* GetMoney::callback(Request* req)
{
    set_data_bases();
    Response* res = new Response;
    for(int i=0;i<publishers.size();i++)
        if(DataBase::get_instance()->get_publishers()[i]->return_id() == stoi(req->getSessionId()))
        {
            Admin::get_admin_instance()->add_cash_from_profit(DataBase::get_instance()->get_publishers()[i]->return_unsetteled_money() , -1);
            DataBase::get_instance()->get_publishers()[i]->get_money_from_media_service();
            for(int j=0;j<users.size();j++)
                if(DataBase::get_instance()->get_users()[j]->return_id() == stoi(req->getSessionId()))
                    DataBase::get_instance()->get_users()[j]->add_money(publishers[i]->return_unsetteled_money());
            res = Response::redirect("/publisher");
            return res;
        }
}