#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class
class Shipment {
protected:
    string trackingNumber;
    double weight;  // in kg

public:
    Shipment(string tn, double w) : trackingNumber(tn), weight(w) {}

    virtual void estimateDeliveryTime() const = 0;
    virtual void showDetails() const = 0;

    virtual ~Shipment() {}
};

// Derived Class: AirFreight
class AirFreight : public Shipment {
public:
    AirFreight(string tn, double w) : Shipment(tn, w) {}

    void estimateDeliveryTime() const override {
        cout << "Estimated Delivery Time (Air): 1-2 business days\n";
    }

    void showDetails() const override {
        cout << "Air Freight\n";
        cout << "- Tracking #: " << trackingNumber << "\n";
        cout << "- Weight: " << weight << " kg\n";
    }
};

// Derived Class: GroundShipment
class GroundShipment : public Shipment {
public:
    GroundShipment(string tn, double w) : Shipment(tn, w) {}

    void estimateDeliveryTime() const override {
        cout << "Estimated Delivery Time (Ground): 3-7 business days\n";
    }

    void showDetails() const override {
        cout << "Ground Shipment\n";
        cout << "- Tracking #: " << trackingNumber << "\n";
        cout << "- Weight: " << weight << " kg\n";
    }
};

// Main Flow
int main() {
    Shipment* shipments[2];
    shipments[0] = new AirFreight("AIR123456", 12.5);
    shipments[1] = new GroundShipment("GRD654321", 45.0);

    for (int i = 0; i < 2; ++i) {
        shipments[i]->showDetails();
        shipments[i]->estimateDeliveryTime();
        cout << endl;
        delete shipments[i];
    }

    return 0;
}
