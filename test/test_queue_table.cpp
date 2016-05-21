#include "gtest.h"
#include "queue_table.h"

TEST(queue_table, can_create_queue_table)
{
	ASSERT_NO_THROW(TQueue<int> *a = new TQueue<int>(5) );
}

TEST(queue_table, throw_if_uncorrect_arn)
{
	ASSERT_ANY_THROW(TQueue<int> *a = new TQueue<int> (-1));
}

TEST(queue_table, proverka_isEmpty)
{
	TQueue<int> *a = new TQueue<int> (2);
	EXPECT_EQ (a->isEmpty(), 1);
}

TEST(queue_table, proverka_popa)
{
	TQueue<int> *a = new TQueue<int> (2);
	a->push(5,1);
	a->pop();
	EXPECT_EQ(a->isEmpty(), 1);
}

TEST(queue_table, throw_if_pop_iz_pustoi_queue_table)
{
	TQueue<int> *a = new TQueue<int> (2);
	ASSERT_ANY_THROW(a->pop());
}


TEST(queue_table, proverka_getsize)
{
	TQueue<int> *a = new TQueue<int> (2);
	EXPECT_EQ(a->GetSize(), 0);
}

TEST(queue_table, proverka_getsize2)
{
	TQueue<int> *a = new TQueue<int> (5);
	a->push(1,2);
	a->push(2,3);
	EXPECT_EQ(a->GetSize(), 2);
}

TEST(queue_table, can_getTable)
{
	TQueue<int> *a = new TQueue<int> (2);
	ASSERT_NO_THROW (a->getTable() );
}
