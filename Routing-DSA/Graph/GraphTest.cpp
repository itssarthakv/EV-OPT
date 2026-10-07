#include <iostream>
#include "Graph.h"

int main()
{
    Graph graph(5);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(1, 3, 20);
    graph.addEdge(2, 3, 5);

    std::cout << "Road Network:" << std::endl;
    graph.displayGraph();

    std::cout << std::endl;

    std::cout << "Dijkstra from vertex 0:" << std::endl;
    graph.dijkstra(0);

    std::cout << std::endl;

    std::cout << "Dijkstra from vertex 3:" << std::endl;
    graph.dijkstra(3);

    return 0;
}