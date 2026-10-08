#include "StationHash.h"
#include <iostream>

void StationHash::addStation(int stationId, std::string stationName)
{
    stations[stationId] = stationName;
}

void StationHash::findStation(int stationId)
{
    if (stations.find(stationId) != stations.end())
    {
        std::cout << "Station found: "
                  << stations[stationId] << std::endl;
    }
    else
    {
        std::cout << "Station not found." << std::endl;
    }
}