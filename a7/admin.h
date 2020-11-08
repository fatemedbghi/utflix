#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <iostream>

#define ADMIN "admin"

class Admin
{
public:
    static Admin *get_admin_instance()
    {
        if (!admin_instance)
            admin_instance = new Admin;
        return admin_instance;
    }
    std::string return_username() {return username;};
    std::string return_password() {return password;};
    int return_cash() {return cash;};
    void add_cash_from_profit(int amount, int substract);
protected:
    Admin();
    static Admin *admin_instance;
    std::string username;
    std::string password;
    int cash;
};

#endif