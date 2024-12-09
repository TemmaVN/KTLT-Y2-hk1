#ifndef TTLLIST_H
#define TTLLIST_H
#include"Library.h"

struct TTNode
{
	int data;
	TTNode* next;
};

//tao node trong dsach co thu tu
TTNode* MakeTTN(int d);

struct TTList
{
	TTNode* first;
};

//khoi tao danh sach co thu tu
void InitTTL(TTList* tt);

//them mot phan tu vao danh sach co thu tu
void InsertLTT(TTList* tt,int d);

//In danh sach co thu tu
void InTTL(TTList tt);

//Loai bo cac phan tu trung nhau trong danh sach co thu tu
void DeleteTT(TTList* tt);


#endif // !TTLLIST_H


