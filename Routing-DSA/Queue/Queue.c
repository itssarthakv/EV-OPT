#include <stdio.h>
#include "Queue.h"

void initializeQueue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int isEmpty(const Queue *q)
{
    return q->count == 0;
}

int isFull(const Queue *q)
{
    return q->count == QUEUE_SIZE;
}

int enqueue(Queue *q, int request)
{
    if (isFull(q))
    {
        printf("Queue Overflow! Queue is full.\n");
        return 0;
    }

    q->rear = (q->rear + 1) % QUEUE_SIZE;
    q->requestId[q->rear] = request;
    q->count++;

    return 1;
}

int dequeue(Queue *q, int *request)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow! Queue is empty.\n");
        return 0;
    }

    *request = q->requestId[q->front];
    q->front = (q->front + 1) % QUEUE_SIZE;
    q->count--;

    if (isEmpty(q))
    {
        q->front = 0;
        q->rear = -1;
    }

    return 1;
}

int peek(const Queue *q, int *request)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return 0;
    }

    *request = q->requestId[q->front];
    return 1;
}

void displayQueue(const Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");

    for (int i = 0; i < q->count; i++)
    {
        int index = (q->front + i) % QUEUE_SIZE;
        printf("%d ", q->requestId[index]);
    }

    printf("\n");
}