#include <stdio.h>
#include "PriorityQueue.h"

int main()
{
    PriorityQueue pq;
    PriorityNode result;

    initializePriorityQueue(&pq);

    printf("---- Priority Queue Test ----\n");

    printf("\nInserting charging requests:\n");

    insert(&pq, 101, 3);
    insert(&pq, 102, 1);
    insert(&pq, 103, 2);
    insert(&pq, 104, 1);
    insert(&pq, 105, 4);

    displayPriorityQueue(&pq);

    printf("\nChecking highest-priority request:\n");

    if (peek(&pq, &result))
    {
        printf("Request ID: %d | Priority: %d\n",
               result.requestId, result.priority);
    }

    printf("\nProcessing requests:\n");

    while (!isEmpty(&pq))
    {
        extractMin(&pq, &result);

        printf("Processed Request: %d | Priority: %d\n",
               result.requestId, result.priority);
    }

    printf("\nTesting Underflow:\n");
    extractMin(&pq, &result);

    printf("\nPriority Queue Empty: %s\n",
           isEmpty(&pq) ? "Yes" : "No");

    return 0;
}