#include "Main.h"

int main()
{
	/*DTNList d1;
	InitDTNL(&d1);
	InsertDTN(&d1, 12);
	InsertDTN(&d1, 13);
	InsertDTN(&d1, 11);
	InsertDTN(&d1, 11);
	InsertDTN(&d1, 12);
	InsertDTN(&d1, 17);
	InsertDTN(&d1, 10);
	DeleteDTN(&d1);
	InDTN(d1);*/

	/*Stack st1;
	InitStack(&st1);*/
	/*st1 = InBSNode(37498);
	InStack(st1);*/

	/*string a;
	getline(cin, a);
	for (int i = 0;i < a.size();i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	string b = DaoString(a);
	cout << b;*/

	LinkedList L;
	L.InsertFirst(3);
	L.InsertFirst(4);
	L.InsertPos(5, 2);
	L.InList();
	
}