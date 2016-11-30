#ifndef ROUTE_H
#define ROUTE_H

using namespace std;

class Route
{
	public:
		Route();
		~Route();

		void setDestAddress(int address);
		void setDestMPR( int nodeMPR);
		void setMPRSequence( int sequenceNum );
		int getDestAddress();
		int getDestMPR();
		int getMPRSequence();

	private:
		int destAddress;
		int destMPR;
		int MPRSequence;
};

#endif
