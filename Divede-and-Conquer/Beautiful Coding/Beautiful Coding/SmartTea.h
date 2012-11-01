#pragma once
#include "Sort.h"
#define MAXKINDS 100
#define MAXNUM   100
#define  INF     -1
class CSmartTea
	:public CSort
{
public:
	CSmartTea(void);
	~CSmartTea(void);
public:
	int OptSatisfy(int volume,  int drinkKings);
	int satiDegree[MAXKINDS];
	int volumeDrink[MAXKINDS];//某种饮料一瓶的容积
	int opt[MAXNUM][MAXKINDS];
	int numDrink[MAXKINDS];
	int drinkKinds;
	int volume;
};
