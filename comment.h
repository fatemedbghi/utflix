#include <iostream>

class Comment
{
public:
    Comment(std::string _comment , int _id , int _user_id);
    std::string return_comment() {return comment;};
    int return_comment_id() {return id;};
    void add_reply(std::string _reply);
    std::string return_reply() {return reply;};
    int return_user_id() {return user_id;};

private:
    std::string comment;
    int user_id;
    std::string reply;
    int id;
    int film_id;
};