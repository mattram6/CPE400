#include "../include/route.h"
#include <iostream>

Route::Route()
{
	destAddress = 0;
	destMPR = 0;
	MPRSequence = 0;
}

Route::~Route()
{

}

void Route::setDestAddress(int address)
{
	destAddress = address;
}

void Route::setDestMPR( int nodeMPR)
{
	destMPR = nodeMPR;
}
void Route::setMPRSequence( int sequenceNum )
{
	MPRSequence = sequenceNum;
}

int Route::getDestAddress()
{
	return destAddress;
}

int Route::getDestMPR()
{
	return destMPR;
}

int Route::getMPRSequence()
{
	return MPRSequence;
}
