#ifndef SORTING_H
#define SORTING_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    int stationId;
    char stationName[50];
    int distance;
} SortStation;

void sortByDistance(SortStation stations[], int size);

#ifdef __cplusplus
}
#endif

#endif