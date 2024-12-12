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
	if (r - l >= 1)
	{
		if (a[l] > a[l + 1]) Swap(a[l], a[l + 1]);
	}
	for (int i = l + 2;i <= r;i++)
	{
		for (int j = i-1;j >= l;j--)
		{
			if (a[j+1] < a[j]) Swap(a[j+1], a[j]);
		}
	}
}

void ISort(int arr[], int n) {
	int i, j, temp;
	if (n > 1)
	{
		if (arr[0] > arr[1]) Swap(arr[0], arr[1]);
	}
	for (i = 1; i < n-1; i++) {
		j = i + 1;
		temp = arr[i + 1];
		while ((j > 0) && (arr[j - 1] > temp)) {
			arr[j] = arr[j - 1];
			j = j - 1;
		}
		arr[j] = temp;
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

