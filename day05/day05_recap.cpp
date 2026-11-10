// DAY 05 — C++ RECAP (ONLY THE CONCEPTS WE COVERED)
// Compile: clang++ -std=c++20 day05_recap.cpp -o day05_recap
// Run:     ./day05_recap
//
// Concept 17: <cmath> functions
// Concept 18: floating-point precision and comparisons
// Concept 19: reusable functions, structs, const references, input validation
// Concept 20: normal PDF and CDF; their use in Black–Scholes

#include <iostream>
#include <iomanip>
#include <cmath>
#include <numbers>

// ------------------------------------------------------------
// CONCEPT 17 — <cmath>
// ------------------------------------------------------------
// std::sqrt(x)       square root
// std::pow(x, y)     x raised to y (the ^ operator is NOT a power)
// std::exp(x)        e^x
// std::log(x)        natural logarithm, ln(x)
// std::log10(x)      base-10 logarithm
// std::abs(x)        absolute value
// std::erf(x)        error function, used in the normal CDF
// std::isfinite(x)   checks that x is neither infinity nor NaN
// std::isnan(x)      checks for NaN
// std::isinf(x)      checks for infinity
//
// For squaring, x*x is often simpler than std::pow(x, 2).
// For real-valued calculations, std::sqrt requires x >= 0,
// and std::log requires x > 0.
// C++20 <numbers> provides std::numbers::pi for accurate pi.

// ------------------------------------------------------------
// CONCEPT 18 — FLOATING-POINT PRECISION
// ------------------------------------------------------------
// Binary floating-point cannot represent many decimal fractions exactly.
// So 0.1 + 0.2 may not compare equal to 0.3 with ==.
// float: about 6-7 significant decimal digits.
// double: about 15-17 significant decimal digits.
// We use double for our options calculations.
//
// Absolute difference = |a-b|.
// A tolerance checks whether two calculated values are close enough.
// 1e-9 = 0.000000001 (scientific notation).
bool approximately_equal(double a, double b, double tolerance) {
    return std::abs(a - b) < tolerance;
}

// Absolute error: |true - approximate|.
// Relative error: |true - approximate| / |true|, if true != 0.
// We also discussed a combined absolute/relative comparison:
// |a-b| <= abs_tol + rel_tol * max(|a|, |b|).
// We do not need an extra function to understand that formula yet.
//
// std::setprecision(17): 17 significant digits by default.
// std::fixed << std::setprecision(4): 4 digits after decimal point.
// IMPORTANT: formatting changes the PRINTED value, not the stored double.

// ------------------------------------------------------------
// CONCEPT 19 — STRUCTS + REUSABLE MATHEMATICAL FUNCTIONS
// ------------------------------------------------------------
// A struct groups related values into one custom type.
struct OptionParameters {
    double S;      // stock price
    double K;      // strike price
    double r;      // risk-free interest rate
    double sigma;  // volatility
    double T;      // time to expiry (years)
};

// const OptionParameters& means:
//   &     pass by reference instead of copying the whole struct
//   const do not modify the object through that reference
// Valid for our current d1/d2 formula: S, K, sigma, T must be positive.
// The risk-free rate may be negative but must be finite.
bool valid_inputs(const OptionParameters& option) {
    if (!(option.S > 0 && option.K > 0 &&
          option.sigma > 0 && option.T > 0)) {
        return false;
    } else if (!(std::isfinite(option.S) && std::isfinite(option.K) &&
                 std::isfinite(option.sigma) && std::isfinite(option.T))) {
        return false;
    } else if (!std::isfinite(option.r)) {
        return false;
    }
    return true;
}

// d1 = [ln(S/K) + (r + sigma^2/2)*T] / [sigma*sqrt(T)]
double calculate_d1(const OptionParameters& option) {
    double numerator = std::log(option.S / option.K) +
                       (option.r + std::pow(option.sigma, 2) / 2.0) * option.T;
    double denominator = option.sigma * std::sqrt(option.T);
    return numerator / denominator;
}