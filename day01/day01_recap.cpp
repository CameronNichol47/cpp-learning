#include <iostream>
#include <string>

int main() {

    // ============================================================
    // 1. BASIC DATA TYPES
    // ============================================================

    int expiration_days = 30;          // Whole numbers
    double stock_price = 227.50;       // Decimal numbers
    bool is_call = true;               // true or false
    char option_type = 'C';            // Single character
    std::string ticker = "AAPL";       // String/text


    // ============================================================
    // 2. OUTPUT WITH std::cout
    // ============================================================

    std::cout << "Ticker: " << ticker << "\n";
    std::cout << "Stock Price: " << stock_price << "\n";
    std::cout << "Expiration Days: " << expiration_days << "\n";


    // ============================================================
    // 3. VARIABLES CAN CHANGE
    // ============================================================

    double strike_price = 230.00;

    strike_price = 235.00;  // Allowed because it is not const

    std::cout << "Strike Price: " << strike_price << "\n";


    // ============================================================
    // 4. CONST VARIABLES
    // ============================================================

    const double risk_free_rate = 0.04;

    // This would cause an error:
    // risk_free_rate = 0.05;

    std::cout << "Risk-Free Rate: " << risk_free_rate << "\n";


    // ============================================================
    // 5. ARITHMETIC
    // ============================================================

    double price_difference = stock_price - strike_price;

    std::cout << "Price Difference: "
              << price_difference << "\n";


    // ============================================================
    // 6. INTEGER DIVISION
    // ============================================================

    int x = 5;
    int y = 2;

    // int / int produces integer division
    double result1 = x / y;

    // One operand being double produces floating-point division
    double result2 = x / 2.0;

    std::cout << "Integer Division: " << result1 << "\n";
    std::cout << "Floating-Point Division: " << result2 << "\n";


    // ============================================================
    // 7. CASTING
    // ============================================================

    double result3 = static_cast<double>(x) / y;

    std::cout << "Using static_cast: " << result3 << "\n";


    // Example important for the options engine:

    double time_to_expiration =
        static_cast<double>(expiration_days) / 365;

    std::cout << "Time to Expiration: "
              << time_to_expiration << "\n";


    // ============================================================
    // 8. ANOTHER WAY TO FORCE FLOATING-POINT DIVISION
    // ============================================================

    double time2 = expiration_days / (365 * 1.0);

    // This works because 1.0 is a double.
    // Therefore:
    //
    // 365 * 1.0
    //
    // becomes:
    //
    // 365.0
    //
    // so the division becomes:
    //
    // 30 / 365.0

    std::cout << "Time using * 1.0: " << time2 << "\n";


    // ============================================================
    // 9. DOUBLE -> INT CASTING
    // ============================================================

    double decimal_number = 8.75;

    int whole_number =
        static_cast<int>(decimal_number);

    // The decimal portion is discarded.
    // Result: 8

    std::cout << "Double converted to int: "
              << whole_number << "\n";


    // ============================================================
    // 10. BOOL OUTPUT
    // ============================================================

    std::cout << "Call Option: " << is_call << "\n";

    // By default:
    // true  -> 1
    // false -> 0

    std::cout << std::boolalpha;

    std::cout << "Call Option with boolalpha: "
              << is_call << "\n";


    // ============================================================
    // 11. COMPOUND ASSIGNMENT
    // ============================================================

    double account_value = 1000.0;

    account_value += 100.0;   // Same as account_value = account_value + 100
    account_value -= 50.0;
    account_value *= 2.0;
    account_value /= 2.0;

    std::cout << "Account Value: "
              << account_value << "\n";


    // ============================================================
    // 12. ++ AND --
    // ============================================================

    int contracts = 5;

    contracts++;   // Add 1
    contracts--;   // Subtract 1

    std::cout << "Contracts: " << contracts << "\n";


    // ============================================================
    // 13. IF / ELSE IF / ELSE
    // ============================================================

    if (stock_price > strike_price) {

        std::cout << "Stock price is above strike.\n";

    }
    else if (stock_price == strike_price) {

        std::cout << "Stock price equals strike.\n";

    }
    else {

        std::cout << "Stock price is below strike.\n";

    }


    // ============================================================
    // 14. SCOPE
    // ============================================================

    if (stock_price > 200) {

        double amount_above_200 =
            stock_price - 200;

        // amount_above_200 exists inside this block.

        std::cout << "Amount Above $200: "
                  << amount_above_200 << "\n";
    }

    // This would NOT work:
    //
    // std::cout << amount_above_200;
    //
    // because amount_above_200 only exists inside
    // the if block above.


    // ============================================================
    // 15. USER INPUT
    // ============================================================

    double user_stock_price;

    std::cout << "Enter a stock price: ";
    std::cin >> user_stock_price;

    std::cout << "You entered: "
              << user_stock_price << "\n";


    // ============================================================
    // QUICK REMINDERS
    // ============================================================

    // =   assignment
    // ==  comparison
    // !=  not equal
    // >   greater than
    // <   less than
    // >=  greater than or equal
    // <=  less than or equal

    // int / int       -> integer division
    // int / double    -> floating-point division
    // double / int    -> floating-point division
    // double / double -> floating-point division

    // 'C'      -> char
    // "AAPL"   -> string

    // Prefer local variables unless there is a reason
    // for something to be global.

    // const means the variable cannot be modified
    // after initialization.

    return 0;
}