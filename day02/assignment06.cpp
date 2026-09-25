#include <iostream>

int main() {
    double stock_price;
    int n_days;
    double daily_growth_rate;

    std::cout << "Enter starting stock price: ";
    std::cin >> stock_price;

    std::cout << "Enter number of days: ";
    std::cin >> n_days;

    std::cout << "Enter daily growth rate: ";
    std::cin >> daily_growth_rate;

    for (int i = 0; i < n_days; i++) {
        stock_price = stock_price*(1 + daily_growth_rate);

        std::cout << "Day " << i + 1 << ": " << stock_price << "\n";
    }


    return 0;
}