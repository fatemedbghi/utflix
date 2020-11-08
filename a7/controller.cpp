#include "controller.h"

using namespace std;

Controller::Controller()
{
    is_publisher = false;
    last_film_id = 0;
    last_user_id = 0;
    if_anyone_online = false;
    admin_status = false;
}

void Controller::set_data_bases()
{
    is_publisher = DataBase::get_instance()->get_if_publisher();
    if_anyone_online = DataBase::get_instance()->show_if_anyone_online_status();
    admin_status = DataBase::get_instance()->show_if_admin_is_online();
    data_base_films = DataBase::get_instance()->get_data_base_films();
    accessible_films = DataBase::get_instance()->get_accessible_films();
    publishers = DataBase::get_instance()->get_publishers();
    users = DataBase::get_instance()->get_users();
    last_film_id = DataBase::get_instance()->get_last_film_id();
    last_user_id = DataBase::get_instance()->get_last_user_id();
}


string Controller::encodePass(string pass)
{
  const int ROT13 = 13, ROT7 = 7;
  string encodedPass = pass;
  for (size_t i = 0; i < encodedPass.size(); i++)
  {
    encodedPass[i] = encodedPass[i] + ROT13;

    if (encodedPass[i] % 5 == 0)
      encodedPass[i] = encodedPass[i] + ROT7;
  }
  return encodedPass;
}