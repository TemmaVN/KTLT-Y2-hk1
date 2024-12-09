#include "Stack.h"

SNode* MakeSN(char d)
{
	SNode* temp = new SNode;
	temp->data = d;
	temp->down = NULL;
	return temp;
}

SDNode* MakeSDN(int d)
{
	SDNode* temp = new SDNode;
	temp->data = d;
	temp->above = NULL;
	temp->down = NULL;
	return temp;
}

void InitStack(Stack* st)
{
	st->top = NULL;
}

void InitDStack(DStack* st)
{
	st->top = NULL;
}

void Push(Stack* st, char d)
{
	SNode* temp = MakeSN(d);
	if (st->top == NULL) st->top = temp;
	else
	{
		temp->down = st->top;
		st->top = temp;
	}
}

void DPush(DStack* st, int d)
{
	SDNode* temp = MakeSDN(d);
	if (st->top == NULL) st->top = temp;
	else
	{
		temp->down = st->top;
		st->top->above = temp;
		st->top = temp;
	}
}

void Pop(Stack* st)
{
	if (st->top == NULL) return;
	else
	{
		SNode* temp = st->top;
		st->top = st->top->down;
		temp = NULL;
		delete temp;
	}
}

void DPop(DStack* st)
{
	if (st->top == NULL) return;
	else
	{
		SDNode* temp = st->top;
		st->top = st->top->down;
		if (st->top!=NULL )st->top->above = NULL;
		temp = NULL;
		delete temp;
	}

}

char Peek(Stack st)
{
	return st.top->data;
}

int DPeek(DStack st)
{
	return st.top->data;                                                                                      
}

bool IsEmptyS(Stack st)
{
	return (st.top == NULL);
}

bool DIsEmptyS(DStack st)
{
	return (st.top == NULL);
}

void MakeES(Stack* st)
{
	while (st->top != NULL)
	{
		Pop(st);
	}
}

void DMakeES(DStack* st)
{
	while (st->top != NULL)
	{
		DPop(st);
	}
}

void InStack(Stack st1)
{
	cout << "Stack hien tai la : ";
	for (SNode* temp = st1.top; temp != NULL;temp = temp->down)
	{
		cout << temp->data << ' ';
	}
	cout << endl;
}

void InDStack(DStack st1)
{
	cout << "DStack hien tai la : ";
	for (SDNode* temp = st1.top;temp != NULL; temp = temp->down)
	{
		cout << temp->data << ' ';
	}
	cout << endl;
}

Stack InBSNode(int data)
{
	Stack st;
	InitStack(&st);
	while (data > 0)
	{
		if (data % 2 == 0) Push(&st, '0');
		else Push(&st, '1');
		data /= 2;
	}
	return st;
}

string DaoString(string a)
{
	Stack st;
	InitStack(&st);
	for (int i = 0;i < a.size();i++)
	{
		Push(&st, a[i]);
	}
	string b;
	for (int i = 0;i < a.size();i++)
	{
		b.push_back(Peek(st));
		Pop(&st);
	}
	return b;
}

bool IsBTright(string bt)
{
	Stack st;
	InitStack(&st);
	for (int i = 0;i < bt.size();i++)
	{
		if (IsEmptyS(st) && bt[i] == ')') return false;
		else if (bt[i] == '(') Push(&st, '(');
		else if (bt[i] == ')') Pop(&st);
	}
	if (IsEmptyS(st)) return true;
	else return false;
}

int PostFix(string s)
{
	DStack ds1;
	InitDStack(&ds1);
	for (int i = 0;i < s.size();i++)
	{
		if (s[i] == '0') DPush(&ds1, 0);
		if (s[i] == '1') DPush(&ds1, 1);
		if (s[i] == '2') DPush(&ds1, 2);
		if (s[i] == '3') DPush(&ds1, 3);
		if (s[i] == '4') DPush(&ds1, 4);
		if (s[i] == '5') DPush(&ds1, 5);
		if (s[i] == '6') DPush(&ds1, 6);
		if (s[i] == '7') DPush(&ds1, 7);
		if (s[i] == '8') DPush(&ds1, 8);
		if (s[i] == '9') DPush(&ds1, 9);
		if (s[i] == '-')
		{
			int a = DPeek(ds1);
			DPop(&ds1);
			int b = DPeek(ds1);
			DPop(&ds1);
			DPush(&ds1, b - a);
		}
		if (s[i] == '+')
		{
			int a = DPeek(ds1);
			DPop(&ds1);
			int b = DPeek(ds1);
			DPop(&ds1);
			DPush(&ds1, b + a);
		}
		if (s[i] == '*')
		{
			int a = DPeek(ds1);
			DPop(&ds1);
			int b = DPeek(ds1);
			DPop(&ds1);
			DPush(&ds1, b * a);
		}
		if (s[i] == '/')
		{
			int a = DPeek(ds1);
			DPop(&ds1);
			int b = DPeek(ds1);
			DPop(&ds1);
			DPush(&ds1, b / a);
		}
	}
	return DPeek(ds1);
}
