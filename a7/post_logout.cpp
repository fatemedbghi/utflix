#include "post_logout.h"

using namespace std;

PostLogout::PostLogout() : Controller() {}

Response* PostLogout::callback(Request* req)
{
    set_data_bases();
    Response *res = new Response;
    is_publisher = false;
    if_anyone_online = false;
    admin_status = false;
    DataBase::get_instance()->set_online_status(if_anyone_online);
    res->setHeader("Content-Type", "text/html");
    res->setSessionId("123");
    res->setBody(readFile("static/login.html"));
    return res;
}
