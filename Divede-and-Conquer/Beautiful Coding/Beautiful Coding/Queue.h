#pragma once
#include <iostream>
using namespace std;
#define MAXLEN  10 
// define sequential queue 
typedef struct
{
	int arrayQueue[MAXLEN];
	int front;
	int rear;
}queueSeq;
//define cycle queue
typedef struct
{
	int arrayQueue[MAXLEN];
	int front;
	int rear;
	int queueLen;
}queueCycle;
//define chain queue
typedef struct queueNode
{
	int data;
	struct queueNode *next;

}queueNode;
typedef struct
{
	queueNode *front,*rear;
}queueChain;
//===============================
class CQueue
{
public:
	CQueue(void);
	CQueue(int mark);
	void Init(int label);
	~CQueue(void);
//protected:
	queueSeq *p;
	queueCycle *q;
	queueChain *r;
	int label;
public:
	bool EnQueue(int element);
	int DeQueue(void);
	bool IsQueueEmpty(void);
	bool OverFlowQueue(void);
	int DepthQueue(void);
};
