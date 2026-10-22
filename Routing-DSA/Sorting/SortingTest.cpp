
#include <iostream>
#include "Sorting.h"

int main()
{
    // Sample distances for testing only
    std::vector<SortStation> stations = {
        {101, "Station A", 10},
        {102, "Station B", 25},
        {103, "Station C", 15}
    };

    Sorting sorter;
    sorter.sortByDistance(stations);

    std::cout << "Stations sorted by distance:" << std::endl;

    for (const auto& station : stations)
    {
        std::cout << station.stationName
                  << " - " << station.distance << std::endl;
    }

    return 0;
}
