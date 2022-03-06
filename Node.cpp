#include "Node.h"

#include <iostream>
#include <algorithm>

Node::Node(int id)
{
    this->id = id;
}

Node::~Node()
{
    if (!neighbors.empty())
    {
        neighbors.clear();
    }
}

void Node::addNeighbor(int k)
{
    if (std::find(neighbors.begin(), neighbors.end(), k) == neighbors.end())
    {
        neighbors.push_back(k); 
    }
}

void Node::printNeighbors()
{
    for (int i = 0; i < neighbors.size(); i++)
    {
        std::cout << " " << neighbors[i];
    }
    std::cout << "\n";
}

std::vector<int>* Node::getNeighbors()
{
    return &neighbors;
}