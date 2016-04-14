#include <queue.h>

void main()
{
	DHeap<int> *a = new DHeap<int>(3,0);
	a->push(5);
	a->push(1);
	a->vyvod();
	cout << endl;

	DHeap<int> *b = new DHeap<int>(*a);
	b->vyvod();

}