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
	int volumeDrink[MAXKINDS];//ĳ������һƿ���ݻ�
	int opt[MAXNUM][MAXKINDS];
	int numDrink[MAXKINDS];
	int drinkKinds;
	int volume;
};
