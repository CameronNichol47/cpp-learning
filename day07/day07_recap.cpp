/*
DAY 07 RECAP — C++ Headers, Source Files, and Linking
Concept 25: Header files (.hpp), #include, #pragma once
Concept 26: Function declarations versus definitions
Concept 27: Separate compilation, object files, linking
Concept 28: Modular Black–Scholes pricing

This is a SINGLE-FILE, compilable recap for review. The real Day 7 assignment
splits the code across four files. See the file layout and commands below.

PROJECT LAYOUT:
  OptionParameters.hpp  -> defines struct OptionParameters
  BlackScholes.hpp      -> declares pricing functions; includes OptionParameters.hpp
  BlackScholes.cpp      -> defines pricing functions; includes BlackScholes.hpp and <cmath>
  main.cpp              -> includes headers and runs tests

EXAMPLE CONTENT OF OptionParameters.hpp:
  #pragma once
  struct OptionParameters { double S, K, r, sigma, T; };

EXAMPLE CONTENT OF BlackScholes.hpp:
  #pragma once
  #include "OptionParameters.hpp"
  double d1(const OptionParameters& option);
  double d2(const OptionParameters& option);
  double normal_cdf(double x);
  double black_scholes_call(const OptionParameters& option);
  double black_scholes_put(const OptionParameters& option);
  bool check_put_call_parity(const OptionParameters& option);

DECLARATION vs DEFINITION:
  Declaration: double normal_cdf(double x); // tells compiler the signature
  Definition:  double normal_cdf(double x) { ... } // provides implementation

COMPILATION / LINKING (when using separate files):
  clang++ -std=c++20 -c main.cpp          # produces main.o
  clang++ -std=c++20 -c BlackScholes.cpp  # produces BlackScholes.o
  clang++ main.o BlackScholes.o -o pricing # linker creates executable
  ./pricing                               # runs executable

Or in one command:
  clang++ -std=c++20 main.cpp BlackScholes.cpp -o pricing && ./pricing

IMPORTANT DEBUGGING LESSON:
  Editing main.cpp does NOT update an old executable named main.
  ./main runs the existing executable, not main.cpp or main.o.
  If you compile with -o pricing, run ./pricing (not ./main).
  'undeclared identifier' -> missing/incorrect declaration at compile time.
  'undefined symbol'     -> missing definition during linking.
  Never #include a .cpp implementation file; include its .hpp instead.

The implementations below are in this one file ONLY so the recap can compile
independently; in your actual project move them to BlackScholes.cpp.
*/

#include <cmath>      // std::log, std::sqrt, std::exp, std::erf, std::abs
#include <iomanip>    // std::fixed, std::setprecision, std::boolalpha
#include <iostream>   // std::cout

// Normally lives in OptionParameters.hpp.
struct OptionParameters {
    double S;      // current stock price
    double K;      // strike price
    double r;      // continuously compounded risk-free annual interest rate
    double sigma;  // annual volatility (e.g. 0.25 = 25%)
    double T;      // time until expiration in years
};

// In a multi-file project, these declarations live in BlackScholes.hpp.
double d1(const OptionParameters& option);
double d2(const OptionParameters& option);
double normal_cdf(double x);
double black_scholes_call(const OptionParameters& option);
double black_scholes_put(const OptionParameters& option);
bool check_put_call_parity(const OptionParameters& option);

// In a multi-file project, these definitions live in BlackScholes.cpp.
double d1(const OptionParameters& option) {
    return (std::log(option.S / option.K)
            + (option.r + option.sigma * option.sigma / 2.0) * option.T)
           / (option.sigma * std::sqrt(option.T));
}

double d2(const OptionParameters& option) {
    return d1(option) - option.sigma * std::sqrt(option.T);
}

double normal_cdf(double x) {
    // Standard normal CDF: N(x) = (1 + erf(x / sqrt(2))) / 2.
    return 0.5 * (1.0 + std::erf(x / std::sqrt(2.0)));
}

double black_scholes_call(const OptionParameters& option) {
    // European call: C = S*N(d1) - K*exp(-r*T)*N(d2)
    return option.S * normal_cdf(d1(option))
           - option.K * std::exp(-option.r * option.T) * normal_cdf(d2(option));
}

double black_scholes_put(const OptionParameters& option) {
    // European put: P = K*exp(-r*T)*N(-d2) - S*N(-d1)
    return option.K * std::exp(-option.r * option.T) * normal_cdf(-d2(option))
           - option.S * normal_cdf(-d1(option));
}

bool check_put_call_parity(const OptionParameters& option) {
    // Put-call parity (no dividends): C - P = S - K*exp(-r*T)
    const double lhs = black_scholes_call(option) - black_scholes_put(option);
    const double rhs = option.S - option.K * std::exp(-option.r * option.T);
    return std::abs(lhs - rhs) < 1e-8; // tolerance for floating-point rounding
}

int main() {
    const OptionParameters option{200.0, 210.0, 0.05, 0.25, 0.5};

    std::cout << std::fixed << std::setprecision(4) << std::boolalpha;
    std::cout << "Call Price: " << black_scholes_call(option) << '\n';
    std::cout << "Put Price: " << black_scholes_put(option) << '\n';
    std::cout << "Put-Call Parity: " << check_put_call_parity(option) << '\n';

    // EXPECTED OUTPUT:
    // Call Price: 11.9770
    // Put Price: 16.7921
    // Put-Call Parity: true
}
