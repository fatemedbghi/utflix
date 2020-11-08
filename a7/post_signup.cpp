#include "post_signup.h"

using namespace std;

PostSignup::PostSignup() : Controller (), user_id(0) {}

Response* PostSignup::callback(Request* req)
{
    set_data_bases();
    Response* res = new Response;
    if(req->getBodyParam(USERNAME) == "admin")
        res = Response::redirect("/invalid_username");
    else
    {
        if(req->getBodyParam(PASSWORD) != req->getBodyParam("password-repeat"))
            res = Response::redirect("/signup_error");
        else
        {
            user_id++;
            int age = stoi(req->getBodyParam(AGE));
            bool is_publisher;
            is_publisher = is_user_publisher(req);
            if (is_publisher == true)
            {
                publishers.push_back(new Publisher(req->getBodyParam(EMAIL) , req->getBodyParam(USERNAME) , encodePass(req->getBodyParam(PASSWORD)) ,age ,is_publisher , user_id));
                DataBase::get_instance()->set_publishers(publishers[publishers.size() - 1]);
                DataBase::get_instance()->set_if_publisher(is_publisher);
            } 
            users.push_back(new User(req->getBodyParam(EMAIL) , req->getBodyParam(USERNAME) , encodePass(req->getBodyParam(PASSWORD)) ,age ,is_publisher , user_id));
            if_anyone_online = true;
            DataBase::get_instance()->set_users(users[users.size() - 1]);
            DataBase::get_instance()->set_online_status(if_anyone_online);
            DataBase::get_instance()->set_last_user_id(user_id);
            if(is_publisher)
                res = Response::redirect("/publisher");
            else
                res = Response::redirect("/user");
            res->setSessionId(to_string(user_id));
            DataBase::get_instance()->set_if_publisher(false);
        }
    }
    return res;    
}

bool PostSignup::is_user_publisher(Request* req)
{
    if (req->getBodyParam(PUBLISHER) == "on")
        return true;
    else 
        return false;
}