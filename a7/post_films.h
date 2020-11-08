#ifndef POST_FILMS_H
#define POST_FILMS_H

#include "controller.h"

class PostFilms : public Controller
{
public:
    PostFilms();
    Response* callback(Request* req);
};

#endif