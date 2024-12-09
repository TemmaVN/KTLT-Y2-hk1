#include "Array.h"

void InitArray(int* a, int sl)
{
	if (sl <= 0 || sl > 1000) sl = 10;
	a = new int[sl + 1];
	a[0] = 0;
}

bool IsFull(int* a)
{
	int sl = sizeof(a) / sizeof(int) - 1;
	return (a[0] == sl);
}

bool IsEmpty(int* a)
{
	return (a[0] == 0);
}

void InsertArray(int** a, int data)
{
	if (IsFull(*a)) return;
	else
	{
		*a[0]++;
		*a[*a[0]] = data;
	}
}

void DeleteLast(int** a)
{
	if (IsEmpty(*a)) return;
	else
	{
		*a[*a[0]] = -1;
		*a[0]--;
	}
}

void InMang(int* a)
{
	cout << "Mang la : ";
	for (int i = 1;i <= a[0];i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}
