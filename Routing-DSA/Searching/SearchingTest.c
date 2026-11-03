#include <stdio.h>
#include "Searching.h"

int main()
{
    Station stations[4] = {
        {101, "Station_A", 15},
        {205, "Station_B", 8},
        {310, "Station_C", 20},
        {415, "Station_D", 12}
    };

    int id;

    printf("Enter Station ID to search: ");
    scanf("%d", &id);

    int result = searchById(stations, 4, id);

    if (result != -1)
    {
        printf("\nStation Found!\n");
        printf("Station ID: %d\n", stations[result].stationId);
        printf("Station Name: %s\n", stations[result].stationName);
        printf("Distance: %d km\n", stations[result].distance);
    }
    else
    {
        printf("\nStation not found!\n");
    }

    return 0;
}