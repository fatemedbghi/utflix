#include "admin.h"

using namespace std;

Admin* Admin::admin_instance = 0;

Admin::Admin()
{
    username = ADMIN;
    password = ADMIN;
    cash = 0;
}

void Admin::add_cash_from_profit(int amount , int substract)
{
    if(substract > 0)
        cash = cash + amount;
    else if(substract < 0)
        cash = cash - amount;

}