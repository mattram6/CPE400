#ifndef NODE_H
#define NODE_H

#include "../include/route.h"
#include <vector>

using namespace std;
class Node
{
    public:
        Node(int ID);
        ~Node();
		
		int getNodeID();
		bool inTwoHopTable(Node* neighbor);

        vector<Node*> getOneHopNeighbors();
        vector<Node*> getTwoHopNeighbors();
		void buildRoutingTable();
        void addOneHopNeighbor(Node* neighbor);
        Node* getOneHopNeighbor(int index);
        int getOneHopNeighborNum();
		void addTwoHopNeighbor(Node* neighbor);
        Node* getTwoHopNeighbor(int index);
        int getTwoHopNeighborNum();
        void setMPR(bool flag);
        bool getMPR();
        bool neighboringMPR();

    private:
        int energy;
		int nodeID;
        vector<Node*> oneHopNeighbor;
        vector<Node*> twoHopNeighbor;
        bool MPR;
		vector<Route> routingTable;
};

#endif /* NODE_H */
