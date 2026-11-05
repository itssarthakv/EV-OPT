#include <stdio.h>
#include "Queue.h"

int main()
{
    Queue q;
    int request;

    initializeQueue(&q);

    printf("---- Circular Queue Test ----\n");

    printf("\nInserting requests:\n");
    enqueue(&q, 101);
    enqueue(&q, 102);
    enqueue(&q, 103);
    enqueue(&q, 104);
    enqueue(&q, 105);

    displayQueue(&q);

    printf("\nTesting Queue Overflow:\n");
    enqueue(&q, 106);

    printf("\nChecking front element:\n");
    if (peek(&q, &request))
        printf("Front request: %d\n", request);

    printf("\nRemoving two requests:\n");

    if (dequeue(&q, &request))
        printf("Removed: %d\n", request);

    if (dequeue(&q, &request))
        printf("Removed: %d\n", request);

    displayQueue(&q);

    printf("\nTesting Circular Reuse:\n");
    enqueue(&q, 106);
    enqueue(&q, 107);

    displayQueue(&q);

    printf("\nRemoving all requests:\n");

    while (!isEmpty(&q))
    {
        dequeue(&q, &request);
        printf("Removed: %d\n", request);
    }

    printf("\nTesting Queue Underflow:\n");
    dequeue(&q, &request);

    printf("\nQueue Empty: %s\n",
           isEmpty(&q) ? "Yes" : "No");

    return 0;
}