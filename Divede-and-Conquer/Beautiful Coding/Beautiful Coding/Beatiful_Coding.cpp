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
	////int test=dynamicProgramming.BookKinds[0];/�����ܷ���
	///*****************================================***************
	//private��ͨ������ɸ�������ݲ��֣�public��Ƹ���Ľӿڲ��֣�protected��ͨ�������ﶨ��ķ��������ݳ�Աͨ�������������ء� 
 //   ���һ������PUBLIC��ʽ�̳У���ô��������������򲿷ֲ��䣬public����Ȼ��public��private����Ȼ��private��protected����Ȼ��protected��
 //   �����е�˽�г�Ա���ܱ����ʣ������private��ʽ�̳�������protected��public���ֽ�����Ϊ˽�в��֣�
 //   ������ԶԻ����protected   and   public���з��ʣ������ܷ���˽�в��֣������protected�̳У���ô�����е�public   and   protected   ����
	//�������б���Ϊprotected���֣������е�public   and   protected���ֿ��Ա����ʣ���˽�в��ֲ����Է��ʡ��������ּ̳з�ʽ��publicȨ�����
	//private:��С��protected�����С�
	//******************================================***************/
	////float price=dynamicProgramming.Price(dynamicProgramming.BookNum,dynamicProgramming.BookKinds)//BookNum������Ϊprotected����������Ǹ����ʣ�
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