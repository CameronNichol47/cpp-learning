#include <iostream>
#include <vector>
#include <iomanip>

double calculate_next_price(double stock_price, double daily_growth_rate) {
    return stock_price*(1+daily_growth_rate);
}

int main() {
    double stock_price;
    int n_days;
    double daily_growth_rate;

    std::vector<double> prices;

    std::cout << "Enter starting stock price: ";
    std::cin >> stock_price;

    std::cout << "Enter number of days: ";
    std::cin >> n_days;

    std::cout << "Enter daily growth rate: ";
    std::cin >> daily_growth_rate;

    std::cout << std::fixed << std::setprecision(2);

    prices.push_back(stock_price);

    for (int i = 0; i < n_days; i++) {
        stock_price = calculate_next_price(stock_price, daily_growth_rate);
        
        prices.push_back(stock_price);
    }

    int i = 0;

    while (i < prices.size()) {
        std::cout << "Day " << i << ": " << prices[i] << '\n';
        i++;
    }

    std::cout << "Number of prices stored: " << prices.size() << '\n';

    return 0;
}