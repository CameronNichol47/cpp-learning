#include <iostream>
#include <iomanip>

void apply_growth(double& stock_price, double growth_rate) {
    stock_price *= (1 + growth_rate);
}

int main() {
    double stock_price;
    double growth_rate;

    std::cout << "Enter stock price: ";
    std::cin >> stock_price;

    std::cout << "Enter growth rate: ";
    std::cin >> growth_rate;

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Stock Price before call: " << stock_price << "\n";
    
    apply_growth(stock_price, growth_rate);

    std::cout << "Stock Price after call: " << stock_price << "\n";

    apply_growth(stock_price, growth_rate);
    apply_growth(stock_price, growth_rate);

    std::cout << "Stock Price after third call: " << stock_price << "\n";
}