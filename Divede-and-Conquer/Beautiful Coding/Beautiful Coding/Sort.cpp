#include "Sort.h"

CSort::CSort(void)
{
	Reverse_Times=0;
}
CSort::~CSort(void)
{
}

bool CSort::Compare(int numA,int numB)
{
	return false;
}

void CSort::Init_Sequence(void)
{
	int i=0;
	cout<<"User Mannel:Enter is quit input and space is another Sequence number."<<endl;
	cout<<"Input the Length of Sequence:";
	cin>>Length_Seq;
	cout<<"Input the number of Sequence:"<<endl;
	/*
	while((c=getchar())!='\n')
	{
		if(c!=' ')
		{
			Sequense[i++]=c;
		}
	}
	for(int j=0;j<i;j++)
		cout<<Sequense[j]<<endl;
	*/
	while(i<Length_Seq)
	{
		cin>>Sequense[i++];
	}
	cout<<"Inputing the  Sequence is Finished."<<endl;
	/*
	//Test input sequence is right or not;
	for(int j=0;j<Length_Seq;j++)
		cout<<Sequense[j]<<endl;
	*/
}

void CSort::Sort_Sequence(int* Array,int length)
{
	int mark;
	mark=FindMaxMin(Array,length);
	if(Max==Array[0])
	{
		Reverse(Array, length);
		Reverse_Times++;
	}
	else if((Max!=Array[length-1]))//Make sure that Maxim number is at the bottom site;
	{
		Reverse(Array, mark+1);
		Reverse(Array, length);
		Reverse_Times=Reverse_Times+2;
	}
}
//find the maxim and minim of a Array
int CSort::FindMaxMin(int* Array,int length)
{
	int mark=0;//mark the maxim number;
	Max=Array[0];//store the Maxim number;
	Min=Array[0];//store the Minim number;
	for(int i=1;i<length;i++)
	{
		if(Max<Array[i])
		{
			Max=Array[i];
		    mark=i;
		}
		if(Min>Array[i])
			Min=Array[i];
	}
	return mark;
}

void CSort::Reverse(int* Array, int length)
{
	for(int i=0;i<length/2;i++)
	{
		int temp;
		temp=Array[i];
		Array[i]=Array[length-1-i];
		Array[length-1-i]=temp;
	}	
}

bool CSort::IsSorted(int* Array, int length)
{
	if(!Array)
	{
		for(int i=0;i<length;i++)
		{
			if(Array[i]>Array[i+1])
				return false;
			else 
				return true;
		}
	}
	else
		return true;
}

void CSort::CountRever_Times(void)
{
	for(int i=Length_Seq;i>1;i--)
	{
		Sort_Sequence(Sequense,i);
		for(int j=0;j<Length_Seq;j++)
			cout<<Sequense[j]<<endl;
	}
	cout<<"Reverse Times is:"<<Reverse_Times<<endl;
}

void CSort::SelectSort(int* ArrayNum, int Length)
{
	if(Length>0&&ArrayNum)
	{	
		for(int i=0;i<Length-1;i++)
		{
			int Mark=i;//take care:init Mark,or Mark remain the premier value;
			int Max=ArrayNum[i];
			for(int j=i+1;j<Length;j++)
				if(Max<ArrayNum[j])
				{	
					Max=ArrayNum[j];
					Mark=j;
				}
			ArrayNum[Mark]=ArrayNum[i];
			ArrayNum[i]=Max;
		}
	}
	else 
		cout<<"Input Array is wrong!!!"<<endl;
		return;
	
}
