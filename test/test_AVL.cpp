#include <gtest.h>
#include "AVL.h"

TEST(AVL, can_create_avl)
{
	ASSERT_NO_THROW(AVL<int> *a = new AVL<int>());
}

TEST(AVL, can_copy_avl)
{
	AVL<int> *a = new AVL<int>;
	ASSERT_NO_THROW(AVL<int> *b = new AVL<int>(*a));
}

TEST(AVL, can_insert_in_tree)
{
	AVL<int> *a = new AVL<int>;
	ASSERT_NO_THROW(a->insert(1));
}

TEST(AVL, can_delete_elem)
{
	AVL<int> *a = new AVL<int>;
	a->insert(5);
	a->insert(3);
	a->insert(7);	
	ASSERT_NO_THROW(a->Delete(3));
}

TEST(AVL, throw_if_delet_uncorrect)
{
	AVL<int> *a = new AVL<int>;
	a->insert(1);
	ASSERT_ANY_THROW(a->Delete(5));
}

TEST(AVL, can_get_bfactor)
{
	AVL<int> *a = new AVL<int>;
	ASSERT_NO_THROW(a->BFactor(a->root));
}

TEST(AVL, can_get_bfactor2)
{
	AVL<int> *a = new AVL<int>;
	a->insert(5);
	a->insert(3);
	a->insert(7);
	EXPECT_EQ(a->BFactor(a->root), 1);
}

TEST(AVL, can_rotate_right)
{
	AVL<int> *a = new AVL<int>;
	a->insert(5);
	a->insert(3);
	a->insert(7);
	ASSERT_NO_THROW(a->rotateRight(a->root));
}

TEST(AVL, can_rotate_left)
{
	AVL<int> *a = new AVL<int>;
	a->insert(5);
	a->insert(3);
	a->insert(7);
	ASSERT_NO_THROW(a->rotateLeft(a->root));
}

TEST(AVL, can_balanced_tree)
{
	AVL<int> *a = new AVL<int>;
	a->insert(5);
	a->insert(3);
	a->insert(7);
	ASSERT_NO_THROW(a->Balance(a->root));
}

TEST(AVL, can_copy_tree)
{
	AVL<int> *a = new AVL<int>;
	a->insert(5);
	a->insert(3);
	a->insert(7);
	AVL<int> *b = new AVL<int>;
	ASSERT_NO_THROW(b->CopyTree(a->root));
}

TEST(AVL, can_copy_tree2)
{
	AVL<int> *a = new AVL<int>;
	a->insert(5);
	a->insert(3);
	a->insert(7);
	AVL<int> *b = new AVL<int>;
	b->CopyTree(a->root);
	int c = a->operator==(*b);
	EXPECT_EQ(c,0);
}

TEST(AVL, can_find_key)
{
	AVL<int> *a = new AVL<int>;
	a->insert(5);
	a->insert(3);
	a->insert(7);
	ASSERT_NO_THROW(a->Findkey(a->root, 3));
}

TEST(AVL, can_find_key2)
{
	AVL<int> *a = new AVL<int>;
	a->insert(5);
	a->insert(3);
	a->insert(7);
	Node<int> *b = new Node<int>;
	b = a->Findkey(a->root, 3);
	EXPECT_EQ(b->key, 3);
}

TEST(AVL, can_findmax)
{
	AVL<int> *a = new AVL<int>;
	a->insert(5);
	a->insert(3);
	a->insert(7);
	ASSERT_NO_THROW(a->FindMax(a->root));
}

TEST(AVL, can_findmax2)
{
	AVL<int> *a = new AVL<int>;
	a->insert(5);
	a->insert(3);
	a->insert(7);
	Node<int> *b = new Node<int>;
	b = a->FindMax(a->root);
	EXPECT_EQ(7,b->key);
}

TEST(AVL, can_findmin)
{
	AVL<int> *a = new AVL<int>;
	a->insert(5);
	a->insert(3);
	a->insert(7);
	ASSERT_NO_THROW(a->FindMin(a->root));
}

TEST(AVL, can_findmin2)
{
	AVL<int> *a = new AVL<int>;
	a->insert(5);
	a->insert(3);
	a->insert(7);
	Node<int> *b = new Node<int>;
	b = a->FindMin(a->root);
	EXPECT_EQ(3,b->key);
}

TEST(AVL, can_findnext)
{
	AVL<int> *a = new AVL<int>;
	a->insert(5);
	a->insert(3);
	a->insert(7);
	Node<int> *tmp = new Node<int>(5);
	ASSERT_NO_THROW(a->FindNext(a->root,tmp));
}

TEST(AVL, can_findnext2)
{
	AVL<int> *a = new AVL<int>;
	a->insert(5);
	a->insert(3);
	a->insert(7);
	Node<int> *tmp = new Node<int>(5);
	Node<int> *b = new Node<int>;
	b = a->FindNext(a->root, tmp);
	EXPECT_EQ(b->key, 7);
}

TEST(AVL, can_findprevious)
{
	AVL<int> *a = new AVL<int>;
	a->insert(5);
	a->insert(3);
	a->insert(7);
	Node<int> *tmp = new Node<int>(5);
	ASSERT_NO_THROW(a->FindPrevious(a->root,tmp));
}

TEST(AVL, can_findprevious2)
{
	AVL<int> *a = new AVL<int>;
	a->insert(5);
	a->insert(3);
	a->insert(7);
	Node<int> *tmp = new Node<int>(5);
	Node<int> *b = new Node<int>;
	b = a->FindPrevious(a->root, tmp);
	EXPECT_EQ(b->key, 3);
}

TEST(AVL, can_workAroundAcross)
{
	AVL<int> *a = new AVL<int>;
	ASSERT_NO_THROW(a->workAroundAcross(a->root));
}

TEST(AVL, can_workAroundForward)
{
	AVL<int> *a = new AVL<int>;
	ASSERT_NO_THROW(a->workAroundForward(a->root));
}

TEST(AVL, can_workAroundReverse)
{
	AVL<int> *a = new AVL<int>;
	ASSERT_NO_THROW(a->workAroundReverse(a->root));
}

TEST(AVL, can_workAroundSymmetr)
{
	AVL<int> *a = new AVL<int>;
	ASSERT_NO_THROW(a->workAroundSymmetr(a->root));
}

TEST(AVL, can_workAroundDepth)
{
	AVL<int> *a = new AVL<int>;
	ASSERT_NO_THROW(a->workAroundDepth(a->root));
}

