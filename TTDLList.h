#ifndef TTDLLIST_H
#define TTDLLIST_H
#include"Library.h"

struct DTN
{
	int data;
	DTN* next;
	DTN* pre;
};

DTN* MakeDTN(int d);

struct DTNList
{
	DTN* first;
	DTN* last;
};

//Khoi tao danh sach co thu tu 
void InitDTNL(DTNList* d1);

//them 1 phan tu vao danh sach co thu tu
void InsertDTN(DTNList* d1, int d);

//In danh sach kep co thu tu
void InDTN(DTNList d1);

//Loai bo cac gia tri trung nhau
void DeleteDTN(DTNList* d1);


#endif // !TTDLLIST_H

