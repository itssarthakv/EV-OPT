
#include "Searching.h"

// Linear Search: checks station IDs one by one
int Searching::searchById(const std::vector<Station>& stations, int stationId)
{
    for (int i = 0; i < stations.size(); i++)
    {
        if (stations[i].stationId == stationId)
        {
            return i; // Station found
        }
    }

    return -1; // Station not found
}
