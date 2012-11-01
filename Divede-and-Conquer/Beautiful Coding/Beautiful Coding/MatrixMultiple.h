#pragma once
#include <memory.h>
#define MAXMATRIX  4
struct matrix
{
	int mat[MAXMATRIX][MAXMATRIX];
	int row;
	int column;

	matrix()
	{
		row=column=MAXMATRIX;
		memset(mat,0,sizeof(mat));
	}
	inline void init(int row,int column)//初始化为单位矩阵
	{
		for(int i=0;i<row;i++)
			for(int j=0;j<column;j++)
				mat[i][j]=(i==j);//对角线为1；
	}
};
class CMatrixMultiple
{
public:
	CMatrixMultiple(void);
	~CMatrixMultiple(void);
	matrix MatrixMulti(matrix matA,matrix matB);
	matrix* MatrixDivide(matrix matA, matrix matB);
	matrix MatrixAdd(matrix matA, matrix matB);
	matrix MatrixSub(matrix matA, matrix matB);
	matrix MatrixConquer(matrix matC1, matrix matC2, matrix matC3, matrix matC4);


	//matrix MatrixMulti_1(matrix* matA,matrix* matB);
	//matrix MatrixAdd_1(matrix* matA, matrix* matB);
	//matrix MatrixSub_1(matrix* matA, matrix* matB);
};
