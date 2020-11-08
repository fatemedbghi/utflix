#ifndef POST_RATE_H
#define POST_RATE_H

#include "controller.h"

class PostRate : public Controller
{
public:
    PostRate();
    Response* callback(Request* req);
    void exert_rate(Request* req);
    void check_score_validity(Request* req);
};

#endif