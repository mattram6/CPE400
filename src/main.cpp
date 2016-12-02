#include "../include/olsr.h"
#include <iostream>

using namespace std;

int main()
{
    OLSR *myNetwork = new OLSR();

    // Debugging
    for(int p = 0; p < myNetwork->getNumOfNodes(); p++)
    {
        myNetwork->broadcastHello(myNetwork->getNode(p));
    }
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

	
    myNetwork->topologyControl();
    
    // Debugging
    for(int i = 0; i < myNetwork->getNumOfNodes(); i++)
    {
        myNetwork->createRoutingTable(myNetwork->getNode(i));
        //cout << endl << "Node " << i << ": " << myNetwork->getNode(i)->getMPR() << endl;
    } 
	cout << endl << "Packet sending from Node 1 to Node 4:" << endl;
	myNetwork->sendPacket(1, 4);
    /*while(engine == good)
    {
        cin << control;
        myNetwork->sendMessage(Node1, Node2);
        myNetwork->broadcastHello();
        myNetwork->topologyControl();
        myNetwork->createRoutingTable();
    }*/
    return 0;
}
