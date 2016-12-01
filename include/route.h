#ifndef ROUTE_H
#define ROUTE_H

#include "../include/node.h"

using namespace std;

class Route
{
	public:
		Route();
		~Route();

		void setDestAddress(Node* address);
		void setDestMPR( Node* nodeMPR);
		void setMPRSequence( int sequenceNum );
		Node* getDestAddress();
		Node* getDestMPR();
		int getMPRSequence();

	private:
	    Node* destAddress;
		Node* destMPR;
		int MPRSequence;
};

#endif
