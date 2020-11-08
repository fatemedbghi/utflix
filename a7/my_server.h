#ifndef MY_SERVER_H
#define MY_SERVER_H

#include "../server/server.hpp"

class MyServer : public Server {
public:
  MyServer(int port = 5000);
};

#endif