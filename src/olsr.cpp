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

	for(int p = 0; p < getNumOfNodes(); p++)
    {
        broadcastHello(network[p]);
    }
	cout << "1 Hop Neighbors of Network" << endl << endl;
	for(int x = 0; x < getNumOfNodes(); x++)
	{
		Node* currentNode = network[x];
		cout << "Node " << x << ": ";
		for(int y = 0; y < currentNode->getOneHopNeighborNum(); y++ )
		{
			cout << (currentNode-> getOneHopNeighbor(y)->getNodeID()) << " ";
		}
		cout << endl;
	}
    cout << endl << "2 Hop Neighbors of Network" << endl << endl;
	for(int i = 0; i < getNumOfNodes(); i++)
	{
		Node* currentNode = network[i];
		cout << "Node " << i << ": ";
		for(int j = 0; j < currentNode->getTwoHopNeighborNum(); j++ )
		{
			cout << (currentNode-> getTwoHopNeighbor(j)->getNodeID()) << " ";
		}
		cout << endl;
	}
	
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
        network[i] = new Node(i);
    }
}

//Returns the current number of nodes in the network
int OLSR::getNumOfNodes()
{
	return network.size();
}

//Sets up 2 Hop Neighbor Table
void OLSR::broadcastHello(Node* node)
{
    for(int i = 0; i < node->getOneHopNeighborNum(); i++)
    {
        Node *currentNeighbor = node -> getOneHopNeighbor(i);
        for(int j = 0; j < currentNeighbor -> getOneHopNeighborNum(); j++)
        {
			for(int k = 0; k < node -> getOneHopNeighborNum(); k++)
            {
            	if(node == currentNeighbor -> getOneHopNeighbor(j)) 
                {
					break;
                }
				else if((currentNeighbor -> getOneHopNeighbor(j) == node -> getOneHopNeighbor(k)))
				{
					break;
				}
				else if( node->inTwoHopTable(currentNeighbor -> getOneHopNeighbor(j)))
				{
					break;
				}
                else
				{
					cout << j << "  " << k << endl;
					node -> addTwoHopNeighbor(currentNeighbor -> getOneHopNeighbor(j));
					break;
				}
    		}
		}
	}
	
}
