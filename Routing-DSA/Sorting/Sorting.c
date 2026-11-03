#include "Sorting.h"

void sortByDistance(SortStation stations[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
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