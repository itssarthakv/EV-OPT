#ifndef STATION_HASH_H
#define STATION_HASH_H

#ifdef __cplusplus
extern "C" {
#endif

#define TABLE_SIZE 10

typedef struct StationNode
{
    int stationId;
    char stationName[50];
    struct StationNode *next;
} StationNode;

typedef struct
{
    StationNode *buckets[TABLE_SIZE];
} StationHash;

void initializeHashTable(StationHash *table);
int addStation(StationHash *table, int stationId, const char *stationName);
const char *findStation(const StationHash *table, int stationId);
void freeHashTable(StationHash *table);

#ifdef __cplusplus
}
#endif

#endif