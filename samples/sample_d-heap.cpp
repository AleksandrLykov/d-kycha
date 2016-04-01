#include <d-heap.h>

void main ()
{
	DHeap<int> *a = new DHeap <int> (3,13);
	a->vstavka (0,100);
	a->vstavka (1,8);
	a->vstavka (2,7);
	a->vstavka (3,12);
	a->vstavka (4,15);
	a->vstavka (5,12);
	a->vstavka (6,18);
	a->vstavka (7,8);
	a->vstavka (8,10);
	a->vstavka (9,12);
	a->vstavka (10,14);
	a->vstavka (11,15);
	a->vstavka (12,13);
	a->vyvod();
	a->pogryzh(0);
	DHeap<int> *b = new DHeap <int> (3,13);
	b->vstavka (0,7);
	b->vstavka (1,8);
	b->vstavka (2,8);
	b->vstavka (3,12);
	b->vstavka (4,15);
	b->vstavka (5,12);
	b->vstavka (6,18);
	b->vstavka (7,100);
	b->vstavka (8,10);
	b->vstavka (9,12);
	b->vstavka (10,14);
	b->vstavka (11,15);
	b->vstavka (12,13);

	a->vyvod();
	b->vyvod();

}