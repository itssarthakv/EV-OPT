#include "Graph.h"
#include <iostream>

Graph::Graph(int vertices)
{
    this->vertices = vertices;
    this->edges = 0;
    adjacencyList.resize(vertices);
}

void Graph::addEdge(int source, int destination, int distance)
{
    adjacencyList[source].push_back({destination, distance});
    adjacencyList[destination].push_back({source, distance});

    edges++;
}

void Graph::displayGraph()
{
    for (int i = 0; i < vertices; i++)
    {
        std::cout << i << " -> ";

        for (auto edge : adjacencyList[i])
        {
            std::cout << "(" << edge.first << ", " << edge.second << ") ";
        }

        std::cout << std::endl;
    }
}