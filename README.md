# Crypto-Exchange Chatbot

**Crypto-Exchange** is a chatbot built using **C++** that allows users to interact with a simulated cryptocurrency exchange. The bot can provide real-time information on cryptocurrency prices, perform mock trades, and offer basic guidance on cryptocurrency-related topics.

## Features

- **Real-time Cryptocurrency Price Lookup**: The chatbot can fetch real-time prices for popular cryptocurrencies (like Bitcoin, Ethereum, etc.).
- **Simulated Trading**: Execute mock buy/sell trades with cryptocurrency amounts and simulate account balances.
- **Cryptocurrency Information**: The bot can provide general information about different cryptocurrencies, their market trends, and other related data.
- **Interactive UI**: A user-friendly interface for chatting and interacting with the bot.

## Requirements

Before you can build and run this chatbot, ensure that you have the following installed:

- **C++ Compiler** (GCC, Clang, or MSVC)
- **C++ Development Environment** (IDE like Visual Studio, Code::Blocks, or terminal-based)
- **Libraries**: The bot uses some standard C++ libraries for network requests, JSON parsing, and other utilities. Ensure the dependencies are properly configured.

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/Moumita-Mou/Crypto-Exchange.git
   ```

2. Navigate into the project directory:

   ```bash
   cd Crypto-Exchange
   ```

3. Build the project using your C++ IDE or the terminal (depending on your system setup). For example, if you’re using g++, run:

   ```bash
   g++ -o CryptoExchange main.cpp
   ```

4. After building, execute the program:

   ```bash
   ./CryptoExchange
   ```

5. Follow the on-screen prompts to interact with the bot.

## How to Use

- **Start the Chatbot**: Run the bot application, and it will ask you to enter commands.
- **Query Prices**: Type in the name of a cryptocurrency (e.g., "Bitcoin") to get the current price.
- **Mock Trade**: Type in commands like "Buy 1 BTC" or "Sell 0.5 ETH" to perform simulated trades.
- **Ask for Information**: Request data on a specific cryptocurrency or general information about the market.
  
## Built With

- **C++**: The core programming language used to build the chatbot and its features.
- **Standard C++ Libraries**: Used for managing inputs/outputs, networking, and parsing JSON data.

## Current Status

The Crypto-Exchange chatbot is functional and able to provide basic cryptocurrency price lookup and mock trading features. Future enhancements can include:

- **API Integration**: Connect to a real cryptocurrency price API for live data.
- **User Authentication**: Implement a system where users can log in and have personalized portfolios.
- **Advanced Trading Simulation**: Allow users to interact with more advanced trading features like stop-loss, limit orders, etc.

## Troubleshooting

1. **Chatbot not responding to commands**:
   - Ensure that your C++ compiler and libraries are set up correctly.
   - Check that you have compiled the code correctly without errors.

2. **Issues with compiling the program**:
   - Ensure all necessary libraries are available for compiling. If you're using specific libraries for JSON parsing or networking, make sure they are linked correctly.

3. **No real-time cryptocurrency data**:
   - The current version does not fetch real-time data from external sources. For live data, consider integrating a cryptocurrency API like CoinGecko or CoinMarketCap.
