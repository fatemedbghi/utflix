#include "comment.h"

using namespace std;

Comment::Comment(string _comment , int _id , int _user_id)
{
    comment = _comment;
    id = _id;
    user_id = _user_id;
}

void Comment::add_reply(string _reply)
{
    reply = _reply;
}