#include <iostream>
#include <string>
#include "Account.h"

#ifndef CARD_H
#define CARD_H

class ATMCard: public Account
{
private:
    std::string card_name;
    std::string card_pin;

public:
    ATMCard() = default;
    ATMCard(std::string c_name, std::string pin);
    
    void card_info();
    void change_passwd();

};

#endif