#include "delete_comments.h"

using namespace std;

DeleteComments::DeleteComments() : Controller() {}

void DeleteComments::do_delete_comments(vector <string> order)
{
    set_data_bases();
    seperate_delete_comments_items(order);
    try {
        check_if_user_is_online(0);
        check_numbers_validity(information[FILM_ID]);
        check_numbers_validity(information[COMMENT_ID]);
        check_validity_of_film_id();
        check_if_publishers_matches();
        is_input_complete();
        online_publisher->delete_comment(stoi(information[FILM_ID]) , stoi(information[COMMENT_ID]));
        delete_specific_comment(data_base_films);
        cout << 5 << endl;
        delete_specific_comment(accessible_films);

        DataBase::get_instance()->set_accessible_films(accessible_films);
        DataBase::get_instance()->set_data_base_films(data_base_films);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}

void DeleteComments::is_input_complete()
{
    if(information[FILM_ID] == "" || information[COMMENT_ID] == "")
        throw BadRequest();
}

void DeleteComments::delete_specific_comment(vector <Film*> films)
{
    for(int i=0;i<films.size() ; i++)
        if(films[i]->return_id() == stoi(information[FILM_ID]))
            for(int j=0;j<films[i]->return_comments().size();j++)
                if(films[i]->return_comments()[j]->return_comment_id() == stoi(information[COMMENT_ID]))
                    films[i]->delete_comment(i,j);
                
}