#include <d-heap.h>
#include <gtest.h>

TEST(dheap, can_create_dheap)
{
	ASSERT_NO_THROW(DHeap<int> *a = new DHeap<int>(3,10));
}

TEST(dheap, throw_if_nekorrect_dannye)
{
	ASSERT_ANY_THROW(DHeap<int> *a = new DHeap<int>(-3,10));
}

TEST(dheap, can_copy_dheap)
{
	DHeap<int> *a = new DHeap<int>(3,10);
	ASSERT_NO_THROW (DHeap<int> *b = new DHeap<int> (*a));
}

TEST(dheap, proverka_getidx)
{
	DHeap<int> *a = new DHeap<int>(3,11);
	int c = a->getidx(6);
	EXPECT_EQ(c,1);
}

TEST(dheap, proverka_transa)
{
	int c;
	DHeap<int> *a = new DHeap<int>(3,13);
	a->vstavka (0,5);
	a->vstavka (1,8);
	for (int i=2;i<13;i++)
		a->vstavka(i,0);
	DHeap<int> *b = new DHeap<int>(3,13);
	b->vstavka (0,8);
	b->vstavka (1,5);
	for (int i=2;i<13;i++)
		b->vstavka(i,0);
	b->trans(0,1);
	c = a->operator==(*b);
	EXPECT_EQ(c,1);
}

TEST(dheap, throw_if_trans_uncorrect)
{
	DHeap<int> *a = new DHeap<int>(3,13);
	ASSERT_ANY_THROW(a->trans(15,17));
}

TEST(dheap, provarka_vsplytiya)
{
	DHeap<int> *a = new DHeap<int>(3,13);
	a->vstavka (0,5);
	a->vstavka (1,8);
	for (int i=2;i<13;i++)
		a->vstavka(i,0);
	ASSERT_NO_THROW(a->vsplyt(1));
}

TEST(dheap, proverka_vsplytiya2)
{
	int c;
	DHeap<int> *a = new DHeap <int> (3,13);
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
	a->vsplyt(12);
	DHeap<int> *b = new DHeap <int> (3,13);
	b->vstavka (0,5);
	b->vstavka (1,8);
	b->vstavka (2,7);
	b->vstavka (3,13);
	b->vstavka (4,15);
	b->vstavka (5,12);
	b->vstavka (6,18);
	b->vstavka (7,8);
	b->vstavka (8,10);
	b->vstavka (9,12);
	b->vstavka (10,14);
	b->vstavka (11,15);
	b->vstavka (12,14);
	c = a->operator==(*b);
	EXPECT_EQ(c,1);
}

TEST(dheap, throw_if_vsplyt_uncorrect)
{
	DHeap<int> *a = new DHeap <int> (3,13);
	ASSERT_ANY_THROW(a->vsplyt(16));
}

TEST(dheap, proverka_minchild)
{
	DHeap<int> *a = new DHeap <int> (3,13);
	a->vstavka (0,5);
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
	int b = a->minchild(0);
	EXPECT_EQ(b,2);
}

TEST(dheap, proverka_minchild2)
{
	DHeap<int> *a = new DHeap <int> (3,13);
	a->vstavka (0,5);
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
	int b = a->minchild(8);
	EXPECT_EQ(b,-1);
}

TEST(dheap, proverka_pogryzh)
{
	DHeap<int> *a = new DHeap <int> (3,13);
	a->vstavka (0,5);
	a->vstavka (1,8);
	a->vstavka (2,13);
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
	a->pogryzh(2);
	DHeap<int> *b = new DHeap <int> (3,13);
	b->vstavka (0,5);
	b->vstavka (1,8);
	b->vstavka (2,8);
	b->vstavka (3,12);
	b->vstavka (4,15);
	b->vstavka (5,12);
	b->vstavka (6,18);
	b->vstavka (7,13);
	b->vstavka (8,10);
	b->vstavka (9,12);
	b->vstavka (10,14);
	b->vstavka (11,15);
	b->vstavka (12,13);
	int c = a->operator==(*b);
	EXPECT_EQ(c,1);
}

TEST(dheap, proverka_pogryzh2)
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
	int c = a->operator==(*b);
	EXPECT_EQ(c,1);
}

TEST(dheap, proverka_pogryzh3)
{
	DHeap<int> *a = new DHeap <int> (3,13);
	a->vstavka (0,5);
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
	a->pogryzh(12);
	int c = a->operator==(*a);
	EXPECT_EQ(c,1);
}

