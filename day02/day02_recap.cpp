#include <iostream>
#include <iomanip>
#include <vector>

// ============================================================
// DAY 02 — C++ RECAP
// Topics:
// 1. if / else if / else
// 2. Comparison operators
// 3. Logical operators
// 4. Loops
// 5. Functions
// 6. Function declarations / prototypes
// 7. std::vector
// 8. Output formatting
// ============================================================


// ============================================================
// 1. FUNCTIONS
// ============================================================

// A function can receive parameters and return a value.

double calculate_next_price(double stock_price, double growth_rate) {
    return stock_price * (1 + growth_rate);
}


// void means the function does NOT return a value.

void print_welcome() {
    std::cout << "Options Pricing Engine\n";
}


// ============================================================
// 2. FUNCTION DECLARATIONS / PROTOTYPES
// ============================================================

// If a function is defined BELOW main(), C++ needs to know
// about it before it is called.
//
// Example:
//
// double calculate_profit(double buy_price, double sell_price);
//
// int main() {
//     double profit = calculate_profit(100, 120);
// }
//
// double calculate_profit(double buy_price, double sell_price) {
//     return sell_price - buy_price;
// }


// ============================================================
// MAIN
// ============================================================

int main() {

    // ========================================================
    // 3. CONDITIONAL STATEMENTS
    // ========================================================

    double stock_price = 150.0;
    double strike_price = 145.0;

    if (stock_price > strike_price) {
        std::cout << "Stock is above strike.\n";
    }
    else if (stock_price == strike_price) {
        std::cout << "Stock equals strike.\n";
    }
    else {
        std::cout << "Stock is below strike.\n";
    }


    // ========================================================
    // 4. COMPARISON OPERATORS
    // ========================================================

    // ==   equal to
    // !=   not equal to
    // >    greater than
    // <    less than
    // >=   greater than or equal to
    // <=   less than or equal to


    // ========================================================
    // 5. LOGICAL OPERATORS
    // ========================================================

    int expiration_days = 20;

    // && = AND
    // || = OR
    // !  = NOT

    if (expiration_days > 0 && expiration_days <= 30) {
        std::cout << "Option expires soon.\n";
    }

    // Often conditions can be simplified by ordering them well:

    if (expiration_days <= 0) {
        std::cout << "Option expired.\n";
    }
    else if (expiration_days <= 30) {
        // We already know expiration_days > 0
        std::cout << "Option expires soon.\n";
    }
    else {
        std::cout << "More than 30 days until expiration.\n";
    }


    // ========================================================
    // 6. FOR LOOPS
    // ========================================================

    // Structure:
    //
    // for (starting value; condition; update)

    for (int i = 0; i < 5; i++) {
        std::cout << "Iteration: " << i << '\n';
    }

    // i++ means:
    //
    // i = i + 1;


    // ========================================================
    // 7. WHILE LOOPS
    // ========================================================

    int counter = 0;

    while (counter < 5) {
        std::cout << counter << '\n';
        counter++;
    }


    // ========================================================
    // 8. break AND continue
    // ========================================================

    // break = immediately exit the loop

    for (int i = 0; i < 10; i++) {

        if (i == 5) {
            break;
        }

        std::cout << i << '\n';
    }


    // continue = skip the rest of the CURRENT iteration

    for (int i = 0; i < 5; i++) {

        if (i == 2) {
            continue;
        }

        std::cout << i << '\n';
    }


    // ========================================================
    // 9. CALLING FUNCTIONS
    // ========================================================

    double current_price = 100.0;
    double daily_growth_rate = 0.02;

    current_price =
        calculate_next_price(current_price, daily_growth_rate);

    std::cout << "New price: " << current_price << '\n';


    // Parameter vs Argument:
    //
    // Function definition:
    //
    // calculate_next_price(double stock_price,
    //                      double growth_rate)
    //
    // stock_price and growth_rate = PARAMETERS
    //
    // Function call:
    //
    // calculate_next_price(100.0, 0.02)
    //
    // 100.0 and 0.02 = ARGUMENTS


    // ========================================================
    // 10. std::vector
    // ========================================================

    // Need:
    //
    // #include <vector>

    // A vector is a resizable collection of values
    // of the same type.

    std::vector<double> prices;


    // ========================================================
    // 11. ADDING VALUES — push_back()
    // ========================================================

    prices.push_back(100.0);
    prices.push_back(102.0);
    prices.push_back(104.04);

    // prices now contains:
    //
    // [100.0, 102.0, 104.04]


    // ========================================================
    // 12. VECTOR INDEXING
    // ========================================================

    // Vectors use zero-based indexing:
    //
    // Index:       0       1       2
    //             ↓       ↓       ↓
    // prices = [100.0, 102.0, 104.04]

    std::cout << prices[0] << '\n';
    std::cout << prices[1] << '\n';
    std::cout << prices[2] << '\n';


    // ========================================================
    // 13. VECTOR SIZE
    // ========================================================

    std::cout << "Number of prices: "
              << prices.size()
              << '\n';


    // ========================================================
    // 14. FIRST AND LAST ELEMENT
    // ========================================================

    std::cout << "First: " << prices.front() << '\n';
    std::cout << "Last: " << prices.back() << '\n';


    // ========================================================
    // 15. LOOPING THROUGH A VECTOR USING INDEX
    // ========================================================

    for (int i = 0; i < prices.size(); i++) {
        std::cout << "Price " << i
                  << ": " << prices[i]
                  << '\n';
    }


    // ========================================================
    // 16. RANGE-BASED FOR LOOP
    // ========================================================

    // Similar to:
    //
    // for price in prices:
    //
    // in Python.

    for (double price : prices) {
        std::cout << price << '\n';
    }


    // ========================================================
    // 17. OUTPUT FORMATTING
    // ========================================================

    double option_price = 12.3456789;

    // fixed + setprecision(2)
    // means 2 digits AFTER the decimal.

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Option price: $"
              << option_price
              << '\n';

    // Output:
    //
    // Option price: $12.35


    // ========================================================
    // 18. RESET OUTPUT FORMATTING
    // ========================================================

    std::cout << std::defaultfloat << std::setprecision(6);


    // ========================================================
    // 19. DAY 2 PRICE PATH EXAMPLE
    // ========================================================

    double starting_price = 100.0;
    double growth_rate = 0.02;
    int number_of_days = 3;

    std::vector<double> price_path;

    // Day 0
    price_path.push_back(starting_price);

    double simulated_price = starting_price;

    // Calculate and store future prices.

    for (int i = 0; i < number_of_days; i++) {

        simulated_price =
            calculate_next_price(simulated_price, growth_rate);

        price_path.push_back(simulated_price);
    }


    // Print after calculations are complete.

    std::cout << std::fixed << std::setprecision(2);

    for (int i = 0; i < price_path.size(); i++) {

        std::cout << "Day " << i
                  << ": "
                  << price_path[i]
                  << '\n';
    }

    std::cout << "Number of prices stored: "
              << price_path.size()
              << '\n';


    // ========================================================
    // QUICK REMINDERS
    // ========================================================

    // Assignment:
    //
    // x = 5;
    //
    // Comparison:
    //
    // x == 5;


    // Increment:
    //
    // i++;
    //
    // Same basic idea as:
    //
    // i = i + 1;


    // Compound assignment:
    //
    // x += 5;
    // x -= 5;
    // x *= 5;
    // x /= 5;


    // Vector:
    //
    // std::vector<double> values;
    //
    // Add:
    // values.push_back(x);
    //
    // Access:
    // values[i];
    //
    // Size:
    // values.size();
    //
    // First:
    // values.front();
    //
    // Last:
    // values.back();


    // Function:
    //
    // double function_name(double x) {
    //     return x * 2;
    // }


    return 0;
}