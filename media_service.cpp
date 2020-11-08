#include "media_service.h"
using namespace std;

MediaService::MediaService() {
    post_signup = new PostSignup();
    post_login = new PostLogin();
    delete_comments = new DeleteComments();
    delete_films = new DeleteFilms();
    get_films = new GetFilms();
    get_followers = new GetFollowers();
    get_notifications = new GetNotifications();
    get_notifications_read = new GetNotificationsRead();
    get_published = new GetPublished();
    get_purchased = new GetPurchased();
    post_buy = new PostBuy();
    post_comments = new PostComments();
    post_films = new PostFilms();
    post_followers = new PostFollowers();
    post_money = new PostMoney();
    post_rate = new PostRate();
    post_replies = new PostReplies();
    put_films = new PutFilms();
}

MediaService::~MediaService()
{
    delete post_signup;
    delete post_login;
    delete delete_comments;
    delete delete_films;
    delete get_films;
    delete get_followers;
    delete get_notifications;
    delete get_notifications_read;
    delete get_published;
    delete get_purchased;
    delete post_buy;
    delete post_comments;
    delete post_films;
    delete post_followers;
    delete post_money;
    delete post_rate;
    delete post_replies;
    delete put_films;
    
}

void MediaService::run()
{
    string input;
    while (getline(cin, input))
    {
        if(input.size() > 0)
        {
            order = remove_extra_spaces(input);
            order.pop_back();
            try {
                check_controllers(order[0]);
                check_url();
                call_each_url(order);
            } catch (const exception &e) {
                cout << e.what() << endl;
            }
        }
    }
}

vector <string> MediaService::remove_extra_spaces(string str)
{ 
    istringstream input(str);
    vector <string> words_of_input;
    do { 
        string word;
        input >> word;
        words_of_input.push_back(word);
    } while (input); 
    return words_of_input;
}

void MediaService::check_controllers(string controller)
{
    if (controller!="POST" && controller!="GET" && controller!="PUT" && controller!="DELETE")
        throw BadRequest();
}

void MediaService::check_url()
{
    if (order[0].compare("GET") == 0)
        check_get_url();
    if (order[0].compare("POST") == 0)
        check_post_url();
    if (order[0].compare("PUT") == 0)
        check_put_url();
    if (order[0].compare("DELETE") == 0)
        check_delete_url();
}

void MediaService::check_get_url()
{
    if (order[1]!= "followers" && order[1]!= "published" && order[1]!= "films" && order[1]!= "purchased" && order[1]!= "notifications")
        throw NotFound();
}

void MediaService::check_post_url()
{
    if (order[1]!= "signup" && order[1]!= "login" && order[1]!= "films" && order[1]!= "money"
    && order[1]!= "replies" && order[1]!= "followers" && order[1]!= "buy" && order[1]!= "rate" && order[1]!= "comments")
        throw NotFound();
}

void MediaService::check_put_url()
{
    if (order[1]!= "films")
        throw NotFound();
}

void MediaService::check_delete_url()
{
    if (order[1]!= "films" && order[1]!= "comments")
        throw NotFound();
}

void MediaService::call_each_url(std::vector <std::string> input)
{
    if (input[1] == "signup")
        post_signup->do_signup(input);
    if (input[1] == "login")
        post_login->do_login(input);
    if (input[0] == "POST" && input[1] == "films")
        post_films->do_post_films(input);
    if (input[0] == "PUT" && input[1] == "films")
        put_films->do_put_films(input);
    if (input[0] == "DELETE" && input[1] == "films")
        delete_films->do_delete_films(input);
    if (input[0] == "DELETE" && input[1] == "comments")
        delete_comments->do_delete_comments(input);
    if (input[0] == "GET" && input[1] == "followers")
        get_followers->do_get_followers();
    if (input[0] == "POST" && input[1] == "money")
        post_money->do_post_money(input);
    if (input[0] == "GET" && input[1] == "published")
        get_published->do_get_published(input);
    if (input[0] == "POST" && input[1] == "replies")
        post_replies->do_post_replies(input);
    if (input[0] == "POST" && input[1] == "followers")
        post_followers->do_post_followers(input);
    if (input[0] == "GET" && input[1] == "films")
        get_films->do_get_films(input);
    if (input[0] == "POST" && input[1] == "buy")
        post_buy->do_post_buy(input);
    if (input[0] == "POST" && input[1] == "rate")
        post_rate->do_post_rate(input);
    if (input[0] == "POST" && input[1] == "comments")
        post_comments->do_post_comments(input);
    if (input[0] == "GET" && input[1] == "purchased")
        get_purchased->do_get_purchased(input);
    if (input[0] == "GET" && input[1] == "notifications" && input.size() == 2)
        get_notifications->do_get_notifications();
    if (input[0] == "GET" && input[1] == "notifications" && input.size() > 2 && input[2] == "read")
        get_notifications_read->do_get_notifications_read(input);
}