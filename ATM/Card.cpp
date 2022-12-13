#include <iostream>
#include <string>
#include <random>
#include "Card.h"

// Constructor
ATMCard::ATMCard(std::string c_name, std::string pin)
    : card_name(c_name), card_pin(pin) {}

void ATMCard::card_info()
{
    std::cout << "======= CARD INFO =======" << std::endl;
    std::cout << "Card -> " << card_name << std::endl; 
    std::cout << "Pin -> *****" << std::endl;
}

void ATMCard::change_passwd()
{   
    int action;
    int i;
    int passwd_length;
    std::string current_pin;

    std::cout << "Do you really want to change the card password?" << std::endl;
    std::cout << "[1] - Change password\n";
    std::cout << "[2] - Exit\n";
    std::cin >> action;

    switch (action)
    {
    case 1:
    {
        std::cout << "Please, insert current password: ";
        std::getline(std::cin, current_pin);
        std::cout << "Insert password length (at least 8 characters): ";
        std::cin >> passwd_length;
        
        while(current_pin != card_pin)
        {
            std::cin.clear();
            std::cout << "Error: Please enter a number greater than 8.\n";
            std::cout << "> ";
            std::cin >> passwd_length;
        }

        char password[passwd_length];

        for (int i = 0; i < passwd_length; i++)
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dist(33, 126);
            password[i] = dist(gen);
        }

        this->card_pin = password;
        std::cout << "Your new password -> " << password << std::endl;
        break;
    }

    case 2:
        std::cout << "Have a nice day!\n";
        break;    
    default:
        break;
    }

}