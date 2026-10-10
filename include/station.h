#ifndef STATION_H
#define STATION_H

#include <string>
#include <vector>
#include "charger.h"

using namespace std;

class Station
{
private:
    int stationId;
    string name;
    string location;
    double availablePower;

    vector<Charger> chargers;

public:
    Station(int id, string n, string loc, double power);

    int getStationId();
    string getName();
    string getLocation();
    double getAvailablePower();

    void addCharger(Charger charger);

    void displayChargers();
};

#endif
