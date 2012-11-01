#pragma once
#define MAXVERTEX  100
class CVertexColoring
{
public:
	CVertexColoring(void);
	~CVertexColoring(void);
protected:
	int graph[MAXVERTEX][MAXVERTEX];
public:
	int Coloring(void);
	int vertexNum;
	bool GraphInit(int* matrix, int vertex);
};
