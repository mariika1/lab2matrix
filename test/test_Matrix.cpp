#include "TMatrix.h"
#include "TVector.h"
#include <gtest.h>


TEST(TMatrix, can_create_matrix)
{
  ASSERT_NO_THROW(TMatrix<int> M(5));

}

TEST(TMatrix, throws_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> M(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> M(5);

  ASSERT_NO_THROW(TMatrix<int> M1(M));
}

TEST(TMatrix, can_get_size)
{
  TMatrix<int> M(5);
  ASSERT_NO_THROW(M.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
  TMatrix<int> M(5);
  M[1][1] = 1;
  EXPECT_EQ(1, M[1][1]);
}

TEST(TMatrix, throws_set_element_with_negative_index)
{
  TMatrix<int> M(5);
  ASSERT_ANY_THROW(M[1][-1] = 1);
}

TEST(TMatrix, compare_equal_matrices)
{
  TMatrix<int> M1(5), M2(5);
  EXPECT_EQ(1, M1 == M2);
}

TEST(TMatrix, compare_matrix_with_itself)
{
  TMatrix<int> M(5);
  EXPECT_EQ(1, M == M);
}

TEST(TMatrix, matrices_with_different_size)
{
  TMatrix<int> M1(5), M2(3);
  EXPECT_NE(1, M1 == M2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
  TMatrix<int> M1(2), M2(2);
  TMatrix<int> SUM(2);
  M1[0][0] = 1;
  M2[0][0] = 2;
  SUM = M1 + M2;
  TMatrix<int> RES(2);
  RES[0][0] = 3;
  EXPECT_EQ(1, SUM == RES);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
  TMatrix<int> M1(5), M2(3);
  ASSERT_ANY_THROW(M1 + M2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
  TMatrix<int> M1(2), M2(2);
  TMatrix<int> SUB(2);
  M1[0][0] = 1;
  M2[0][0] = 2;
  SUB = M1 - M2;
  TMatrix<int> RES(2);
  RES[0][0] = -1;
  EXPECT_EQ(1, SUB == RES);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  TMatrix<int> M1(5), M2(3);
  ASSERT_ANY_THROW(M1 - M2);
}