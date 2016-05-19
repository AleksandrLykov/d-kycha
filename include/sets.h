#ifndef __SETS_H__
#define __SETS_H__

#include "queue.h"
#include "graphs.h"
#include "d-heap.h"
#include <stack>

template <class HType>
class sets
{
private:
	int *parent;
	int *height;
	int n;
public:
	sets(int);
	~sets();

	void makesets (int);
	int findsets (int);
	void unionsets (int, int);
	void vyvod();

	int* getsets(int);
	Graph<HType>* kruskal(Graph<HType>*&);
};

template <class HType>
sets<HType>::sets(int a)
{
	parent = new int[a];
	for (int i = 0; i < a; i++)
		parent[i] = -1;
	height = new int[a];
	n = a;
}

template <class HType>
sets<HType>::~sets()
{
	delete[] parent;
	delete[] height;
}

template <class HType> 
void sets<HType>::makesets(int a)
{
	if ((a > n) || (a < 0))
		throw 
		exception ("������������ �������");
	
	if (parent[a] != -1)
		return;

	parent[a] = a;
	height[a] = 0;
}

template <class HType>
int sets<HType>::findsets (int a)
{
	if ((a > n) || (a < 0))
		throw 
		exception ("������������ �������");
	if (parent[a] == -1)
		return -1;

	while (parent[a] != a)
		a = parent[a];
	return a;	
}

template <class HType>
void sets<HType>::unionsets (int a, int b)
{
	if ((a > n) || (a < 0) || (b > n) || (b < 0))
		throw 
		exception ("������������ �������");
	if ((parent[a] == -1) || (parent[b] == -1))
		throw
		exception ("������ ���������");

	a = findsets (a);
	b = findsets (b);
	if (height[a] > height[b])
		parent[b] = a;
	else if (height[a] < height[b])
		parent[a] = b;
	else
	{
		parent[b] = a;
		height[a]++;
	}
}

template <class HType>
int* sets<HType>::getsets (int a)
{
	if ((a > n) || (a < 0))
		throw 
		exception ("������������ �������");
	if (parent[a] != a)
		throw 
		exception ("����� ������� �������");
	
	stack<int> st;
	int *res = new int;
	for (int i=0; i<n; i++)
	{
		if (parent[i] == a)
			st.push(i);
	}
	res[0] = st.size();
	int j=1;
	while (!st.empty())
	{
		res[j] = st.top();
		st.pop();
		j++;
	}
	return res;
}

template <class HType>
void sets<HType>::vyvod ()
{
	HType*tmp = new HType;
	for (int i=0; i<n;i++)
	{
		if (parent[i] == i)
		{
			tmp = getsets(i);

			if (tmp[0] > 1)
			{
				cout << '{';
				for (int k = 1; k<=tmp[0]; k++)
					cout << tmp[k] << ' ';
				cout << "} ";
			}
			else 
				cout << '{' << tmp[1] << "} ";
		}
	}
	cout << endl;
}

template <class HType>
class DataEdge : public Prior<HType>
{
public:
	DataEdge (edge<HType> *);
	edge<HType> *e;
};

template <class HType>
DataEdge<HType>::DataEdge (edge<HType> *a)
{
	e = a;
	pr = e->weight;
}


template <class HType>
Graph<HType>* sets<HType>::kruskal (Graph<HType>*& gr)
{
	
	int n = gr->getKolvo();
	int m = gr->getRealSize();
	Graph<HType> *tree = new Graph<HType>(n,m);

	sets<HType> *set = new sets<HType>(n);
	for (int i=0; i<n; i++)
		set->makesets(i);

	
	Prior<HType> **data = new Prior<HType>*[m];
	for (int i=0; i<m;i++)
		data[i] = new DataEdge<HType>(gr->getEdgesets()[i]);

	HQueue<HType> *queue = new HQueue<HType>(data, m, 4);
	int treeEdgeSize = 0;
	while ((treeEdgeSize < n-1) && (!queue->isEmpty()))
	{
		Prior<HType> *tmp = queue->top();
		queue->pop();
		int N = ((DataEdge<HType>*)tmp)->e->o;
		int K = ((DataEdge<HType>*)tmp)->e->k;
		HType weight = ((DataEdge<HType>*)tmp)->e->weight;
		int An = set->findsets(N);
		int Ak = set->findsets(K);
		if (An != Ak)
		{
			set->unionsets(An, Ak);
			tree->addEdge(N, K, weight);
			treeEdgeSize++;
		}
	}

	return tree;
}


#endif