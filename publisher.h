#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "user.h"

class Publisher : public User
{
public:
    Publisher(std::string _email , std::string _username , std::string _password , int _age ,bool _is_publisher , int _id);
    ~Publisher();
    void add_followers(User* new_follower);
    void upload_film(std::string name , int year , int length , int price ,std::string summary , std::string director , int film_id);
    void edit_film(int film_id , std::string name , int year , int length , std::string summary , std::string director);
    void delete_film(int id);
    void show_followers();
    void calculate_unsetteled_money(int amount , int status);
    void get_money_from_media_service();
    void show_published_films(std::string name , int min_rate , int min_year , int price , int max_year , std::string director);
    void reply_comments(int film_id , int comment_id , std::string content);
    void delete_comment(int film_id , int comment_id);
    std::vector<User*> return_followers() {return followers;};
    std::vector<Film*> return_published_films() {return published_films;};
private:
    std::vector <Film*> published_films;
    std::vector <User*> followers;
    int unsetteled_money;
};

#endif