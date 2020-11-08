#ifndef POST_FILMS_H
#define POST_FILMS_H

#include "controller.h"

class PostFilms : public Controller
{
public:
    PostFilms();
    void do_post_films(std::vector<std::string> order);
    void is_input_complete();
    void send_notification();
};

#endif