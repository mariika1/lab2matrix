#include "TVector.h"
#include <gtest.h>

TEST(TVector, can_create_vector)
{
	ASSERT_NO_THROW(TVector<int> V(5));
}

TEST(TVector, throws_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TVector<int> V(-5));
}

TEST(TVector, throws_create_vector_with_negative_startindex)
{
	ASSERT_ANY_THROW(TVector<int> V(5, -1));
}

TEST(TVector, can_create_copied_vector)
{
	TVector<int> V(5);

	ASSERT_NO_THROW(TVector<int> V1(V));
}

TEST(TVector, can_get_size)
{
	TVector<int> V(5);

	EXPECT_EQ(5, V.GetSize());
}

TEST(TVector, can_get_start_index)
{
	TVector<int> V(5, 1);

	EXPECT_EQ(1, V.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
	TVector<int> V(5);
	V[0] = 2;

	EXPECT_EQ(2, V[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> V(5);
	ASSERT_ANY_THROW(V[-1] = 1;);
}

TEST(TVector, compare_equal_vectors)
{
	TVector<int> V(5), V1(5);
	for (int i = 0; i < 5; i++)
		V[i] = 1;
	for (int i = 0; i < 5; i++)
		V1[i] = 1;
	EXPECT_EQ(1, V1 == V);
}

TEST(TVector, compare_vector_with_itself)
{
	TVector<int> V(5);
	for (int i = 0; i < 5; i++)
		V[i] = 1;
	EXPECT_EQ(1, V == V);
}

TEST(TVector, vectors_are_not_equal)
{
	TVector<int> V(5), V1(3);
	EXPECT_NE(1, V == V1);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> V(5);
	for (int i = 0; i < 5; i++)
		V[i] = 1;
	TVector<int> SUM(5);
	SUM = V + 2;
	TVector<int> RES(5);
	for (int i = 0; i < 5; i++)
		RES[i] = 3;
	EXPECT_EQ(1, SUM == RES);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> V(5);
	for (int i = 0; i < 5; i++)
		V[i] = 3;
	TVector<int> SUB(5);
	SUB = V - 2;
	TVector<int> RES(5);
	for (int i = 0; i < 5; i++)
		RES[i] = 1;
	EXPECT_EQ(1, SUB == RES);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> V(5);
	for (int i = 0; i < 5; i++)
		V[i] = 3;
	TVector<int> MUL(5);
	MUL = V * 2;
	TVector<int> RES(5);
	for (int i = 0; i < 5; i++)
		RES[i] = 6;
	EXPECT_EQ(1, MUL == RES);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> V1(3), V2(3);
	V1[0] = 1; V1[1] = 2; V1[2] = 3;
	V2[0] = 2; V2[1] = 3; V2[2] = 4;
	TVector<int> SUM(3);
	SUM = V1 + V2;
	TVector<int> RES(3);
	RES[0] = 3; RES[1] = 5; RES[2] = 7;
	EXPECT_EQ(1, SUM == RES);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> V1(5), V2(3);
	ASSERT_ANY_THROW(V1 + V2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> V1(3), V2(3);
	V1[0] = 1; V1[1] = 2; V1[2] = 3;
	V2[0] = 2; V2[1] = 3; V2[2] = 4;
	TVector<int> SUB(3);
	SUB = V2 - V1;
	TVector<int> RES(3);
	RES[0] = 1; RES[1] = 1; RES[2] = 1;
	EXPECT_EQ(1, SUB == RES);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> V1(5), V2(3);
	ASSERT_ANY_THROW(V1 - V2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> V1(3), V2(3);
	V1[0] = 1; V1[1] = 2; V1[2] = 3;
	V2[0] = 2; V2[1] = 3; V2[2] = 4;
	int MUL;
	MUL = V1 * V2;
	int RES = 20;
	EXPECT_EQ(1, MUL == RES);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> V1(5), V2(3);
	ASSERT_ANY_THROW(V1 * V2);
}