#ifndef DATA_BASE_H
#define DATA_BASE_H

#include <iostream>
#include <string>
#include <vector>
#include "user.h"
#include "publisher.h"
#include "film.h"

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
    void set_data_base_films(std::vector <Film*> _data_base_films);
    void set_accessible_films(std::vector <Film*> _accessible_films);
    void set_publishers(std::vector <Publisher*> _publishers);
    void set_users(std::vector <User*> _users);
    void set_last_film_id(int _last_film_id);
    void set_last_user_id(int _last_user_id);
    User* get_online_user();
    Publisher* get_online_publisher();
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
    std::vector <Film*> data_base_films;
    std::vector <Film*> accessible_films;
    std::vector <Publisher*> publishers;
    std::vector <User*> users;
    int last_film_id;
    int last_user_id;
};

#endif