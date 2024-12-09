#include "DLList.h"

DLList::DLList()
{
	this->first = NULL;
	this->last = NULL;
	this->sl = 0;
}

DNode* MakeDN(int d)
{
	DNode* temp = new DNode();
	temp->data = d;
	temp->next = NULL;
	temp->pre = NULL;
	return temp;
}

void DLList::IF(int d)
{
	DNode* temp = MakeDN(d);
	if (this->first == NULL)
	{
		this->first = temp;
		this->last = temp;
	}
	else
	{
		temp->next = this->first;
		this->first->pre = temp;
		this->first = temp;
	}
	sl++;
}

void DLList::IL(int d)
{
	DNode* temp = MakeDN(d);
	if (this->first == NULL)
	{
		this->first = temp;
		this->last = temp;
	}
	else
	{
		this->last->next = temp;
		temp->pre = this->last;
		this->last = temp;
	}
	sl++;
}

void DLList::IP(int d, int Pos)
{
	if (Pos<0 || Pos>sl + 1) return;
	if (Pos == 1) IF(d);
	else if (Pos == sl + 1) IL(d);
	else
	{
		DNode* temp = MakeDN(d);
		DNode* run = this->first;
		while (Pos > 2)
		{
			run = run->next;
			Pos--;
		}
		temp->pre = run;
		temp->next = run->next;
		run->next->pre = temp;
		run->next = temp;
		sl++;
	}
}

void DLList::DF()
{
	if (this->first == NULL) return;
	else if (this->first == this->last)
	{
		DNode* temp = this->first;
		this->first = NULL;
		this->last = NULL;
		temp = NULL;
		delete temp;
		sl--;
	}
	else
	{
		DNode* temp = this->first;
		this->first = this->first->next;
		this->first->pre = NULL;
		temp->next = NULL;
		temp = NULL;
		delete temp;
		sl--;
	}
}

void DLList::DL()
{
	if (this->first == NULL) return;
	else if (this->first == this->last)
	{
		DF();
		return;
	}
	else
	{
		DNode* del = this->last;
		this->last = this->last->pre;
		this->last->next = NULL;
		del->pre = NULL;
		del = NULL;
		delete del;
		sl--;
	}
}

void DLList::DP(int Pos)
{
	if (this->first == NULL) return;
	if (Pos <= 0 || Pos > sl) return;
	if (Pos == 1)
	{
		DF();
		return;
	}
	if (Pos == sl)
	{
		DL();
		return;
	}
	DNode* temp = this->first;
	while (Pos > 2)
	{
		temp = temp->next;
		Pos--;
	}
	DNode* del = temp->next;
	temp->next = del->next;
	del->next->pre = temp;
	del->next = NULL;
	del->pre = NULL;
	del = NULL;
	delete del;
	sl--;
}

bool DLList::IsE()
{
	return (this->first == NULL);
}

void DLList::InDList()
{
	cout << "Danh sach la : ";
	for (DNode* temp = this->first; temp != NULL;temp = temp->next)
	{
		cout << temp->data << ' ';
	}
	cout << endl << "Danh sach co " << this->sl << " phan tu !!" << endl;
}

