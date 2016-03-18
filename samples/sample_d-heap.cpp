#include <d-heap.h>

void main ()
{
	int c=0; 
	DHeap<int> *a = new DHeap <int> (3,12);
	a->vstavka (0,5);
	a->vstavka (1,8);
	a->vstavka (2,7);
	a->vstavka (3,14);
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
	a->vsplyt(12);
	a->vyvod();

}