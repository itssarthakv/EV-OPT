#include <iostream>
#include "StationHash.h"

int main()
{
    StationHash stationMap;

    stationMap.addStation(101, "Station A");
    stationMap.addStation(102, "Station B");
    stationMap.addStation(103, "Station C");

    stationMap.findStation(102);
    stationMap.findStation(105);

    return 0;
}