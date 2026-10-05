#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <utility>

class Graph
{
private:
    int vertices;
    int edges;
    std::vector<std::vector<std::pair<int, int>>> adjacencyList;

public:
    Graph(int vertices);
    void addEdge(int source, int destination, int distance);
    void displayGraph();
};

#endif