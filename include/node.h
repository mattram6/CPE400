#ifndef NODE_H
#define NODE_H

#include <vector>
using namespace std;
class Node
{
    public:
        Node();
        ~Node();
    private:
        int energy;
        vector<Node*> oneHopNeighbor;
        vector<Node*> twoHopNeighbor;
        bool MPR;
};

#endif /* NODE_H */
