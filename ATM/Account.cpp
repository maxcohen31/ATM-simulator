#include <iostream>
#include <string>
#include <random>
#include "Account.h"

// Constructor
Account::Account(float starting_fund, std::string account_name, std::string account_passwd)
    : checkings(starting_fund), passwd(account_passwd), name(account_name) {}

void Account::set_name(std::string new_name)
{
    this->name = new_name;
}

void Account::set_user_passwd()
{
    int action;
    int i;
    int passwd_length;
    std::string current_user_passwd;

    std::cout << "Do you really want to change the card password?" << std::endl;
    std::cout << "[1] - Change password\n";
    std::cout << "[2] - Exit\n";
    std::cin >> action;

    switch (action)
    {
    case 1:
    {
        
        std::cout << "Insert password length (at least 8 characters): \n";
        std::cin >> passwd_length;

        // If wrong input keep asking
        while(!std::cin || passwd_length < 8)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error: Please enter a number greater than 8.\n";
            std::cout << "> ";
            std::cin >> passwd_length;
        }

        // Store new password
        char new_user_password[passwd_length];

        // Return a random string of fixed lenght 
        for (int i = 0; i < passwd_length; i++)
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dist(33, 126);
            new_user_password[i] = dist(gen);
        }

        this->passwd = new_user_password;

        std::cout << "Your new password -> " << new_user_password << std::endl;
        break;
    }
    case 2:
        break;
    default:
        break;
    }
}

void Account::add_to_chekings(float n)
{
    checkings += n;
}

void Account::add_to_savings(float n)
{
    savings += n;
}

float Account::get_checkings()
{
    return checkings;
}

float Account::get_savings()
{
    return savings;
}

void Account::transfer()
{   
    int option;
    int amount;

    std::cout << " -----------------------------\n";
    std::cout << "|       TRANSFER OPTIONS      |\n";
    std::cout << "|[1] - Checkings -> Savings   |\n";
    std::cout << "|[2] - Savings -> Checkings   |\n";
    std::cout << " -----------------------------\n";

    switch (option)
    {
    case 1:

        std::cout << "Enter amount -> ";
        std::cin >> amount;

        if(amount <= checkings)
        {
            checkings = checkings - amount;
            savings = savings + amount;
            break;

        }
        else
        {
            std::cout << "Not enough money.";
            break;
        }
    case 2:

        std::cout << "Enter amount -> ";
        std::cin >> amount;

        if(amount <= savings)
        {
            savings = savings - amount;
            checkings = checkings + amount;
            break;

        }
        else
        {
            std::cout << "Not enough money.";
            break;
        }
    default:
        break;
    }
}

void Account::withdraw_money()
{   
    int option;
    float money_to_withdraw;

    std::cout << " -----------------------------\n";
    std::cout << "|      WITHDRAWAL OPTIONS     |\n";
    std::cout << "|[1] - Checkings              |\n";
    std::cout << "|[2] - Savings                |\n";
    std::cout << " -----------------------------\n";
    std::cout << "Where do you want to withdraw money from?\n";

    switch (option)
    {
    case 1:
    
        std::cout << "How much money do you want to withdraw? ";
        std::cout << "> ";
        std::cin >> option;

        if(money_to_withdraw <= checkings)
        {
            checkings = checkings - money_to_withdraw;
            std::cout << "Checkings: " << checkings << std::endl;
        }
        else
        {
            std::cout << "Not enough money";
        }
        break;
    case 2:

        std::cout << "How much money do you want to withdraw? ";
        std::cout << "> ";
        std::cin >> option;

        if(money_to_withdraw <= savings)
        {
            savings = savings - money_to_withdraw;
            std::cout << "Savings: " << savings << std::endl;
        }
        else
        {
            std::cout << "Not enough money";
        }
        break;

    
    default:
        break;
    }
}

void Account::get_info()
{   
    int info_option;

    std::cout << "------------------\n";
    std::cout << "|  ACCOUNT INFO  |\n";
    std::cout << "------------------\n";
    std::cout << "USER NAME -> " << name << std::endl;
    std::cout << "PASSWORD -> *****\n";
    std::cout << "=====================\n";
    std::cout << "Show password? \n";
    std::cout << "[1] - Password\n";
    std::cout << "[2] - Exit\n";
    std::cin >> info_option;

    switch (info_option)
    {
    case 1:
        std::cout << "Password: " << passwd << std::endl;
        break;
    case 2:
        std::cout << "Have a nice day!\n";
        break;
    default:
        break;
    }
}