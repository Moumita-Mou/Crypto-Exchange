#include "MerkelMain.h"
#include <iostream>
#include <vector>
#include "OrderBook.h"
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include "MerkelBot.h"

MerkelBot::MerkelBot()
{

}

void MerkelBot::init()
{
      std::string currentTime = orderBook.getEarliestTime();  //keeping note of the current time
    
      wallet.insertCurrency("BTC", 10000); //wallet stats
    
        //Welcoming message for user
        std::cout << "MerkelBot >> Hi! I am Merkel, the Advisor Bot. I will be helping you for trade. " << std::endl; 
        std::cout << "          >> Please proceed by Typing any command or type 'Help'. " << std::endl;
    
        //when similation starts and it loads the commands over and over
        while(load)
    {
            //validating user input
            std::string input;
            std::getline(std::cin, input);
            std::cout << "User >> ";
            std::cin >> input;

            //Help Command
            if(input ==  "help" || input == "Help") //check if user-input is help
            {
                std::cout << "MerkelBot >> The Available Commands Are:- " << std::endl; 
                std::cout << "          >> 1) Help              2)Help-Cmd    3)Prod          4)Time          5)Step " << std::endl;
                std::cout << "          >> 6) Current-Balance   7)Avg         8)Total-Sales   9) Min          10)Max  " << std::endl;
                std::cout << "          >> 11) Allover-Stats    12)Predict    13)Total-Ask    14)Total-Bid    15)Clear  " << std::endl;
                std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
                std::cout << "MerkelBot >> To start trade, please type in any command and proceed." << std::endl;
            }
            //Product Command
            else if(input == "prod" ||input == "Prod") //check if user-input is prod
            {
                for (std::string const& p : orderBook.getKnownProducts())
                {
                    std::cout << "MerkelBot >> The Products in market are: " << p << std::endl;
                }
            }
            //Time Command
            else if(input == "time" || input == "Time") //check if user-input is time
            {
                std::cout << "MerkelBot >> The Current time is: " << currentTime << std::endl;
            }

            //Step Command
            else if(input == "step" || input == "Step") //check if user-input is step
            {
                std::cout << "Going to next time frame. " << std::endl;
                currentTime = orderBook.getNextTime(currentTime);
                std::cout << "Steped on to New time: " << currentTime << std::endl;
            }

            //Allover-Stats Command
            else if(input == "allover-stats" || input == "Allover-Stats") //check user-input 
            {
                for (std::string const& p : orderBook.getKnownProducts())
                {
                    std::cout << "Product " << p << std::endl;
                    std::vector<OrderBookEntry> sales =  orderBook.matchAsksToBids(p, currentTime);
                    for (OrderBookEntry& sale : sales)
                    {
                        std::cout << "Sale price: " << sale.price << " amount " << sale.amount << std::endl; 
                    }
                }
            }

            //Max Command
            else if(input == "max" || input == "Max") //check user-input 
            {
                //validate user input
                std::string input_2;  
                std::cout << "Please enter Max, Product type, OrderBookType e.g. Max, ETH/BTC, ask/bid." << std::endl;
                std::cout << "User >> ";
                std::cin >> input_2; //store user input

                std::getline(std::cin, input_2);

                std::vector<std::string> tokens = CSVReader::tokenise(input_2, ','); // tokenise the user input

                if (tokens.size() != 2) //check if number of tokens are accurate 
                {
                    std::cout << "MerkelMain::Bad input! " << input << std::endl;
                }
                else {
                    try {
                            for(std::string const& p : orderBook.getKnownProducts()) //iterate over orderbook to fetch product names
                            {
                                std::cout << "Product: " << p  << std::endl;
                                std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, 
                                                                                        p, currentTime);                                                     
                                std::cout << "MerkelBot >> The Max is: " << OrderBook::getHighPrice(entries) << std::endl;
                            }
                    }catch (const std::exception& e) //throw exceptions
                        {
                            std::cout << " MerkelMain::Bad input " << std::endl;
                        }   
                } 
                
            }

            //Min Command
            else if(input == "min" || input == "Min") //check user-input 
            {
                //validate user input
                std::string input_2;  
                std::cout << "Please enter Min, Product type, OrderBookType e.g. Min, ETH/BTC, ask/bid." << std::endl;
                std::cout << "User >> ";
                std::cin >> input_2; //store user input

                std::getline(std::cin, input_2);

                std::vector<std::string> tokens = CSVReader::tokenise(input_2, ','); // tokenise the user input

                if (tokens.size() != 2) //check if number of tokens are accurate 
                {
                    std::cout << "MerkelMain::Bad input! " << input << std::endl;
                }
                else {
                    try {
                            for (std::string const& p : orderBook.getKnownProducts()) //iterate over orderbook to fetch product names
                            {
                                std::cout << "Product: " << p << std::endl;
                                std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, 
                                                                                        p, currentTime);
                                std::cout << "MerkelBot >> The Min is: " << OrderBook::getLowPrice(entries) << std::endl;
                            } 
                    }catch (const std::exception& e) //throw exceptions
                        {
                            std::cout << " MerkelMain::Bad input " << std::endl;
                        }   
                }
        
            }
            //Avg Command
            else if(input == "avg" || input == "Avg") //check user input
            {
                //validate user input
                std::string input_2;  
                std::cout << "Please enter Avg, Product type, OrderBookType, Timesteps e.g. Avg, ETH/BTC, ask/bid, 100." << std::endl;
                std::cout << "User >> ";
                std::cin >> input_2; //store user input

                std::getline(std::cin, input_2);

                std::vector<std::string> tokens = CSVReader::tokenise(input_2, ','); //tokenise user input

                if (tokens.size() != 3) //check if number of tokens are accurate
                {
                    std::cout << "MerkelMain:: Bad input! " << input << std::endl;
                }
                else {
                    try {
                            for (std::string const& p : orderBook.getKnownProducts()) //iterate over orderBook
                            {
                                std::cout << "Product: " << p << std::endl;
                                std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, 
                                                                                        p, currentTime);
                                std::cout << "MerkelBot >> The Average is: " << OrderBook::getLowPrice(entries) + OrderBook:: getHighPrice(entries)/entries.size() << std::endl;
                            }  
                    }catch (const std::exception& e) //throw exceptions
                        {
                            std::cout << " MerkelMain::Bad input " << std::endl;
                        }   
                }

            }

            //Predict Command
            else if(input == "predict" || input == "Predict") //check user input
            {
                //validate user input
                std::string input_2;  
                std::cout << "Please enter Predict, Product type, OrderBookType, Timesteps e.g. Predict, ETH/BTC, ask/bid, 10." << std::endl;
                std::cout << "User >> ";
                std::cin >> input_2; //store user input

                std::getline(std::cin, input_2);

                std::vector<std::string> tokens = CSVReader::tokenise(input_2, ','); //tokenise the user input

                if (tokens.size() != 3) //check the number of tokens are accurate
                {
                    std::cout << "MerkelMain:: Bad input! " << input << std::endl;
                }
                else {
                    try {
                            for (std::string const& p : orderBook.getKnownProducts()) // iterations to search for products types
                            {
                                std::cout << "Product: " << p << std::endl;
                                std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, 
                                                                                        p, currentTime);
                                std::cout << "MerkelBot >> The prediction for next step is: " << OrderBook::getLowPrice(entries) + OrderBook:: getHighPrice(entries)/rand() << std::endl;
                            }   
                    }catch (const std::exception& e) // throw exceptions
                        {
                            std::cout << " MerkelMain::Bad input " << std::endl;
                        }   
                }

            }

            //Total-Ask Command
            else if(input == "total-ask" || input == "Total-Ask") //check user input
            {
            for (std::string const& p : orderBook.getKnownProducts())
                {
                    std::cout << "Product " << p << std::endl;
                    std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, 
                                                                            p, currentTime);
                    std::cout << "MerkelBot >> Total Asks: " << entries.size() << std::endl;
                }
            }

            //Total-Bid Command
            else if(input == "total-bid" || input == "Total-Bid") //check user input
            {
            for (std::string const& p : orderBook.getKnownProducts())
                {
                    std::cout << "Product " << p << std::endl;
                    std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::bid, 
                                                                            p, currentTime);
                    std::cout << "MerkelBot >> Total Bids " << entries.size() << std::endl;
                }
            }

            //Total-Sales Command
            else if(input == "total-sales" || input == "Total-Sales") //check user input
            {
                    orderBook.getKnownProducts();
                    
                    std::vector<OrderBookEntry> sales;
                    std::cout << "Sales: " << sales.size() << std::endl;  
                
            }

            //Current-Balance Command
            else if(input == "current-balance" || input == "Current-Balance") //check user input
            {
                std::cout << "MerkelBot >> The current balance is:  " << wallet.toString() << std::endl;
            }

            //Clear Command
            else if(input == "clear" || input == "Clear") //check user input
            {
                std::cout << "MerkelBot >> Please wait until the screen gets cleared." << std::endl; 
                system("cls"); //clearing screen
                std::cout << "---------------Clearing Screen Done-----------------" << std::endl;
            }

            
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            
            //Help-Cmd Command
            else if(input == "help-cmd" || input == "Help-Cmd") //check user input
            {
                std::cout << "MerkelBot >> Help-Cmd -> After 'Help' just type in the command. Help will be provided for each available command. E.g. Help-Prod " << std::endl; 
            }

            //Help-Prod Command
            else if(input == "help-prod" || input == "Help-Prod") //check user input
            {
                std::cout << "MerkelBot >> Prod -> The Products in market. " << std::endl; 
            }
            
            //Help-avg Command
            else if(input == "help-avg" || input == "Help-Avg") //check user input
            {
                std::cout << "MerkelBot >> Avg -> Average of given product type's ask/bid price over given time-steps." << std::endl; 
            }

            //Help-max Command
            else if(input == "help-max" || input == "Help-Max") //check user input
            {
                std::cout << "MerkelBot >> Max -> Maximum ETH/BTC ask/bid price in market. " << std::endl; 
            }

            //Help-min Command
            else if(input == "help-min" || input == "Help-Min") //check user input
            {
                std::cout << "MerkelBot >> Min -> Minimum ETH/BTC ask/bid price in market." << std::endl; 
            }

            //help-predict command
            else if(input == "help-predict" || input == "Help-Pridict") //check user input
            {
                std::cout << "MerkelBot >> Predict -> Makes Prediction of given product type's bid/ask within 10 timesteps. " << std::endl; 
            }

            //help-time command
            else if(input == "help-time" || input == "Help-Time") //check user input
            {
                std::cout << "MerkelBot >> Time -> Current time in market. " << std::endl; 
            }

            //help-step command
            else if(input == "help-step" || input == "Help-Step") //check user input
            {
                std::cout << "MerkelBot >> Step -> Go to next timestep in market. " << std::endl; 
            }

            //Help-total-sales Command
            else if(input == "help-total-sales" || input == "Help-Total-Sales") //check user input
            {
                std::cout << "MerkelBot >> Sales -> It prints the total number of sales so far. " << std::endl; 
            }

            //Help-allover-stats Command
            else if(input == "help-allover-stats" || input == "Help-Allover-Stats") //check user input
            {
                std::cout << "MerkelBot >> Allover-Stats -> It shows the status of Max/Min per Ask and Bid for all products at once. " << std::endl; 
            }

            //Help-total-ask Command
            else if(input == "help-total-ask" || input == "Help-Total-Ask") //check user input
            {
                std::cout << "MerkelBot >> Total-Ask -> It prints the total number of asks in exchange for each products. " << std::endl; 
            }

            //Help-total-bid Command
            else if(input == "help-total-bid" || input == "Help-Total-Bid") //check user input
            {
                std::cout << "MerkelBot >> Total-Bid -> It prints the total number of bids in exchange for each products. " << std::endl; 
            }

            //Help-total-ask Command
            else if(input == "help-current-balance" || input == "Help-Current-Balance") //check user input
            {
                std::cout << "MerkelBot >> Total-Current-Balance -> It prints the total amount of currency in current account. " << std::endl; 
            } 
             
            //Help-Clear Command 
            else if(input == "help-clear" || input == "Help-Clear") //check user input
            {
                std::cout << "MerkelBot >> Clear -> It Clears the screen when it becomes too tedious to read the data. " << std::endl; 
            }
        
            // Invalid Command Message
            else
            {
                std::cout << "Invalid command. Please type in valid commands" << std::endl;
            }
    }
    

}
