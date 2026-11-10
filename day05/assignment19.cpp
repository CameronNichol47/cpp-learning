#include <iostream>
#include <iomanip>
#include <cmath>

struct OptionParameters {
    double S;
    double K;
    double r;
    double sigma;
    double T;
};

double calculate_d1(const OptionParameters& option) {
    double d1 = (std::log(option.S/option.K) + 
    (option.r + std::pow(option.sigma, 2)/2)*option.T) / (option.sigma * std::sqrt(option.T));

    return d1;
}
double calculate_d2(const OptionParameters& option) {
    double d2 = calculate_d1(option) - option.sigma * std::sqrt(option.T);
    return d2;
}

bool valid_inputs(const OptionParameters& option) {
    if (!(option.S > 0 && option.K > 0 && option.sigma > 0 && option.T > 0)) {
        return false;
    } else if (!(std::isfinite(option.S) && std::isfinite(option.K) && 
                std::isfinite(option.sigma) && std::isfinite(option.T))) {

        return false;
    } else if (!std::isfinite(option.r)) {
        return false;
    }

    return true;
}

int main () {
    OptionParameters option;

    std::cout << "Enter Stock Price: ";
    std::cin >> option.S;
    std::cout << "Enter Strike Price: ";
    std::cin >> option.K;
    std::cout << "Enter Risk-Free: ";
    std::cin >> option.r;
    std::cout << "Enter Volatility: ";
    std::cin >> option.sigma;
    std::cout << "Enter Time to Expiry: ";
    std::cin >> option.T;


    if (!valid_inputs(option)) {
        std::cout << "Invalid Black-Scholes inputs.\n";
        return 1;
    }

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "d1: " << calculate_d1(option) << "\n";
    std::cout << "d2: " << calculate_d2(option) << "\n";





    // double S, K, r, sigma, T;

    // std::cout << "Enter Stock Price: ";
    // std::cin >> S;
    // std::cout << "Enter Strike Price: ";
    // std::cin >> K;
    // std::cout << "Enter Risk-Free: ";
    // std::cin >> r;
    // std::cout << "Enter Volatility: ";
    // std::cin >> sigma;
    // std::cout << "Enter Time to Expiry: ";
    // std::cin >> T;

    // if (!valid_inputs(S, K, sigma, T) || !std::isfinite(r)) {
    //     std::cout << "Invalid Black-Scholes inputs.\n";
    //     return 1;
    // }

    // std::cout << std::fixed << std::setprecision(4);
    // std::cout << "d1: " << calculate_d1(S, K, r, sigma, T) << "\n";
    // std::cout << "d2: " << calculate_d2(S, K, r, sigma, T) << "\n";

    return 0;
}