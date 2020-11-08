#ifndef GET_PUBLISHED_H
#define GET_PUBLISHED_H

#include "controller.h"

class GetPublished : public Controller
{
public:
    GetPublished();
    Response* callback(Request* req);
};

#endif