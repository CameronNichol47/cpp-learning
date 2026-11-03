#include <iostream>
#include <iomanip>

void apply_growth(double stock_price, double growth_rate) {
    stock_price = stock_price*(1 + growth_rate);
    std:: cout << "Inside Function: " << stock_price << "\n";
} 

int main() {
    double stock_price;
    double growth_rate;

    std::cout << std::fixed << std::setprecision(2);

    std:: cout << "Enter stock price: ";
    std::cin >> stock_price ;

    std:: cout << "Original Stock Price: " << stock_price << "\n";

    std:: cout << "Enter growth rate: ";
    std::cin >> growth_rate ;

    std:: cout << "Original Growth Rate: " << growth_rate << "\n";
    
    apply_growth(stock_price, growth_rate);

    std::cout << "Outside Function: " << stock_price << "\n";
}

