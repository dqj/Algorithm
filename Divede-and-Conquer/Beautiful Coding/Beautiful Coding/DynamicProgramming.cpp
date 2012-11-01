#include "DynamicProgramming.h"

CDynamicProgramming::CDynamicProgramming(void)
{
	cout<<"=========Dynamic Programming======"<<endl;
	cout<<"Readme:Input the number of books."<<endl;
	BookKinds=5;
}

CDynamicProgramming::~CDynamicProgramming(void)
{
}

void CDynamicProgramming::InitBookNum(void)
{
	int i=0;
	char choice;
	cout<<"Would you use default discount![y/n]:";
    cin>>choice;
	if(choice=='y')
	{
		//use default  book  number and discount
		PriceDiscount[0]=0;
		PriceDiscount[1]=0.05;
		PriceDiscount[2]=0.1;
		PriceDiscount[3]=0.2;
		PriceDiscount[4]=0.25;
	}
	else
	{
		cout<<"Input How many kinds of book:";
		cin>>BookKinds;
		while(BookKinds<0)
		{
				cout<<"Input Number is below 0,please input again!"<<endl;
				cin>>BookKinds;
		}
		
		//Input form screen 
		while(i<BookKinds)	
		{
			PriceBooks[i]=0;
			cout<<"Input"<<i+1<<"'s number:"<<endl;
			cin>>BookNum[i];
			while(BookNum[i]<0)
			{
				cout<<"Input Number is below 0,please input again!"<<endl;
				cin>>BookNum[i];
			}
		
			cout<<"Input"<<i+1<<"'s discount:"<<endl;
			cin>>PriceDiscount[i++];
			while(PriceDiscount[i-1]<0&&PriceDiscount[i-1]>1)
			{
				cout<<"Input Number is below 0 or above 1,please input again!"<<endl;
				cin>>PriceDiscount[i-1];
			}	
		}
	}
}

bool CDynamicProgramming::IsBookNumNull(int* ArrayBookNum,int Length)
{
	int Sum=0;
	for(int i=0;i<Length;i++)
		Sum=Sum+ArrayBookNum[i];
	if(Sum==0)
		return false;
	else 
		return true;
}
//find Array  ArrayBookNum's minim 
float CDynamicProgramming::Minim(float* ArrayPrice,int Length)
{
	float Min=ArrayPrice[0];
	for(int i=1;i<Length;i++)
	{
		if(ArrayPrice[i]<Min)
			Min=ArrayPrice[i];
	}
	return Min;
}

float CDynamicProgramming::Price(int* ArrayBookNum,int Length)
{
	if(IsBookNumNull(ArrayBookNum,Length))
	{
		SelectSort(ArrayBookNum,Length);
		int ArrayBookNum_1[MaxBookKinds][MaxBookKinds];
		float price_1[MaxBookKinds];//save current price
		int mark=0;//Mark the number of ArrayBookNum which  element is not zero
		for(int i=Length-1;i>=0;i--)
		{
			if(ArrayBookNum[i]>=1)
			{
				mark++;
				price_1[i]=0;		
				for(int j=i;j>=0;j--)
				{
					//ArrayBookNum[j]=ArrayBookNum[j]-1;//save current array
					ArrayBookNum_1[i][j]=ArrayBookNum[j]-1;

				}
				for(int j=i+1;j<Length;j++)
				{
					ArrayBookNum_1[i][j]=ArrayBookNum[j];
				}
				//PriceBooks[i]=PriceBooks[i]+(i+1)*8*(1-PriceDiscount[i])+Price(ArrayBookNum[i],Length);//take care:init PriceBooks[i]=0
				price_1[i]=(i+1)*8*(1-PriceDiscount[i])+Price(ArrayBookNum_1[i],Length);
			}
		}
		 PriceBooks[0]=Minim(price_1,mark);
		//PriceBooks[0]=PriceBooks[0]+min_1;//take care:init PriceBooks[i]=0
		return PriceBooks[0];

	}
	else 
    	return 0;
}

float CDynamicProgramming::DisPlayPrice(float* ArrayPrice, int Length)
{
	return Minim(ArrayPrice,Length);
}
