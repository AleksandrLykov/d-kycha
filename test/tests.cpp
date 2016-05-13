#include <d-heap.h>
#include <gtest.h>
#include <queue.h>
#include <graphs.h>
#include "AVL.h"
#include "bintree.h"
#include "sets.h"

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
	DHeap<int> *a = new DHeap<int>(3,0);
	a->push(5);
	a->push(8);
	DHeap<int> *b = new DHeap<int>(3,0);
	b->push (8);
	b->push (5);

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
	DHeap<int> *a = new DHeap<int>(3,0);
	a->push (5);
	a->push (8);
	ASSERT_NO_THROW(a->vsplyt(1));
}

TEST(dheap, proverka_vsplytiya2)
{
	int c;
	DHeap<int> *a = new DHeap <int> (3,0);
	a->push (5);
	a->push (8);
	a->push (7);
	a->push (14);
	a->push (15);
	a->push (12);
	a->push (18);
	a->push (8);
	a->push (10);
	a->push (12);
	a->push (14);
	a->push (15);
	a->push (13);
	a->vsplyt(12);

	DHeap<int> *b = new DHeap <int> (3,0);
	b->push (5);
	b->push (8);
	b->push (7);
	b->push (13);
	b->push (15);
	b->push (12);
	b->push (18);
	b->push (8);
	b->push (10);
	b->push (12);
	b->push (14);
	b->push (15);
	b->push (14);
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
	DHeap<int> *a = new DHeap <int> (3,0);
	a->push (5);
	a->push (8);
	a->push (7);
	a->push (14);
	a->push (15);
	a->push (12);
	a->push (18);
	a->push (8);
	a->push (10);
	a->push (12);
	a->push (14);
	a->push (15);
	a->push (13);
	int b = a->minchild(0);
	EXPECT_EQ(b,2);
}

TEST(dheap, proverka_minchild2)
{
	DHeap<int> *a = new DHeap <int> (3,0);
	a->push (5);
	a->push (8);
	a->push (7);
	a->push (14);
	a->push (15);
	a->push (12);
	a->push (18);
	a->push (8);
	a->push (10);
	a->push (12);
	a->push (14);
	a->push (15);
	a->push (13);
	int b = a->minchild(8);
	EXPECT_EQ(b,-1);
}

TEST(dheap, proverka_pogryzh)
{
	DHeap<int> *a = new DHeap <int> (3,0);
	a->push (5);
	a->push (30);
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
	a->pogryzh(1);

	DHeap<int> *b = new DHeap <int> (3,0);
	b->push (5);
	b->push (12);
	b->push (7);
	b->push (12);
	b->push (15);
	b->push (30);
	b->push (18);
	b->push (8);
	b->push (10);
	b->push (12);
	b->push (14);
	b->push (15);
	b->push (13);
	int c = a->operator==(*b);
	EXPECT_EQ(c,1);
}

TEST(dheap, proverka_pogryzh2)
{
	DHeap<int> *a = new DHeap <int> (3,0);
	a->push (100);
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
	a->pogryzh(0);
	DHeap<int> *b = new DHeap <int> (3,0);
	b->push (7);
	b->push (8);
	b->push (8);
	b->push (12);
	b->push (15);
	b->push (12);
	b->push (18);
	b->push (100);
	b->push (10);
	b->push (12);
	b->push (14);
	b->push (15);
	b->push (13);
	int c = a->operator==(*b);
	EXPECT_EQ(c,1);
}

TEST(dheap, proverka_pogryzh3)
{
	DHeap<int> *a = new DHeap <int> (3,0);
	a->push (5);
	a->push (8);
	a->push (7);
	a->push (14);
	a->push (15);
	a->push (12);
	a->push (18);
	a->push (8);
	a->push (10);
	a->push (12);
	a->push (14);
	a->push (15);
	a->push (13);
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
	a->delet();

	DHeap<int> *b = new DHeap <int> (3,0);
	b->push (7);
	b->push (8);
	b->push (8);
	b->push (12);
	b->push (15);
	b->push (12);
	b->push (18);
	b->push (13);
	b->push (10);
	b->push (12);
	b->push (14);
	b->push (15);
	int c = a->operator==(*b);
	EXPECT_EQ(c,1);
}

