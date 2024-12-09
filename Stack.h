#ifndef STACK_H
#define STACK_H
#include"Library.h"
#include"LinkedList.h"

struct SNode
{
	char data;
	SNode* down;
};

SNode* MakeSN(char d);

struct SDNode
{
	int data;
	SDNode* down;
	SDNode* above;
};

SDNode* MakeSDN(int d);

struct Stack
{
	SNode* top;
};

struct DStack
{
	SDNode* top;
};

void InitStack(Stack* st);

void InitDStack(DStack* st);

void Push(Stack* st, char d);

void DPush(DStack* st, int d);

void Pop(Stack* st);

void DPop(DStack* st);

char Peek(Stack st);

int DPeek(DStack st);

bool IsEmptyS(Stack st);

bool DIsEmptyS(DStack st);

void MakeES(Stack* st);

void DMakeES(DStack* st);

void InStack(Stack st1);

void InDStack(DStack st1);

Stack InBSNode(int data);

string DaoString(string a);

bool IsBTright(string bt);

int PostFix(string s);

#endif // !STACK_H



