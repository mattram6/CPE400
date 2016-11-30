#include "../include/olsr.h"
#include <iostream>

using namespace std;

int main()
{
    OLSR *myNetwork = new OLSR();
    //for(int i = 0; i < myNetwork->getNumOfNodes(); i++)
    //{
        //myNetwork->broadcastHello(network[i]);
    //}
    //myNetwork->topologyControl();
    //myNetwork->createRoutingTable();

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
