/*
24k-0682
Syed Mustafa Bukhari
Lab 6 Question 5
*/
#include <iostream>

class Device {
protected:
    int deviceID;
    bool status;

public:
    Device(int id, bool status) : deviceID(id), status(status) {}

    virtual void displayDetails() const {
        std::cout << "Device ID: " << deviceID << "\nStatus: " << (status ? "On" : "Off") << "\n";
    }
};

class SmartPhone : public Device {
protected:
    float screenSize;

public:
    SmartPhone(int id, bool status, float screenSize) 
        : Device(id, status), screenSize(screenSize) {}

    void displayDetails() const override {
        std::cout << "Device ID: " << deviceID << "\nStatus: " << (status ? "On" : "Off") 
                  << "\nScreen Size: " << screenSize << " inches\n";
    }
};

class SmartWatch : public Device {
protected:
    bool heartRateMonitor;

public:
    SmartWatch(int id, bool status, bool heartRateMonitor) 
        : Device(id, status), heartRateMonitor(heartRateMonitor) {}

    void displayDetails() const override {
        std::cout << "Device ID: " << deviceID << "\nStatus: " << (status ? "On" : "Off") 
                  << "\nHeart Rate Monitor: " << (heartRateMonitor ? "Enabled" : "Disabled") << "\n";
    }
};

class SmartWearable : public SmartPhone, public SmartWatch {
private:
    int stepCounter;

public:
    SmartWearable(int id, bool status, float screenSize, bool heartRateMonitor, int stepCounter) 
        : Device(id, status), SmartPhone(id, status, screenSize), 
          SmartWatch(id, status, heartRateMonitor), stepCounter(stepCounter) {}

    void displayDetails() const override {
        std::cout << "Device ID: " << deviceID << "\nStatus: " << (status ? "On" : "Off") 
                  << "\nScreen Size: " << screenSize << " inches"
                  << "\nHeart Rate Monitor: " << (heartRateMonitor ? "Enabled" : "Disabled") 
                  << "\nStep Counter: " << stepCounter << "\n";
    }
};

int main() {
    SmartWearable wearable(101, true, 1.5, true, 5000);
    wearable.displayDetails();

    return 0;
}
