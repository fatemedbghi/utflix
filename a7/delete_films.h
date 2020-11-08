#ifndef DELETE_FILMS_H
#define DELETE_FILMS_H

#include "controller.h"

class DeleteFilms : public Controller
{
public:
    DeleteFilms();
    Response* callback(Request* req);
    void update_accessible_films(Request* req);
};

#endif