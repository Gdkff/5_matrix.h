#include "test_s21_matrix.h"

START_TEST(determinant_test_1) {
  matrix_t A;
  double B, R = 1.25;
  int err_A = s21_create_matrix(1, 1, &A);

  A.matrix[0][0] = 1.25;
  s21_determinant(&A, &B);

  ck_assert_double_eq_tol(B, R, 1e-7);
  if (!err_A) s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_2) {
  matrix_t A;
  double B, R = -69;
  int err_A = s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 0.25;
  A.matrix[0][1] = 1.25;
  A.matrix[0][2] = 2.25;
  A.matrix[1][0] = 3.25;
  A.matrix[1][1] = 10;
  A.matrix[1][2] = 5.25;
  A.matrix[2][0] = 6.25;
  A.matrix[2][1] = 7.25;
  A.matrix[2][2] = 8.25;

  s21_determinant(&A, &B);
  ck_assert_double_eq_tol(B, R, 1e-7);
  if (!err_A) s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_3) {
  matrix_t A;
  int err_A = s21_create_matrix(3, 5, &A);
  double B;
  int err_R = s21_determinant(&A, &B);
  ck_assert_int_eq(err_R, 2);
  if (!err_A) s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_4) {
  matrix_t A;
  int err_A = s21_create_matrix(1, 1, &A);
  A.rows = 0;
  A.columns = 0;
  double B;
  int err_R = s21_determinant(&A, &B);
  A.rows = 1;
  A.columns = 1;
  ck_assert_int_eq(err_R, 1);
  if (!err_A) s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_5) {
  matrix_t A;
  int err_A = s21_create_matrix(5, 1, &A);
  A.columns = 0;
  double B;
  int err_R = s21_determinant(&A, &B);
  A.columns = 1;
  ck_assert_int_eq(err_R, 1);
  if (!err_A) s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_6) {
  matrix_t A;
  int err_A = s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 0.25;
  A.matrix[0][1] = 1.25;
  A.matrix[0][2] = 2.25;
  A.matrix[1][0] = 3.25;
  A.matrix[1][1] = 4.25;
  A.matrix[1][2] = 5.25;
  A.matrix[2][0] = 6.25;
  A.matrix[2][1] = 7.25;
  A.matrix[2][2] = 8.25;

  A.rows = 0;
  double number = 10;

  int err = s21_determinant(&A, &number);
  ck_assert_int_eq(err, 1);

  A.rows = 3;
  if (!err_A) s21_remove_matrix(&A);
}
END_TEST

Suite *suite_s21_determinant(void) {
  Suite *s = suite_create("suite_s21_determinant");
  TCase *tc = tcase_create("s21_determinant");

  tcase_add_test(tc, determinant_test_1);
  tcase_add_test(tc, determinant_test_2);
  tcase_add_test(tc, determinant_test_3);
  tcase_add_test(tc, determinant_test_4);
  tcase_add_test(tc, determinant_test_5);
  tcase_add_test(tc, determinant_test_6);

  suite_add_tcase(s, tc);
  return s;
}
