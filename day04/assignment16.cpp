#include <iostream>
#include <iomanip>
#include <string>

class Stock {
    private:
        std::string ticker;
        double price;
    public:
        Stock(const std::string& ticker, double price)
            : ticker(ticker), price(price >= 0.0 ? price : 0.0) {
        }

        void set_price(double price) {
            if (price >= 0.0) {
                this->price = price;
            }
        }

        void apply_growth(double growth_rate) {
            this->set_price(this->price * (1+growth_rate));
        }

        double get_price() const {
            return this->price;
        }

        std::string get_ticker() const {
            return this->ticker;
        }

        Stock& update_price(double new_price) {
            set_price(new_price);
            return *this;
        }

};

int main() {
    Stock apple("AAPL", 200.0);

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Ticker: " << apple.get_ticker() << "\n";
    std::cout << "Initial Price: " << apple.get_price() << "\n";

    apple.set_price(220.0);

    apple.apply_growth(0.10);

    apple.set_price(-100.0);

    std::cout << "Final Price: " << apple.get_price() << "\n";

    apple.update_price(300.0).update_price(350.0);

    std::cout << "Updated Price: " << apple.get_price() << "\n";
    return 0;
}