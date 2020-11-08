#include "delete_films.h"

using namespace std;

DeleteFilms::DeleteFilms() : Controller() {}

Response* DeleteFilms::callback(Request* req)
{
    set_data_bases();
    Response* res = new Response;
    for(int i=0;i<publishers.size();i++)
        if(publishers[i]->return_id() == stoi(req->getSessionId()))
            DataBase::get_instance()->get_publishers()[i]->delete_film(stoi(req->getQueryParam(FILM_ID)));
    update_accessible_films(req);
    res = Response::redirect("/publisher");
    return res;
}

void DeleteFilms::update_accessible_films(Request* req)
{
    for(int i=0;i<accessible_films.size() ; i++)
        if(accessible_films[i]->return_id() == stoi(req->getQueryParam(FILM_ID)))
            accessible_films.erase(accessible_films.begin() + i , accessible_films.end() - (accessible_films.size() - i -1));
    DataBase::get_instance()->set_accessible_films(accessible_films);
}