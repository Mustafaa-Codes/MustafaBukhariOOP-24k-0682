#include <iostream>
#include <string>
using namespace std;

// Abstract Class
class Patient {
protected:
    string name;
    string id;

public:
    Patient(string n, string i) : name(n), id(i) {}

    virtual void displayTreatment() const = 0;
    virtual double calculateCost() const = 0;
    virtual ~Patient() {} // Virtual destructor
};

// Derived Class - InPatient
class InPatient : public Patient {
public:
    InPatient(string n, string i) : Patient(n, i) {}

    void displayTreatment() const override {
        cout << "InPatient Treatment for " << name << " (ID: " << id << "):\n";
        cout << "- Hospital stay: 5 days\n";
        cout << "- Daily medication and monitoring\n";
        cout << "- Surgery scheduled on day 3\n";
    }

    double calculateCost() const override {
        double dailyRate = 5000.0;
        double surgeryCost = 20000.0;
        return (5 * dailyRate) + surgeryCost;
    }
};

// Derived Class - OutPatient
class OutPatient : public Patient {
public:
    OutPatient(string n, string i) : Patient(n, i) {}

    void displayTreatment() const override {
        cout << "OutPatient Treatment for " << name << " (ID: " << id << "):\n";
        cout << "- Weekly check-ups for 1 month\n";
        cout << "- Prescription medicines\n";
    }

    double calculateCost() const override {
        double consultationFee = 1500.0;
        double medicineCost = 2000.0;
        return (4 * consultationFee) + medicineCost;
    }
};

// Main flow
int main() {
    Patient* p1 = new InPatient("Ali Khan", "IP001");
    Patient* p2 = new OutPatient("Sara Ahmed", "OP001");

    // Display and calculate using polymorphism
    cout << "\n=== InPatient Info ===\n";
    p1->displayTreatment();
    cout << "Total Cost: PKR " << p1->calculateCost() << "\n";

    cout << "\n=== OutPatient Info ===\n";
    p2->displayTreatment();
    cout << "Total Cost: PKR " << p2->calculateCost() << "\n";

    delete p1;
    delete p2;

    return 0;
}
