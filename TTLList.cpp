#include "TTLList.h"

TTNode* MakeTTN(int d)
{
	TTNode* temp = new TTNode;
	temp->data = d;
	temp->next = NULL;
	return temp;
}

void InitTTL(TTList* tt)
{
	tt->first = NULL;
}

void InsertLTT(TTList* tt, int d)
{
	if (d < 0) return;
	TTNode* temp = MakeTTN(d);
	if (tt->first == NULL) tt->first = temp;
	else if (tt->first->data > d)
	{
		temp->next = tt->first;
		tt->first = temp;
	}
	else
	{
		TTNode* run = tt->first;
		while (run->next != NULL && run->next->data < d)
		{
			run = run->next;
		}
		temp->next = run->next;
		run->next = temp;
	}
}

void InTTL(TTList tt)
{
	cout << "Danh sach la : ";
	for (TTNode* temp = tt.first;temp != NULL; temp = temp->next)
	{
		cout << temp->data << ' ';
	}
	cout << endl;                                                               
}

void DeleteTT(TTList* tt)
{
	TTNode* temp = tt->first;
	while (temp->next != NULL)
	{
		if (temp->next->data == temp->data)
		{
			TTNode* del = temp->next;
			temp->next = del->next;
			del = NULL;
			delete del;
		}
		else temp = temp->next;
	}
}