TEST(dheap, proverka_delet_s_zadan)
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
	a->deletzadan(2);

	DHeap<int> *b = new DHeap <int> (3,0);
	b->push (5);
	b->push (8);
	b->push (8);
	b->push (12);
	b->push (15);
	b->push (12);
	b->push (18);
	b->push (13);
	b->push (10);
	b->push (12);
	b->push (14);
	b->push (15);
	int c = a->operator==(*b);
	EXPECT_EQ(c,1);
}
	
TEST(dheap, throw_if_idx_uncorrect)
{
	DHeap<int> *a = new DHeap <int> (3,13);
	ASSERT_ANY_THROW(a->deletzadan(16));
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
	DHeap<int> *a = new DHeap <int> (3,0);
	a->push (5);
	a->push (8);
	a->push (7);
	a->push (14);
	a->push (15);
	a->push (12);
	a->push (18);
	a->push (8);
	a->push (10);
	a->push (12);
	a->push (14);
	a->push (15);
	a->push (13);

	DHeap<int> *b = new DHeap <int> (3,0);

	a = b;
	int c = a->operator==(*b);
	EXPECT_EQ(c,1);
}

/////////////////////////////////////////////////////////////////////////
TEST(queue, can_create_queue)
{
	ASSERT_NO_THROW(HQueue<int> *a = new HQueue<int> (2));
}

TEST(queue, throw_if_uncorrect_arn)
{
	ASSERT_ANY_THROW(HQueue<int> *a = new HQueue<int> (-1));
}

TEST(queue, can_copy_queue)
{
	HQueue<int> *a = new HQueue<int> (2);
	ASSERT_NO_THROW(HQueue<int> *b = new HQueue<int> (*a));
}

TEST(queue, proverka_isEmpty)
{
	HQueue<int> *a = new HQueue<int> (2);
	EXPECT_EQ (a->isEmpty(), 1);
}

TEST(queue, proverka_popa)
{
	HQueue<int> *a = new HQueue<int> (2);
	a->push(5);
	a->pop();
	EXPECT_EQ(a->isEmpty(), 1);
}

TEST(queue, throw_if_pop_iz_pustoi_queue)
{
	HQueue<int> *a = new HQueue<int> (2);
	ASSERT_ANY_THROW(a->pop());
}

TEST(queue, proverka_topa)
{
	HQueue<int> *a = new HQueue<int> (2);
	a->push(5);
	EXPECT_EQ(a->top()->pr, 5);
}

TEST(queue, proverka_na_ravenstvo)
{
	HQueue<int> *a = new HQueue<int> (2);
	a->push(5);
	HQueue<int> *b = new HQueue<int> (2);
	b->push(5);
	int c = a->operator==(*b);
	EXPECT_EQ(c,1);
}

/////////////////////////////////////////////////////////////////////////
TEST(graph, can_create_graph)
{
	ASSERT_NO_THROW(Graph<int> *a = new Graph<int>(5,8) );
}

TEST(graph, throw_if_create_graph_with_uncorrect)
{
	ASSERT_ANY_THROW(Graph<int> *a = new Graph<int>(5,15) );
}

TEST(graph, proverka_get_kolvo)
{
	Graph<int> *a = new Graph<int>(5,8);
		EXPECT_EQ(a->getKolvo(), 5);
}

TEST(graph, proverka_getEdgeSize)
{
	Graph<int> *a = new Graph<int>(5,8);
	EXPECT_EQ(a->getEdgeSize(), 8);
}

TEST(graph, proverka_getRealSize)
{
	Graph<int> *a = new Graph<int>(5,1);
	EXPECT_EQ(a->getRealSize(), 0);
}

