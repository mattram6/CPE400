#include "../include/node.h"
#include <iostream>

Node::Node()
{
    energy = 100;
	MPR = false;
    oneHopNeighbor.clear();
}

//Deletes vector objects and frees the memory allocated
Node::~Node()
{
	for(unsigned int i = 0; i < (oneHopNeighbor.size()); i++)
	{
		oneHopNeighbor[i] = NULL;
	}
	for(unsigned int j = 0; j < (twoHopNeighbor.size()); j++)
	{
		twoHopNeighbor[j] = NULL;
	}
	oneHopNeighbor.clear();
	oneHopNeighbor.shrink_to_fit();
	twoHopNeighbor.clear();
	twoHopNeighbor.shrink_to_fit();
}

void Node::addOneHopNeighbor(Node* neighbor)
{
    oneHopNeighbor.push_back(neighbor);
}

int Node::getOneHopNeighborNum()
{
    return oneHopNeighbor.size();
}

Node* Node::getOneHopNeighbor(int index)
{
    return oneHopNeighbor[index];
}

vector<Node*> Node::getOneHopNeighbors()
{
    return oneHopNeighbor;
}
