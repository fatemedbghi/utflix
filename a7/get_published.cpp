#include "get_published.h"

using namespace std;

GetPublished::GetPublished() : Controller() {}

Response* GetPublished::callback(Request* req)
{
    set_data_bases();
    vector <Film*> published_films;
    for(int i=0;i<publishers.size();i++)
        if(publishers[i]->return_id() == stoi(req->getSessionId()))
                published_films = publishers[i]->show_published_films(req->getQueryParam(DIRECTOR));
        Response *res = new Response;
        res->setHeader("Content-Type", "text/html");
        string body;
        body += "<!DOCTYPE html> <html> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"> <head> <style>";
        body += "body {background-image: url(\"background.png\"); background-repeat: no-repeat; background-attachment: fixed; background-position: center; background-size: cover; }";
        body += "table { font-family: arial, sans-serif; border-collapse: collapse; width: 100%; }";
        body += "td, th { border: 1px solid #dddddd; text-align: left; padding: 8px; }";
        body += "tr:nth-child(even) { background-color: #dddddd; }";
        body += ".button { background-color: #f4511e; border: none; color: white; padding: 16px 32px; text-align: center; font-size: 16px;";
        body += "margin: 4px 2px; opacity: 0.6; transition: 0.3s; display: inline-block; text-decoration: none; cursor: pointer; } .button:hover {opacity: 1}";
        body += ".button:hover {opacity: 1} a:link, a:visited { background-color: #f44336; color: white; padding: 14px 25px; text-align: center; text-decoration: none; display: inline-block;} a:hover, a:active { background-color: red; }";
        body += "</style> </head> <body>";
        body += "<a href=";
        body += "/logout";
        body += " >Logout</a>";
        body += " <a href=";
        body += "/post_films";
        body += ">Post New Film</a>";
        body += " <a href=";
        body += "/get_money";
        body += ">Get Money From MediaService</a>";
        body += "<h1>Published Films</h1>";
        body += "<table> <tr>";
        body += "<th>Film Id</th>";
        body += "<th>Name</th>";
        body += "<th>Length</th>";
        body += "<th>Price</th>";
        body += "<th>Rate</th>";
        body += "<th>Production Year</th>";
        body += "<th>Film Director</th>";
        for(int i=0;i<published_films.size();i++)
        {
            string id = to_string(published_films[i]->return_id());
            body += "<tr> <td>";
            body += "<form action=\"/get_films\" method=\"get\">";
            body += "<button class=\"button\" name=\"film_id\" type=\"submit\" value=";
            body += id;
            body += ">";
            body += id;
            body += "</button>";
            body += "</form>";
            body += "<form action=\"/delete_films\" method=\"get\">";
            body += "<button class=\"button\" name=\"film_id\" type=\"submit\" value=";
            body += id;
            body += ">delete</button>";
            body += "</form>";
            body += "</td> <td>";
            body += published_films[i]->name;
            body += "</td> <td>";
            body += to_string(published_films[i]->length);
            body += "</td> <td>";
            body += to_string(published_films[i]->return_price());
            body += "</td> <td>";
            body += to_string(published_films[i]->return_rate());
            body += "</td> <td>";
            body += to_string(published_films[i]->year);
            body += "</td> <td>";
            body += published_films[i]->director;
            body += "</td> </tr>";
        }
        body += "</table>";
        body += "<form action=\"/publisher\" method=\"get\">";
        body += "<h1>Filter Films</h1>";
        body += "<label for=\"director\"><b>Director</b></label>";
        body += "<input type=\"text\" placeholder=\"Enter Director\" name=\"director\" required>";
        body += "<button class=\"button\" type=\"submit\" style=\"display:block; width: 20%; padding: 7px;\">Filter</button>";
        body += "<button class=\"button\" type=\"reset\" style=\"display:block; width: 20%; padding: 7px;\">Reset</button></form>";
        body += "</body>";
        body += "</html>";
        res->setBody(body);
        return res;

}