#include "post_rate.h"

using namespace std;

PostRate::PostRate() : Controller() {}

Response* PostRate::callback(Request* req)
{
    set_data_bases();
    Response* res = new Response;
        exert_rate(req);
    res = Response::redirect("/userprofile");
    return res;
}

void PostRate::exert_rate(Request* req)
{
    for(int i=0;i<accessible_films.size();i++)
        if(accessible_films[i]->return_id() == stoi(req->getBodyParam(FILM_ID)))
        {
            accessible_films[i]->calculate_rate(stoi(req->getBodyParam(RATE)));
            for(int j=0;j<data_base_films.size();j++)
                if(data_base_films[j]->return_id() == stoi(req->getBodyParam(FILM_ID)))
                    data_base_films[i]->calculate_rate(stoi(req->getBodyParam(RATE)));
            DataBase::get_instance()->set_accessible_films(accessible_films);
            DataBase::get_instance()->set_data_base_films(data_base_films);
        }
}