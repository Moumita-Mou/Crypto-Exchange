#include "Wallet.h"
#include <iostream>
#include "MerkelMain.h"
#include "MerkelBot.h"

int main()
{   
    std::cout << "Choose 1: Merkel Main Trade App OR " << std::endl; 
    std::cout << "Choose 2: Merkel Advisor Bot" << std::endl;

    // validating user input
    int input;
    std::cin >> input;
    std::cout << input << std::endl;

   if(input == 1) //when user input is 1 start the Main app 
    {
        MerkelMain app{};
        app.init();
    }

    else if(input == 2) // when user input is 2 start the Advisor Bot
    {
        MerkelBot app{};
        app.init();
    }
}
