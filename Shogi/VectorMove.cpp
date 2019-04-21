#include "VectorMove.h"



VectorMove::VectorMove()
{
	
}

VectorMove::VectorMove(int a,int b)
{
	x = a;
	y = b;
}
VectorMove::~VectorMove()
{
}
int& VectorMove::getCompX()
{
	return this->x ;
}
int& VectorMove::getCompY()
{
	return  this->y;
}