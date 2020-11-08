#include "post_login.h"

using namespace std;

PostLogin::PostLogin() : Controller() {}

Response* PostLogin::callback(Request* req)
{
    set_data_bases();
    Response* res = new Response;
    int session_id;
    if(req->getBodyParam(USERNAME) == "admin" && req->getBodyParam(PASSWORD) == "admin")
    {
        admin_status = true;
        if_anyone_online = true;
        DataBase::get_instance()->set_admin_status(admin_status);
        DataBase::get_instance()->set_online_status(if_anyone_online);
        res = Response::redirect("/admin");
    }
    else
    {
        int flag = 0;
        for (int i=0; i<users.size() ; i++)
            if(req->getBodyParam(USERNAME)==users[i]->return_username() && encodePass(req->getBodyParam(PASSWORD))==users[i]->return_password())
                flag = 1;

        if(flag == 1)
        {
            for (int i=0; i<users.size() ; i++)
            {
                if(req->getBodyParam(USERNAME)==users[i]->return_username() && encodePass(req->getBodyParam(PASSWORD))==users[i]->return_password())
                {
                    session_id = users[i]->return_id();
                    if_anyone_online = true;
                    DataBase::get_instance()->set_online_status(if_anyone_online);
                    if(users[i]->return_if_publisher())
                        for(int j=0;j<publishers.size();j++)
                            if(req->getBodyParam(USERNAME) == publishers[j]->return_username())
                            {
                                is_publisher = true;
                                DataBase::get_instance()->set_if_publisher(true);
                            }
                }
            }
            if(is_publisher)
                res = Response::redirect("/publisher");
            else
                res = Response::redirect("/user");
            res->setSessionId(to_string(session_id));
        }
        if(flag == 0)
            res = Response::redirect("/login_error");
        
    }
    return res;
}