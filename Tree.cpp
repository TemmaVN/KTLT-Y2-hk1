#include "Tree.h"

TNode* MakeTN(int d)
{
	TNode* temp = new TNode;
	temp->data = d;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void InsertTree(TNode*& T, int d)
{
	if (T == NULL) T = MakeTN(d);
	else if (T->data < d) InsertTree(T->right, d);
	else if (T->data > d) InsertTree(T->left, d);
}

void PRDTree(TNode* T)
{
	if (T == NULL) return;
	else
	{
		cout << T->data << ' ';
		PRDTree(T->left);
		PRDTree(T->right);
	}
}

void IDTree(TNode* T)
{
	if (T == NULL) return;
	else
	{
		IDTree(T->left);
		cout << T->data << ' ';
		IDTree(T->right);
	}
}

void PDTree(TNode* T)
{
	if (T == NULL) return;
	else
	{
		PDTree(T->left);
		PDTree(T->right);
		cout << T->data << ' ';
	}
}

void LDTree(TNode* T)
{
	if (T == NULL) return;
	queue<TNode*>Q;
	Q.push(T);
	while (!Q.empty())
	{
		TNode* tmp = Q.front();
		Q.pop();
		cout << tmp->data << ' ';
		if (tmp->left != NULL)
		{
			Q.push(tmp->left);
		}
		if (tmp->right != NULL)
		{
			Q.push(tmp->right);
		}
	}
}

int Height(TNode* T)
{
	if (T == NULL) return -1;
	else return max(Height(T->left), Height(T->right)) + 1;
}

int CountNode(TNode* T)
{
	if (T == NULL) return 0;
	return CountNode(T->left) + CountNode(T->right) + 1;
}

int SumTree(TNode* T)
{
	if (T == NULL) return 0;
	return SumTree(T->left) + SumTree(T->right) + T->data;
}

TNode* FindTN(TNode* T,int d)
{
	if (T == NULL) return NULL;
	if (T->data == d) return T;
	else if (T->data < d) return FindTN(T->right, d);
	else return FindTN(T->left, d);
}

TNode* FindMTN(TNode* T)
{
	if (T == NULL) return NULL;
	if (T->right == NULL) return T;
	else return FindMTN(T->right);
}

TNode* DeleteTN(TNode*& T, int d)
{
	if (T == NULL) return NULL;
	if (T->data > d)
	{
		T->left = DeleteTN(T->left, d);
	}
	else if (T->data < d)
	{
		T->right = DeleteTN(T->right, d);
	}
	else
	{
		if (T->left == NULL && T->right == NULL) return NULL;
		else if (T->left == NULL)
		{
			TNode* tmp = T->right;
			T = NULL;
			delete T;
			return tmp;
		}
		else if (T->right == NULL)
		{
			TNode* tmp = T->left;
			T = NULL;
			delete T;
			return tmp;
		}
		else
		{
			TNode* rightmost = FindMTN(T->left);
			T->data = rightmost->data;
			T->left = DeleteTN(T->left, rightmost->data);
		}	
	}
	return T;
}

TNode* MakeTree(int a[], int n)
{
	TNode* Tree = NULL;
	for (int i = 0;i < n;i++)
	{
		InsertTree(Tree, a[i]);
	}
	return Tree;
}

void RemoveTree(TNode*& T)
{
	if (T == NULL) return;
	else
	{
		RemoveTree(T->left);
		RemoveTree(T->right);
		T = NULL;
		delete T;
	}
}

int HeightNode(TNode* T, int value)
{
	TNode* FoundTNode = FindTN(T, value);
	return Height(FoundTNode);
}

int Level(TNode* CurNode, TNode* p, int curlevel) {
	if (CurNode == NULL) return -1;
	if (CurNode == p) return curlevel;
	return max(Level(CurNode->right, p, curlevel + 1), Level(CurNode->left, p, curlevel + 1));
}

int Level(TNode* CurNode, TNode* p)
{
	if (CurNode == NULL || p == NULL) return -1;
	return Level(CurNode, p, 0);
}

int NumLeaf(TNode* T)
{
	if (T == NULL) return 0;
	if (T->left == NULL && T->right == NULL) return 1;
	return NumLeaf(T->left) + NumLeaf(T->right);
}

int NumNodeL(TNode* T, int d)
{
	if (T == NULL) return 0;
	if (T->data < d) return NumNodeL(T->left, d) + NumNodeL(T->right, d) + 1;
	return NumNodeL(T->left, d) + NumNodeL(T->right, d);
}

int NumNodeS(TNode* T, int d)
{
	if (T == NULL) return 0;
	if (T->data <= d) return NumNodeS(T->left, d) + NumNodeS(T->right, d) + 1;
	return NumNodeS(T->left, d) + NumNodeS(T->right, d);
}

bool isBTS(TNode* T, int& value)
{
	if (T == NULL) return true;
	if (isBTS(T->left, value) == false) return false;
	if (T->data <= value) return false;
	value = T->data;
	return isBTS(T->right, value);
}

bool IsFullTree(TNode* T)
{
	if (T->left == NULL && T->right == NULL) return true;
	if (T->left == NULL || T->right == NULL) return false;
	return IsFullTree(T->left) && IsFullTree(T->right);
}