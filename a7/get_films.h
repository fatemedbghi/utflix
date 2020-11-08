#ifndef GET_FILMS_H
#define GET_FILMS_H

#include "controller.h"

class GetFilms : public Controller
{
public:
    GetFilms();
    Response* callback(Request* req);
};

#endif