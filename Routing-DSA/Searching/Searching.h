#ifndef SEARCHING_H
#define SEARCHING_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    int stationId;
    char stationName[50];
    int distance;
} Station;

int searchById(const Station stations[], int size, int stationId);

#ifdef __cplusplus
}
#endif

#endif