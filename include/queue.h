#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <d-heap.h>


template <class HType>
class HQueue
{
private:
	DHeap<HType> *heap; // очередь
public:
	HQueue(int);
	~HQueue();
	HQueue(const HQueue<HType>&);
	HQueue(Data<HType>**, int, int);

	void push(const HType);
	void pop();
	int isEmpty();
	HType top();
	void vyvod();
	int operator ==(const HQueue<HType>&)const;
};

template <class HType>
HQueue<HType>::HQueue (int d)
{	
	if (d < 0)
		throw
		exception ("введите корректные данные");
	heap = new DHeap<HType> (d, 0);
}

template <class HType>
HQueue<HType>::~HQueue ()
{
	delete heap;
}

template <class HType>
HQueue<HType>::HQueue (const HQueue<HType>& a)
{
	this->heap = new DHeap<HType>(*(a.heap));
}

 template <class HType>
int HQueue<HType>::isEmpty()
{
	if (heap->getKolvo() == 0)
		return 1;
	else return 0;
}

template <class HType>
void HQueue<HType>::pop()
{
	if (isEmpty())
		throw
		exception ("очередь пуста");
	heap->delet();
}

template <class HType>
void HQueue<HType>::push(const HType a)
{
	heap->push(a);
}

template <class HType>
HType HQueue<HType>::top ()
{
	if (isEmpty())
		throw
		exception ("очередь пуста");
	return heap->getKey(0);
}

template <class HType>
void HQueue<HType>::vyvod ()
{
	heap->vyvod();
}

template <class HType>
int HQueue<HType>::operator== (const HQueue<HType>& a)const
{
	 return *heap == *a.heap;
}

template <class HType>
HQueue<HType>::HQueue (Data<HType> **a, int n, int d)
{
	heap = new DHeap<HType> (d, n);
	heap->add(a, n);
}

#endif