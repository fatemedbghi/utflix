#include "post_money.h"

using namespace std;

PostMoney::PostMoney() : Controller() {}

Response* PostMoney::callback(Request* req)
{
    set_data_bases();
    Response* res = new Response;
    DataBase::get_instance()->get_users()[stoi(req->getSessionId()) - 1]->add_money(stoi(req->getBodyParam(AMOUNT)));
    if(is_publisher)
        for(int i=0;i<DataBase::get_instance()->get_publishers().size();i++)
            if(DataBase::get_instance()->get_publishers()[i]->return_id() == stoi(req->getSessionId()))
                DataBase::get_instance()->get_publishers()[i]->add_money(stoi(req->getBodyParam(AMOUNT)));
    res = Response::redirect("/user");
    return res;
}