#include "post_buy.h"

using namespace std;

PostBuy::PostBuy() : Controller() {}

Response* PostBuy::callback(Request* req)
{
    set_data_bases();
    Response* res = new Response;
    DataBase::get_instance()->update_recommender_system(stoi(req->getQueryParam(FILM_ID)), stoi(req->getSessionId()));
    for(int i=0;i<users.size();i++)
        if(DataBase::get_instance()->get_users()[i]->return_id() == stoi(req->getSessionId()))
            DataBase::get_instance()->get_users()[i]->buy_film(stoi(req->getQueryParam(FILM_ID)), accessible_films);
    send_money(req);
    res = Response::redirect("/user");
    return res;
}

void PostBuy::send_money(Request* req)
{
    for(int i=0;i < publishers.size();i++)
        for(int j=0;j<accessible_films.size();j++)
            if(accessible_films[j]->return_id() == stoi(req->getQueryParam(FILM_ID)))
                if(accessible_films[j]->return_user_id() == publishers[i]->return_id())
                {
                    DataBase::get_instance()->get_publishers()[i]->calculate_unsetteled_money(accessible_films[j]->return_price() , accessible_films[j]->return_status());
                    Admin::get_admin_instance()->add_cash_from_profit(accessible_films[j]->return_price() , 1);
                }
}