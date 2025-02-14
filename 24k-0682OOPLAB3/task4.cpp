/*
24k-0682
Syed Mustafa Bukhari
OOP Lab 3
*/
#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string brand;
    string model;
    float fuelCapacity;     
    float currentFuelLevel; 

public:
    // Constructor
    Car(string b, string m, float capacity) {
        brand = b;
        model = m;
        fuelCapacity = capacity;
        currentFuelLevel = capacity; 
    }

    // drive the car
    void drive(float distance) {
        float fuelConsumed = distance * 0.1; // 10 km\L
        if (fuelConsumed > currentFuelLevel) {
            cout << "Not enough fuel to drive " << distance << " km!\n";
        } else {
            currentFuelLevel -= fuelConsumed;
            cout << "Drove " << distance << " km. Fuel consumed: " << fuelConsumed << " liters.\n";
            checkFuelStatus();
        }
    }

    //  refuel the car
    void refuel(float amount) {
        if (amount <= 0) {
            cout << "Invalid fuel amount!\n";
            return;
        }

        if (currentFuelLevel + amount > fuelCapacity) {
            cout << "Tank overflow! Filling up to full capacity.\n";
            currentFuelLevel = fuelCapacity;
        } else {
            currentFuelLevel += amount;
            cout << "Added " << amount << " liters of fuel.\n";
        }
        checkFuelStatus();
    }

    //  check fuel status
    void checkFuelStatus() const {
        cout << "Current fuel level: " << currentFuelLevel << " liters.\n";
        if (currentFuelLevel < 5) {
            cout << "Warning: Low fuel! Please refuel soon.\n";
        }
    }

    //  display car details
    void displayCarInfo() const {
        cout << "Car: " << brand << " " << model << "\n";
        cout << "Fuel Capacity: " << fuelCapacity << " liters\n";
        cout << "Current Fuel Level: " << currentFuelLevel << " liters\n";
    }
};


int main() {
    Car zoyaCar("Toyota", "Corolla", 50); 

    zoyaCar.displayCarInfo();
    
    // Simulating driving
    zoyaCar.drive(100); 
    zoyaCar.drive(200); 
    
    // Refueling
    zoyaCar.refuel(10);
    zoyaCar.refuel(40); 
    
    zoyaCar.displayCarInfo(); 
    return 0;
}
