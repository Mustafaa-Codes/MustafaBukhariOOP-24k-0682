#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class
class WeatherSensor {
public:
    virtual void readData() = 0;
    virtual void displayReport() const = 0;
    virtual ~WeatherSensor() {}
};

// Derived Class: Thermometer
class Thermometer : public WeatherSensor {
private:
    float temperature;

public:
    void readData() override {
        // Simulated reading
        temperature = 28.5;
    }

    void displayReport() const override {
        cout << "Thermometer Reading:\n";
        cout << "- Temperature: " << temperature << "°C\n";
    }
};

// Derived Class: Barometer
class Barometer : public WeatherSensor {
private:
    float pressure;

public:
    void readData() override {
        // Simulated reading
        pressure = 1012.3;
    }

    void displayReport() const override {
        cout << "Barometer Reading:\n";
        cout << "- Atmospheric Pressure: " << pressure << " hPa\n";
    }
};

// Main Flow
int main() {
    WeatherSensor* sensors[2];
    sensors[0] = new Thermometer();
    sensors[1] = new Barometer();

    for (int i = 0; i < 2; ++i) {
        sensors[i]->readData();
        sensors[i]->displayReport();
        cout << endl;
        delete sensors[i];
    }

    return 0;
}
