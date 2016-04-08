#include <queue.h>

void main ()
{
	HQueue<int> *a = new HQueue <int> (32,3,13);
	DHeap<int> *b = new DHeap <int> (3,13);
	a->push(*b, 2);
}
