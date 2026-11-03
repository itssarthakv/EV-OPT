#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Graph.h"

#define INF INT_MAX

typedef struct
{
    int vertex;
    int distance;
} HeapNode;

typedef struct
{
    HeapNode *array;
    int size;
    int capacity;
} MinHeap;

int heapPush(MinHeap *heap, int vertex, int distance)
{
    if (heap->size == heap->capacity)
    {
        int newCapacity = heap->capacity * 2;

        HeapNode *newArray = realloc(
            heap->array, newCapacity * sizeof(HeapNode));

        if (newArray == NULL)
        {
            return 0;
        }

        heap->array = newArray;
        heap->capacity = newCapacity;
    }

    int i = heap->size;
    heap->size++;

    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (heap->array[parent].distance <= distance)
        {
            break;
        }

        heap->array[i] = heap->array[parent];
        i = parent;
    }

    heap->array[i].vertex = vertex;
    heap->array[i].distance = distance;

    return 1;
}

HeapNode heapPop(MinHeap *heap)
{
    HeapNode result = heap->array[0];
    HeapNode last = heap->array[heap->size - 1];

    heap->size--;

    if (heap->size > 0)
    {
        int i = 0;

        while (1)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;

            if (left < heap->size &&
                heap->array[left].distance <
                heap->array[smallest].distance)
            {
                smallest = left;
            }

            if (right < heap->size &&
                heap->array[right].distance <
                heap->array[smallest].distance)
            {
                smallest = right;
            }

            if (smallest == i)
            {
                break;
            }

            heap->array[i] = heap->array[smallest];
            i = smallest;
        }

        heap->array[i] = last;
    }

    return result;
}

int initializeGraph(Graph *graph, int vertices)
{
    if (graph == NULL || vertices <= 0)
    {
        return 0;
    }

    graph->vertices = vertices;
    graph->adjacencyList = calloc(vertices, sizeof(EdgeNode *));

    if (graph->adjacencyList == NULL)
    {
        graph->vertices = 0;
        return 0;
    }

    return 1;
}

int addEdge(Graph *graph, int src, int dest, int weight)
{
    if (graph == NULL || graph->adjacencyList == NULL ||
        src < 0 || dest < 0 ||
        src >= graph->vertices || dest >= graph->vertices ||
        weight < 0)
    {
        return 0;
    }

    EdgeNode *newNode1 = malloc(sizeof(EdgeNode));
    EdgeNode *newNode2 = malloc(sizeof(EdgeNode));

    if (newNode1 == NULL || newNode2 == NULL)
    {
        free(newNode1);
        free(newNode2);
        return 0;
    }

    newNode1->vertex = dest;
    newNode1->weight = weight;
    newNode1->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode1;

    newNode2->vertex = src;
    newNode2->weight = weight;
    newNode2->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode2;

    return 1;
}

void displayGraph(const Graph *graph)
{
    if (graph == NULL || graph->adjacencyList == NULL)
    {
        return;
    }

    printf("\nGraph Representation:\n");

    for (int i = 0; i < graph->vertices; i++)
    {
        EdgeNode *temp = graph->adjacencyList[i];

        printf("Vertex %d: ", i);

        while (temp != NULL)
        {
            printf(" -> %d (Weight: %d)",
                   temp->vertex, temp->weight);

            temp = temp->next;
        }

        printf("\n");
    }
}

void dijkstra(const Graph *graph, int startVertex)
{
    if (graph == NULL || graph->adjacencyList == NULL ||
        startVertex < 0 || startVertex >= graph->vertices)
    {
        printf("Invalid starting vertex!\n");
        return;
    }

    int *distance = malloc(graph->vertices * sizeof(int));

    if (distance == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    for (int i = 0; i < graph->vertices; i++)
    {
        distance[i] = INF;
    }

    MinHeap heap;
    heap.size = 0;
    heap.capacity = 8;
    heap.array = malloc(heap.capacity * sizeof(HeapNode));

    if (heap.array == NULL)
    {
        free(distance);
        printf("Memory allocation failed!\n");
        return;
    }

    distance[startVertex] = 0;
    heapPush(&heap, startVertex, 0);

    while (heap.size > 0)
    {
        HeapNode current = heapPop(&heap);

        int u = current.vertex;

        if (current.distance != distance[u])
        {
            continue;
        }

        EdgeNode *temp = graph->adjacencyList[u];

        while (temp != NULL)
        {
            int v = temp->vertex;
            int weight = temp->weight;

            if (distance[u] <= INF - weight &&
                distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;

                if (!heapPush(&heap, v, distance[v]))
                {
                    printf("Memory allocation failed!\n");
                    free(heap.array);
                    free(distance);
                    return;
                }
            }

            temp = temp->next;
        }
    }

    printf("\nShortest Distances from Vertex %d:\n", startVertex);

    for (int i = 0; i < graph->vertices; i++)
    {
        if (distance[i] == INF)
        {
            printf("Vertex %d: Unreachable\n", i);
        }
        else
        {
            printf("Vertex %d: %d\n", i, distance[i]);
        }
    }

    free(heap.array);
    free(distance);
}

void freeGraph(Graph *graph)
{
    if (graph == NULL || graph->adjacencyList == NULL)
    {
        return;
    }

    for (int i = 0; i < graph->vertices; i++)
    {
        EdgeNode *temp = graph->adjacencyList[i];

        while (temp != NULL)
        {
            EdgeNode *nextNode = temp->next;
            free(temp);
            temp = nextNode;
        }
    }

    free(graph->adjacencyList);
    graph->adjacencyList = NULL;
    graph->vertices = 0;
}