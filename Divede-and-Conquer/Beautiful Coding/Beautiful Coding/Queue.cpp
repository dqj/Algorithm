#include "Queue.h"
#define SEQ 1
#define CYCLE 2
#define CHAIN 3
CQueue::CQueue(void)
{
	label=1;
	Init(label);
}
CQueue::CQueue(int mark)
{
	label=mark;
	Init(label);
}
void CQueue::Init(int label)
{
	switch(label)
	{
		case SEQ:
		{
			//采用顺序队列实现
			p=new queueSeq;
			p->front=-1;
			p->rear=-1;
			break;
		}
		case CYCLE:
		{
			//采用循环队列来实现，即队列的尾端指向队列的头
			q=(queueCycle*)malloc(sizeof(queueCycle));
			q->front=q->rear=MAXLEN-1;
			q->queueLen=0;
			break;
		}
		case CHAIN:
		{
			r=new queueChain;
			r->front=r->rear=NULL;
			break;
		}
		default:
			break;
	}
}
CQueue::~CQueue(void)
{
}

bool CQueue::EnQueue(int element)
{
	if(!OverFlowQueue())
	{
		switch(label)
		{
			case SEQ:
				{
					p->arrayQueue[++p->rear]=element;
					break;
				}
			case CYCLE:
				{
					q->rear=(q->rear+1)%MAXLEN;
					q->arrayQueue[q->rear]=element;
					q->queueLen++;
					break;
				}
			case CHAIN:
				{
					queueNode *r_1=new queueNode;
					r_1->data=element;
					r_1->next=NULL;
					if(r->front==NULL)
						r->front=r_1;
					else
						r->rear->next=r_1;
					r->rear=r_1;
				}
			default:
				{
					return false;
					break;
				}
		}
			return true;
	}
	else
		return false;
}

int CQueue::DeQueue(void)
{
	if(!IsQueueEmpty())
	{
		switch(label)
		{
			case SEQ:
				{
					return p->arrayQueue[++p->front];
				}
			case CYCLE:
				{
					q->front=(q->front+1)%MAXLEN;
					q->queueLen--;
					return q->arrayQueue[q->front];
				}
			case CHAIN:
				{
					int x=r->front->data;
					queueNode *r_1;
					r_1=r->front;
					r->front=r->front->next;
					if(r->front==NULL)
						r->rear=NULL;
					delete r_1;
					return x;
				}
			default:
				{
					return 0;
					break;
				}
		}

	}	
	return 0;
}

bool CQueue::IsQueueEmpty(void)
{
	if(DepthQueue()==0)
		return true;
	else 
		return false;
}

bool CQueue::OverFlowQueue(void)
{
	if(DepthQueue()==MAXLEN)
		return true;
	else
		return false;
}

int CQueue::DepthQueue(void)
{
		switch(label)
		{
			case SEQ:
				{
					return (p->rear-p->front);
				}
			case CYCLE:
				{
					return q->queueLen;
				}
			case CHAIN:
				{

				}
			default:
				{
					int len=0;
					queueNode *r_1=r->front;
					while(NULL!=r_1)
					{
						len++;
						if(NULL!=r_1->next)
							r_1=r_1->next;
						else
							break;
					}
					return len;
					break;
				}
		}

}
