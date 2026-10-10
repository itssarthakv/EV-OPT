#include "../include/station.h"
#include <iostream>

using namespace std;

Station::Station(int id, string n, string loc, double power)
{
    stationId = id;
    name = n;
    location = loc;
    availablePower = power;
}

int Station::getStationId()
{
    return stationId;
}

string Station::getName()
{
    return name;
}

string Station::getLocation()
{
    return location;
}

double Station::getAvailablePower()
{
    return availablePower;
}

void Station::addCharger(Charger charger)
{
    chargers.push_back(charger);
}

void Station::displayChargers()
{
    cout << "\nChargers at " << name << ":" << endl;

    for (Charger charger : chargers)
    {
        cout << "Charger ID: "
             << charger.getChargerId()
             << " | Power: "
             << charger.getPower()
             << " kW"
             << " | Status: "
             << charger.getStatus()
             << endl;
    }
}
