#include <gtest.h>
#include "queue_bintree.h"

TEST(queue_bintree, can_create_queue_bintree)
{
	ASSERT_NO_THROW (BQueue<int> *a = new BQueue<int>);
}

TEST(queue_bintree, proverka_isempty)
{
	BQueue<int> *a = new BQueue<int>;
	EXPECT_EQ(a->isEmpty(), 1);
}

TEST(queue_bintree, proverka_push)
{
	BQueue<int> *a = new BQueue<int>;
	ASSERT_NO_THROW(a->push(1));
}

TEST(queue_bintree, proverka_popy)
{
	BQueue<int> *a = new BQueue<int>;
	a->push(1);
	ASSERT_NO_THROW(a->pop() );
}

TEST(queue_bintree, throw_if_pop_empty_tree)
{
	BQueue<int> *a = new BQueue<int>;
	ASSERT_ANY_THROW(a->pop() );
}

TEST(queue_bintree, can_top_queue)
{
	BQueue<int> *a = new BQueue<int>;
	a->push(1);
	ASSERT_NO_THROW(a->top() );
}

TEST(queue_bintree, throw_if_top_empty_tree)
{
	BQueue<int> *a = new BQueue<int>;
	ASSERT_ANY_THROW(a->top());
}

TEST(queue_bintree, can_print_queue)
{
	BQueue<int> *a = new BQueue<int>;
	ASSERT_NO_THROW (a->print() );
}

TEST(queue_bintree, can_getsize_queue)
{
	BQueue<int> *a = new BQueue<int>;
	ASSERT_NO_THROW (a->GetSize() );
}

TEST(queue_bintree, can_getsize_queue2)
{
	BQueue<int> *a = new BQueue<int>;
	a->push(1);
	EXPECT_EQ(1, a->GetSize());
}

TEST(queue_bintree, proverka_na_ravenstvo)
{
	BQueue<int> *a = new BQueue<int>;
	BQueue<int> *b = new BQueue<int>;
	a->push(1);
	b->push(1);
	int c = a->operator==(*b);
	EXPECT_EQ(c,1);
}

TEST(queue_bintree, can_gettree)
{
	BQueue<int> *a = new BQueue<int>;
	ASSERT_NO_THROW(a->getTree());
}

