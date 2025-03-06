/*
24k-0682
Syed Mustafa Bukhari
Lab 5 Question 1  
*/
#include <iostream>
#include <cstring>

class Apartment {
private:
    int id;
    std::string address;
    char* owner;

public:
    Apartment(int id, std::string address, const char* ownerName)
        : id(id), address(address) {
        owner = new char[strlen(ownerName) + 1];
        strcpy(owner, ownerName);
    }
    Apartment(const Apartment& other)
        : id(other.id), address(other.address), owner(other.owner) {
    }
    ~Apartment() {
        delete[] owner; 
    }

    void display() const {
        std::cout << "Apartment ID: " << id 
                  << "\nAddress: " << address 
                  << "\nOwner: " << owner 
                  << "\n----------------------\n";
    }
};

int main() {
    Apartment apt1(101, "123 Main St", "John Doe");
    apt1.display();
    Apartment apt2 = apt1;
    apt2.display();

    return 0;
}
