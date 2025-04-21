#include <iostream>
#include <string>
using namespace std;

// Abstract Class
class MenuItem {
protected:
    string dishName;
    double price;

public:
    MenuItem(string name, double cost) : dishName(name), price(cost) {}

    virtual void showDetails() const = 0;
    virtual void prepare() const = 0;

    virtual ~MenuItem() {}
};

// Derived Class - Appetizer
class Appetizer : public MenuItem {
public:
    Appetizer(string name, double cost) : MenuItem(name, cost) {}

    void showDetails() const override {
        cout << "Appetizer: " << dishName << "\nPrice: PKR " << price << "\n";
    }

    void prepare() const override {
        cout << "Preparing " << dishName << ":\n- Chopping veggies\n- Adding spices\n- Quick fry\n";
    }
};

// Derived Class - MainCourse
class MainCourse : public MenuItem {
public:
    MainCourse(string name, double cost) : MenuItem(name, cost) {}

    void showDetails() const override {
        cout << "Main Course: " << dishName << "\nPrice: PKR " << price << "\n";
    }

    void prepare() const override {
        cout << "Preparing " << dishName << ":\n- Marinating meat\n- Cooking rice\n- Simmering curry\n";
    }
};

// Main flow
int main() {
    MenuItem* item1 = new Appetizer("Spring Rolls", 550.0);
    MenuItem* item2 = new MainCourse("Chicken Biryani", 850.0);

    // Use polymorphism
    cout << "\n=== Appetizer Info ===\n";
    item1->showDetails();
    item1->prepare();

    cout << "\n=== Main Course Info ===\n";
    item2->showDetails();
    item2->prepare();

    delete item1;
    delete item2;

    return 0;
}
