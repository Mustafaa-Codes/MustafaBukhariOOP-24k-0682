/*
24k-0682
Syed Mustafa Bukhari
Lab 5 Question 7
*/
#include <iostream>
#include <string>

class Product {
public:
    int id;
    std::string name;
    int quantity;

    Product(int id, std::string name, int quantity) : id(id), name(name), quantity(quantity) {}
};

class Warehouse {
private:
    Product* inventory[50];
    int productCount;

public:
    Warehouse() : productCount(0) {}

    void addProduct(int id, std::string name, int quantity) {
        if (productCount < 50) {
            inventory[productCount++] = new Product(id, name, quantity);
        }
    }

    void sortProducts() {
        for (int i = 0; i < productCount - 1; i++) {
            for (int j = i + 1; j < productCount; j++) {
                if (inventory[i]->name > inventory[j]->name) {
                    std::swap(inventory[i], inventory[j]);
                }
            }
        }
    }

    Product* searchProduct(int id) {
        for (int i = 0; i < productCount; i++) {
            if (inventory[i]->id == id) {
                return inventory[i];
            }
        }
        return nullptr;
    }

    void displayProducts() {
        std::cout << "Warehouse Inventory:\n";
        for (int i = 0; i < productCount; i++) {
            std::cout << "ID: " << inventory[i]->id << ", Name: " << inventory[i]->name 
                      << ", Quantity: " << inventory[i]->quantity << "\n";
        }
        std::cout << "----------------------\n";
    }

    ~Warehouse() {
        for (int i = 0; i < productCount; i++) {
            delete inventory[i];
        }
    }
};

int main() {
    Warehouse warehouse;
    warehouse.addProduct(101, "Chair", 20);
    warehouse.addProduct(102, "Laptop", 10);
    warehouse.addProduct(103, "Apple", 50);

    warehouse.sortProducts();
    warehouse.displayProducts();

    int searchId = 102;
    Product* foundProduct = warehouse.searchProduct(searchId);
    if (foundProduct) {
        std::cout << "Product Found: ID: " << foundProduct->id << ", Name: " 
                  << foundProduct->name << ", Quantity: " << foundProduct->quantity << "\n";
    } else {
        std::cout << "Product not found.\n";
    }

    return 0;
}
