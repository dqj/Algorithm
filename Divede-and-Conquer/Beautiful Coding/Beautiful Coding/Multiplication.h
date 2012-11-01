#pragma once
#include <math.h>
class CMultiplication
{
public:
	CMultiplication(void);
	~CMultiplication(void);
	long MultiDivide(long multiNumTop,long multiNumDown,int bitLenTop,int bitLenDown);
	long MultiConquer(long M1,long M2,long M3,long M4,int halfLenTop,int halfLenDown);
};
