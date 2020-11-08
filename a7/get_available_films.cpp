#include "get_available_films.h"

using namespace std;

GetAvailableFilms::GetAvailableFilms() : Controller() {}

Response* GetAvailableFilms::callback(Request* req)
{
    set_data_bases();
    
    vector<Film*> available_films;
    for(int i=0;i<users.size();i++)
        if(users[i]->return_id() == stoi(req->getSessionId()))
        {   
            for(int j=0;j<accessible_films.size();j++)
                if(accessible_films[j]->return_price() <= users[i]->return_cash())
                    available_films.push_back(accessible_films[j]);
            for(int k=0;k<users[i]->return_bought_films().size();k++)
                for(int l=0;l<available_films.size();l++)
                    if(users[i]->return_bought_films()[k]->return_id() == available_films[l]->return_id())
                        available_films.erase(available_films.begin() + l);
        }

    Response *res = new Response;
    res->setHeader("Content-Type", "text/html");
    string body;
    body += "<!DOCTYPE html> <html> <head> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"> <style>";
    body += "body {background-image: url(\"background.png\"); background-repeat: no-repeat; background-attachment: fixed; background-position: center; background-size: cover; }";
    body += "table { font-family: arial, sans-serif; border-collapse: collapse; width: 100%; }";
    body += "td, th { border: 1px solid #dddddd; text-align: left; padding: 8px; }";
    body += "tr:nth-child(even) { background-color: #dddddd; }";
    body += ".button { background-color: #f4511e; border: none; color: white; padding: 16px 32px; text-align: center; font-size: 16px;";
    body += "margin: 4px 2px; opacity: 0.6; transition: 0.3s; display: inline-block; text-decoration: none; cursor: pointer; } .button:hover {opacity: 1}";
    body += ".button:hover {opacity: 1} a:link, a:visited { background-color: #f44336; color: white; padding: 14px 25px; text-align: center; text-decoration: none; display: inline-block;} a:hover, a:active { background-color: red; }";
    body += "</style> </head>";
    body += "<body>";
    body += "<br />";
    body += "<a href= \"/logout\" get=\"_blank\">Logout</a>";
    body += "<a href= \"/userprofile\" get=\"_blank\" >Profile</a>";
    body += "<h1>Available Films</h1>";
    body += "<table> <tr>";
    body += "<th>Film Id</th>";
    body += "<th>Name</th>";
    body += "<th>Length</th>";
    body += "<th>Price</th>";
    body += "<th>Rate</th>";
    body += "<th>Production Year</th>";
    body += "<th>Film Director</th>";
    for(int i=0;i<available_films.size();i++)
    {
        string id = to_string(available_films[i]->return_id());
        body += "<tr> <td>";
        body += "<form action=\"/get_films\" method=\"get\">";
        body += "<button class=\"button\" name=\"film_id\" type=\"submit\" value=";
        body += id;
        body += ">";
        body += id;
        body += "</button>";
        body += "</form>";
        body += "<form action=\"/post_buy\" method=\"get\">";
        body += "<button class=\"button\" name=\"film_id\" type=\"submit\" value=";
        body += id;
        body += ">buy</button>";
        body += "</form>";
        body += "</td> <td>";
        body += available_films[i]->name;
        body += "</td> <td>";
        body += to_string(available_films[i]->length);
        body += "</td> <td>";
        body += to_string(available_films[i]->return_price());
        body += "</td> <td>";
        body += to_string(available_films[i]->return_rate());
        body += "</td> <td>";
        body += to_string(available_films[i]->year);
        body += "</td> <td>";
        body += available_films[i]->director;
        body += "</td> </tr>";
    }
    body += "</table>";
    body += "</body>";
    body += "</html>";
    res->setBody(body);
    return res;
}