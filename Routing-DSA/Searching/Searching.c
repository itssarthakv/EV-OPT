#include "Searching.h"

int searchById(const Station stations[], int size, int stationId)
{
    for (int i = 0; i < size; i++)
    {
        if (stations[i].stationId == stationId)
        {
            return i;
        }
    }

    return -1;
}