#include "../include/olsr.h"
#include <iostream>

using namespace std;

OLSR::OLSR()
{
	pushNodes(5);
    network[0]->addOneHopNeighbor(network[1]);
    network[0]->addOneHopNeighbor(network[3]);
    network[1]->addOneHopNeighbor(network[0]);
    network[1]->addOneHopNeighbor(network[2]);
    network[2]->addOneHopNeighbor(network[1]);
    network[2]->addOneHopNeighbor(network[3]);
    network[3]->addOneHopNeighbor(network[0]);
    network[3]->addOneHopNeighbor(network[2]);
    network[3]->addOneHopNeighbor(network[4]);
    network[4]->addOneHopNeighbor(network[3]);

    cout << "Node 0: " << network[0]->getOneHopNeighborNum() << endl;
    cout << "Node 1: " << network[1]->getOneHopNeighborNum() << endl;
    cout << "Node 2: " << network[2]->getOneHopNeighborNum() << endl;
    cout << "Node 3: " << network[3]->getOneHopNeighborNum() << endl;
    cout << "Node 4: " << network[4]->getOneHopNeighborNum() << endl;
	
    /*
    for(unsigned int i = 0; i < getNumOfNodes(); i++)
    {
        broadcastHello(network[i]);
        {
            neighbordummy = network[i].getNeighbors();

            for(int i = 0; i < network.length(); i++)
            {
                if(selected node)
                    // do nothing
                else // regular case (all other nodes)
                {
                    nework[i].setNeighbors2(network[i].getNeighbors() + neighbordummy);
                }
            }
        }
    }
	*/

    //routing table

}

//Deletes vector object and frees the memory allocated
OLSR::~OLSR()
{
	network.clear();
	network.shrink_to_fit();
}

//Adds nodes to the network
void OLSR::pushNodes(int num)
{
	network.resize(num);
    for(int i = 0; i < num; i++)
    {
        network[i] = new Node();
    }
}

//Returns the current number of nodes in the network
int OLSR::getNumOfNodes()
{
	return network.size();
}


void OLSR::broadcastHello(Node* node)
{
    for(int i = 0; i < node->getOneHopNeighborNum(); i++)
    {
        vector<Node*> TwoHopNeighbor = node->getOneHopNeighbors();
        for(int j = 0; j < TwoHopNeighbor.size(); j++)
        {
            for(int k = 0; k < node->getOneHopNeighbor[i]->getOneHopNeighborNum(); k++)
            {
                if(TwoHopNeighbor[j] == node->getOneHopNeighbor[i])
                {
                    // do nothing
                }
                if(node == node->getOneHopNeighbor[i]->getOneHopNeighbor[k])
                {
                    
            
            
    }
        
	
}
