#include "post_comments.h"

using namespace std;

PostComments::PostComments() : Controller() {}

void PostComments::do_post_comments(vector<string> order)
{
    set_data_bases();
    seperate_post_comments_items(order);
    try {
        check_if_user_is_online(1);
        check_if_film_is_bought();
        check_numbers_validity(information[FILM_ID]);
        is_input_complete();
        check_validity_of_film_id();
        online_user->post_comment(stoi(information[FILM_ID]) , information[CONTENT] , return_comment_id() , data_base_films);
        exert_comments(accessible_films);
        exert_comments(data_base_films);
        send_notification();
        DataBase::get_instance()->set_accessible_films(accessible_films);
        DataBase::get_instance()->set_data_base_films(data_base_films);
        DataBase::get_instance()->set_publishers(publishers);
        DataBase::get_instance()->set_users(users);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}

void PostComments::is_input_complete()
{
    if(information[FILM_ID] == "" || information[CONTENT] == "")
        throw BadRequest();
}

int PostComments::return_comment_id()
{
    for(int i=0;i<data_base_films.size(); i++)
        if(data_base_films[i]->return_id() == stoi(information[FILM_ID]))
            return (data_base_films[i]->return_last_comment_id() + 1);
}

void PostComments::exert_comments(vector <Film*> films)
{
    for(int i=0;i<films.size(); i++)
        if(films[i]->return_id() == stoi(information[FILM_ID]))
            films[i]->add_comment(information[CONTENT] , online_user->return_id());
}

void PostComments::send_notification()
{
    for(int i=0;i<users.size();i++)
        for(int j=0;j<accessible_films.size();j++)
            if(accessible_films[j]->return_id() == stoi(information[FILM_ID]))
                if(accessible_films[j]->return_user_id() == users[i]->return_id())
                {
                    string notif;
                    notif = "User ";
                    notif.append(online_user->return_username());
                    notif.append(" with id ");
                    notif.append(to_string(online_user->return_id()));
                    notif.append(" comment on your film ");
                    notif.append(return_film_name());
                    notif.append(" with id ");
                    notif.append(information[FILM_ID]);
                    notif.append(".");
                    users[i]->add_notifications(notif);
                }
}