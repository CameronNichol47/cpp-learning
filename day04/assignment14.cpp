#include <iostream>
#include <string>
#include <iomanip>

class Stock {
private:
    std::string ticker;
    double price = 0.0;
public: 
    void set_ticker(const std::string& new_ticker){
        ticker = new_ticker;
    }

    void set_price(double new_price) {
        if (new_price >= 0.0) {
            price = new_price;
        }
    }

    std::string get_ticker() const {
        return ticker;
    }

    double get_price() const {
        return price;
    }

    void apply_growth(double growth_rate) {
        double s;
        s = get_price();
        s *= (1 + growth_rate);
        set_price(s);
    }
};



int main() {
    Stock stock;

    std::string ticker;
    double price;

    std::cout << "Enter ticker: ";
    std::cin >> ticker;

    std::cout << "Enter stock price: ";
    std::cin >> price;

    stock.set_ticker(ticker);
    stock.set_price(price);

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Ticker: " << stock.get_ticker() << "\nPrice: " << stock.get_price() << "\n";

    stock.set_price(-50.0);

    std::cout << "Price: " << stock.get_price() << "\n";

    stock.apply_growth(0.05);

    std::cout << "Price: " << stock.get_price() << "\n";


}