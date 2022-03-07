#include "Graph.h"
#include "Node.h"

#include <iostream>
#include <algorithm>
#include <stack>

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
// TODO: check if the path from originNode to destNode is returned correctly
bool Graph::pathExistsDFSRec(int originNode, int destNode, std::vector<int>& visited)
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
        if (pathExistsDFSRec((*neighbors)[i], destNode, visited))
        {
            return true;
        }
    }
    return false;
}

// iterative implementation using stack
// TODO: check if the path from originNode to destNode is returned correctly
bool Graph::pathExistsDFSIter(int originNode, int destNode, std::vector<int>& visited)
{
    std::stack<int> s;
    s.push(originNode);
    while (!s.empty())
    {
        int item = s.top();
        s.pop();
        auto it = std::find(visited.begin(), visited.end(), item);
        if (it == visited.end())
        {
            visited.push_back(item);
            if (item == destNode)
            {
                return true;
            }

            std::vector<int>* neighbors = nodes[item]->getNeighbors();
            for (int i = 0; i < neighbors->size(); i++)
            {
                s.push((*neighbors)[i]);
            }
        }
    }
    return false;
}