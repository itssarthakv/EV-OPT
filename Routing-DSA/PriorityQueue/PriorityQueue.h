#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif

#define PQ_SIZE 50

typedef struct
{
    int requestId;
    int priority;
    unsigned long long order;
} PriorityNode;

typedef struct
{
    PriorityNode heap[PQ_SIZE];
    int size;
    unsigned long long nextOrder;
} PriorityQueue;

void initializePriorityQueue(PriorityQueue *pq);
int isEmpty(const PriorityQueue *pq);
int isFull(const PriorityQueue *pq);
int insert(PriorityQueue *pq, int requestId, int priority);
int peek(const PriorityQueue *pq, PriorityNode *result);
int extractMin(PriorityQueue *pq, PriorityNode *result);
void displayPriorityQueue(const PriorityQueue *pq);

#ifdef __cplusplus
}
#endif

#endif