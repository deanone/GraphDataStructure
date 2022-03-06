#ifndef NODE_H
#define NODE_H

#include <vector>

class Node
{
    int id;
    std::vector<int> neighbors;

public:
    /*!
     * Constructor
     * @param id the id of the node. 
     */
    Node(int id);

    /*!
     * Destructor. 
     */
    ~Node();

    /*!
     * Adds a neighbor to the list of neighbors of the node.
     * @param k the id of the neighbor. 
     */
    void addNeighbor(int k);

    /*!
     * Prints the ids of all neighbors of the node. 
     */
    void printNeighbors();

    std::vector<int>* getNeighbors();
};


#endif