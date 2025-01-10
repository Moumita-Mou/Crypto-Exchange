#pragma once

#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"
#include "Wallet.h"

class MerkelBot
{
    public:
        MerkelBot();
        /** Call this to start the simulation */
        void init();
        
     private:
        void helpCommand(); 

        

        std::string currentTime;  // declaring variable for current-time 
        OrderBook orderBook{"20200601.csv"};  // reading csv file
        Wallet wallet;  // calling wallet
        bool load = true;                     
};        