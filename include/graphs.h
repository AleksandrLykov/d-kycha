#ifndef __GRAPHS_H__
#define __GRAPHS_H__

#include <ctime>
#include <cstdlib>
#include <iostream>
#include "queue.h"
#include "d-heap.h"

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
class Graph 
{
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
	edge<HType>*  getMinEdge(int);
	HType getWeight(int, int); 
	void print();
	int findEdge(int, int);
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
HType Graph<HType>::getWeight(int a, int b)
{
	for (int i = 0; i < m_cur; i++)
		if ((edges[i]->o == a) && (edges[i]->k == b) || (edges[i]->o == b) && (edges[i]->k == a))
			return edges[i]->weight;
	return 0;
}

template <class HType>
void Graph<HType>::print()
{
	HType **graph = new HType*[n];
	for (int i=0;i<n;i++)
		graph[i] = new HType[n];
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			graph[i][j] = 0;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
		{
			if ((edges[j]->o == i) || (edges[j]->k == i))
			{
				graph[edges[j]->o][edges[j]->k] = edges[j]->weight;
				graph[edges[j]->k][edges[j]->o] = edges[j]->weight;
			}
		}

	
	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << graph[i][j] << " ";
		cout << endl;
	}
}

template <class HType>
edge<HType>* Graph<HType>::getMinEdge(int a)
{
	return edges[a];
}

template <class HType>
void Graph<HType>::delEdge(int a, int b)
{
	int tmp = findEdge(a, b);
	if (tmp == -1)
		throw 
		exception ("Такого ребра нет");
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
HType* Graph<HType>::deykstra(int s)
{
	if ((s < 0) || (s >= n))
		throw 
		exception ("Такой нет");
	
	HType **graph = new HType*[n];
	for (int i=0;i<n;i++)
		graph[i] = new HType[n];
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			graph[i][j] = 0;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
		{
			if ((edges[j]->o == i) || (edges[j]->k == i))
			{
				graph[edges[j]->o][edges[j]->k] = edges[j]->weight;
				graph[edges[j]->k][edges[j]->o] = edges[j]->weight;
			}
		}
	
	HType *dist = new HType[n];
	bool *visited = new bool[n];
	for(int i=0;i<n;i++) 
	{
		dist[i] = MAX_HTYPE;
		visited[i] = false;
	}
	dist[s] = 0;
	int idx, u;

	for (int i=0; i<n-1;i++)
	{
		int min = MAX_HTYPE;
		for (i=0; i<n;i++)
			if (!visited[i] && dist[i] <= min)
			{
				min = dist[i];
				idx = i;
			}
		u = idx;
		visited[u] = true;
		for (i=0; i<n; i++)
			if ((!visited[i]) && (graph[u][i]) && (dist[u] != MAX_HTYPE) && (dist[u] + graph[u][i] < dist [i]))
				dist[i] = dist[u] + graph[u][i];
	}
		
	return dist;
}

#endif