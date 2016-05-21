#include "gtest.h"
#include "hqueue.h"

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


TEST(queue, proverka_na_ravenstvo)
{
	HQueue<int> *a = new HQueue<int> (2);
	a->push(5);
	HQueue<int> *b = new HQueue<int> (2);
	b->push(5);
	int c = a->operator==(*b);
	EXPECT_EQ(c,1);
}
