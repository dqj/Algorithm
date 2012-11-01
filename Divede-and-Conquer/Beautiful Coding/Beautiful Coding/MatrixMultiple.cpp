#include "MatrixMultiple.h"

CMatrixMultiple::CMatrixMultiple(void)
{
}

CMatrixMultiple::~CMatrixMultiple(void)
{
}

matrix CMatrixMultiple::MatrixMulti(matrix matA,matrix matB)//MatrixDivide
{
	
	matrix mat[8];
	matrix p[7];
	matrix c[4];
	
	if(matA.column>1)
	{

		
		for(int i=0;i<4;i++)
		{
			mat[i].row=matA.row/2;
			mat[i].column=matA.column/2;
			for(int row=0;row<matA.row/2;row++)
				for(int column=0;column<matA.column/2;column++)
				{	
					mat[i].mat[row][column]=matA.mat[row+(i/2)*matA.row/2][column+(i%2)*matA.column/2];		
				}	

			mat[i+4].row=matB.row/2;
			mat[i+4].column=matB.column/2;
			for(int row=0;row<matB.row/2;row++)
				for(int column=0;column<matB.column/2;column++)
				{	
					mat[i+4].mat[row][column]=matB.mat[row+(i/2)*matB.row/2][column+(i%2)*matB.column/2];
				}
		}
		

		for(int j=0;j<7;j++)
		{
			p[j].row=matA.row/2;
			p[j].column=matA.column/2;
		}
		p[0]=MatrixMulti(mat[0],MatrixSub(mat[5],mat[7]));
		p[1]=MatrixMulti(MatrixAdd(mat[0],mat[1]),mat[7]);
		p[2]=MatrixMulti(MatrixAdd(mat[2],mat[3]),mat[4]);
		p[3]=MatrixMulti(mat[3],MatrixSub(mat[6],mat[4]));
		p[4]=MatrixMulti(MatrixAdd(mat[0],mat[3]),MatrixAdd(mat[4],mat[7]));
		p[5]=MatrixMulti(MatrixSub(mat[1],mat[3]),MatrixAdd(mat[6],mat[7]));
		p[6]=MatrixMulti(MatrixSub(mat[0],mat[2]),MatrixAdd(mat[4],mat[5]));
		
		c[0]=MatrixSub(MatrixAdd(MatrixAdd(p[3],p[4]),p[5]),p[1]);
		c[1]=MatrixAdd(p[0],p[1]);
		c[2]=MatrixAdd(p[2],p[3]);
		c[3]=MatrixSub(MatrixAdd(p[0],p[4]),MatrixAdd(p[2],p[6]));	

		return MatrixConquer(c[0],c[1],c[2],c[3]);
	}
	else
	{
		matrix matLast;
		matLast.row=matA.row;
		matLast.column=matA.column;
		matLast.mat[matLast.row-1][matLast.column-1]=matA.mat[matA.row-1][matA.column-1]*matB.mat[matB.row-1][matB.column-1];
		return matLast;

	}
	


}
matrix* CMatrixMultiple::MatrixDivide(matrix matA, matrix matB)
{
	matrix* mat=new matrix[8];
	for(int i=0;i<4;i++)
	{
		mat[i].row=matA.row/2;
		mat[i].column=matA.column/2;
		for(int row=0;row<matA.row/2;row++)
			for(int column=0;column<matA.column/2;column++)
			{	
				mat[i].mat[row][column]=matA.mat[row+(i/2)*matA.row/2][column+(i%2)*matA.column/2];		
			}	

		mat[i+4].row=matB.row/2;
		mat[i+4].column=matB.column/2;
		for(int row=0;row<matB.row/2;row++)
			for(int column=0;column<matB.column/2;column++)
			{	
				mat[i+4].mat[row][column]=matB.mat[row+(i/2)*matB.row/2][column+(i%2)*matB.column/2];
			}
	}
	return mat;
}

matrix CMatrixMultiple::MatrixAdd(matrix matA, matrix matB)
{
	matrix matSum;
	if((matA.row==matB.row)&&(matA.column==matB.column))
	{
		matSum.row=matA.row;
		matSum.column=matA.column;
		for(int i=0;i<matA.row;i++)
			for(int j=0;j<matA.column;j++)
				matSum.mat[i][j]=matA.mat[i][j]+matB.mat[i][j];
	}

	return matSum;
}

