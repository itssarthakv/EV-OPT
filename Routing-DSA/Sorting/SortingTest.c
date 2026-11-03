#include <stdio.h>
#include "Sorting.h"

int main()
{
    SortStation stations[4] = {
        {101, "Station_A", 15},
        {205, "Station_B", 8},
        {310, "Station_C", 20},
        {415, "Station_D", 12}
    };

    printf("Before Sorting:\n");

    for (int i = 0; i < 4; i++)
    {
        printf("ID: %d  Name: %s  Distance: %d km\n",
               stations[i].stationId,
               stations[i].stationName,
               stations[i].distance);
    }

    sortByDistance(stations, 4);

    printf("\nAfter Sorting (Ascending Distance):\n");

    for (int i = 0; i < 4; i++)
    {
        printf("ID: %d  Name: %s  Distance: %d km\n",
               stations[i].stationId,
               stations[i].stationName,
               stations[i].distance);
    }

    return 0;
}