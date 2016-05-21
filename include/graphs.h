#ifndef __GRAPHS_H__
#define __GRAPHS_H__

#include <ctime>
#include <cstdlib>
#include <iostream>
#include "hqueue.h"
#include "d_heap.h"

using namespace std;


template <class HType>
class edge //ребро 
{
public:
	edge(int, int, HType);

	int o; //откуда
	int k;  // куда
	HType weight; //вес
};

template <class HType>
class Graph 
{
private:
	int n; //количество вершин
	int m; //количество ребер
	edge<HType>** edges; //ребра
	int m_cur; //текущее ребро
public:
	Graph(int, int);
	~Graph();

	void createGraph (HType, HType); //создать граф
	void addEdge(int, int, HType); //добавить ребро
	void delEdge(int, int); //удалить ребро
	int getKolvo(); //вернуть количество вершин
	int getEdgeSize(); //вернуть максимальное количество ребер
	int getRealSize();	//вернуть дейсвствующее количество ребер
	edge<HType>*  getEdge(int); //вернуть ребро
	HType getWeight(int, int);  //вернуть вес ребра
	void print(); 
	int findEdge(int, int); 
	void gen(int&, int&);

	bool visit (int, int*);
	void sort();
	HType* deykstra (int, HType*&);
};

template <class HType>
edge<HType>::edge(int a, int b, HType c)
{
	o = a;
	k = b;
	weight = c;
}

template <class HType>
Graph<HType>::Graph(int a, int b)
{
	if (a < 0)
		throw 
		exception ("Ќеверные номера вершин");
	else
		n = a;

	if ((b < 0) || (b > n*(n - 1) / 2))
		throw 
		exception ("Ќеверный номер рЄбра");
	else
		m = b;

	m_cur = 0;

	edges = new edge<HType>*[m];
}

template <class HType>
Graph<HType>::~Graph()
{
	for (int i = 0; i < m_cur; i++)
		delete edges[i];
	delete[] edges;
}

template <class HType>
void Graph<HType>::addEdge(int a, int b, HType c)
{
	if (m_cur == m)
		throw 
		exception ("√раф полон");
	if (a == b)
		throw 
		exception ("ѕетель не надо");
	if ((a > n) || (b > n))
		throw
		exception ("“аких вершин нет");

	edges[m_cur] = new edge<HType>(a, b, c);
	m_cur++;
}

template <class HType>
void Graph<HType>::gen (int &a, int &b)
{
	do
	{
		a = rand() % n;
		b = rand() % n;
	} 
	while ((a == b) || (findEdge(a, b) != -1));
}

template <class HType>
void Graph<HType>::createGraph (HType a, HType b)
{
	if (a > b)
		throw "Ќеверные рассто€ни€";

	int u, v;
	HType weight;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
	{
		gen(u, v);
		weight = a + static_cast <HType> (rand()) /( static_cast <HType> (RAND_MAX/(b-a)));
		edges[i] = new edge<HType>(u, v, weight);
		m_cur++;
	}
}

template <class HType>
int Graph<HType>::getKolvo()
{
	return n;
}

template <class HType>
int Graph<HType>::getEdgeSize()
{
	return m;
}

template <class HType>
int Graph<HType>::getRealSize()
{
	return m_cur;
}

template <class HType>
HType Graph<HType>::getWeight(int a, int b)
{
	if ((a < 0) || (a > n) || (b < 0) || (b > n))
		throw
		exception ("Ќеверные номера вершин");
	for (int i = 0; i < m_cur; i++)
		if ((edges[i]->o == a) && (edges[i]->k == b) || (edges[i]->o == b) && (edges[i]->k == a))
			return edges[i]->weight;
	return 0;
}

template <class HType>
void Graph<HType>::print()
{
	cout << "ќткуда -> куда (вес)" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m_cur; j++)
		{
			if (edges[j]->o == i)
				cout << edges[j]->o << "<->" << edges[j]->k << " (" << edges[j]->weight << ")" << endl;
		}
	}
}

template <class HType>
edge<HType>* Graph<HType>::getEdge(int a)
{
	return edges[a];
}

template <class HType>
void Graph<HType>::delEdge(int a, int b)
{
	int tmp = findEdge(a, b);
	if (tmp == -1)
		throw 
		exception ("“акого ребра нет");
	delete edges[tmp];
	edges[tmp] = edges[m_cur - 1];
	m_cur--;
}

template <class HType>
int Graph<HType>::findEdge(int a, int b)
{	
	for (int i = 0; i < m_cur; i++)
	{
		if ((edges[i]->o == a) && (edges[i]->k == a) || (edges[i]->o == b) && (edges[i]->k == b))
			return -1;
		if ((edges[i]->o == a) && (edges[i]->k == b) || (edges[i]->k == a) && (edges[i]->o == b))
			return i;
	}
	return -1;

}

template <class HType>
void Graph<HType>::sort()
{
	edge<HType> *tmp = new edge<HType>(0,0,0);
	for (int i=0; i<m;i++)
	{
		for (int j=m-1;j>i;j--)
		{
			if (edges[j]->weight < edges[j-1]->weight)
			{
				tmp = edges[j];
				edges[j] = edges[j-1];
				edges[j-1] = tmp;
			}
		}
	}
}

template <class HType>
bool Graph<HType>::visit (int a, int* b)
{
	bool res = false;
	for (int i=0;i<n;i++)
		if (b[i] == a)
			res = true;
	return res;
}

template <class HType>
HType* Graph<HType>::deykstra(int s, HType *&P)
{
	if ((s < 0) || (s >= n))
		throw 
		exception ("“акой нет");
	
	HType **graph = new HType*[n];
	for (int i=0;i<n;i++)
		graph[i] = new HType[n];
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			graph[i][j] = -1;

	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
		{
			if ((edges[j]->o == i) || (edges[j]->k == i))
			{
				graph[edges[j]->o][edges[j]->k] = edges[j]->weight;
				graph[edges[j]->k][edges[j]->o] = edges[j]->weight;
			}
		}

	HType *dist = new HType[n]; //рассто€ние
	int *vis = new int[n]; //массив посещенных вершин
	for (int i=0; i<n;i++)
		vis[i] = -1;
	vis[0] = s;
	int pyt;
	int w, min;
//////////////////////////////////////////////////////////////
	for (int i=0; i<n; i++) 
	{                       
		if (graph[s][i] == -1)
			dist[i]=MAX_HTYPE;
			else dist[i]=graph[s][i];
	}
	for (int i=1; i<n-1; i++) 
	{
		min=MAX_HTYPE;
		for (int k=0; k<n; k++) {
			if (dist[k] < min && k!=s && !visit(k, vis) ) 
			{
				w=k;
				min=dist[k];
			}
		}
		if (min == MAX_HTYPE) break;
		vis[i]=w;
		for (int j=0; j < n; j++) {
			if (!visit(j,vis) && graph[w][j] != -1 && (dist[w]+graph[w][j])<=dist[j]) 
			{
				P[j]=w;
				dist[j]=dist[w]+graph[w][j];
			}
		}
	}

	dist[s] = 0;
	return dist;
}

#endif