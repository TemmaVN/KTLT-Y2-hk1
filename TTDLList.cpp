#include "TTDLList.h"

DTN* MakeDTN(int d)
{
	DTN* temp = new DTN;
	temp->data = d;
	temp->next = NULL;
	temp->pre = NULL;
	return temp;
}

void InitDTNL(DTNList* d1)
{
	d1->first = NULL;
	d1->last = NULL;
}

void InsertDTN(DTNList* d1, int d)
{
	DTN* temp = MakeDTN(d);
	if (d1->first == NULL)
	{
		d1->first = temp;
		d1->last = temp;
	}
	else if (d < d1->first->data)
	{
		temp->next = d1->first;
		d1->first->pre = temp;
		d1->first = temp;
	}
	else
	{
		DTN* run = d1->first;
		while (run->next != NULL&&run->next->data<d)
		{
			run = run->next;
		}
		if (run == d1->last)
		{
			run->next = temp;
			temp->pre = run;
			d1->last = temp;
			return;
		}
		temp->pre = run;
		temp->next = run->next;
		if (run->next!=NULL) run->next->pre = temp;
		run->next = temp;
	}
}

void InDTN(DTNList d1)
{
	cout << "Danh sach ( kep ) co thu tu la: ";
	for (DTN* run = d1.first; run != NULL; run = run->next)
	{
		cout << run->data << ' ';
	}
	cout << endl;
}

void DeleteDTN(DTNList* d1)
{
	if (d1->first == d1->last) return;
	else
	{
		DTN* run = d1->first;
		while (run->next != NULL)
		{
			if (run->data == run->next->data)
			{
				if (run->next == d1->last)
				{
					DTN* temp = d1->last;
					d1->last = d1->last->pre;
					run->next = NULL;
					temp = NULL;
					delete temp;
					return;
				}
				DTN* del = run->next;
				run->next = del->next;
				if (del->next != NULL) del->next->pre = run;
				del = NULL;
 				delete del;
			}
			else run = run->next;
		}
	}
}
