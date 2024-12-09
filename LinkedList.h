#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include"Library.h"
#include"Stack.h"

struct Node
{
	int data;
	Node* next;
};

Node* MakeNode(int d);

class LinkedList
{
private:
	Node* first;
	int sl;
public:
	LinkedList();
	void InsertFirst(int d);
	void InsertLast(int d);
	void InsertPos(int d, int pos);
	void DeleteFirst();
	void DeleteLast();
	void DeletePos(int Pos);
	void InList();
	bool IsEmpty();
	LinkedList DaoLList();
	Node* FindNode(int d);
};


#endif // !LINKEDLIST