TEST(graph, can_add_edge)
{
	Graph<int> *a = new Graph<int>(5,3);
	a->addEdge(2,3,6);
	EXPECT_EQ(a->getRealSize(), 1);
}

TEST(graph, throw_if_uncorrect_add_edge)
{
	Graph<int> *a = new Graph<int>(5,8);
	ASSERT_ANY_THROW(a->addEdge(6,1,5));
}

TEST(graph, throw_if_uncorrect_add_edge2)
{
	Graph<int> *a = new Graph<int>(5,8);
	ASSERT_ANY_THROW(a->addEdge(2,2,6));
}

TEST(graph, throw_if_graph_isFull)
{
	Graph<int> *a = new Graph<int>(2,1);
	a->addEdge(0,1,6);
	ASSERT_ANY_THROW(a->addEdge(1,0,6));
}

TEST(graph, proverka_getWeight)
{
	Graph<int> *a = new Graph<int>(2,1);
	a->addEdge(0,1,7);
	EXPECT_EQ(a->getWeight(0,1), 7);
}

TEST(graph, proverka_delEdge)
{
	Graph<int> *a = new Graph<int>(2,1);
	a->addEdge(0,1,5);
	a->delEdge(0,1);
	EXPECT_EQ(a->getRealSize(), 0);
}

TEST(graph, throw_if_uncorrect_del)
{
	Graph<int> *a = new Graph<int>(2,1);
	ASSERT_ANY_THROW(a->delEdge(0,1));
}

TEST(graph, proverka_findEdge)
{
	Graph<int> *a = new Graph<int>(2,1);
	a->addEdge(0,1,5);
	EXPECT_EQ(a->findEdge(0,1), 0);
}

TEST(graph, proverka_if_uncorrect_find)
{
	Graph<int> *a = new Graph<int>(2,1);
	EXPECT_EQ(a->findEdge(3,4), -1);
}


///////////////////////////////////////////////////////////////////
TEST(sets, can_create_sets)
{
	ASSERT_NO_THROW(sets<int> *a = new sets<int>(2));
}

TEST(sets, can_makesets)
{
	sets<int> *a = new sets<int>(2);
	ASSERT_NO_THROW(a->makesets(1));
}

TEST(sets, can_find_sets)
{
	sets<int> *a = new sets<int>(2);
	a->makesets(1);
	EXPECT_EQ(a->findsets(1), 1);
}

TEST(sets, throw_if_uncorrect_find)
{
	sets<int> *a = new sets<int>(2);
	ASSERT_ANY_THROW(a->findsets(5));
}

TEST(sets, throw_if_uncorrect_make)
{
	sets<int> *a = new sets<int>(2);
	ASSERT_ANY_THROW(a->makesets(8));
}

TEST(sets, throw_if_elem_already_used)
{
	sets<int> *a = new sets<int>(2);
	a->makesets(1);
	ASSERT_ANY_THROW(a->makesets(1));
}

TEST(sets, can_union_sets)
{
	sets<int> *a = new sets<int>(2);
	a->makesets(1);
	a->makesets(0);
	ASSERT_NO_THROW(a->unionsets(0,1));
}

TEST(sets, throw_if_uncorrect_union)
{
	sets<int> *a = new sets<int>(2);
	ASSERT_ANY_THROW(a->unionsets(5,1));
}

TEST(sets, throw_if_union_not_root_elem)
{
	sets<int> *a = new sets<int>(2);
	ASSERT_ANY_THROW(a->unionsets(0,1));
}

TEST(bintree, can_create_bintree)
{
	ASSERT_NO_THROW(bintree<int> *a = new bintree<int>());
}

TEST(bintree, can_copy_bintree)
{
	bintree<int> *a = new bintree<int>();
	Node<int> *b = new Node<int>();
	b->key = 6;
	a->insert(a->root,b);
	ASSERT_NO_THROW(bintree<int> *b = new bintree<int>(*a));
}

