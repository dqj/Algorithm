#include "SmartTea.h"

CSmartTea::CSmartTea(void)
{
	drinkKinds=5;
	volume=15;
	int satiDegree_1[]={4,2,10,1,2},numDrink_1[]={1,15,3,15,7},volumeDrink_1[]={12,1,4,1,2}; 
	//int satiDegree_1[]={2,10},numDrink_1[]={15,3},volumeDrink_1[]={1,4}; 

	
	for(int i=0;i<drinkKinds;i++)
	{
		satiDegree[i]=satiDegree_1[i];
		numDrink[i]=numDrink_1[i];
		volumeDrink[i]=volumeDrink_1[i];
	}
	
	for(int i=0;i<=volume;i++)
	{
		for(int j=0;j<=drinkKinds;j++)
			opt[i][j]=INF;
	}
	//opt[volume][drinkKinds]=INF;

}

CSmartTea::~CSmartTea(void)
{
}
//volume是饮料的总容积,数组numDrink、satiDegree、volumeDrink是每种饮料对应的数量、满意度、每种饮料最小的容积，
//drinkKings是饮料的种类，opt[drinkKinds][volume]是存储的最优解的2维数组
int CSmartTea::OptSatisfy(int volume, int drinkKinds)
{
	/*
	if(volume==0||drinkKinds==0)
		return 0 ;
	if(opt[volume][drinkKinds]==INF)
	{
		for(int i=0;i<=numDrink[drinkKinds-1];i++)
			if(volume-volumeDrink[drinkKinds-1]*i>=0)
				opt[volume][drinkKinds-1]=OptSatisfy(volume-volumeDrink[drinkKinds-1]*i,drinkKinds-1)+i*satiDegree[drinkKinds-1];
			else 
				continue;		
	}	
	return opt[volume][drinkKinds-1];
	*/

	
	if(drinkKinds==0)
	{
		if(volume==0)
			return 0 ;
		else 
			return INF;
	}
	if(volume<0)
		return INF;
	else if(volume==0)
		return 0;
	else if(opt[volume][drinkKinds]!=INF)
		return opt[volume][drinkKinds];

	for(int i=0;i<=numDrink[drinkKinds-1];i++)
		if(volume-volumeDrink[drinkKinds-1]*i>=0)
			opt[volume][drinkKinds-1]=OptSatisfy(volume-volumeDrink[drinkKinds-1]*i,drinkKinds-1)+i*satiDegree[drinkKinds-1];	

	return opt[volume][drinkKinds-1];

	/*
	opt[0][drinkKinds]=0;//总容量为0时，opt[0][drinkKinds]=0
	for(int i=1;i<=volume;i++)
	{
		opt[0][i]=INF;
	}
	for(int i=0;i<drinkKinds;i++)
	{
		for(int k=1;k<=volume;k++)
		{

			//opt[i][k]=max(OptSatisfy(k,i-1),OptSatisfy(k-numDrink[i],i-1)+satiDegree[i]);
			opt[k][i]=INF;
			for(int j=numDrink[i];j>=0;j--)
			{
				//int volume_1=volume-j*volumeDrink[i];//volumeDrink[i]是第i种饮料的单个容量
				if(k>=j*volumeDrink[i])
				{		
					int x=opt[k-j*volumeDrink[i]][i+1];
					if(x!=INF)
					{	
						x+=j*satiDegree[i];
						if(x>opt[k][i])
						{
							opt[k][i]=x;
						}
					}
				}
			}
		}
		//int mark=FindMaxMin(opt[i],numDrink[i]);
		///return opt[i][mark];
	}
	return opt[volume][0];
	*/
}
