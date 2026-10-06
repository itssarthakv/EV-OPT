#include <iostream>
#include "Graph.h"

int main()
{
    Graph graph(4);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(1, 3, 20);
    graph.addEdge(2, 3, 5);
    graph.displayGraph();
    graph.dijkstra(0);
    return 0;
}