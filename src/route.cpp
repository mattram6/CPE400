#include "../include/node.h"
#include <iostream>

Route::Route()
{
	destAddress = NULL;
	destMPR = NULL;
	MPRSequence = 0;
}

Route::~Route()
{

}

void Route::setDestAddress(Node* address)
{
	destAddress = address;
}

void Route::setDestMPR( Node* nodeMPR)
{
	destMPR = nodeMPR;
}
void Route::setMPRSequence( int sequenceNum )
{
	MPRSequence = sequenceNum;
}

Node* Route::getDestAddress()
{
	return destAddress;
}

Node* Route::getDestMPR()
{
	return destMPR;
}

int Route::getMPRSequence()
{
	return MPRSequence;
}
