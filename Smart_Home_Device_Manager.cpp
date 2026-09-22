#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SmartDevice {
private:
    string deviceId;
    string location;
    string status;
    string lastUpdated;

public:
    SmartDevice(string id, string loc, string stat, string time)
        : deviceId(id),
          location(loc),
          status(stat),
          lastUpdated(time) {}

    void turnOn(string time) {
        status = "ON";
        lastUpdated = time;
    }

    void turnOff(string time) {
        status = "OFF";
        lastUpdated = time;
    }

    void changeStatus(string newStatus, string time) {
        status = newStatus;
        lastUpdated = time;
    }

    void display() const {
        cout << "Device ID: " << deviceId
             << " | Location: " << location
             << " | Status: " << status
             << " | Last Updated: " << lastUpdated
             << endl;
    }
};

int main() {
    vector<SmartDevice> devices;

    devices.emplace_back("D001", "Living Room", "OFF", "08:00");
    devices.emplace_back("D002", "Bedroom", "OFF", "08:00");
    devices.emplace_back("D003", "Kitchen", "ON", "08:00");
    devices.emplace_back("D004", "Main Door", "LOCKED", "08:00");

    cout << "=== Smart Home Dashboard ===" << endl;

    for (const auto& device : devices) {
        device.display();
    }

    devices[0].turnOn("09:00");
    devices[1].turnOn("09:05");
    devices[3].changeStatus("UNLOCKED", "09:10");

    cout << "\n=== Updated Smart Home Dashboard ===" << endl;

    for (const auto& device : devices) {
        device.display();
    }

    return 0;
}
