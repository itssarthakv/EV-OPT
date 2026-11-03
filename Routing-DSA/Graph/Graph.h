#ifndef GRAPH_H
#define GRAPH_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct EdgeNode
{
    int vertex;
    int weight;
    struct EdgeNode *next;
} EdgeNode;

typedef struct
{
    int vertices;
    EdgeNode **adjacencyList;
} Graph;

int initializeGraph(Graph *graph, int vertices);
int addEdge(Graph *graph, int src, int dest, int weight);
void displayGraph(const Graph *graph);
void dijkstra(const Graph *graph, int startVertex);
void freeGraph(Graph *graph);

#ifdef __cplusplus
}
#endif

#endif