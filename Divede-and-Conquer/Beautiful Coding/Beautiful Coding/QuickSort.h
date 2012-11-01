#pragma once
#define MAXNUM 100
class CQuickSort
{
public:
	CQuickSort(void);
	virtual ~CQuickSort(void);
	int MergeSort(int* arrayA, int  first, int last);
	int Merge(int* arrayA, int first, int middle, int last);
};
