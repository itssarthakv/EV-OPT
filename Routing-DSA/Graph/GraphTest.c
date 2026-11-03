#include <stdio.h>
#include "Graph.h"

int main()
{
    Graph graph = {0};

    if (!initializeGraph(&graph, 4))
    {
        printf("Graph initialization failed!\n");
        return 1;
    }

    addEdge(&graph, 0, 1, 10);
    addEdge(&graph, 0, 2, 15);
    addEdge(&graph, 1, 3, 20);
    addEdge(&graph, 2, 3, 5);

    printf("EV-OPT Graph and Dijkstra System\n");

    displayGraph(&graph);

    dijkstra(&graph, 0);

    freeGraph(&graph);

    return 0;
}