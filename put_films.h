#ifndef PUT_FILMS_H
#define PUT_FILMS_H

#include "controller.h"

class PutFilms : public Controller
{
public:
    PutFilms();
    void do_put_films(std::vector<std::string> order);
    void is_input_complete();
    void filter_films();
    void exert_edit_film(std::vector<Film*> films);
private:
    int year;
    int length;
};

#endif