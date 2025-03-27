#include <iostream>
#include <string>
using namespace std;

class Device {
protected:
    string deviceID, deviceName, location;
    bool status;
public:
    Device(string id, string name, string loc = "") : deviceID(id), deviceName(name), location(loc), status(false) {}
    virtual void turnOn() { status = true; }
    virtual void turnOff() { status = false; }
    virtual string getStatus() { return status ? "On" : "Off"; }
    virtual void displayInfo() {
        cout << "Device ID: " << deviceID << "\nDevice Name: " << deviceName << "\nStatus: " << getStatus();
        if (!location.empty()) cout << "\nLocation: " << location;
        cout << endl;
    }
};

class Light : public Device {
    int brightnessLevel;
    string colorMode;
public:
    Light(string id, string name, string loc, int brightness, string color) 
        : Device(id, name, loc), brightnessLevel(brightness), colorMode(color) {}
    void displayInfo() override {
        Device::displayInfo();
        cout << "\nBrightness: " << brightnessLevel << "\nColor Mode: " << colorMode << endl;
    }
};

class Thermostat : public Device {
    float temperature, targetTemperature;
    string mode;
public:
    Thermostat(string id, string name, string loc, float temp, string mode, float target) 
        : Device(id, name, loc), temperature(temp), mode(mode), targetTemperature(target) {}
    string getStatus() override {
        return "Current Temp: " + to_string(temperature) + " | Mode: " + mode + " | Target: " + to_string(targetTemperature);
    }
};

class SecurityCamera : public Device {
    string resolution;
    bool recordingStatus, nightVisionEnabled;
public:
    SecurityCamera(string id, string name, string loc, string res, bool nightVision) 
        : Device(id, name, loc), resolution(res), nightVisionEnabled(nightVision), recordingStatus(false) {}
    void turnOn() override { status = true; recordingStatus = true; }
    void turnOff() override { status = false; recordingStatus = false; }
    void displayInfo() override {
        Device::displayInfo();
        cout << "\nResolution: " << resolution << "\nRecording: " << (recordingStatus ? "Yes" : "No")
             << "\nNight Vision: " << (nightVisionEnabled ? "Enabled" : "Disabled") << endl;
    }
};

class SmartPlug : public Device {
    float powerConsumption;
    int timerSetting;
public:
    SmartPlug(string id, string name, string loc, float power, int timer) 
        : Device(id, name, loc), powerConsumption(power), timerSetting(timer) {}
    void turnOff() override {
        cout << "Power Consumption Logged: " << powerConsumption << "W" << endl;
        status = false;
    }
};

int main() {
    Light light("L1", "Living Room Light", "Living Room", 75, "Warm White");
    Thermostat thermostat("T1", "Main Thermostat", "Hallway", 22.5, "Cooling", 24.0);
    SecurityCamera camera("C1", "Front Door Camera", "Entrance", "1080p", true);
    SmartPlug plug("P1", "Smart Plug", "Kitchen", 150.5, 30);

    light.turnOn();
    thermostat.turnOn();
    camera.turnOn();
    plug.turnOn();

    light.displayInfo();
    cout << thermostat.getStatus() << endl;
    camera.displayInfo();
    plug.turnOff();

    return 0;
}
