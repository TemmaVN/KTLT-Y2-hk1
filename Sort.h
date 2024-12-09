#ifndef SORT_H
#define SORT_H
#include"Library.h"

//swao 2 gia tri trong mang
void Swap(int& x, int& y);

//in mang
void InMang(int a[], int l, int r);

//Sap xep noi bot
void BubbleSort(int a[], int l, int r);

//Sap xep chon
void SelectionSort(int a[], int l, int r);

//Sap xep chen
void InsertionSort(int a[], int l, int r);

//Sap xep nhanh
void QuickSort(int a[], int l, int r);

//tim kiem tuan tu
int FindTT(int a[], int l, int r,int data);

//tim kiem nhi phan
int BinarySearch(int a[], int l, int r, int data);



#endif // !SORT_H


