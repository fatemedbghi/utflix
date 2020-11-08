#include "post_comments.h"

using namespace std;

PostComments::PostComments() : Controller() {}

Response* PostComments::callback(Request* req)
{
    set_data_bases();
    Response* res = new Response;
    exert_comments(accessible_films , req);
    exert_comments(data_base_films , req);
    DataBase::get_instance()->set_accessible_films(accessible_films);
    DataBase::get_instance()->set_data_base_films(data_base_films);
    res = Response::redirect("/userprofile");
    return res;
}

void PostComments::exert_comments(vector <Film*> films , Request* req)
{
    for(int i=0;i<films.size(); i++)
        if(films[i]->return_id() == stoi(req->getBodyParam(FILM_ID)))
            films[i]->add_comment(req->getBodyParam("comment"));
}