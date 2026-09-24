#include <iostream>
#include <string>

int main() {
    std::string ticker;
    double stock_price;
    double strike_price;
    int expiration_days;
    double volatility;
    double risk_free_rate;

    std::cout << "Enter ticker: ";
    std::cin >> ticker;

    std::cout << "Enter stock price: ";
    std::cin >> stock_price;

    std::cout << "Enter strike price: ";
    std::cin >> strike_price;

    std::cout << "Enter days to expiration: ";
    std::cin >> expiration_days;

    std::cout << "Enter volatility: ";
    std::cin >> volatility;

    std::cout << "Enter risk-free agent: ";
    std::cin >> risk_free_rate;

    double price_difference = stock_price - strike_price;

    std::cout << "Ticker: " << ticker << "\n";
    std::cout << "Stock Price: " << stock_price << "\n";
    std::cout << "Strike Price: " << strike_price << "\n";
    std::cout << "Days to Expiration: " << expiration_days << "\n"; 
    std::cout << "Volatility: " << volatility << "\n";
    std::cout << "Risk-Free Rate: " << risk_free_rate << "\n";
    std::cout << "Price Difference: " << price_difference << "\n";




    return 0;
}