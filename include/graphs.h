#ifndef __GRAPHS_H__
#define __GRAPHS_H__

#include <ctime>
#include <cstdlib>
#include <iostream>
#include "queue.h"

#define maxVerticesSize 1000	

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
class Graph {
private:
	int n; //количество вершин
	int m; //количество ребер
	edge<HType>** edges; //ребра
	int* vertices; //вершины
	int m_cur; //текущее ребро

public:
	Graph(int, int);
	~Graph();

	void createGraph (HType, HType);
	void addEdge(int, int, HType);
	void delEdge(int, int);
	int getKolvo();
	int getEdgeSize();
	int getRealSize();	
	edge<HType>*  getEdge(int);
	HType getWeight(int, int); 
	void print();
	int findEdge(int, int);
	edge<HType>** getEdgeSet();
	void gen(int&, int&);

	HType* deykstra (int);
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
		exception ("Неверные номера вершин");
	else
		n = a;

	if ((b < 0) || (b > n*(n - 1) / 2))
		throw 
		exception ("Неверный номер рёбра");
	else
		m = b;

	m_cur = 0;

	vertices = new int[n];
	for (int i=0;i<n;i++)
		vertices[i] = i;
	edges = new edge<HType>*[m];
}

template <class HType>
Graph<HType>::~Graph()
{
	for (int i = 0; i < m_cur; i++)
		delete edges[i];
	delete[] edges;
	delete[]vertices;
}

template <class HType>
void Graph<HType>::addEdge(int a, int b, HType c)
{
	if (m_cur == m)
		throw "Граф полон";
	if (a == b)
		throw "Петель не надо";
	edges[m_cur] = new edge(a, b, c);
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
		throw "Неверные расстояния";

	int u, v;
	HType weight;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
	{
		gen(u, v);
		weight = rand() % (int)(a - b - 1) + a;
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
edge<HType>** Graph<HType>::getEdgeSet()
{
	return edges;
}

template <class HType>
HType Graph<HType>::getWeight(int a, int b)
{
	for (int i = 0; i < m_cur; i++)
		if ((edges[i]->o == a) && (edges[i]->k == b))
			return edges[i]->weight;
	throw
		exception ("Неверные данные");
}

template <class HType>
void Graph<HType>::print()
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m_cur; j++)
		{
			if (edges[j]->o == i)
				cout << "из " << i << " в " << edges[j]->k << ": расстояние = " << edges[j]->weight << endl;
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
		exception ("Такого графа нет");
	delete edges[tmp];
	edges[tmp] = edges[m_cur - 1];
	m_cur--;
}

template <class HType>
int Graph<HType>::findEdge(int a, int b)
{	
	for (int j = 0; j < m_cur; j++)
		if ((edges[j]->o= a) && (edges[j]->k == b) || (edges[j]->k == a) && (edges[j]->o == b))
			return j;
	return -1;

}


template <class HType>
HType* Graph<HType>::deykstra(int s)
{
	if ((s < 0) || (s >= n))
		return 0;
	return 0;
};

#endif