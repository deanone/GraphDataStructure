#include "Graph.h"
#include "Node.h"

#include <iostream>
#include <algorithm>

Graph::Graph(std::vector<std::vector<int>> adjacencyMatrix)
{
    for (int i = 0; i < adjacencyMatrix.size(); i++)
    {
        nodes[i] = new Node(i);
    }

    for (int i = 0; i < adjacencyMatrix.size(); i++)
    {
        for (int j = 0; j < adjacencyMatrix[i].size(); j++)
        {
            if (adjacencyMatrix[i][j] == 1)
            {
                nodes[i]->addNeighbor(j);
                nodes[j]->addNeighbor(i);
            }
        }
    }
}

Graph::~Graph()
{
    if (!nodes.empty())
    {
        for (auto it = nodes.begin(); it != nodes.end(); ++it)
        {
            if (it->second != nullptr)
            {
                delete it->second;
                it->second = nullptr;
            }
        }
        nodes.clear();
    }
}

void Graph::print()
{
    for (auto it = nodes.begin(); it != nodes.end(); ++it)
    {
        std::cout << "Node " << it->first << ":";
        it->second->printNeighbors();
    }
}

// recursive implementation
bool Graph::pathExistsDFS(int originNode, int destNode, std::vector<int>& visited)
{
    auto it = std::find(visited.begin(), visited.end(), originNode);
    if (it != visited.end())
    {
        return false;
    }
    visited.push_back(originNode);

    if (originNode == destNode)
    {
        return true;
    }

    std::vector<int>* neighbors = nodes[originNode]->getNeighbors();

    for (int i = 0; i < neighbors->size(); i++)
    {
        if (pathExistsDFS((*neighbors)[i], destNode, visited))
        {
            return true;
        }
    }
    return false;
}