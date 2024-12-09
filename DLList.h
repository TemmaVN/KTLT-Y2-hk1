#ifndef DLLIST_H
#define DLLIST_H
#include"Library.h"

struct DNode
{
	int data;
	DNode* next;
	DNode* pre;
};

DNode* MakeDN(int d);

class DLList
{
private:
	DNode* first;
	DNode* last;
	int sl;
public:
	DLList();
	void IF(int d);
	void IL(int d);
	void IP(int d, int Pos);
	void DF();
	void DL();
	void DP(int Pos);
	bool IsE();
	void InDList();
};

#endif // !DLLIST_H



