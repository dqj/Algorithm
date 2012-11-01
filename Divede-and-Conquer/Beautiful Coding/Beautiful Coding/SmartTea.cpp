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
//volume�����ϵ����ݻ�,����numDrink��satiDegree��volumeDrink��ÿ�����϶�Ӧ������������ȡ�ÿ��������С���ݻ���
//drinkKings�����ϵ����࣬opt[drinkKinds][volume]�Ǵ洢�����Ž��2ά����
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
	opt[0][drinkKinds]=0;//������Ϊ0ʱ��opt[0][drinkKinds]=0
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
				//int volume_1=volume-j*volumeDrink[i];//volumeDrink[i]�ǵ�i�����ϵĵ�������
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
