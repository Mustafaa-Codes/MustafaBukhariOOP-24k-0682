#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
    string productID, productName;
    double price;
    int stockQuantity;
public:
    Product(string id, string name, double p, int stock = 0) 
        : productID(id), productName(name), price(p), stockQuantity(stock) {}
    virtual double applyDiscount() { return price; }
    virtual double calculateTotalPrice(int quantity) { return applyDiscount() * quantity; }
    virtual void displayProductInfo() {
        cout << "Product ID: " << productID << "\nProduct Name: " << productName 
             << "\nPrice: $" << price << "\nStock: " << stockQuantity << endl;
    }
    friend Product operator+(const Product &p1, const Product &p2) {
        return Product("", "Bulk Purchase", p1.price + p2.price);
    }
    friend ostream& operator<<(ostream &out, const Product &p) {
        out << "Product: " << p.productName << " | Price: $" << p.price;
        return out;
    }
};

class Electronics : public Product {
    int warrantyPeriod;
    string brand;
public:
    Electronics(string id, string name, double p, int stock, int warranty, string brandName) 
        : Product(id, name, p, stock), warrantyPeriod(warranty), brand(brandName) {}
    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "Warranty: " << warrantyPeriod << " months\nBrand: " << brand << endl;
    }
};

class Clothing : public Product {
    string size, color, fabricMaterial;
public:
    Clothing(string id, string name, double p, int stock, string sz, string clr, string fabric) 
        : Product(id, name, p, stock), size(sz), color(clr), fabricMaterial(fabric) {}
    double applyDiscount() override { return price * 0.9; }
};

class FoodItem : public Product {
    string expirationDate;
    int calories;
public:
    FoodItem(string id, string name, double p, int stock, string expiry, int cal) 
        : Product(id, name, p, stock), expirationDate(expiry), calories(cal) {}
    double calculateTotalPrice(int quantity) override {
        return (quantity >= 5) ? (applyDiscount() * quantity * 0.9) : applyDiscount() * quantity;
    }
};

class Book : public Product {
    string author, genre;
public:
    Book(string id, string name, double p, int stock, string auth, string gen) 
        : Product(id, name, p, stock), author(auth), genre(gen) {}
    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "Author: " << author << "\nGenre: " << genre << endl;
    }
};

int main() {
    Electronics laptop("E1", "Gaming Laptop", 1200.0, 10, 24, "TechBrand");
    Clothing shirt("C1", "Casual Shirt", 40.0, 50, "M", "Blue", "Cotton");
    FoodItem apple("F1", "Apple", 1.5, 100, "2025-01-01", 95);
    Book novel("B1", "Mystery Novel", 15.0, 20, "John Doe", "Mystery");
    
    laptop.displayProductInfo();
    cout << "Discounted Price: $" << shirt.applyDiscount() << endl;
    cout << "Total Price for 6 Apples: $" << apple.calculateTotalPrice(6) << endl;
    novel.displayProductInfo();
    
    Product bundle = laptop + novel;
    cout << bundle << endl;
    
    return 0;
}
