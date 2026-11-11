// DAY 06 RECAP — BLACK–SCHOLES EUROPEAN OPTION PRICING
// Concepts 21–24: Call pricing, put pricing, put–call parity, testing.
// Compile: clang++ -std=c++20 day06_recap.cpp -o day06_recap
// Run:     ./day06_recap
//
// This file contains only the material covered on Day 6, with the Day 5
// helper functions needed to make the program compile and run.

#include <iostream>  // std::cout, std::boolalpha
#include <iomanip>   // std::fixed, std::setprecision
#include <cmath>     // std::log, std::sqrt, std::exp, std::erf, std::abs

// Store the five Black–Scholes inputs in one object.
// S: stock price; K: strike; r: annual risk-free rate;
// sigma: annual volatility; T: years to expiration.
struct OptionParameters {
    double S;
    double K;
    double r;
    double sigma;
    double T;
};

// Day 5 helpers, reused in Day 6.
// d1 = [ln(S/K) + (r + sigma^2/2)T] / [sigma sqrt(T)]
double d1(const OptionParameters& option) {
    return (std::log(option.S / option.K)
            + (option.r + std::pow(option.sigma, 2) / 2.0) * option.T)
           / (option.sigma * std::sqrt(option.T));
}

// d2 = d1 - sigma sqrt(T)
double d2(const OptionParameters& option) {
    return d1(option) - option.sigma * std::sqrt(option.T);
}

// N(x) = P(Z <= x), for Z ~ standard normal.
// Black–Scholes prices use the normal CDF, not the PDF.
double normal_cdf(double x) {
    return 0.5 * (1.0 + std::erf(x / std::sqrt(2.0)));
}

// CONCEPT 21 — EUROPEAN CALL PRICE
// C = S*N(d1) - K*exp(-r*T)*N(d2)
// A call gives the right to BUY at strike K at expiration.
// Intrinsic value today: max(S-K, 0).
// The returned premium is PER SHARE, not per 100-share contract.
double black_scholes_call(const OptionParameters& option) {
    return option.S * normal_cdf(d1(option))
         - option.K * std::exp(-option.r * option.T) * normal_cdf(d2(option));
}

// CONCEPT 22 — EUROPEAN PUT PRICE
// P = K*exp(-r*T)*N(-d2) - S*N(-d1)
// A put gives the right to SELL at strike K at expiration.
// Intrinsic value today: max(K-S, 0).
double black_scholes_put(const OptionParameters& option) {
    return option.K * std::exp(-option.r * option.T) * normal_cdf(-d2(option))
         - option.S * normal_cdf(-d1(option));
}

// CONCEPT 23 — PUT–CALL PARITY
// For European calls/puts with the same strike and expiry,
// assuming no dividends: C - P = S - K*exp(-r*T).
// Use a tolerance, not ==, when comparing floating-point calculations.
bool check_put_call_parity(const OptionParameters& option) {
    double lhs = black_scholes_call(option) - black_scholes_put(option);
    double rhs = option.S - option.K * std::exp(-option.r * option.T);
    return std::abs(lhs - rhs) < 1e-8;
}

// CONCEPT 24 — REUSABLE TEST OUTPUT
// A void function prints results rather than returning a price.
// const OptionParameters& avoids copying and prevents modification.
void print_option_results(const OptionParameters& option) {
    std::cout << std::fixed << std::setprecision(4) << std::boolalpha;
    std::cout << "S=" << option.S << ", K=" << option.K
              << ", r=" << option.r << ", sigma=" << option.sigma
              << ", T=" << option.T << '\n';
    std::cout << "d1: " << d1(option) << '\n';
    std::cout << "d2: " << d2(option) << '\n';
    std::cout << "N(d1): " << normal_cdf(d1(option)) << '\n';
    std::cout << "N(d2): " << normal_cdf(d2(option)) << '\n';
    std::cout << "Call: " << black_scholes_call(option) << '\n';
    std::cout << "Put: " << black_scholes_put(option) << '\n';
    std::cout << "Parity: " << check_put_call_parity(option) << "\n\n";
}

int main() {
    // Your original test from Assignments 21–23:
    OptionParameters option1{200, 210, 0.05, 0.25, 0.5};
    // Deep in-the-money call, out-of-the-money put:
    OptionParameters option2{150, 100, 0.05, 0.20, 1.0};
    // Deep out-of-the-money call, in-the-money put:
    OptionParameters option3{50, 100, 0.05, 0.20, 1.0};
    // Extra at-the-money test discussed on Day 6:
    OptionParameters option4{100, 100, 0.05, 0.20, 1.0};

    print_option_results(option1);
    print_option_results(option2);
    print_option_results(option3);
    print_option_results(option4);

    // THEORY RECAP:
    // Premium = intrinsic value + time (extrinsic) value.
    // For option2, call intrinsic value is $50; the BS premium is
    // approximately $54.97, leaving about $4.97 in extrinsic value.
    // This does NOT predict that the stock will rise by $4.97.
    //
    // Brownian motion underlies the Black–Scholes stock-price model:
    // dS_t = mu*S_t*dt + sigma*S_t*dW_t.
    // The closed-form pricing functions above account for this model
    // analytically, so we do NOT simulate Brownian motion here.
    // Monte Carlo simulation will come later.
    //
    // IMPORTANT ASSUMPTIONS for these formulas:
    // European exercise; no dividends; constant volatility and rate;
    // positive S, K, sigma, T; frictionless-market model.
    // These are theoretical prices, not guaranteed market quotes.
    return 0;
}
