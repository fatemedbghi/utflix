#ifndef DELETE_FILMS_H
#define DELETE_FILMS_H

#include "controller.h"

class DeleteFilms : public Controller
{
public:
    DeleteFilms();
    void do_delete_films(std::vector<std::string> order);
    void is_input_complete();
    void update_accessible_films();
};

#endif