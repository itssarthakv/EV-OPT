#include <stdlib.h>
#include <string.h>
#include "StationHash.h"

int hashFunction(int stationId)
{
    return (unsigned int)stationId % TABLE_SIZE;
}

void initializeHashTable(StationHash *table)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table->buckets[i] = NULL;
    }
}

int addStation(StationHash *table, int stationId, const char *stationName)
{
    if (table == NULL || stationName == NULL || strlen(stationName) >= 50)
    {
        return 0;
    }

    int index = hashFunction(stationId);

    StationNode *temp = table->buckets[index];

    while (temp != NULL)
    {
        if (temp->stationId == stationId)
        {
            strcpy(temp->stationName, stationName);
            return 1;
        }

        temp = temp->next;
    }

    StationNode *newNode = malloc(sizeof(StationNode));

    if (newNode == NULL)
    {
        return 0;
    }

    newNode->stationId = stationId;
    strcpy(newNode->stationName, stationName);

    newNode->next = table->buckets[index];
    table->buckets[index] = newNode;

    return 1;
}

const char *findStation(const StationHash *table, int stationId)
{
    if (table == NULL)
    {
        return NULL;
    }

    int index = hashFunction(stationId);

    StationNode *temp = table->buckets[index];

    while (temp != NULL)
    {
        if (temp->stationId == stationId)
        {
            return temp->stationName;
        }

        temp = temp->next;
    }

    return NULL;
}

void freeHashTable(StationHash *table)
{
    if (table == NULL)
    {
        return;
    }

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        StationNode *temp = table->buckets[i];

        while (temp != NULL)
        {
            StationNode *nextNode = temp->next;
            free(temp);
            temp = nextNode;
        }

        table->buckets[i] = NULL;
    }
}