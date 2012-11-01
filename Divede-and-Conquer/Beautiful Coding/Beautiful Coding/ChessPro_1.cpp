#include "ChessPro_1.h"
//adopt Traversal method
ChessPro_1::ChessPro_1()
{
	cout<<"ChessPro class is constructed!!!"<<endl;
}
void ChessPro_1::ChessPro_Traverse()
{
	//construct function;
	unsigned char i=0;//waring:char's length is [-127,128],but unsiged char's length is [0,255]
	Var=0;
	for(;i<=136;i++)
	{
		if((i&0x0F)<9)
		{
			if((i&0x0F)%3!=((i&0xF0)>>4)%3)
			{
				cout<<(1+(i&0x0F))<<(1+((i&0xF0)>>4))<<endl;
				Var++;
			}
		}	
		else
			continue;
	}
	cout<<"times:"<<Var<<endl;
}
void ChessPro_1::ChessPro_Opt()
{
	char i;
	Var=0;
	for(i=1;i<=81;i++)
	{
		if((i/9% 3)!=((i% 9) % 3) )
		{
			cout<<"King Position is:"<<(i %9)+1<<(i/9)+1<<endl;
			Var++;
		}
	}
	cout<<"times:"<<Var<<endl;
}
bool ChessPro_1::Comp(int numA,int numB)
{
	if(numA-numB<0)
		return true;
	else 
		return false;
}