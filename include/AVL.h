#ifndef __AVL_h__
#define __AVL_h__

#include "bintree.h"
#include "graphs.h"
#include "queue_AVL.h"

template <class TType>
class AVL : public bintree<TType>
{
public:
	AVL() : bintree() {};
	~AVL();

	int BFactor(Node<TType>*); // получить баланс
	void rotateRight(Node<TType> *&); //однократный правый поворот
	void rotateLeft(Node<TType> *&); //однократный левый поворот
	void doubleRotateRight (Node<TType> *&); //двукратный правый поворот
	void doubleRotateLeft (Node<TType> *&); //двукратный левый поворот
	void Balance (Node<TType>*&); //балансировка

	void recursInsert (Node<TType>*&, Node<TType>*);
	void recursDelete (Node<TType>*&, const TType&);
	virtual void insert (const TType& k)
	{
		if (root == NULL)
		{
			root = new Node<TType>(k);
			size++;
			return;
		}
		Node<TType>* tr = root;
		Node<TType>* tmp = new Node<TType>(k);		
		recursInsert(tr, tmp);
		root = tr;
		Balance(root);
		size ++;
	};
	virtual void Delete (const TType &k)
	{
		if (root == NULL)
			return;
		Node<TType>* tr = root;
		if (Findkey(tr, k) == NULL)
			throw
			exception ("Нет такого элемента");

		recursDelete (tr, k);
		root = tr;
		Balance(root);
		size--;
	};	

	Graph<TType>* kruskal (Graph<TType> *&);
};

template <class TType>
AVL<TType>::~AVL()
{
	delete root;
}

template <class TType>
int AVL<TType>::BFactor (Node<TType>* tr)
{
	return getHeight(tr->right) - getHeight(tr->left) + 1;
}

template <class TType>
void AVL<TType>::rotateRight (Node<TType> *&node)
{
	Node<TType> *A  = node;
	Node<TType> *B  = A->left;
	Node<TType> *t = B->right;

	A->left  = t;
	B->right = A;
	B->parent = A->parent;
	A->parent = B;
	if (t == NULL)
	{
		node = B;
		return;
	}
	
	t->parent = A;
	node = B;
}

template <class TType>
void AVL<TType>::rotateLeft (Node<TType> *&node)
{
	Node<TType> *A  = node;
	Node<TType> *B  = A->right;
	Node<TType> *t1 = B->left;

	A->right = t1;
	B->left = A;
	B->parent = A->parent;
	A->parent = B;
	if (t1 == NULL)
	{
		node = B;
		return;
	}
	t1->parent = A;
	node = B;
}

template <class TType>
void AVL<TType>::doubleRotateRight (Node<TType> *&node)
{
	Node<TType> *A  = node;
	Node<TType> *B  = A->left;
	Node<TType> *C  = B->right;
	Node<TType> *t1 = B->left;
	Node<TType> *t2 = C->left;
	Node<TType> *t3 = C->right;
	Node<TType> *t4 = A->right;

	C->right = A;
	C->left  = B;
	C->parent = A->parent;
	A->parent = C;
	B->parent = C;
	B->right = t2;
	A->left = t3;
	t2->parent = B;
	t3->parent = A;

	node = C;
}

template <class TType>
void AVL<TType>::doubleRotateLeft (Node<TType> *&node)
{
	Node<TType> *A  = node;
	Node<TType> *B  = A->right;
	Node<TType> *C  = B->left;
	Node<TType> *t1 = A->left;
	Node<TType> *t2 = C->left;
	Node<TType> *t3 = C->right;
	Node<TType> *t4 = B->right;

	C->left = A;
	C->right  = B;
	C->parent = A->parent;
	A->parent = C;
	B->parent = C;
	B->left = t3;
	A->right = t2;
	t2->parent = A;
	t3->parent = B;

	node = C;
}

template <class TType> 
void AVL<TType>::recursInsert (Node<TType> *& tree, Node<TType>* node)
{
	if (node->key < tree->key)
		{
			if (tree->left == NULL)
			{
				tree->left = node;
				node->parent = tree;
			}
			else
				recursInsert(tree->left, node);
		}
	else
		{
			if (tree->right == NULL)
			{
				tree->right = node;
				node->parent = tree;
			}
			else 
				recursInsert(tree->right, node);
		}
}

template <class TType>
void AVL<TType>::recursDelete (Node<TType> *& tree, const TType& k)
{
		if (tree == NULL)
			return;
		if (k < tree->key)
			recursDelete(tree->left, k);
		if (k > tree->key)
			recursDelete(tree->right, k);
		if (k == tree->key)
		{
			if ((tree->left == NULL) && (tree->right == NULL)) 
			{
				if (tree->parent->right == tree)
					tree->parent->right = NULL;
				else
					tree->parent->left = NULL;
				delete tree;
			}
			else if ((tree->right == NULL) && (tree->left != NULL))
				{
					Node<TType>* y = tree->left;
				y->parent = tree->parent;
				if (tree->parent->right == tree)
					tree->parent->right = y;
				else
					tree->parent->left = y;
				delete tree;
				}
			else if ((tree->left == NULL) && (tree->right != NULL))
				{
					Node<TType>* y = tree->right;
				y->parent = tree->parent;
				if (tree->parent->right == tree)
					tree->parent->right = y;
				else
					tree->parent->left = y;
				delete tree;
				}
			else 
				{
				Node<TType>* y = FindMin(tree->right);
			tree->key = y->key;
			y->parent->left = y->right;
			if (y->right != NULL)
				y->right->parent = y->parent;
			delete y;
			Balance(tree);
			}
		}		
}

template <class TType>
void AVL<TType>::Balance (Node<TType>*& p)
{
	int c = BFactor(p);
	if (c == 2)
	{
		if (BFactor(p->right) < 0)
			rotateRight(p->right);
		rotateLeft(p);
	}
	if (c == -2)
	{
		if (BFactor (p->left) > 0)
			rotateLeft(p->left);
		rotateRight(p);
	}
	p->balance = BFactor(p);
}

template <class TType>
Graph<TType>* AVL<TType>::kruskal (Graph<TType>*& gr)
{
	int n = gr->getKolvo();
	int m = gr->getRealSize();
	Graph<TType> *tree = new Graph<TType>(n,m);

	sets<TType> *set = new sets<TType>(n);
	for (int i=0; i<n; i++)
		set->makesets(i);

	Prior<TType> **data = new Prior<TType>*[m];
	for (int i=0; i<m;i++)
		data[i] = new DataEdge<TType>(gr->getEdgesets()[i]);

	BQueue<TType> *queue = new BQueue<TType>;
	for (int i=0; i<m; i++)
		queue->push(data[i]->pr);

	int treeEdgeSize = 0;
	int i;
	while ((treeEdgeSize < n-1) && (!queue->isEmpty()))
	{
		i=0;

		Node<TType> *tmp = queue->top();
		queue->pop();

		while (tmp->key != data[i]->pr)
			i++;
		int N = ((DataEdge<TType>*)data)->e->o;
		int K = ((DataEdge<TType>*)data)->e->k;
		TType weight = tmp->key;
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