TEST(bintree, provekra_copy)
{
	bintree<int> *a = new bintree<int>();
	Node<int> *b = new Node<int>();
	b->key = 6;
	a->insert(a->root,b);
	b->key = 2;
	a->insert(a->root,b);
	bintree<int> *c = new bintree<int>(*a);
	int d = a->operator==(*c);
	EXPECT_EQ(d,1);
}

TEST(bintree, proverka_FindKey_if_key_est)
{
	bintree<int> *a = new bintree<int>();
	Node<int> *b = new Node<int>();
	b->key = 6;
	a->insert(a->root,b);
	b->key = 2;
	a->insert(a->root,b);
	b->key = 8;
	a->insert(a->root, b);
	b->key = 0;
	a->insert(a->root, b);
	b = a->Findkey(a->root, 2);
	EXPECT_EQ(b->key, 2);
}

TEST(bintree, any_throw_if_FindKey_havent_key)
{
	bintree<int> *a = new bintree<int>();
	Node<int> *b = new Node<int>();
	b->key = 6;
	a->insert(a->root,b);
	b->key = 2;
	a->insert(a->root,b);
	b->key = 8;
	a->insert(a->root, b);
	b->key = 0;
	a->insert(a->root, b);
	ASSERT_ANY_THROW(a->Findkey(a->root, 10));
}

TEST(bintree, probyem_FindMin)
{
	bintree<int> *a = new bintree<int>();
	Node<int> *b = new Node<int>();
	b->key = 9;
	a->insert(a->root,b);
	b->key = 6;
	a->insert(a->root,b);
	b->key = 8;
	a->insert(a->root, b);
	b->key = 2;
	a->insert(a->root, b);
	b->key = 4;
	a->insert(a->root, b);
	b->key = 0;
	a->insert(a->root, b);
	b->key = 5;
	a->insert(a->root, b);
	b->key = 1;
	a->insert(a->root, b);
	b->key = 7;
	a->insert(a->root, b);
	Node<int> *c = a->FindMin(a->root);
	EXPECT_EQ(c->key, 0);
}

TEST(bintree, throw_if_in_FindMin_pustoe_tree)
{
	bintree<int> *a = new bintree<int>();
	ASSERT_ANY_THROW(a->FindMin(a->root));
}

TEST(bintree, probyem_FindMax)
{
	bintree<int> *a = new bintree<int>();
	Node<int> *b = new Node<int>();
	b->key = 9;
	a->insert(a->root,b);
	b->key = 6;
	a->insert(a->root,b);
	b->key = 8;
	a->insert(a->root, b);
	b->key = 2;
	a->insert(a->root, b);
	b->key = 4;
	a->insert(a->root, b);
	b->key = 0;
	a->insert(a->root, b);
	b->key = 5;
	a->insert(a->root, b);
	b->key = 1;
	a->insert(a->root, b);
	b->key = 7;
	a->insert(a->root, b);
	Node<int> *c = a->FindMax(a->root);
	EXPECT_EQ(c->key, 9);
}

TEST(bintree, throw_if_in_FindMax_pustoe_tree)
{
	bintree<int> *a = new bintree<int>();
	ASSERT_ANY_THROW(a->FindMax(a->root));
}

TEST(bintree, probyem_FindNext)
{
	bintree<int> *a = new bintree<int>();
	Node<int> *b = new Node<int>();
	b->key = 9;
	a->insert(a->root,b);
	b->key = 6;
	a->insert(a->root,b);
	b->key = 8;
	a->insert(a->root, b);
	b->key = 2;
	a->insert(a->root, b);
	b->key = 4;
	a->insert(a->root, b);
	b->key = 0;
	a->insert(a->root, b);
	b->key = 5;
	a->insert(a->root, b);
	b->key = 1;
	a->insert(a->root, b);
	b->key = 7;
	a->insert(a->root, b);
	b->key = 6;
	Node<int> *c = a->FindNext(a->root, b);
	EXPECT_EQ(c->key, 7);
}

