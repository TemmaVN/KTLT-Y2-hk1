#ifndef TREE_H
#define TREE_H
#include"Library.h"

struct TNode
{
	int data;
	TNode* left;
	TNode* right;
};

//tao node cho cay
TNode* MakeTN(int d);

//them gia tri vao cay
void InsertTree(TNode* &T, int d);

//Duyet Pre-order
void PRDTree(TNode *T);

//Duyet In-order
void IDTree(TNode* T);

//Duyet Post-order
void PDTree(TNode* T);

//Duyet Level-Order
void LDTree(TNode* T);

//chieu cao cua cay
int Height(TNode* T);

//so nut cua cay
int CountNode(TNode* T);

//tong gia tri cac nut cua cay
int SumTree(TNode* T);

//TIm va gui ve Node can tim
TNode* FindTN(TNode* T,int d);

//Tim Node co gia tri lon nhat tren cay
TNode* FindMTN(TNode* T);

//Xoa Node co gia tri d
TNode* DeleteTN(TNode*& T,int d);

//Tao cay tu mang mot chieu
TNode* MakeTree(int a[], int n);

//Xoa hoan toan cay nhi phan
void RemoveTree(TNode*& T);

//Tim chieu cao cua Node voi gia tri cho truoc
int HeightNode(TNode* T, int value);

//tim level cua Node cho truoc
int Level(TNode* CurNode, TNode* p, int curlevel);
int Level(TNode* CurNode, TNode* p);

//tim so la cua cay
int NumLeaf(TNode* T);

//So luong Node co gia tri nho hon d
int NumNodeL(TNode* T, int d);

//So luong Node co gia tri ko lon hon d
int NumNodeS(TNode* T, int d);

//Kiem tra mot cay nhi phan co phai cay nhi phan tim kiem ko
bool isBTS(TNode* T, int& value);

//Kiem tra cay nhi phan co hoan chinh khong
bool IsFullTree(TNode* T);

#endif // !TREE_H

