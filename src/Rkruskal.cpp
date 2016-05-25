#include "Rkruskal.h"

template <class TType>
Graph<TType>* Algoritm<TType>::kruskal (Graph<TType>*& gr, PQueue<TType>*& queue)
{
	int n = gr->getKolvo();
	int m = gr->getRealSize();
	Graph<TType> *tree = new Graph<TType>(n,m);
	sets<TType> *set = new sets<TType>(n);
	for (int i=0; i<n; i++)
		set->makesets(i);
	
	for (int i=0; i<m;i++)
		queue->push(gr->getEdge(i)->weight);

	int treeEdgeSize = 0; 
	int x = 0;
	TType tmp;

	while (treeEdgeSize < n-1)
	{
		tmp = queue->top();
		queue->pop();

		int u = gr->getEdge(x)->o;
		int v = gr->getEdge(x)->k;
		TType weight = tmp;

		int An = set->findsets(u);
		int Ak = set->findsets(v);
		if (An != Ak)
		{
			set->unionsets(An, Ak);
			tree->addEdge(u, v, weight);
			treeEdgeSize++;
		}
		x++;
	}

	return tree;
};