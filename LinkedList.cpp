#include "LinkedList.h"

Node* MakeNode(int d)
{
	Node* temp = new Node();
	temp->data = d;
	temp->next = NULL;
	return temp;
}

LinkedList::LinkedList()
{
	this->first = NULL;
	this->sl = 0;
}

void LinkedList::InsertFirst(int d)
{
	Node* temp = MakeNode(d);
	if (this->first == NULL) this->first = temp;
	else
	{
		temp->next = this->first;
		this->first = temp;
	}
	sl++;
}

void LinkedList::InsertLast(int d)
{
	Node* temp = MakeNode(d);
	if (this->first == NULL) this->first = temp;
	else
	{
		Node* run = this->first;
		while (run->next != NULL)
		{
			run = run->next;
		}
		run->next = temp;
	}
	sl++;
}

void LinkedList::InsertPos(int d, int Pos)
{
	Node* temp = MakeNode(d);
	if (Pos <= 0 || Pos > sl + 1) return;//nhap ngu vl
	if (Pos == 1)
	{
		InsertFirst(d);
		return;
	}
	else if (Pos == sl + 1)
	{
		InsertLast(d);
		return;
	}
	else
	{
		Node* run = this->first;
		while (Pos > 2)
		{
			run = run->next;
			Pos--;
		}
		temp->next = run->next;
		run->next = temp;

	}
	sl++;
}

void LinkedList::InList()
{
	cout << "Danh sach la : ";
	for (Node* temp = this->first; temp != NULL;temp = temp->next)
	{
		cout << temp->data << ' ';
	}
	cout << endl << "Danh sach gom : " << sl << " phan tu!" << endl;
}

void LinkedList::DeleteFirst()
{
	if (this->first == NULL) return;
	else
	{
		Node* temp = this->first;
		this->first = this->first->next;
		temp->next = NULL;
		temp = NULL;
		delete temp;
	}
	sl--;
}

void LinkedList::DeleteLast()
{
	if (this->first == NULL) return;
	else if (this->first->next == NULL) DeleteFirst();
	else
	{
		Node* temp = this->first;
		while (temp->next->next != NULL)
		{
			temp = temp->next;
		}
		Node* del = temp->next;
		temp->next = NULL;
		del = NULL;
		delete del;
	}
	sl--;
}

bool LinkedList::IsEmpty()
{
	return (this->first == NULL);
}

Node* LinkedList::FindNode(int d)
{
	Node* temp = MakeNode(d);
	for (Node* run = this->first;run != NULL;run = run->next)
	{
		if (temp->data = run->data) return run;
	}
	return NULL;
}

void LinkedList::DeletePos(int Pos)
{
	if (Pos <1 || Pos>sl) return;
	if (Pos == 1)
	{
		DeleteFirst();
		return;
	}
	if (Pos == sl)
	{
		DeleteLast();
		return;
	}
	Node* temp = this->first;
	while (Pos > 2)
	{
		temp = temp->next;
		Pos--;
	}
	Node* del = temp->next;
	temp->next = del->next;
	del->next = NULL;
	del = NULL;
	delete del;
	sl--;
}

LinkedList LinkedList::DaoLList()
{
	LinkedList L1;
	DStack DL;
	InitDStack(&DL);
	for (Node* temp = this->first;temp != NULL;temp = temp->next)
	{
		DPush(&DL, temp->data);
	}
	for (Node* temp = this->first;temp != NULL;temp = temp->next)
	{
		L1.InsertLast(DPeek(DL));
		DPop(&DL);
	}
	return L1;
}

