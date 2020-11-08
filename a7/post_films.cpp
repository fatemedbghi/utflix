#include "post_films.h"

using namespace std;

PostFilms::PostFilms() : Controller() {
}

Response* PostFilms::callback(Request* req)
{
    set_data_bases();
    last_film_id++;
    Response* res = new Response;
    int year = stoi(req->getBodyParam(YEAR));
    int length = stoi(req->getBodyParam(LENGTH));
    int price = stoi(req->getBodyParam(PRICE));
    int user_id = stoi(req->getSessionId());
    data_base_films.push_back(new Film(req->getBodyParam(NAME) , year , length , price , req->getBodyParam(SUMMARY) , req->getBodyParam(DIRECTOR) , last_film_id , user_id));
    accessible_films.push_back(new Film(req->getBodyParam(NAME) , year , length , price , req->getBodyParam(SUMMARY) , req->getBodyParam(DIRECTOR) , last_film_id , user_id));
    DataBase::get_instance()->set_data_base_films(data_base_films);
    DataBase::get_instance()->set_accessible_films(accessible_films);
    for(int i=0;i<DataBase::get_instance()->get_publishers().size();i++)
        if(DataBase::get_instance()->get_publishers()[i]->return_id() == user_id)
            DataBase::get_instance()->get_publishers()[i]->upload_film(req->getBodyParam(NAME) , year , length , price , req->getBodyParam(SUMMARY) , req->getBodyParam(DIRECTOR) , last_film_id);
    DataBase::get_instance()->set_last_film_id(last_film_id);
    res = Response::redirect("/publisher");
    return res;
}