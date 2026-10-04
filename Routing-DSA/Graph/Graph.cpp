#include "Graph.h"

Graph::Graph(int vertices)
{
    this->vertices = vertices;
    this->edges = 0;
    adjacencyList.resize(vertices);
}
