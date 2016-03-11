#include <d-heap.h>
#include <gtest.h>

TEST(dheap, can_create_dheap)
{
	ASSERT_NO_THROW(DHeap<int> *a = new DHeap<int>(3,10));
}

TEST(dheap, can_copy_dheap)
{
	DHeap<int> *a = new DHeap<int>(3,10);
	ASSERT_NO_THROW (DHeap<int> *b = new DHeap<int> (*a));
}

TEST(dheap, proverka_getidx)
{
	DHeap<int> *a = new DHeap<int>(3,10);
	int c = a->getidx(6);
	EXPECT_EQ(c,1);
}

TEST(dheap, proverka_transa_and_vstavki)
{
	int c;
	DHeap<int> *a = new DHeap<int>(3,12);
	a->vstavka (0,5);
	a->vstavka (1,8);
	for (int i=2;i<12;i++)
		a->vstavka(i,0);
	DHeap<int> *b = new DHeap<int>(3,12);
	b->vstavka (0,8);
	b->vstavka (1,5);
	for (int i=2;i<12;i++)
		b->vstavka(i,0);
	b->trans(0,1);
	a->vyvod();
}