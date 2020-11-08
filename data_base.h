#ifndef DATA_BASE_H
#define DATA_BASE_H

#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h> 
#include "user.h"
#include "publisher.h"
#include "film.h"
#include "admin.h"

class DataBase
{
public:
    static DataBase *get_instance()
    {
        if (!instance)
            instance = new DataBase;
        return instance;
    }
    ~DataBase();
    void set_online_user(User* _online_user);
    void set_online_publisher(Publisher* _online_publisher);
    void set_online_status(bool online_status);
    void set_admin_status(bool admin);
    void set_data_base_films(std::vector <Film*> _data_base_films);
    void set_accessible_films(std::vector <Film*> _accessible_films);
    void set_publishers(std::vector <Publisher*> _publishers);
    void set_users(std::vector <User*> _users);
    void set_last_film_id(int _last_film_id);
    void set_last_user_id(int _last_user_id);
    void resize_recommendation();
    void update_recommender_system(int film_id , int user_id);
    std::vector<int> sort_weighted_graph(int film_id);
    std::vector<Film*> recommended_films(int film_id);
    std::vector<Film*> check_deleted_films(std::vector <Film*> recommended_films);
    void recommender_system(int film_id, int user_id);
    void print_recommended_films(std::vector <Film*> recommended_films);
    User* get_online_user();
    Publisher* get_online_publisher();
    bool show_if_anyone_online_status();
    bool show_if_admin_is_online();
    std::vector <Film*> get_data_base_films();
    std::vector <Film*> get_accessible_films();
    std::vector <Publisher*> get_publishers();
    std::vector <User*> get_users();
    int get_last_film_id();
    int get_last_user_id();
private:
    DataBase();
    static DataBase *instance;
    User* online_user;
    Publisher* online_publisher;
    bool if_anyone_online_status;
    bool admin_status;
    std::vector <Film*> data_base_films;
    std::vector <Film*> accessible_films;
    std::vector <Publisher*> publishers;
    std::vector <User*> users;
    std::vector<std::vector<int>> recommendation;
    int last_film_id;
    int last_user_id;
};

#endif