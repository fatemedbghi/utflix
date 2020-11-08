#ifndef DELETE_COMMENTS_H
#define DELETE_COMMENTS_H

#include "controller.h"

class DeleteComments : public Controller
{
public:
    DeleteComments();
    void do_delete_comments(std::vector<std::string> order);
    void is_input_complete();
    void delete_specific_comment(std::vector <Film*> films);
};

#endif