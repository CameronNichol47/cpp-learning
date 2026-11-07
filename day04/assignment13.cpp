#include <iostream>
#include <string>

struct OptionContract {
    std::string ticker;
    double strike_price;
    double time_to_expiry;
    bool is_call;
};

void print_option(const OptionContract& option) {
    std::cout << "Option Contract: \n";
    std::cout << "Ticker: " << option.ticker << "\n";
    std::cout << "Strike Price: " << option.strike_price << "\n";
    std::cout << "Time to Expiry: " << option.time_to_expiry << "\n";
    if (!option.is_call) {
         std::cout << "Option Type: Put" << "\n";
    } else {
        std::cout << "Option Type: Call" << "\n";
    }
}

void update_strike(OptionContract& option, double new_strike) {
    option.strike_price = new_strike;
}

int main() {
    OptionContract contract;

    std::cout << "Enter ticker: ";
    std::cin >> contract.ticker;

    std::cout << "Enter strike price: ";
    std::cin >> contract.strike_price;

    std::cout << "Enter time to expiry: ";
    std::cin >> contract.time_to_expiry;

    std::cout << "Enter option type Call (1), Put (0): ";
    std::cin >> contract.is_call;

    std::cout << "\n";
    print_option(contract);

    std::cout << "\n";
    update_strike(contract, 225);

    print_option(contract);

}