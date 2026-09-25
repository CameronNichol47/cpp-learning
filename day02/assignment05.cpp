#include <iostream>

int main() {
    double stock_price;
    double strike_price;
    int expiration_days;

    std::cout << "Enter stock price: ";
    std::cin >> stock_price;

    std::cout << "Enter strike price: ";
    std::cin >> strike_price;

    std::cout << "Enter the days to expiration: ";
    std::cin >> expiration_days;

    if (stock_price > strike_price) {
        std::cout << "Stock price is above the strike price. \n";
        std::cout << "Difference: " << stock_price - strike_price << "\n";
    } else if (stock_price == strike_price) {
        std::cout << "Stock price is equal to the strike price. \n";
        std::cout << "Difference: 0\n";
    } else {
        std::cout << "Stock price is less than the strike price. \n";
        std::cout << "Difference: " << strike_price - stock_price << "\n";
    }   

    if (expiration_days <= 30 && expiration_days > 0) {
        std::cout << "Expires soon. \n";
    } else if (expiration_days > 30) {
        std::cout << "More than 30 days until expiration. \n";
    } else {
        std::cout << "Option expired. \n";
    }


    return 0;
}

