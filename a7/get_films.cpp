#include "get_films.h"

using namespace std;

GetFilms::GetFilms() : Controller() {}

Response* GetFilms::callback(Request* req)
{
    set_data_bases();
    int film_id = stoi(req->getQueryParam(FILM_ID));
    int user_id = stoi(req->getSessionId());
    Film* film;
    for(int i=0;i<data_base_films.size();i++)
        if(data_base_films[i]->return_id() == film_id)
            film = data_base_films[i];
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
    body += "<a href= \"/logout\" get=\"_blank\">Logout</a>";
    body += "<h1>Details Of Film ";
    body += film->name;
    body += "</h1>";
    body += "<p>Id = ";
    body += to_string(film->return_id());
    body += "</p> <p>Director = ";
    body += film->director;
    body += "</p> <p>Length = ";
    body += to_string(film->length);
    body += "</p> <p>Year = ";
    body += to_string(film->year);
    body += "</p> <p>Summary = ";
    body += film->summary;
    body += "</p> <p>Rate = ";
    body += to_string(film->return_rate());
    body += "</p> <p>Price = ";
    body += to_string(film->return_price());
    body += "</p>";
    body += "<h2>Comments</h2>";
    for(int i=0;i<film->return_comments().size();i++)
    {
        body += "<p>";
        body += to_string(film->return_comments()[i]->return_comment_id());
        body += ". ";
        body += film->return_comments()[i]->return_comment();
        body += "</p>";
    }

    body += "<form action=\"/post_comments\" method=\"post\">";
    body += "Comment : <input type=\"text\" name=\"comment\" value=>";
    body += "<input type = \"hidden\" id=\"film_id\" name=\"film_id\" value =";
    body += req->getQueryParam(FILM_ID);
    body += ">";
    body += "<button class=\"button\" type=\"submit\" style=\"display:block; width: 10%; padding: 7px;\">Post Comment</button> </form>";

    body += "<h2>Recommendation Film<h2>";
    vector<Film*> recommended = DataBase::get_instance()->recommender_system(film_id , user_id);
    int limit = recommended.size();
    if(recommended.size() >= 4)
        limit = 4;
    body += "<table> <tr>";
    body += "<th>Film Id</th>";
    body += "<th>Film Name</th>";
    body += "<th>Film Length</th>";
    body += "<th>Film Director</th>";
    for(int i=0;i<limit ; i++)
    {    
        string id = to_string(recommended[i]->return_id());
        body += "<tr> <td>";
        body += "<form action=\"/get_films\" method=\"get\">";
        body += "<button class=\"button\" name=\"film_id\" type=\"submit\" value=";
        body += id;
        body += ">";
        body += id;
        body += "</button>";
        body += "</form>";
        body += "</td> <td>";
        body += recommended[i]->name;
        body += "</td> <td>";
        body += to_string(recommended[i]->length);
        body += "</td> <td>";
        body += recommended[i]->director;
        body += "</td> </tr>";
    }
    body += "</table>";
    body += "</body>";
    body += "</html>";
    res->setBody(body);
    return res;
}