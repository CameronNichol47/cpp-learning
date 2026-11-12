#include <iostream>
#include "OptionParameters.hpp"
#include "BlackScholes.hpp"
#include <iomanip>

int main() {
    OptionParameters option{200, 210, 0.05, 0.25, 0.5};

    std::cout << std::fixed << std::setprecision(4);
    std::cout << std::boolalpha;

    std::cout << "Call Price: " << black_scholes_call(option) << "\n";
    std::cout << "Put Price: " << black_scholes_put(option) << "\n";
    std::cout << "Put-Call Parity: " << check_put_call_parity(option) << "\n";
    return 0;
}