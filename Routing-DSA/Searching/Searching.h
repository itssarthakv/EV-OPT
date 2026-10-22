
#ifndef SEARCHING_H
#define SEARCHING_H

#include <vector>
#include <string>

struct Station
{
    int stationId;
    std::string stationName;
    int distance;
};

class Searching
{
public:
    // Finds a station by ID; returns its index or -1 if not found
    int searchById(const std::vector<Station>& stations, int stationId);
};

#endif
