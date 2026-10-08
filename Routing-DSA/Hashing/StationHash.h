#ifndef STATION_HASH_H
#define STATION_HASH_H

#include <unordered_map>
#include <string>

class StationHash
{
private:
    std::unordered_map<int, std::string> stations;

public:
    void addStation(int stationId, std::string stationName);
    void findStation(int stationId);
};

#endif