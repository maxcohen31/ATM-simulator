#include <iostream>
#include "Account.h"
#include "Card.h"

void atm_display();

int main(){

    int atm_option;

    Account user1 {5000.50, "Tix", "Kix-12£"};
    atm_display();

    std::cout << "Select an operation -> ";
    std::cin >> atm_option;

    switch (atm_option)
    {
    case 1:
    {
        user1.withdraw_money();
        break;
    case 2:
        user1.transfer();
        break;
    case 3: 
        user1.get_info();
        break;
    case 4:
        user1.get_checkings();
        break;
    case 5:
        user1.get_savings();
        break;
    case 6:
        
        ATMCard card1 {"Visa", "ldkw!f.a-"};
        int card_option;

        std::cout << "------------------------\n";
        std::cout << "|      CARD OPTION      |\n";
        std::cout << "|-----------------------|\n";
        std::cout << "| [1] - Card Info       |\n";
        std::cout << "| [2] - Change Password |\n";
        std::cout << "-------------------------\n";

        switch (card_option)
        {
        case 1:
            card1.card_info();
            break;
        case 2:
            card1.change_passwd();
            break;
        default:
            break;
        }
    }
    case 7:
        break;
    
    default:
        break;

    }

}

void atm_display()
{   

    std::cout << " ----------------------" << std::endl;
    std::cout << "|      ATM SERVICE       |"  << std::endl;
    std::cout << "|------------------------|" << std::endl;
    std::cout << "| [1] - Withdrawal option|" << std::endl;
    std::cout << "| [2] - Transfer option  |" << std::endl;
    std::cout << "| [3] - Account Info     |" << std::endl;
    std::cout << "| [4] - Get checkings    |" << std::endl;
    std::cout << "| [5] - Get savings      |" << std::endl;
    std::cout << "| [6] - Card             |" << std::endl;
    std::cout << "| [7] - Exit             |" << std::endl;
    std::cout <<  "-----------------------" << std::endl;

}