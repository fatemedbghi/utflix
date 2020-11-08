#ifndef GET_AVAILABLE_FILMS_H
#define GET_AVAILABLE_FILMS_H

#include "controller.h"

class GetAvailableFilms : public Controller
{
public:
    GetAvailableFilms();
    Response* callback(Request* req);
};

#endif