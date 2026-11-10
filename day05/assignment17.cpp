#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double stock_price, strike_price, volatility, 
    risk_free_rate, time_to_expiry;

    double volatility_term, log_price_ratio, 
    discounted_strike, squared_volatility,
    black_scholes_numerator, d1, d2;

    std::cout << "Enter Stock Price: ";
    std::cin >> stock_price;

    std::cout << "Enter Strike Price: ";
    std::cin >> strike_price;

    std::cout << "Enter Volatility: ";
    std::cin >> volatility;

    std::cout << "Enter Risk Free Rate: ";
    std::cin >> risk_free_rate;

    std::cout << "Enter Time To Expiry: ";
    std::cin >> time_to_expiry;

    volatility_term = volatility * std::sqrt(time_to_expiry);
    log_price_ratio = std::log(stock_price / strike_price);
    discounted_strike = strike_price * std::exp(-risk_free_rate * time_to_expiry);
    squared_volatility = std::pow(volatility, 2);
    black_scholes_numerator = log_price_ratio + (risk_free_rate + squared_volatility/2) * time_to_expiry;

    d1 = black_scholes_numerator / volatility_term;

    d2 = d1 - volatility_term;

    std::cout << std::fixed << std::setprecision(4);

    std::cout << "Volatility Term: " << volatility_term << "\n";
    std::cout << "Log Price Ratio: " << log_price_ratio << "\n";
    std::cout << "Discounted Strike: " << discounted_strike << "\n";
    std::cout << "Squared Volatility: " << squared_volatility << "\n";
    std::cout << "Black-Scholes Numerator: " << black_scholes_numerator << "\n";
    std::cout << "d1: " << d1 << "\n";
    std::cout << "d2: " << d2 << "\n";

    return 0;
}