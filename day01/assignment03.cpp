#include <iostream>
#include <string>

int main() {
    const std::string ticker="NVDA";
    double stock_price = 180.50;
    const double strike_price = 185.50;
    int expiration_days = 45;
    double volatility = 0.32;
    double risk_free_rate = 0.04;

    double price_difference = stock_price - strike_price;

    std::cout << "Ticker: " << ticker << "\n";
    std::cout << "Stock Price: " << stock_price << "\n";
    std::cout << "Strike Price: " << strike_price << "\n";
    std::cout << "Price Difference: " << price_difference << "\n";
    std::cout << "Volatility: " << volatility << "\n";
    std::cout << "Risk-Free Rate: " << risk_free_rate << "\n";



    return 0;
}
