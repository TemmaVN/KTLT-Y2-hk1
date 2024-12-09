#ifndef QUEUE_H
#define QUEUE_H
#include"Library.h"

//hang doi bang dslk kep

struct QDNode
{
	int data;
	QDNode* next;
	QDNode* pre;
};

QDNode* MakeQDN(int d);

struct DQueue
{
	QDNode* front;
	QDNode* rear;
};

void InitDQueue(DQueue* Q);

void DPut(DQueue* Q, int d);

void DPop(DQueue* Q);

int DPeek(DQueue Q);

bool IsDQEmpty(DQueue Q);

void InDQueue(DQueue Q);

//Hang doi bang danh sach lien ket don

struct QNode
{
	char data;
	QNode* next;
};

QNode* MakeQN(char d);

struct Queue
{
	QNode* rear;
	QNode* front;
};

void InitQueue(Queue* Q);

void Put(Queue* Q, char d);

void Pop(Queue* Q);

char Peek(Queue Q);

bool IsQEmpty(Queue Q);

void InQueue(Queue Q);

void InQueue(Queue Q);

#endif // !QUEUE_H



