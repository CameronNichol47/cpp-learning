#include <iostream>
#include <string>

int main() {
    std::string ticker="AAPL";
    double stock_price = 227.50;
    double strike_price = 230.00;
    int expiration_days = 30;
    bool call = true;

    std::cout << "Ticker: " << ticker << "\n";
    std::cout << "Stock Price: " << stock_price << "\n";
    std::cout << "Strike Price: " << strike_price << "\n";
    std::cout << "Days to Expiration: " << expiration_days << "\n";
    std::cout << "Call Option: " << call << "\n";

    return 0;
}
