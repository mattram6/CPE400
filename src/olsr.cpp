#include "../include/olsr.h"
#include <iostream>

using namespace std;

OLSR::OLSR()
{
	pushNodes(5);
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
}

//Returns the current number of nodes in the network
int OLSR::getNumOfNodes()
{
	return network.size();
}

/*
void OLSR::broadcastHello(int nodeID)
{
	if( nodeID % 2 == 0 && ((nodeID + 2) < getNumOfNodes()))
	{
		network[nodeID].oneHopNeighbor[0] = network[nodeID+1];
		network[nodeID].oneHopNeighbor[1] = network[nodeID+2];
		network[nodeID+1].oneHopNeighbor[0] = network[nodeID];
		network[nodeID+2].oneHopNeighbor[0] = network[nodeID];
	}
	else
	{

	}
}
*/
