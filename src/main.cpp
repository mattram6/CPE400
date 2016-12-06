#include "../include/olsr.h"
#include <iostream>

using namespace std;

void update(OLSR *network);

int main()
{
    OLSR *myNetwork = new OLSR();

    // Debugging
    for(int p = 0; p < myNetwork->getNumOfNodes(); p++)
    {
        myNetwork->broadcastHello(myNetwork->getNode(p));
    }

    /*
	cout << "1 Hop Neighbors of Network" << endl << endl;
	for(int x = 0; x < myNetwork->getNumOfNodes(); x++)
	{
		Node* currentNode = myNetwork->getNode(x);
		cout << "Node " << x << ": ";
		for(int y = 0; y < currentNode->getOneHopNeighborNum(); y++ )
		{
			cout << (currentNode-> getOneHopNeighbor(y)->getNodeID()) << " ";
		}
		cout << endl;
	}
    cout << endl << "2 Hop Neighbors of Network" << endl << endl;
	for(int i = 0; i < myNetwork->getNumOfNodes(); i++)
	{
		Node* currentNode = myNetwork->getNode(i);
		cout << "Node " << i << ": ";
		for(int j = 0; j < currentNode->getTwoHopNeighborNum(); j++ )
		{
			cout << (currentNode-> getTwoHopNeighbor(j)->getNodeID()) << " ";
		}
		cout << endl;
	}
    */
	
    myNetwork->topologyControl();
    
    // Debugging
    for(int i = 0; i < myNetwork->getNumOfNodes(); i++)
    {
        for(int j = 0; j < myNetwork->getNumOfNodes(); j++)
        {
            if(myNetwork->getNode(j) != myNetwork->getNode(i) && !(myNetwork->getNode(i)->isOneHopNeighbor(myNetwork->getNode(j))))
		    {
			    myNetwork->findRoute(myNetwork->getNode(i), NULL, myNetwork->getNode(i), myNetwork->getNode(j), 0);
		    }
        }
    }

    // Print routing table
    //myNetwork->printRoutingTable();
   
	for(int i = 0; i < 120; i++)
    {
        myNetwork->sendPacketEnergy(0, 2);
        if(myNetwork->checkNodes())
        {
            update(myNetwork);
        }
    }
    myNetwork->checkNetworkPower();
    
    return 0;
}

void update(OLSR *network)
{
    for(int p = 0; p < network->getNumOfNodes(); p++)
    {
        network->broadcastHello(network->getNode(p));
    }
    network->topologyControl();

    for(int i = 0; i < network->getNumOfNodes(); i++)
    {
        for(int j = 0; j < network->getNumOfNodes(); j++)
        {
            if(network->getNode(j) != network->getNode(i) && !(network->getNode(i)->isOneHopNeighbor(network->getNode(j))))
		    {
			    network->findRoute(network->getNode(i), NULL, network->getNode(i), network->getNode(j), 0);
		    }
        }
    }
}