TEST(dheap, throw_if_pogryzh_uncorrect)
{
	DHeap<int> *a = new DHeap <int> (3,13);
	ASSERT_ANY_THROW(a->pogryzh(20));
}

TEST(dheap, provekra_delet_s_min)
{
	DHeap<int> *a = new DHeap <int> (3,13);
	a->vstavka (0,5);
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
	a->delet();

	DHeap<int> *b = new DHeap <int> (3,12);
	b->vstavka (0,7);
	b->vstavka (1,8);
	b->vstavka (2,8);
	b->vstavka (3,12);
	b->vstavka (4,15);
	b->vstavka (5,12);
	b->vstavka (6,18);
	b->vstavka (7,13);
	b->vstavka (8,10);
	b->vstavka (9,12);
	b->vstavka (10,14);
	b->vstavka (11,15);
	int c = a->operator==(*b);
	EXPECT_EQ(c,1);
}

TEST(dheap, proverka_delet_s_zadan)
{
	DHeap<int> *a = new DHeap <int> (3,13);
	a->vstavka (0,5);
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
	a->deletzadan(2);

	DHeap<int> *b = new DHeap <int> (3,12);
	b->vstavka (0,5);
	b->vstavka (1,8);
	b->vstavka (2,8);
	b->vstavka (3,12);
	b->vstavka (4,15);
	b->vstavka (5,12);
	b->vstavka (6,18);
	b->vstavka (7,13);
	b->vstavka (8,10);
	b->vstavka (9,12);
	b->vstavka (10,14);
	b->vstavka (11,15);
	int c = a->operator==(*b);
	EXPECT_EQ(c,1);
}
	
TEST(dheap, throw_if_idx_uncorrect)
{
	DHeap<int> *a = new DHeap <int> (3,13);
	ASSERT_ANY_THROW(a->deletzadan(16));
}

TEST(dheap, proverka_delet_s_zadan2)
{
	DHeap<int> *a = new DHeap <int> (3,13);
	a->vstavka (0,5);
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
	a->deletzadan(0);

	DHeap<int> *b = new DHeap <int> (3,12);
	b->vstavka (0,7);
	b->vstavka (1,8);
	b->vstavka (2,8);
	b->vstavka (3,12);
	b->vstavka (4,15);
	b->vstavka (5,12);
	b->vstavka (6,18);
	b->vstavka (7,13);
	b->vstavka (8,10);
	b->vstavka (9,12);
	b->vstavka (10,14);
	b->vstavka (11,15);
	int c = a->operator==(*b);
	EXPECT_EQ(c,1);
}

TEST(dheap, proverka_pusha)
{
	DHeap<int> *a = new DHeap <int> (3,13);
	a->vstavka (0,5);
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
	a->push(4);

	DHeap<int> *b = new DHeap <int> (3,14);
	b->vstavka (0,4);
	b->vstavka (1,5);
	b->vstavka (2,7);
	b->vstavka (3,12);
	b->vstavka (4,8);
	b->vstavka (5,12);
	b->vstavka (6,18);
	b->vstavka (7,8);
	b->vstavka (8,10);
	b->vstavka (9,12);
	b->vstavka (10,14);
	b->vstavka (11,15);
	b->vstavka (12,13);
	b->vstavka (13,15);
	
	int c = a->operator==(*b);
	EXPECT_EQ(c,1);
}

TEST(dheap, proverka_okychivaniya)
{
	DHeap<int> *a = new DHeap <int> (3,0);
	a->push (5);
	a->push (8);
	a->push (7);
	a->push (12);
	a->push (15);
	a->push (12);
	a->push (18);
	a->push (8);
	a->push (10);
	a->push (12);
	a->push (14);
	a->push (15);
	a->push (13);
	a->okych();
	int c = a->operator==(*a);
	EXPECT_EQ(c,1);
}

TEST(dheap, throw_if_kycha_pusta_pri_okych)
{
	DHeap<int> *a = new DHeap <int> (3,0);
	ASSERT_ANY_THROW(a->okych());
}

TEST(dheap, proverka_operatora_ravno)
{
	DHeap<int> *a = new DHeap <int> (3,13);
	a->vstavka (0,5);
	a->vstavka (1,8);
	a->vstavka (2,7);
	a->vstavka (3,12);

	DHeap<int> *b = new DHeap <int> (3,12);

	a = b;
	int c = a->operator==(*b);
	EXPECT_EQ(c,1);
}
