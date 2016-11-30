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
        Node* getNode(int index);
    private:
        vector<Node*> network;
};

#endif /* OLSR_H */
