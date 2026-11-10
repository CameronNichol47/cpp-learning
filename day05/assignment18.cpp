#include <iostream>
#include <cmath>
#include <iomanip>

bool approximately_equal(double a, double b, double tolerance) {
    return std::abs(a - b) < tolerance;
}

int main() {
    //part A

    double a = 0.1;
    double b = 0.2;
    double diff = std::abs((a + b) - 0.3);

    std::cout << std::boolalpha;

    std::cout << ((a+b) == 0.3) << "\n";
    std::cout << (diff <= 1e-9) << "\n";
    std::cout << std::setprecision(17) << (a + b) << "\n";

    //Part B

    double model_price = 12.3456789;
    double market_price = 12.3456791;

    std::cout << std::fixed << std::setprecision(10);
    std::cout << std::abs(model_price - market_price) << "\n";

    std::cout<<std::boolalpha;
    std::cout << (std::abs(model_price - market_price) < 1e-6) << "\n";

    //Part C

    double stock_price = 200.0;
    double strike_price = 210.0;
    double volatility = 0.0;
    double time_to_expiry = 0.5;

    if (!(stock_price > 0 && strike_price > 0 && volatility > 0 && time_to_expiry > 0)) {
        std::cout << "Invalid Black-Scholes inputs. \n";
    } else {
        std::cout << "Inputs are valid. \n";
    }
    
    //Bonus

    std::cout << approximately_equal(a + b, 0.3, 1e-9) << "\n";

    std::cout << approximately_equal(model_price, market_price, 1e-6) << "\n"; 



    return 0;
}