#pragma once
#include <iostream>
using namespace std;
class CChess
{
public:
	CChess(void);
	~CChess(void);
	bool Comp(int numA,int numB);
	void ChessPro_Traverse();
	void ChessPro_Opt();
protected:
	int Var;

};
