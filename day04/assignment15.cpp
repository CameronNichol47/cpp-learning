#include <iostream>
#include <iomanip>
#include <string>

class Stock {
    private:
        std::string ticker;
        double price;
    public:
        Stock() : ticker("UNKNOWN"), price(0.0) {
        }

        Stock(const std::string& new_ticker, double new_price)
            : ticker(new_ticker), price(new_price >= 0.0 ? new_price : 0.0) {
        }

        std::string get_ticker() const {
            return ticker;
        }

        double get_price() const {
            return price;
        }

        void set_price(double new_price) {
            if (new_price >= 0.0) {
                price = new_price;
            }
        }

        Stock(const std::string& new_ticker) 
            : ticker(new_ticker), price(0.0) {
        }
};

int main() {
    Stock apple("AAPL", 200.0);

    Stock tesla("TSLA", 350.0);

    Stock unknown;

    std::cout << std::fixed << std::setprecision(2);

    std::cout << apple.get_ticker() << ": " << apple.get_price() << "\n";
    std::cout << tesla.get_ticker() << ": " << tesla.get_price() << "\n";
    std::cout << unknown.get_ticker() << ": " << unknown.get_price() << "\n";
    
    Stock invalid("NVDA", -100.0);

    Stock microsoft("MSFT");

    std::cout << invalid.get_ticker() << ": " << invalid.get_price() << "\n";
    std::cout << microsoft.get_ticker() << ": " << microsoft.get_price() << "\n";

}