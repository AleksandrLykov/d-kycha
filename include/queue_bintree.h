#ifndef __queue_h__
#define __queue_h__

#include "bintree.h"

template <class TType>
class BQueue
{
private:
	bintree<TType> *tree;
public:
	BQueue();
	~BQueue();

	void push(const TType);
	void pop();
	int isEmpty();
	Node<TType>* top();
	void print();
	int GetSize();
	int operator==(const BQueue<TType>&)const;
	bintree<TType>* getTree ();
};


template <class TType>
BQueue<TType>::BQueue ()
{
	tree = new bintree<TType>;
}

template <class TType>
BQueue<TType>::~BQueue()
{
	delete tree;
}

template <class TType>
int BQueue<TType>::isEmpty()
{
	int a = tree->getSize();
	if (a != 0)
		return 0;
	else return 1;
}

template <class TType>
void BQueue<TType>::push (const TType a)
{
	Node<TType> *tmp = new Node<TType>(a);
	tree->insert(tree->root, tmp);
}

template <class TType>
Node<TType>* BQueue<TType>::top()
{
	if (isEmpty() )
		throw
		exception ("������� �����");
	return tree->root;
}

template <class TType>
void BQueue<TType>::pop()
{
	if (isEmpty() )
		throw
		exception ("������� �����");

	tree->Delete(tree->root, tree->root->key);
}

template <class TType>
void BQueue<TType>::print()
{
	cout << endl;
	cout << "����� ����� � ������ - ";
	tree->workAroundAcross(tree->root);
	cout << ';' << endl << "����� ������ ����� - ";
	tree->workAroundForward(tree->root);
	cout << ';' << endl << "����� �������� ����� - ";
	tree->workAroundReverse(tree->root);
	cout << ';' << endl << "����� ������������ ����� - ";
	tree->workAroundSymmetr(tree->root);
	cout << ';' << endl << "����� ����� � ������� - ";
	tree->workAroundDepth(tree->root);
}

template <class TType>
int BQueue<TType>::GetSize()
{
	return tree->getSize();
}

template <class TType>
int BQueue<TType>::operator==(const BQueue<TType>& a)const
{
	return *tree == *a.tree;
}

template <class TType>
bintree<TType>* BQueue<TType>::getTree()
{
	return tree;
}


#endif