TEST(bintree, can_findprevious)
{
	bintree<int> *a = new bintree<int>();
	Node<int> *b = new Node<int>();
	b->key = 9;
	a->insert(a->root,b);
	b->key = 6;
	a->insert(a->root,b);
	b->key = 8;
	a->insert(a->root, b);
	b->key = 2;
	a->insert(a->root, b);
	b->key = 4;
	a->insert(a->root, b);
	b->key = 0;
	a->insert(a->root, b);
	b->key = 5;
	a->insert(a->root, b);
	b->key = 1;
	a->insert(a->root, b);
	b->key = 7;
	a->insert(a->root, b);
	b->key = 6;
	Node<int> *c = a->FindPrevious(a->root, b);
	EXPECT_EQ(c->key, 5);
}

TEST(bintree, proverka_getsize)
{
	bintree<int> *a = new bintree<int>();
	Node<int> *b = new Node<int>();
	b->key = 9;
	a->insert(a->root,b);
	b->key = 6;
	a->insert(a->root,b);
	b->key = 8;
	a->insert(a->root, b);
	b->key = 2;
	a->insert(a->root, b);
	b->key = 4;
	a->insert(a->root, b);
	b->key = 0;
	a->insert(a->root, b);
	b->key = 5;
	a->insert(a->root, b);
	b->key = 1;
	a->insert(a->root, b);
	b->key = 7;
	a->insert(a->root, b);
	EXPECT_EQ(a->getSize(), 9);
}

TEST(bintree, throw_if_findnext_uncorrect)
{
	bintree<int> *a = new bintree<int>();
	Node<int> *b = new Node<int>();
	b->key = 9;
	a->insert(a->root,b);
	b->key = 6;
	a->insert(a->root,b);
	b->key = 8;
	a->insert(a->root, b);
	b->key = 2;
	a->insert(a->root, b);
	b->key = 4;
	a->insert(a->root, b);
	b->key = 0;
	a->insert(a->root, b);
	b->key = 5;
	a->insert(a->root, b);
	b->key = 1;
	a->insert(a->root, b);
	b->key = 7;
	a->insert(a->root, b);
	b->key = 100;
	ASSERT_ANY_THROW(a->FindNext(a->root, b));
}

TEST(bintree, throw_if_findprevious_uncorrect)
{
	bintree<int> *a = new bintree<int>();
	Node<int> *b = new Node<int>();
	b->key = 9;
	a->insert(a->root,b);
	b->key = 6;
	a->insert(a->root,b);
	b->key = 8;
	a->insert(a->root, b);
	b->key = 2;
	a->insert(a->root, b);
	b->key = 4;
	a->insert(a->root, b);
	b->key = 0;
	a->insert(a->root, b);
	b->key = 5;
	a->insert(a->root, b);
	b->key = 1;
	a->insert(a->root, b);
	b->key = 7;
	a->insert(a->root, b);
	b->key = 100;
	ASSERT_ANY_THROW (a->FindPrevious(a->root, b));
}

TEST(bintree, proverka_getHeight)
{
	bintree<int> *a = new bintree<int>();
	Node<int> *b = new Node<int>();
	b->key = 9;
	a->insert(a->root,b);
	b->key = 6;
	a->insert(a->root,b);
	b->key = 8;
	a->insert(a->root, b);
	b->key = 2;
	a->insert(a->root, b);
	b->key = 4;
	a->insert(a->root, b);
	b->key = 0;
	a->insert(a->root, b);
	b->key = 5;
	a->insert(a->root, b);
	b->key = 1;
	a->insert(a->root, b);
	b->key = 7;
	a->insert(a->root, b);
	EXPECT_EQ (a->getHeight(a->root), 4);
}


TEST(avl, iusf)
{
	AVL<int> *tmp = new AVL<int>;
	tmp->insert(1);
	tmp->insert(2);
	tmp->insert(3);
}