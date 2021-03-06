#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <map>
#include <set>

class Node;

class Graph
{
    std::map<int, Node*> nodes;

public:

    /*!
     * Constructor.
     * @param adjacencyMatrix the adjacency matrix of the graph.
     */
    Graph(std::vector<std::vector<int>> adjacencyMatrix);

    /*!
     * Destructor.
     */
    ~Graph();

    /*!
     * Prints the graph, i.e., all its nodes along with the neighbors for each node. 
     */
    void print();

    /*!
     * Traverses the graph with depth-first search (DFS) in order to find a path between 
     * the originNode and the destNode.
     * @param originNode the origin node.
     * @param destNode the destination node.
     * @param visited contains the nodes that have been explored.
     * @return true if path exists, false otherwise.
     */
    bool pathExistsDFSRec(int originNode, int destNode, std::vector<int>& visited);

    /*!
     * Traverses the graph with depth-first search (DFS) in order to find a path between 
     * the originNode and the destNode.
     * @param originNode the origin node.
     * @param destNode the destination node.
     * @param visited contains the nodes that have been explored.
     * @return true if path exists, false otherwise.
     */
    bool pathExistsDFSIter(int originNode, int destNode, std::vector<int>& visited);

    /*!
     * Traverses the graph with breadth-first search (BFS) in order to find a path between 
     * the originNode and the destNode.
     * @param originNode the origin node.
     * @param destNode the destination node.
     * @param visited contains the nodes that have been explored.
     * @return true if path exists, false otherwise.
     */
    bool pathExistsBFSIter(int originNode, int destNode, std::vector<int>& visited);
};

#endif