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
	HType n;//универс
	HType *parent;//множества
public:
	sets(HType);
	~sets();

	void makesets (HType);
	HType findsets (HType);
	void unionsets (HType, HType);
	void vyvod();

	HType* getsets(HType);
	Graph<HType>* kruskal(Graph<HType>*&);
};

template <class HType>
sets<HType>::sets(HType a)
{
	n = a;
	parent = new HType[n];
	for (int i=0;i<n;i++)
		parent[i] = -1;
}

template <class HType>
sets<HType>::~sets()
{
	delete[] parent;
}

template <class HType> 
void sets<HType>::makesets(HType a)
{
	if ((a > n) || (a < 0))
		throw 
		exception ("Некорректный элемент");
	
	if (parent[(int)a] != -1)
		throw 
		exception ("элемент уже занят");

	parent[(int)a] = a;
}

template <class HType>
HType sets<HType>::findsets (HType a)
{
	if ((a > n) || (a < 0))
		throw 
		exception ("Некорректный элемент");
	if (parent[(int)a] == -1)
		return -1;

	while (parent[(int)a] != a)
		a = parent[(int)a];
	return a;	
}

template <class HType>
void sets<HType>::unionsets (HType a, HType b)
{
	if ((a > n) || (a < 0) || (b > n) || (b < 0))
		throw 
		exception ("Некорректный элемент");
	if ((parent[(int)a] == -1) || (parent[(int)b] == -1))
		throw
		exception ("Пустое множество");

	a = findsets (a);
	b = findsets (b);
	if (a != b)
		parent [(int)b] = a;
}

template <class HType>
HType* sets<HType>::getsets (HType a)
{
	if ((a > n) || (a < 0))
		throw 
		exception ("Некорректный элемент");
	if (parent[a] != a)
		throw 
		exception ("Нужен главный элемент");
	
	stack<HType> st;
	HType *res = new HType;
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
Graph<HType>* sets<HType>::kruskal (Graph<HType>*& gr)
{
	
	int n = gr->getKolvo();
	int m = gr->getRealSize();
	Graph<HType> *tree = new Graph<HType>(n,m);

	sets<HType> *s = new sets<HType>(n);
	for (int i=0; i<n; i++)
		s->makesets(i);

	gr->sort();
	int treeSize = 0;
	int i = 0;
	while ((treeSize < n-1) && (i < m))
	{
		edge<HType> *tmp = gr->getMinEdge(i);
		int o = tmp->o;
		int k = tmp->k;
		int weight = tmp->weight;
		int Ao = s->findsets(o);
		int Ak = s->findsets(k);
		if (Ao != Ak)
		{
			s->unionsets(Ao, Ak);
			tree->addEdge(o, k, weight);
			treeSize++;
		}
		i++;
	}

	return tree;
}


#endif