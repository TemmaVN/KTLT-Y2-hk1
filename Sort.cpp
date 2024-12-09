#include "Sort.h"

void Swap(int& x, int& y)
{
	int tg = x;
	x = y;
	y = tg;
}

void InMang(int a[], int l, int r)
{
	cout << "Mang la : ";
	for (int i = l;i <= r;i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}

void BubbleSort(int a[], int l, int r)
{
	if (l >= r) return;
	for (int i = l + 1;i <= r;i++)
	{
		if (a[i] < a[i - 1]) Swap(a[i], a[i - 1]);
	}
	BubbleSort(a, l, r - 1);
}

void SelectionSort(int a[], int l, int r)
{
	if (l >= r) return;
	for (int i = l;i < r;i++)
	{
		if (a[i] > a[r]) Swap(a[i], a[r]);
	}
	SelectionSort(a, l, r - 1);
}

void InsertionSort(int a[], int l, int r)
{
	for (int i = l + 2;i <= r;i++)
	{
		int tg = a[i];
		for (int j = i;j > l;j--)
		{
			if (tg < a[j]) Swap(tg, a[j]);
		}
		a[i] = tg;
	}
}

void QuickSort(int a[], int l, int r)
{
	if (l >= r) return;
	int i = l;
	int j = r;
	int mid = (i + j) / 2;

	while (j > i)
	{
		if (a[j] > a[mid])
		{
			j--;
		}
		if (a[i] < a[mid])
		{
			i++;
		}
		if (a[i] >= a[mid] && a[j] <= a[mid])
		{
			Swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	QuickSort(a, l, j);
	QuickSort(a, i, r);
}

int FindTT(int a[], int l, int r,int data)
{
	for (int i = l;i <= r;i++)
	{
		if (a[i] == data) return a[i];
	}
	return -1;
}

int BinarySearch(int a[], int l, int r, int data)
{
	if (l > r) return -1;
	int mid = (l + r) / 2;
	if (a[mid] == data) return a[mid];
	else if (a[mid] < data) return BinarySearch(a, mid + 1, r, data);
	else return BinarySearch(a, l, mid - 1, data);
}

