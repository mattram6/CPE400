#include "../include/node.h"
#include <iostream>

Node::Node(int ID)
{
	nodeID = ID;
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

// 1 Hop 

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

//2 Hop

bool Node::inTwoHopTable(Node* neighbor)
{
	for(int i = 0; i < getTwoHopNeighborNum(); i++)
	{
		if(twoHopNeighbor[i] == neighbor)
		{
			return true;
		}
	}
	return false;
}

void Node::addTwoHopNeighbor(Node* neighbor)
{
    twoHopNeighbor.push_back(neighbor);
}

int Node::getTwoHopNeighborNum()
{
    return twoHopNeighbor.size();
}

Node* Node::getTwoHopNeighbor(int index)
{
    return twoHopNeighbor[index];
}

vector<Node*> Node::getTwoHopNeighbors()
{
    return twoHopNeighbor;
}

int Node::getNodeID()
{
	return nodeID;
}

void Node::setMPR(bool flag)
{
    MPR = flag;
}

bool Node::getMPR()
{
    return MPR;
}

bool Node::neighboringMPR()
{
    bool neighboringMPR = false;
    for(int i = 0; i < getOneHopNeighborNum(); i++)
    {
        if(oneHopNeighbor[i]->getMPR())
        {
            neighboringMPR = true;
        }
    }
    return neighboringMPR;
}

bool Node::isOneHopNeighbor(Node* node)
{
    for(unsigned int i = 0; i < oneHopNeighbor.size(); i++)
    {
        if(node == oneHopNeighbor[i])
        {
            return true;
        }
    }
    return false;
}

void Node::pushRoute(Route route)
{
    routingTable.push_back(route);
}

Route Node::getRoute(int routeNum)
{
    return routingTable[routeNum];
}

int Node::getTableSize()
{
    return routingTable.size();
}

vector<Route> Node::getRoutingTable()
{
	return routingTable;
}

int Node::getEnergy()
{
	return energy;
}

void Node::losePower()
{
	energy--;
}

void Node::removeRoute(int index)
{
    routingTable.erase(routingTable.begin() + index);
}

void Node::removeOneHopNeighbor(Node *node)
{
    for(unsigned int i = 0; i < oneHopNeighbor.size(); i++)
    {
        if(node == oneHopNeighbor[i])
        {
            oneHopNeighbor.erase(oneHopNeighbor.begin() + i);
        }
    }
}

void Node::clearTwoHop()
{
    twoHopNeighbor.clear();
    twoHopNeighbor.shrink_to_fit();
}

void Node::clearRoutingTable()
{
    routingTable.clear();
    routingTable.shrink_to_fit();
}
