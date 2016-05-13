#ifndef __AVL_h__
#define __AVL_h__

#include "bintree.h"


template <class TType>
class AVL : public bintree<TType>
{
public:
	AVL() : bintree() {};
	~AVL();

	int BFactor(Node<TType>*); // получить баланс
	Node<TType>* rotateRight(Node<TType> *); //однократный правый поворот
	void rotateLeft(Node<TType> *&); //однократный левый поворот
	Node<TType>* doubleRotateRight (Node<TType> *); //двукратный правый поворот
	Node<TType>* doubleRotateLeft (Node<TType> *); //двукратный левый поворот
	void Balance (Node<TType>*&); //балансировка

	void recursInsert (Node<TType>*&, Node<TType>*);
	void recursDelete (Node<TType>*&, const TType&);
	virtual void insert (const TType& k)
	{
		TType a = k;
	if (root == NULL)
	{
		root = new Node<TType>;
		root -> key = a;
		return;
	}
	Node<TType> *x = root, *y = 0;
	while (x != NULL)
	{
 		y = x;
		if (x->key <= a)
		{
			x = x->right;			
		}
		else
		{
			x = x->left;
		}
	}
	if (y->key <= a)
	{
		y->right = new Node<TType>;
		y->right->key = a;
		y->right->parent = y;
	}
	else
	{
		y->left = new Node<TType>;
		y->left->key = a;
		y->left->parent = y;
	}
	Balance(root);
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
	};	
};

template <class TType>
AVL<TType>::~AVL()
{
	delete root;
}

template <class TType>
int AVL<TType>::BFactor (Node<TType>* tr)
{
	Node<TType> *tmp = tr;
	return getHeight(tmp->right) - getHeight(tmp->left) + 1;
}

template <class TType>
Node<TType>* AVL<TType>::rotateRight (Node<TType> *node)
{	
	Node<TType> *A  = node;
	Node<TType> *B  = A->left;
	Node<TType> *t = B->right;

	A->left  = t;
	B->right = A;
	B->parent = A->parent;
	A->parent = B;
	t->parent = A;

	node = B;
	return node;
}

template <class TType>
void AVL<TType>::rotateLeft (Node<TType> *&node)
{
	Node<TType> *A  = node;
	Node<TType> *B  = A->right;
	Node<TType> *t1 = B->right;

	A->right = t1;
	B->left = A;
	B->parent = A->parent;
	A->parent = B;
	t1->parent = A;

	node = B;

}

template <class TType>
Node<TType>* AVL<TType>::doubleRotateRight (Node<TType> *node)
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
	return node;
}

template <class TType>
Node<TType>* AVL<TType>::doubleRotateLeft (Node<TType> *node)
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
	return node;
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
	rotateLeft(p);
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
				if (tree->parent->left == tree) 
					tree->parent->left = NULL;
				else 
					tree->parent->right = NULL;
				delete tree;
			}
		if ((tree->right == NULL) && (tree->left != NULL))
		{
			if (tree->parent->left == tree) 
				tree->parent->left = tree->left;
			else 
				tree->parent->right = tree->left;
			tree->left->parent = tree->parent;
			delete tree;
		}
		if ((tree->left == NULL) && (tree->right != NULL))
		{
			if (tree->parent->left == tree) 
				tree->parent->left = tree->right;
			else 
				tree->parent->right = tree->right;
			tree->right->parent = tree->parent;
			delete tree;
		}
		if ((tree->left != NULL) && (tree->right != NULL))
		{
			Node<TType>* tmpNext = FindNext(tree, tree);
			Node<TType>* tmp = tmpNext->parent;
			tmpNext->right->parent = tmpNext->parent;		
			if (tmpNext->parent->left == tmpNext) 
				tmpNext->parent->left = tmpNext->right;
			else 
				tmpNext->parent->right = tmpNext->right;
				tmpNext->parent = tree->parent;
				tmpNext->left = tree->left;
				tmpNext->right = tree->right;
				delete tree;
				
				while (tmp != tmpNext)
				{
					Balance(tmp);
					tmp = tmp->parent;
				}
		}
		}
}

template <class TType>
void AVL<TType>::Balance (Node<TType>*& p)
{
	if (p == NULL)
		return;
	p->balance = BFactor(p);
	if (p->balance == 2)
	{
		if (BFactor(p->right) < 0)
			p->right = rotateRight(p->right);
		rotateLeft(p);
		p->balance = BFactor(p);
	}
	if (p->balance == -2)
	{
		if (BFactor (p->left) > 0)
			rotateLeft(p->left);
		p = rotateRight(p);
		p->balance = BFactor(p);
	}	
}

#endif