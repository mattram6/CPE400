#ifndef NODE_H
#define NODE_H

#include <vector>
using namespace std;
class Node
{
    public:
        Node();
        ~Node();

        vector<Node*> getOneHopNeighbors();
        void addOneHopNeighbor(Node* neighbor);
        Node* getOneHopNeighbor(int index);
        int getOneHopNeighborNum();
    private:
        int energy;
        int nodeID;
        vector<Node*> oneHopNeighbor;
        vector<Node*> twoHopNeighbor;
        bool MPR;
};

#endif /* NODE_H */
