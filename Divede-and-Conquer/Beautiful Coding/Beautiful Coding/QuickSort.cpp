#include "QuickSort.h"

CQuickSort::CQuickSort(void)
{
}

CQuickSort::~CQuickSort(void)
{
}

int CQuickSort::MergeSort(int* arrayA, int first, int last)
{
	if(first<last)
	{
		int middle=(first+last)/2;
		MergeSort(arrayA,first,middle);
		MergeSort(arrayA,middle+1,last);
		Merge(arrayA,first,middle,last);
	}
	return 0;
}

int CQuickSort::Merge(int* arrayA, int first, int middle, int last)
{
	int p=first,q=middle+1;
	int arrayL[MAXNUM],arrayR[MAXNUM];
	for(int i=p;i<q;i++)
		arrayL[i-p]=arrayA[i];
	for(int i=q;i<=last;i++)
		arrayR[i-q]=arrayA[i];

	bool mark;
	int j=first;
	int k=0,m=0;
	while(1)
	{
		if(arrayL[k]<arrayR[m])
		{
			arrayA[j++]=arrayL[k++];
			if(k>middle-first)
			{
				mark=true;
				break;
			}
		}
		else 
		{
			arrayA[j++]=arrayR[m++];
			//m++;
			if(m>last-middle-1)
			{
				mark=false;
				break;
			}
		}
	}
	for(;j<=last;j++)
	{
		if(mark)
			arrayA[j]=arrayR[m++];
		else
			arrayA[j]=arrayL[k++];
	}
		
	return 0;
}
