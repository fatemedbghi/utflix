#ifndef COMMENT_H
#define COMMENT_H
#include <iostream>

class Comment
{
public:
    Comment(std::string _comment , int _id);
    std::string return_comment() {return comment;};
    int return_comment_id() {return id;};
private:
    std::string comment;
    int id;
};
#endif