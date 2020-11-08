#include "get_purchased.h"

using namespace std;

GetPurchased::GetPurchased() : Controller() {}

Response* GetPurchased::callback(Request* req)
{
    set_data_bases();
    vector<Film*> bought_films;
    for(int i=0;i<users.size();i++)
        if(users[i]->return_id() == stoi(req->getSessionId()))
            bought_films = users[i]->return_bought_films();
    Response *res = new Response;
    res->setHeader("Content-Type", "text/html");
    string body;
    body += "<!DOCTYPE html> <html> <head> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"> <style>";
    body += "body {background-image: url(\"background.png\"); background-repeat: no-repeat; background-attachment: fixed; background-position: center; background-size: cover; }";
    body += "table { font-family: arial, sans-serif; border-collapse: collapse; width: 100%; }";
    body += "td, th { border: 1px solid #dddddd; text-align: left; padding: 8px; }";
    body += "tr:nth-child(even) { background-color: #dddddd; }";
    body += ".button { background-color: #f4511e; border: none; color: white; padding: 16px 32px; text-align: center; font-size: 16px;";
    body += ".button:hover {opacity: 1} a:link, a:visited { background-color: #f44336; color: white; padding: 14px 25px; text-align: center; text-decoration: none; display: inline-block;} a:hover, a:active { background-color: red; }";    
    body += "margin: 4px 2px; opacity: 0.6; transition: 0.3s; display: inline-block; text-decoration: none; cursor: pointer; } .button:hover {opacity: 1}";
    body += ".button:hover {opacity: 1} a:link, a:visited { background-color: #f44336; color: white; padding: 14px 25px; text-align: center; text-decoration: none; display: inline-block;} a:hover, a:active { background-color: red; }";
    body += "</style> </head>";
    body += "<body>";
    body += "<br /> <a href=";
    body += "/logout";
    body += ">Logout</a>";
    body += "<a href=";
    body += "/user";
    body += ">Home Page</a>";
    body += "<a href=";
    body += "/post_money";
    body += ">Post Money</a>";
    body += "<h1>bought Films</h1>";
    body += "<table> <tr>";
    body += "<th>Film Id</th>";
    body += "<th>Name</th>";
    body += "<th>Length</th>";
    body += "<th>Price</th>";
    body += "<th>Rate</th>";
    body += "<th>Production Year</th>";
    body += "<th>Film Director</th>";
    for(int i=0;i<bought_films.size();i++)
    {
        string id = to_string(bought_films[i]->return_id());
        body += "<tr> <td>";
        body += "<form action=\"/get_films\" method=\"get\">";
        body += "<button class=\"button\" name=\"film_id\" type=\"submit\" value=";
        body += id;
        body += ">";
        body += id;
        body += "</button>";
        body += "</form>";
        body += "<form action=\"/post_rate\" method=\"post\">";
        body += "Rate : <input type=\"number\" min=\"1\" max=\"10\" name=\"rate\" value=>";
        body += "<input type = \"hidden\" id=\"film_id\" name=\"film_id\" value =";
        body += id;
        body += ">";
        body += "<button class=\"button\" type=\"submit\" style=\"display:block; width: 15%; padding: 7px;\">Rate";
        body += "</button> </form>";
        body += "</td> <td>";
        body += bought_films[i]->name;
        body += "</td> <td>";
        body += to_string(bought_films[i]->length);
        body += "</td> <td>";
        body += to_string(bought_films[i]->return_price());
        body += "</td> <td>";
        body += to_string(bought_films[i]->return_rate());
        body += "</td> <td>";
        body += to_string(bought_films[i]->year);
        body += "</td> <td>";
        body += bought_films[i]->director;
        body += "</td> </tr>";
    }
    body += "</table>";
    body += "</body>";
    body += "</html>";
    res->setBody(body);
    return res;
}