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

double d1 (const OptionParameters& option) {
    return (std::log(option.S/option.K) + (option.r + std::pow(option.sigma, 2)/2)*option.T) / (option.sigma * std::sqrt(option.T));
}

double d2(const OptionParameters& option) {
    return d1(option) - option.sigma * std::sqrt(option.T);
}

double normal_cdf(double x) {
    return 0.5 * (1+ std::erf(x/std::sqrt(2.0)));
}

double black_scholes_call(const OptionParameters& option) {
    return option.S * (normal_cdf(d1(option))) - option.K * std::exp(-option.r * option.T) * normal_cdf(d2(option));
}

int main() {
    OptionParameters option{200, 210, 0.05, 0.25, 0.5};

    std::cout << std::fixed << std::setprecision(4);

    std::cout << "d1: " << d1(option) << "\n";
    std::cout << "d2: " << d2(option) << "\n";
    std::cout << "N(d1): " << normal_cdf(d1(option)) << "\n";
    std::cout << "N(d2): " << normal_cdf(d2(option)) << "\n";

    std::cout << "Black-Scholes Call: " << black_scholes_call(option) << "\n";


    return 0;
}