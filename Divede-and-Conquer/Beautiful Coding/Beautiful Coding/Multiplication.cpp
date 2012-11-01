#include "Multiplication.h"

CMultiplication::CMultiplication(void)
{
}

CMultiplication::~CMultiplication(void)
{
}

long CMultiplication::MultiDivide(long multiNumTop,long multiNumDown,int bitLenTop,int bitLenDown)
{
	int lenTop=bitLenTop/2;
	int lenDown=bitLenDown/2;
	double  top_1=pow(2,(double)lenTop)-1;
	double  down_1=pow(2,(double)lenDown)-1;

	int top=(int) top_1;
	int down=(int) down_1;
	if(lenTop||lenDown)
		return multiNumTop*multiNumDown;
	else
	{
		long M1=MultiDivide(multiNumTop>>lenTop,multiNumDown>>lenDown,lenTop,lenDown);
		long M2=MultiDivide(multiNumTop&top,multiNumDown>>lenDown,lenTop,lenDown);
		long M3=MultiDivide(multiNumTop>>lenTop,multiNumDown&down,lenTop,lenDown);
		long M4=MultiDivide(multiNumTop&down,multiNumDown&top,lenTop,lenDown);
		return MultiConquer(M1,M2,M3,M4,lenTop,lenDown);
	}
}

long CMultiplication::MultiConquer(long M1,long M2,long M3,long M4,int halfLenTop,int halfLenDown)
{
	long multiValue=(M1<<(halfLenTop+halfLenDown))+(M2<<halfLenDown)+(M3<<halfLenTop)+M4;
	return multiValue;
}
