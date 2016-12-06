#ifndef OLSR_H
#define OLSR_H

#include <vector>
#include "node.h"

using namespace std;

class OLSR
{
    public:
        OLSR();
        ~OLSR();
		
	    void pushNodes(int num);
	    int getNumOfNodes();
        void broadcastHello(Node* node);
        void topologyControl();
        Node* getNode(int index);
        void createRoutingTable(Node* node);
        Route findRoute(Node* prev, Node* src, Node* dest, int seqNum);
        bool sendPacket(int src, int dest);
		void checkNetworkPower();
    private:
        vector<Node*> network;
};

#endif /* OLSR_H */
