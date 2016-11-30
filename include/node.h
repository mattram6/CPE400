#ifndef NODE_H
#define NODE_H

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

        void addOneHopNeighbor(Node* neighbor);
        Node* getOneHopNeighbor(int index);
        int getOneHopNeighborNum();
		void addTwoHopNeighbor(Node* neighbor);
        Node* getTwoHopNeighbor(int index);
        int getTwoHopNeighborNum();

    private:
        int energy;
		int nodeID;
        vector<Node*> oneHopNeighbor;
        vector<Node*> twoHopNeighbor;
        bool MPR;
};

#endif /* NODE_H */
