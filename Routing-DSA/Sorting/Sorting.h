
#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include <string>

struct SortStation
{
    int stationId;
    std::string stationName;
    int distance;
};

class Sorting
{
public:
    // Sorts stations from nearest to farthest
    void sortByDistance(std::vector<SortStation>& stations);
};

#endif
