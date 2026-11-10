#include <iostream>
#include <cmath>
#include <numbers>
#include <iomanip>
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

double normal_pdf(double x) {
    double coeffecient = 1/std::sqrt(2 * std::numbers::pi); 
    double exponent = std::exp(-std::pow(x, 2)/2);

    return coeffecient * exponent;
}

double normal_cdf(double x) {
    return 0.5 * (1.0 + std::erf(x/std::sqrt(2)));
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

int main() {
    double x1 = 0.0;
    double x2 = 1.0;
    double x3 = -1.0;
    double x4 = 2.0;
        OptionParameters option;


    std::cout << std::fixed << std::setprecision(6);

    std::cout << "x = " << x1 << "\n";
    std::cout << "PDF: " << normal_pdf(x1) << "\n";
    std::cout << "CDF: " << normal_cdf(x1) << "\n\n";

    std::cout << "x = " << x2 << "\n";
    std::cout << "PDF: " << normal_pdf(x2) << "\n";
    std::cout << "CDF: " << normal_cdf(x2) << "\n\n";

    std::cout << "x = " << x3 << "\n";
    std::cout << "PDF: " << normal_pdf(x3) << "\n";
    std::cout << "CDF: " << normal_cdf(x3) << "\n\n";

    std::cout << "x = " << x4 << "\n";
    std::cout << "PDF: " << normal_pdf(x4) << "\n";
    std::cout << "CDF: " << normal_cdf(x4) << "\n";

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

    double d1 = calculate_d1(option);
    double d2 = calculate_d2(option);

    std::cout << "\nd1: " << d1 << "\n";
    std::cout << "d2: " << d2 << "\n";

    std::cout << "N(d1): " << normal_cdf(d1) << "\n";
    std::cout << "N(d2): " << normal_cdf(d2) << "\n";

    std::cout << "PDF(d1): " << normal_pdf(d1) << "\n";
    std::cout << "PDF(d2): " << normal_pdf(d2) << "\n";


    return 0;
}