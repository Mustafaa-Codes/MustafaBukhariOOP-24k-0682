/*
24k-0682
Syed Mustafa Bukhari
Lab 5 Question 4
*/
#include <iostream>
#include <string>

class AlarmSystem {
private:
    std::string securityLevel;

public:
    AlarmSystem(std::string level) : securityLevel(level) {}

    void display() const {
        std::cout << "Alarm System Security Level: " << securityLevel << "\n";
    }
};

class SmartHome {
private:
    std::string homeName;
    AlarmSystem alarm;

public:
    SmartHome(std::string name, std::string securityLevel) 
        : homeName(name), alarm(securityLevel) {}

    void displayDetails() const {
        std::cout << "Smart Home: " << homeName << "\n";
        alarm.display();
        std::cout << "----------------------\n";
    }
};

int main() {
    SmartHome home1("Villa Serenity", "High");
    SmartHome home2("Urban Apartment", "Medium");

    home1.displayDetails();
    home2.displayDetails();

    return 0;
}
