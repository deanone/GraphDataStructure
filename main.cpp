#include "Graph.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char* argv[])
{
    std::string graphAdjMatrixFilename = "graph.csv";
    std::vector<std::vector<int>> adjacencyMatrix;

    // read graph's adjecency matrix from file
    std::ifstream in(graphAdjMatrixFilename, std::ios::in);
    std::string dataline = "";
    if (in.is_open())
    {
        while (std::getline(in, dataline))
        {
            std::istringstream inStream(dataline);
            std::string item = "";
            std::vector<std::string> items;
            while (getline(inStream, item, ','))
            {
                items.push_back(item);
            }

            std::vector<int> adjacencyMatrixRow;
            for (int i = 0; i < items.size(); i++)
            {
                adjacencyMatrixRow.push_back(std::stoi(items[i]));
            }
            items.clear();
            adjacencyMatrix.push_back(adjacencyMatrixRow);
        }
        in.close();
    }

    Graph* graph = new Graph(adjacencyMatrix);
    graph->print();

    // check for path using DFS
    std::vector<int> visited;
    int originNode = std::stoi(std::string(argv[1]));
    int destNode = std::stoi(std::string(argv[2]));

    std::cout << "Recursive approach\n";
    bool pathExists = graph->pathExistsDFSRec(originNode, destNode, visited);
    if (pathExists)
    {
        std::cout << "Path from node " << originNode << " to node " << destNode << "\n";
        for (auto node : visited)
        {
            std::cout << node << " ";
        }
        std::cout << "\n";
    }
    else
    {
        std::cout << "No path between node " << originNode << " and node " << destNode << " exists.\n";
    }
    visited.clear();

    std::cout << "Iterative approach\n";
    pathExists = graph->pathExistsDFSIter(originNode, destNode, visited);
    if (pathExists)
    {
        std::cout << "Path from node " << originNode << " to node " << destNode << "\n";
        for (auto node : visited)
        {
            std::cout << node << " ";
        }
        std::cout << "\n";
    }
    else
    {
        std::cout << "No path between node " << originNode << " and node " << destNode << " exists.\n";
    }

    // clear resources
    delete graph;

    return 0;
}