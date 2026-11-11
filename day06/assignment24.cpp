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

double black_scholes_put(const OptionParameters& option) {
    return option.K * std::exp(-option.r * option.T) * normal_cdf(-d2(option)) - option.S * normal_cdf(-d1(option));
}

bool check_put_call_parity(const OptionParameters& option) {
    double lhs = black_scholes_call(option) - black_scholes_put(option);
    double rhs = option.S - option.K * std::exp(-option.r * option.T);

    return std::abs(lhs - rhs) < 1e-8;
}

void print_option_results(const OptionParameters& option) {
    std::cout << std::fixed << std::setprecision(4);

    std::cout << "Call: " << black_scholes_call(option) << "\n";
    std::cout << "Put: " << black_scholes_put(option) << "\n";

    std::cout << std::boolalpha;
    std::cout << "Parity: " << check_put_call_parity(option) << "\n";
}

int main() {
    OptionParameters option1{200, 210, 0.05, 0.25, 0.5};
    OptionParameters option2{150, 100, 0.05, 0.20, 1.0};
    OptionParameters option3{50, 100, 0.05, 0.20, 1.0};

    print_option_results(option1);
    print_option_results(option2);
    print_option_results(option3);
    

    return 0;
}