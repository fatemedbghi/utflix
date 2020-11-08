#include "post_replies.h"

using namespace std;

PostReplies::PostReplies() : Controller() {}

void PostReplies::do_post_replies(vector<string> order)
{
    set_data_bases();
    seperate_post_replies_items(order);
    try {
        check_if_user_is_online(0);
        check_numbers_validity(information[FILM_ID]);
        check_numbers_validity(information[COMMENT_ID]);
        check_if_publishers_matches();
        is_input_complete();
        online_publisher->reply_comments(stoi(information[FILM_ID]), stoi(information[COMMENT_ID]) , information[CONTENT]);
        save_reply(data_base_films);
        save_reply(accessible_films);
        send_notifications();
        DataBase::get_instance()->set_accessible_films(accessible_films);
        DataBase::get_instance()->set_data_base_films(data_base_films);
        DataBase::get_instance()->set_users(users);
        DataBase::get_instance()->set_publishers(publishers);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}

void PostReplies::is_input_complete()
{
    if(information[FILM_ID] == "" || information[COMMENT_ID] == "" || information[CONTENT] == "")
        throw BadRequest();
}

void PostReplies::save_reply(vector <Film*> films)
{
    for(int i=0;i<films.size(); i++)
        if(films[i]->return_id() == stoi(information[FILM_ID]))
            for(int j=0;j<films[i]->return_comments().size() ; j++)
                if(films[i]->return_comments()[j]->return_comment_id() == stoi(information[COMMENT_ID]))
                    films[i]->return_comments()[j]->add_reply(information[CONTENT]);
}

void PostReplies::send_notifications()
{
    for(int i=0; i<data_base_films.size();i++)
        if(data_base_films[i]->return_id() == stoi(information[FILM_ID]))
            for(int j=0;j<data_base_films[i]->return_comments().size();j++)
            {
                if(data_base_films[i]->return_comments()[j]->return_comment_id() == stoi(information[COMMENT_ID]))
                {
                    for(int k=0;k<users.size();k++)
                        if(users[k]->return_id() == data_base_films[i]->return_comments()[j]->return_user_id())
                        {
                            string notif;
                            notif = "Publisher ";
                            notif.append(online_publisher->return_username());
                            notif.append(" with id ");
                            notif.append(to_string(online_publisher->return_id()));
                            notif.append(" reply to your comment.");
                            users[k]->add_notifications(notif);
                        }
                }
            }
}