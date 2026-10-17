#include "Graph.h"
#include <iostream>
#include <queue>
#include <climits>
#include <functional>

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
}   // ✅ This closes displayGraph()


void Graph::dijkstra(int source)
{
    std::vector<int> distance(vertices, INT_MAX);

    std::priority_queue<
        std::pair<int, int>,
        std::vector<std::pair<int, int>>,
        std::greater<std::pair<int, int>>
    > pq;

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int currentDistance = pq.top().first;
        int currentVertex = pq.top().second;

        pq.pop();

        if (currentDistance > distance[currentVertex])
        {
            continue;
        }

        for (auto edge : adjacencyList[currentVertex])
        {
            int nextVertex = edge.first;
            int edgeDistance = edge.second;

            int newDistance = currentDistance + edgeDistance;

            if (newDistance < distance[nextVertex])
            {
                distance[nextVertex] = newDistance;
                pq.push({newDistance, nextVertex});
            }
        }
    }

    std::cout << "Shortest distances from vertex "
              << source << ":" << std::endl;

    for (int i = 0; i < vertices; i++)
    {
        if (distance[i] == INT_MAX)
        {
            std::cout << i << " -> Unreachable" << std::endl;
        }
        else
        {
            std::cout << i << " -> " << distance[i] << std::endl;
        }
    }
}