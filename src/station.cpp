#include "../include/station.h"
#include <iostream>
#include <iomanip>

int Station::nextId = 1;

Station::Station(int id, const std::string& n, const std::string& loc,
                 double capacity)
    : stationId(id), name(n), location(loc),
      powerCapacity(capacity), allocatedPower(0.0) {
    if (id >= nextId) nextId = id + 1;
}

int         Station::getStationId()      const { return stationId; }
std::string Station::getName()           const { return name; }
std::string Station::getLocation()       const { return location; }
double      Station::getPowerCapacity()  const { return powerCapacity; }
double      Station::getAllocatedPower()  const { return allocatedPower; }
double      Station::getAvailablePower() const { return powerCapacity - allocatedPower; }
int         Station::getChargerCount()   const { return (int)chargers.size(); }

int Station::getAvailableChargerCount() const {
    int count = 0;
    for (const auto& c : chargers)
        if (c.getStatus() == "AVAILABLE") ++count;
    return count;
}

void Station::addCharger(const Charger& c) { chargers.push_back(c); }

std::vector<Charger>&       Station::getChargers()       { return chargers; }
const std::vector<Charger>& Station::getChargers() const { return chargers; }

Charger* Station::findAvailableCharger() {
    for (auto& c : chargers)
        if (c.getStatus() == "AVAILABLE") return &c;
    return nullptr;
}

Charger* Station::findChargerById(int id) {
    for (auto& c : chargers)
        if (c.getChargerId() == id) return &c;
    return nullptr;
}

bool Station::allocatePower(double amount) {
    if (amount > getAvailablePower()) return false;
    allocatedPower += amount;
    return true;
}

void Station::releasePower(double amount) {
    allocatedPower -= amount;
    if (allocatedPower < 0) allocatedPower = 0;
}

void Station::setPowerCapacity(double capacity) {
    powerCapacity = capacity;
    if (allocatedPower > powerCapacity) allocatedPower = powerCapacity;
}

void Station::resetPowerAllocation() {
    allocatedPower = 0.0;
}

void Station::displayChargers() const {
    std::cout << "\n  Chargers at " << name << ":\n";
    std::cout << "  " << std::string(60, '-') << "\n";
    std::cout << "  " << std::left
              << std::setw(12) << "Charger ID"
              << std::setw(12) << "Power(kW)"
              << std::setw(14) << "Cost(Rs/kWh)"
              << std::setw(14) << "Status" << "\n";
    std::cout << "  " << std::string(60, '-') << "\n";
    for (const auto& c : chargers) {
        std::cout << "  " << std::left
                  << std::setw(12) << c.getChargerId()
                  << std::setw(12) << c.getPower()
                  << std::setw(14) << c.getCostPerKWh()
                  << std::setw(14) << c.getStatus() << "\n";
    }
}

void Station::displayInfo() const {
    std::cout << "  Station ID   : " << stationId << "\n"
              << "  Name         : " << name << "\n"
              << "  Location     : " << location << "\n"
              << "  Capacity     : " << powerCapacity << " kW\n"
              << "  Allocated    : " << allocatedPower << " kW\n"
              << "  Available    : " << getAvailablePower() << " kW\n"
              << "  Chargers     : " << chargers.size()
              << " (" << getAvailableChargerCount() << " available)\n";
}
