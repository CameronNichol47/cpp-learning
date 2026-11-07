// DAY 04 — C++ CONCEPT RECAP
// Topics: structs, classes, access control, constructors, initializer lists,
//         const member functions, this pointer, and method chaining.
// Compile: clang++ -std=c++17 day04_recap.cpp -o day04_recap
// Run:     ./day04_recap

#include <iostream>
#include <iomanip>
#include <string>

// ============================================================
// 1. STRUCTS: a custom type that groups related data.
// ============================================================
// A struct's members are PUBLIC by default. It can contain both
// data and functions. The definition ends with a semicolon.
struct OptionContract {
    std::string ticker;
    double strike_price;
    double time_to_expiry;
    bool is_call;
};

// Passing by const reference avoids copying and prevents changes
// through the reference. A struct's members use the dot operator.
void print_option(const OptionContract& option) {
    std::cout << option.ticker << " strike=" << option.strike_price
              << " expiry=" << option.time_to_expiry
              << " type=" << (option.is_call ? "Call" : "Put") << '\n';
}

// Passing by non-const reference lets a function modify the original.
void change_strike(OptionContract& option, double new_strike) {
    if (new_strike >= 0.0) {
        option.strike_price = new_strike;
    }
}

// ============================================================
// 2. CLASSES: custom types with controlled access.
// ============================================================
// class members are PRIVATE by default (unlike struct).
// public:  accessible from outside the class.
// private: accessible from the class's own member functions.
// Encapsulation means keeping internal state controlled by
// public operations. A setter can enforce an invariant.
class Stock {
private:
    std::string ticker;
    double price;

public:
    // ========================================================
    // 3. CONSTRUCTORS: run when an object is created.
    // ========================================================
    // Same name as class, NO return type (not even void).
    // Constructors can be overloaded by parameter list.

    // Default constructor: can be called without arguments.
    Stock() : ticker("UNKNOWN"), price(0.0) {}

    // Parameterized constructor with a MEMBER INITIALIZER LIST.
    // The name BEFORE (...) identifies the member; the name
    // INSIDE (...) is the parameter when they share a name.
    // price(price) is valid, but we validate before initializing.
    Stock(const std::string& ticker, double price)
        : ticker(ticker), price(price >= 0.0 ? price : 0.0) {}

    // Constructor overloading: ticker only.
    Stock(const std::string& ticker)
        : ticker(ticker), price(0.0) {}

    // Initializer lists initialize members directly. By contrast,
    // assignments in a constructor body happen AFTER members are
    // initialized. Prefer initializer lists, especially for const
    // members, references, and members lacking default constructors.
    // IMPORTANT: initialization order follows MEMBER DECLARATION
    // order, not the order written in the initializer list.

    // ========================================================
    // 4. GETTERS, SETTERS, AND CONST MEMBER FUNCTIONS.
    // ========================================================
    void set_price(double price) {
        // Parameter "price" hides member "price" here.
        // this->price explicitly means this object's member.
        if (price >= 0.0) {
            this->price = price;
        }
    }

    double get_price() const {
        // Trailing const: this function cannot modify ordinary
        // data members of the object through this.
        return price; // "this->price" would also work.
    }

    std::string get_ticker() const {
        return ticker;
    }

    // Member functions can access private members directly.
    // Reusing set_price avoids duplicating validation logic.
    void apply_growth(double growth_rate) {
        set_price(price * (1.0 + growth_rate));
    }

    // ========================================================
    // 5. THE this POINTER AND METHOD CHAINING.
    // ========================================================
    // In a non-static member function, this points to the
    // current object. this->price means (*this).price.
    // this cannot be reassigned. Static member functions have
    // no this pointer.
    //
    // this  = pointer to current object
    // *this = current object (an lvalue)
    //
    // Returning Stock& avoids a copy and supports chaining.
    Stock& update_price(double new_price) {
        set_price(new_price);
        return *this;
    }
};

// ============================================================
// 6. SMALL BUT IMPORTANT DETAILS
// ============================================================
// - Stock apple; calls the default constructor.
// - Stock apple("AAPL", 200.0); calls a parameterized constructor.
// - If you declare a constructor taking arguments, the compiler
//   does not automatically supply a no-argument constructor.
// - A class can contain member functions defined inside the class,
//   or declared in a .hpp and defined in a separate .cpp.
// - this-> is NOT needed when a member name isn't hidden.
// - In an initializer list, write : price(price), NOT
//   : this->price(price) (the latter is invalid syntax).
// - With a constructor BODY, this->price = price distinguishes
//   a member from a parameter with the same name.
// - A const object can call const member functions, but not
//   ordinary non-const member functions.
// - An object's pointer uses ->, e.g. ptr->get_price().
// - C++ structs and classes can both have private/public members,
//   functions, constructors, and inheritance; their main language
//   difference is the default access level.
// - A header (.hpp) is a file convention, NOT a Java interface.
//   Header: declarations; source (.cpp): definitions (commonly).
// - For multiple source files:
//   clang++ -std=c++17 main.cpp Stock.cpp -o stock_program

int main() {
    std::cout << std::fixed << std::setprecision(2);

    // Aggregate initialization: values match struct member order.
    OptionContract call{"AAPL", 210.0, 0.5, true};
    print_option(call);
    change_strike(call, 225.0);
    print_option(call);

    Stock unknown;                   // Default constructor
    Stock apple("AAPL", 200.0);     // Two-parameter constructor
    Stock microsoft("MSFT");        // One-parameter constructor
    Stock invalid("NVDA", -100.0);  // Negative price becomes 0

    std::cout << unknown.get_ticker() << ": " << unknown.get_price() << '\n';
    std::cout << microsoft.get_ticker() << ": " << microsoft.get_price() << '\n';
    std::cout << invalid.get_ticker() << ": " << invalid.get_price() << '\n';

    apple.set_price(220.0);
    apple.apply_growth(0.10);       // 220 * 1.10 = 242
    apple.set_price(-100.0);        // Rejected: remains 242
    std::cout << apple.get_ticker() << ": " << apple.get_price() << '\n';

    apple.update_price(300.0).update_price(350.0);
    std::cout << "After chaining: " << apple.get_price() << '\n';

    // Pointer to an object: -> accesses members through pointer.
    Stock* ptr = &apple;
    std::cout << "Via pointer: " << ptr->get_price() << '\n';

    // Const objects can call getters because getters are const.
    const Stock tesla("TSLA", 350.0);
    std::cout << tesla.get_ticker() << ": " << tesla.get_price() << '\n';
    // tesla.set_price(400.0); // ERROR: setter is not const

    return 0;
}
