
#include "Sorting.h"

// Bubble Sort: compares adjacent stations and swaps when needed
void Sorting::sortByDistance(std::vector<SortStation>& stations)
{
    int n = stations.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (stations[j].distance > stations[j + 1].distance)
            {
                SortStation temp = stations[j];
                stations[j] = stations[j + 1];
                stations[j + 1] = temp;
            }
        }
    }
}
