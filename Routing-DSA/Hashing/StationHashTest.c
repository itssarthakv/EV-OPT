#include <stdio.h>
#include "StationHash.h"

int main()
{
    StationHash table;

    initializeHashTable(&table);

    addStation(&table, 101, "Station_A");
    addStation(&table, 111, "Station_B");
    addStation(&table, 121, "Station_C");
    addStation(&table, 205, "Station_D");
    addStation(&table, 310, "Station_E");

    printf("Station Hashing System\n");
    printf("----------------------\n");

    int id;

    printf("Enter Station ID to search: ");
    scanf("%d", &id);

    const char *result = findStation(&table, id);

    if (result != NULL)
    {
        printf("\nStation Found!\n");
        printf("Station ID: %d\n", id);
        printf("Station Name: %s\n", result);
    }
    else
    {
        printf("\nStation not found!\n");
    }

    freeHashTable(&table);

    return 0;
}