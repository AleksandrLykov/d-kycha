#ifndef __D_HEAP__H__
#define __D_HEAP__H__

#include <cstdlib>
#include <iostream>

using namespace std;

template <class HType>
class DHeap
{
private:
	int d;
	HType *keys;
	int kolvo;
public:
	DHeap (const int, const int);
	DHeap (const DHeap&);
	~DHeap ();
	int getidx (int a);
	void trans (const int a, const int b);
	void vsplyt (int a);
	void pogryzh (int a);
	void minchild (int a);
	void delet ();
	void deletzadan (int a);
	void push (int a);
	void okych ();
	void sort ();
};

template <class HType>
DHeap<HType>::DHeap (const int arnost, const int size)
{
	d = arnost; 
	kolvo = size;
	keys = new HType [kolvo];
}

template <class HType>
DHeap<HType>::DHeap (const DHeap &a)
{
	d = a.d;
	kolvo = a.kolvo;
	for (int i=0;i<kolvo;i++)
		keys[i] = a.keys[i];
}

template <class HType>
DHeap<HType>::~DHeap ()
{
	delete []keys;
}

template <class HType>
int DHeap<HType>::getidx (int a)
{
	int p;
	return p = (a-1)/d;
}

template <class HType>
void DHeap<HType>::trans (const int a, const int b) 
{
	int tmp = keys[a];
	keys[a] = keys[b];
	keys[b] = tmp;
}

template <class HType>
void DHeap<HType>::vsplyt (int a) 
{
	int p = getidx (a);
}

#endif