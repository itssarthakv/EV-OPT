#ifndef QUEUE_H
#define QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif

#define QUEUE_SIZE 5

typedef struct
{
    int requestId[QUEUE_SIZE];
    int front;
    int rear;
    int count;
} Queue;

void initializeQueue(Queue *q);
int isEmpty(const Queue *q);
int isFull(const Queue *q);
int enqueue(Queue *q, int request);
int dequeue(Queue *q, int *request);
int peek(const Queue *q, int *request);
void displayQueue(const Queue *q);

#ifdef __cplusplus
}
#endif

#endif