#include <string>
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{   

private:
    float checkings {0.0f};
    float savings {0.0f};
    std::string passwd;
    std::string name;

public:
    Account() = default;
    Account(float starting_fund, std::string account_name, std::string account_passwd);
    
    void set_name(std::string new_name);
    void set_user_passwd();
    void add_to_chekings(float n);
    void add_to_savings(float n);
    float get_checkings();
    float get_savings();
    void transfer();
    void withdraw_money();
    void get_info();

};

#endif