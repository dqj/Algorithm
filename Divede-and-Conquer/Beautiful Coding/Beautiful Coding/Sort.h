/***============================base class 中数据类型定义原则===========================***
===========定义类为基类时，将成员设计为public 的标准没有改变：仍然是接口===================
===========函数应该为public而数据一般不应为public。被继承的类必须决定实现==================
===========的哪些部分声明为protected，而哪些部分声明为private。希望禁止派==================
===========生类访问的成员应该设为private，提供派生类实现所需操作或数据的成=================
===========员应设为protected。换句话说，提供给派生类型的接口是protected成员================
===========                    和public成员的组合。                ========================
***=====================================================================================***
*/
#pragma once
#include <iostream>
using namespace std;
#define MAXLENGTH  100
class CSort
{
public:
	CSort(void);
	virtual ~CSort(void);
	bool Compare(int numA,int numB);
	void Init_Sequence(void);
	void Sort_Sequence(int* Array,int length);
	int FindMaxMin(int* Array,int length);
	void CSort::Reverse(int* Array, int length);
	bool IsSorted(int* Array, int length);
	void CountRever_Times(void);
	void SelectSort(int* ArrayNum, int Length);
protected:
	int Sequense[MAXLENGTH];
	int Reverse_Times;
	int Length_Seq;
	int Max;
	int Min;
};
