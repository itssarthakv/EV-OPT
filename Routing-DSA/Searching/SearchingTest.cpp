
#include <iostream>
#include "Searching.h"

int main()
{
    // Sample station data for testing
    std::vector<Station> stations = {
        {101, "Station A", 10},
        {102, "Station B", 25},
        {103, "Station C", 15}
    };

    Searching search;

    int index = search.searchById(stations, 102);

    if (index != -1)
        std::cout << "Station found: " << stations[index].stationName << std::endl;
    else
        std::cout << "Station not found." << std::endl;

    index = search.searchById(stations, 105);

    if (index != -1)
        std::cout << "Station found: " << stations[index].stationName << std::endl;
    else
        std::cout << "Station not found." << std::endl;

    return 0;
}
