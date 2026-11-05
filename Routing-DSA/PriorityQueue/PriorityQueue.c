#include <stdio.h>
#include "PriorityQueue.h"

static void swap(PriorityNode *a, PriorityNode *b)
{
    PriorityNode temp = *a;
    *a = *b;
    *b = temp;
}

// Lower priority number = higher priority.
// For equal priorities, earlier insertion comes first.
static int hasHigherPriority(PriorityNode a, PriorityNode b)
{
    if (a.priority != b.priority)
        return a.priority < b.priority;

    return a.order < b.order;
}

void initializePriorityQueue(PriorityQueue *pq)
{
    pq->size = 0;
    pq->nextOrder = 0;
}

int isEmpty(const PriorityQueue *pq)
{
    return pq->size == 0;
}

int isFull(const PriorityQueue *pq)
{
    return pq->size == PQ_SIZE;
}

int insert(PriorityQueue *pq, int requestId, int priority)
{
    if (isFull(pq))
    {
        printf("Priority Queue Overflow!\n");
        return 0;
    }

    int i = pq->size;

    pq->heap[i].requestId = requestId;
    pq->heap[i].priority = priority;
    pq->heap[i].order = pq->nextOrder++;

    pq->size++;

    // Heapify Up
    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (hasHigherPriority(pq->heap[i], pq->heap[parent]))
        {
            swap(&pq->heap[i], &pq->heap[parent]);
            i = parent;
        }
        else
        {
            break;
        }
    }

    return 1;
}

int peek(const PriorityQueue *pq, PriorityNode *result)
{
    if (isEmpty(pq))
    {
        printf("Priority Queue is empty!\n");
        return 0;
    }

    *result = pq->heap[0];
    return 1;
}

int extractMin(PriorityQueue *pq, PriorityNode *result)
{
    if (isEmpty(pq))
    {
        printf("Priority Queue Underflow!\n");
        return 0;
    }

    *result = pq->heap[0];

    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;

    // Heapify Down
    int i = 0;

    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < pq->size &&
            hasHigherPriority(pq->heap[left], pq->heap[smallest]))
        {
            smallest = left;
        }

        if (right < pq->size &&
            hasHigherPriority(pq->heap[right], pq->heap[smallest]))
        {
            smallest = right;
        }

        if (smallest != i)
        {
            swap(&pq->heap[i], &pq->heap[smallest]);
            i = smallest;
        }
        else
        {
            break;
        }
    }

    return 1;
}

void displayPriorityQueue(const PriorityQueue *pq)
{
    if (isEmpty(pq))
    {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("\nRequest ID\tPriority\n");

    for (int i = 0; i < pq->size; i++)
    {
        printf("%d\t\t%d\n",
               pq->heap[i].requestId,
               pq->heap[i].priority);
    }
}