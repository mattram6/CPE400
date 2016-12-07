#include "../include/olsr.h"
#include <iostream>

using namespace std;

void update(OLSR *network);
void testSmall(OLSR *network);
void testSmallEnergy(OLSR *network);
void testLarge(OLSR *network);
void testLargeEnergy(OLSR *network);

int main()
{
    bool size;
    cout << "Select Network" << endl;
    cout << "Enter 0 for small network or 1 or greater for large network" << endl;
    cin >> size;
    OLSR *myNetwork = new OLSR(size);

    // Build 2-Hop Neighbor Tables
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
    
    // Build routing table
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

    cout << "Select Test" << endl;
    if(size)
    {
        bool test;
        cout << "Enter 0 for OLSR or 1 for OLSR with energy" << endl;
        cin >> test;
        if(test)
        {
	        testLargeEnergy(myNetwork);
            //myNetwork->checkNetworkPower();
        }
        if(!test)
        {
            testLarge(myNetwork);
            //myNetwork->checkNetworkPower();
        }
    }
    if(!size)
    {
        bool test;
        cout << "Enter 0 for OLSR or 1 for OLSR with energy" << endl;
        cin >> test;
        if(test)
        {
	        testSmallEnergy(myNetwork);
            //myNetwork->checkNetworkPower();
        }
        if(!test)
        {
            testSmall(myNetwork);
            //myNetwork->checkNetworkPower();
        }
    }
    
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

void testSmall(OLSR *network)
{
    for(int i = 0; i < 3; i++)
    {
        network->sendPacket(1, 9);
        network->checkNetworkPower();
    }
    for(int i = 0; i < 7; i++)
    {
        network->sendPacket(0, 2);
        network->checkNetworkPower();
    }
}    

void testSmallEnergy(OLSR *network)
{
    for(int i = 0; i < 3; i++)
    {
        network->sendPacketEnergy(1, 9);
        network->checkNetworkPower();
    }
    for(int i = 0; i < 7; i++)
    {
        network->sendPacketEnergy(0, 2);
        network->checkNetworkPower();
    }
}            

void testLarge(OLSR *network)
{
    for(int i = 0; i < 5; i++)
    {
        network->sendPacket(3, 34);
        network->checkNetworkPower();
    }
    for(int i = 0; i < 5; i++)
    {
        network->sendPacket(2, 34);
        network->checkNetworkPower();
    }
}

void testLargeEnergy(OLSR *network)
{
    for(int i = 0; i < 5; i++)
    {
        network->sendPacketEnergy(3, 34);
        network->checkNetworkPower();
    }
    for(int i = 0; i < 5; i++)
    {
        network->sendPacket(2, 34);
        network->checkNetworkPower();
    }
}