matrix CMatrixMultiple::MatrixSub(matrix matA, matrix matB)
{
	matrix matDiff;
	if((matA.row==matB.row)&&(matA.column==matB.column))
	{
		matDiff.row=matA.row;
		matDiff.column=matA.column;
		for(int i=0;i<matA.row;i++)
			for(int j=0;j<matA.column;j++)
				matDiff.mat[i][j]=matA.mat[i][j]-matB.mat[i][j];
	}

	return matDiff;
}

matrix CMatrixMultiple::MatrixConquer(matrix matC1, matrix matC2, matrix matC3, matrix matC4)
{
	matrix matrixConq;
	if((matC1.column==matC3.column)&&(matC1.row=matC2.row)&&(matC2.column==matC4.column)&&(matC3.row==matC4.row))
	{
		matrixConq.row=matC1.row+matC3.row;
		matrixConq.column=matC1.column+matC2.column;
		for(int i=0;i<matC1.row;i++)
		{		
			for(int j=0;j<matC1.column;j++)
				matrixConq.mat[i][j]=matC1.mat[i][j];
			for(int k=0;k<matC2.column;k++)
				matrixConq.mat[i][k+matC1.column]=matC2.mat[i][k];
		}
		for(int i=0;i<matC3.row;i++)
		{
			for(int j=0;j<matC3.column;j++)
				matrixConq.mat[i+matC1.row][j]=matC3.mat[i][j];
			for(int k=0;k<matC4.column;k++)
				matrixConq.mat[i+matC1.row][k+matC1.column]=matC4.mat[i][k];

		}
	}
	return matrixConq;
}





//matrix* CMatrixMultiple::MatrixMulti_1(matrix* matA,matrix* matB)//MatrixDivide
//{
//	//matrix mat[8];
//	matrix* p[7];
//	matrix* c[4];
//	
//	if(matA->column>1)
//	{
//
//		matrix* mat[8]=MatrixDivide(matA,matB);
//		for(int j=0;j<7;j++)
//		{
//			p[j].row=matA->row/2;
//			p[j].column=matA->column/2;
//		}
//		p[0]=MatrixMulti_1(mat[0],MatrixSub(mat[5],mat[7]));
//		p[1]=MatrixMulti_1(MatrixAdd(mat[0],mat[1]),mat[7]);
//		p[2]=MatrixMulti_1(MatrixAdd(mat[2],mat[3]),mat[4]);
//		p[3]=MatrixMulti_1(mat[3],MatrixSub(mat[6],mat[4]));
//		p[4]=MatrixMulti_1(MatrixAdd(mat[0],mat[3]),MatrixAdd(mat[4],mat[7]));
//		p[5]=MatrixMulti_1(MatrixSub(mat[1],mat[3]),MatrixAdd(mat[6],mat[7]));
//		p[6]=MatrixMulti_1(MatrixSub(mat[0],mat[2]),MatrixAdd(mat[4],mat[5]));
//		
//		c[0]=MatrixSub(MatrixAdd(MatrixAdd(p[3],p[4]),p[5]),p[1]);
//		c[1]=MatrixAdd(p[0],p[1]);
//		c[2]=MatrixAdd(p[2],p[3]);
//		c[3]=MatrixSub(MatrixAdd(p[0],p[4]),MatrixAdd(p[2],p[6]));	
//
//		return MatrixConquer(c[0],c[1],c[2],c[3]);
//	}
//	else
//	{
//		matrix matLast;
//		matLast.row=matA.row;
//		matLast.column=matA.column;
//		matLast.mat[matLast.row-1][matLast.column-1]=matA.mat[matA.row-1][matA.column-1]*matB.mat[matB.row-1][matB.column-1];
//		return matLast;
//
//	}
//}
//matrix CMatrixMultiple::MatrixAdd_1(matrix* matA, matrix* matB)
//{
//	matrix matSum;
//	if((matA->row==matB->row)&&(matA->column==matB->column))
//	{
//		matSum.row=matA->row;
//		matSum.column=matA->column;
//		for(int i=0;i<matA->row;i++)
//			for(int j=0;j<matA->column;j++)
//				matSum.mat[i][j]=matA->mat[i][j]+matB->mat[i][j];
//	}
//
//	return matSum;
//}
//
//matrix CMatrixMultiple::MatrixSub_1(matrix* matA, matrix* matB)
//{
//	matrix matDiff;
//	if((matA->row==matB->row)&&(matA->column==matB->column))
//	{
//		matDiff.row=matA->row;
//		matDiff.column=matA->column;
//		for(int i=0;i<matA->row;i++)
//			for(int j=0;j<matA->column;j++)
//				matDiff.mat[i][j]=matA->mat[i][j]-matB->mat[i][j];
//	}
//
//	return matDiff;
//}

