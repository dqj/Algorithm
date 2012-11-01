//window OS 下文件名不区分大小写
#pragma once
#define MaxBookKinds 100
#include "SmartTea.h"
#include "Sort.h"
#include <iostream>
using namespace std;

class CDynamicProgramming  :
	public CSort
{
public:
	CDynamicProgramming(void);
	~CDynamicProgramming(void);
	void InitBookNum(void);
	bool IsBookNumNull(int* ArrayBookNum,int Length);
	float PriceDiscount[MaxBookKinds];
	float Minim(float* ArrayPrice,int Length);
	float Price(int* ArrayBookNum, int Length);
	float DisPlayPrice(float* ArrayPrice, int Length);
protected:
//private:
	int BookNum[MaxBookKinds];//define the number of each kind book
	int BookKinds;//define the kinds of books;
	float PriceBooks[MaxBookKinds];
};
