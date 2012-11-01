/***============================base class ���������Ͷ���ԭ��===========================***
===========������Ϊ����ʱ������Ա���Ϊpublic �ı�׼û�иı䣺��Ȼ�ǽӿ�===================
===========����Ӧ��Ϊpublic������һ�㲻ӦΪpublic�����̳е���������ʵ��==================
===========����Щ��������Ϊprotected������Щ��������Ϊprivate��ϣ����ֹ��==================
===========������ʵĳ�ԱӦ����Ϊprivate���ṩ������ʵ��������������ݵĳ�=================
===========ԱӦ��Ϊprotected�����仰˵���ṩ���������͵Ľӿ���protected��Ա================
===========                    ��public��Ա����ϡ�                ========================
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
