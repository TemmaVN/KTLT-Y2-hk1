#include "Queue.h"

QNode* MakeQN(char d)
{
	QNode* temp = (QNode*)malloc(sizeof(QNode));
	temp->data = d;
	temp->next = NULL;
	return temp;
}

void InitQueue(Queue* Q)
{
	Q->front = NULL;
	Q->rear = NULL;
}

void Put(Queue* Q, char d)
{
	QNode* temp = MakeQN(d);
	if (Q->rear == NULL)
	{
		Q->front = temp;
		Q->rear = temp;
	}
	else
	{
		temp->next = Q->rear;
		Q->rear = temp;
	}
}

void Pop(Queue* Q)
{
	QNode* temp = Q->rear;
	if (Q->rear == NULL) return;
	else if (Q->front == Q->rear)
	{
		Q->front = NULL;
		Q->rear = NULL;
		temp = NULL;
		delete temp;
	}
	else
	{
		while (temp->next != Q->front)
		{
			temp = temp->next;
		}
		Q->front = temp;
		temp->next = NULL;
		delete temp->next;
	}
}

char Peek(Queue Q)
{
	return Q.front->data;
}

bool IsQEmpty(Queue Q)
{
	return (Q.rear == NULL);
}

QDNode* MakeQDN(int d)
{
	QDNode* temp = (QDNode*)malloc(sizeof(QDNode));
	temp->data = d;
	temp->next = NULL;
	temp->pre = NULL;
	return temp;
}


void InitDQueue(DQueue* Q)
{
	Q->front = NULL;
	Q->rear = NULL;
}

void DPut(DQueue* Q, int d)
{
	QDNode* temp = MakeQDN(d);
	if (Q->front == NULL)
	{
		Q->front = temp;
		Q->rear = temp;
	}
	else
	{
		temp->next = Q->rear;
		Q->rear->pre = temp;
		Q->rear = temp;
	}
}

void DPop(DQueue* Q)
{
	if (Q->rear == NULL) return;
	else if (Q->front == Q->rear)
	{
		Q->front = NULL;
		Q->rear = NULL;
		delete Q->front;
	}
	else
	{
		QDNode* temp = Q->front;
		Q->front = Q->front->pre;
		Q->front->next = NULL;
		temp = NULL;
		delete temp;
	}
}

int DPeek(DQueue Q)
{
	return (Q.front->data);
}

bool IsDQEmpty(DQueue Q)
{
	return (Q.rear == NULL);
}

void InDQueue(DQueue Q)
{
	cout << "Hang doi kep la : ";
	for (QDNode* temp = Q.rear; temp != NULL; temp = temp->next)
	{
		cout << temp->data << ' ';
	}
	cout << endl;
}

void InQueue(Queue Q)
{
	cout << "Hang doi la :";
	for (QNode* temp = Q.rear;temp != NULL; temp = temp->next)
	{
		cout << temp->data << ' ';
	}
	cout << endl;
}