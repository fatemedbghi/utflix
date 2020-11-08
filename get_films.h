#ifndef GET_FILMS_H
#define GET_FILMS_H

#include "controller.h"

class GetFilms : public Controller
{
public:
    GetFilms();
    void do_get_films(std::vector<std::string> order);
    void set_inputs();
private:
    int min_rate;
    int min_year;
    int max_year;
    int price;
};

#endif