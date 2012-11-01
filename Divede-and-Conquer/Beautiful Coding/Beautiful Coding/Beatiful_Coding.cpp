#include "Beatiful_Coding.h"
void Prematation(string &in,string &out, int len,int level);
void main()
{
	string in="abc";
	string out;
	Prematation(in,out,3,0); 

	/*
	ChessPro chessPro;
	chessPro.ChessPro_Traverse();
	chessPro.ChessPro_Opt();
	*/
	/*
	CSort cSort;
	cSort.Init_Sequence();
	cSort.CountRever_Times();
	*/
 
 //   int ArrayNum[5]={2,3,3,1,3};
	//CBuyBook buyBook;
	//float sum=buyBook.SearchFast(ArrayNum);

	//CDynamicProgramming  dynamicProgramming;
	//dynamicProgramming.InitBookNum();
	//float price=dynamicProgramming.Price(ArrayNum,5);
	////int test=dynamicProgramming.BookKinds[0];/、不能访问
	///*****************================================***************
	//private域通常定义成该类的数据部分，public域称该类的接口部分，protected域通常在这里定义的方法或数据成员通常留给子类重载。 
 //   如果一个类以PUBLIC方式继承，那么该类各上述三个域部分不变，public域仍然是public域，private域仍然是private域，protected域仍然是protected域，
 //   基类中的私有成员不能被访问；如果以private方式继承则基类的protected和public部分将被视为私有部分，
 //   子类可以对基类的protected   and   public进行访问，但不能访问私有部分；如果以protected继承，那么基类中的public   and   protected   部分
	//在子类中被视为protected部分，基类中的public   and   protected部分可以被访问，但私有部分不可以访问。并且三种继承方式，public权限最大，
	//private:最小，protected：居中。
	//******************================================***************/
	////float price=dynamicProgramming.Price(dynamicProgramming.BookNum,dynamicProgramming.BookKinds)//BookNum的类型为protected，因而不能那个访问？
	//cout<<"Price is:"<<price<<endl;
	
	//CSmartTea smartTea;
	//int i=smartTea.OptSatisfy(smartTea.volume,smartTea.drinkKinds);
	//CQuickSort quickSort;
	//int a[]={3,1,2,6,4,7,9,5,3,1,2,6,4,7,9,5};
	//quickSort.MergeSort(a,0,15);
	//for(int i=0;i<16;i++)
	//	cout<<a[i]<<endl;

	//CMultiplication multiplication;
	//int x=multiplication.MultiDivide(300,15,9,4);
	//cout<<x<<endl;
	/*
	matrix a,b;
	a.column=a.row=2;
	b.column=b.row=2;
	//a.init(2,2);
	//b.init(2,2)

	a.mat[0][0]=7;
	a.mat[0][1]=6;
	a.mat[1][0]=5;
	a.mat[1][1]=4;
	b.mat[0][0]=7;
	b.mat[0][1]=6;
	b.mat[1][0]=5;
	b.mat[1][1]=4;
	;

	CMatrixMultiple matrixMul;
	matrix c=matrixMul.MatrixMulti(a,b);
	cout<<c.mat[0][0]<<endl;
	cout<<c.column<<c.row<<endl;
	*/
	getchar();
}
void Prematation(string &in,string &out, int len,int level){    if(level==len)        return;    for(;level<len;level++)    {        out.push_back(in[level]);		cout<<out.data()<<endl;        Prematation(in,out,len,level+1);        out.erase(in[level]);         //out.Empty(  )  ;        //out="";    }      return;}