#include "VertexColoring.h"

CVertexColoring::CVertexColoring(void)
{
}

CVertexColoring::~CVertexColoring(void)
{
}

int CVertexColoring::Coloring(void)
{

	return 0;
}

bool CVertexColoring::GraphInit(int* matrix, int vertex)
{
	vertexNum=vertex;
	if(vertexNum==0)
		return false;
	else 
	{
		for(int i=0;i<vertexNum;i++)
			for(int j=0;j<vertexNum;j++)
				graph[i][j]=*(matrix+(i*vertex+j));//����άָ��ֻ��ʾ��ά����ͷָ�룬��ȡֵ��̫����
		return true;
	}
}