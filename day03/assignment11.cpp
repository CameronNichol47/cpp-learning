#include <iostream>
#include <iomanip>
#include <vector>

double calculate_next_price(double stock_price, double growth_rate) {
    return stock_price * (1 + growth_rate);
}

void print_prices(const std::vector<double>& prices) {
    for (std::size_t i = 0; i < prices.size(); i++) {
        std::cout << "Day " << i << ": " << prices[i] << "\n";
    }
}

double calculate_average_price(const std::vector<double>& prices) {
    if (prices.empty()) {
        return 0.0;
    }

    double sum = 0.0;
    
    for (double price : prices) {
        sum += price;
    }

    return sum / prices.size();
}

int main() {
    double stock_price, growth_rate, avg;
    int days;
    std::vector <double> prices;

    std::cout << "Enter stock price: ";
    std::cin >> stock_price;
    prices.push_back(stock_price);

    std::cout << "Enter growth rate: ";
    std::cin >> growth_rate;

    std::cout << "Enter number of days: ";
    std::cin >> days;

    std::cout << std::fixed << std::setprecision(2);

    for (int i = 0; i < days; i++) {
        prices.push_back(calculate_next_price(prices.back(), growth_rate));
    }


    print_prices(prices);
    std::cout << "Number of prices stored: " << prices.size() << '\n';

    avg = calculate_average_price(prices);
    std::cout << "Average: " << avg << "\n";

}