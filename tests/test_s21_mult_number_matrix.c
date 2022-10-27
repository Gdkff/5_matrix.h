#include "test_s21_matrix.h"

START_TEST(mult_number_test_1) {
  matrix_t A, B, R;
  int err_A = s21_create_matrix(1, 1, &A);
  int err_B = s21_create_matrix(1, 1, &B);

  A.matrix[0][0] = 1.25;
  B.matrix[0][0] = -5;

  int err_R = s21_mult_number(&A, -4, &R);

  ck_assert_int_eq(s21_eq_matrix(&R, &B), 1);
  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
  if (!err_R) s21_remove_matrix(&R);
}
END_TEST

START_TEST(mult_number_test_2) {
  matrix_t A, R, R2;
  int err_A = s21_create_matrix(3, 3, &A);
  int err_R2 = s21_create_matrix(3, 3, &R2);

  A.matrix[0][0] = 0.25;
  A.matrix[0][1] = 1.25;
  A.matrix[0][2] = 2.25;
  A.matrix[1][0] = 3.25;
  A.matrix[1][1] = 4.25;
  A.matrix[1][2] = 5.25;
  A.matrix[2][0] = 6.25;
  A.matrix[2][1] = 7.25;
  A.matrix[2][2] = 8.25;

  R2.matrix[0][0] = 1;
  R2.matrix[0][1] = 5;
  R2.matrix[0][2] = 9;
  R2.matrix[1][0] = 13;
  R2.matrix[1][1] = 17;
  R2.matrix[1][2] = 21;
  R2.matrix[2][0] = 25;
  R2.matrix[2][1] = 29;
  R2.matrix[2][2] = 33;

  int err_R = s21_mult_number(&A, 4, &R);

  ck_assert_double_eq_tol(R.matrix[0][0], R2.matrix[0][0], 1e-7);
  ck_assert_double_eq_tol(R.matrix[0][1], R2.matrix[0][1], 1e-7);
  ck_assert_double_eq_tol(R.matrix[0][2], R2.matrix[0][2], 1e-7);
  ck_assert_double_eq_tol(R.matrix[1][0], R2.matrix[1][0], 1e-7);
  ck_assert_double_eq_tol(R.matrix[1][1], R2.matrix[1][1], 1e-7);
  ck_assert_double_eq_tol(R.matrix[1][2], R2.matrix[1][2], 1e-7);
  ck_assert_double_eq_tol(R.matrix[2][0], R2.matrix[2][0], 1e-7);
  ck_assert_double_eq_tol(R.matrix[2][1], R2.matrix[2][1], 1e-7);
  ck_assert_double_eq_tol(R.matrix[2][2], R2.matrix[2][2], 1e-7);
  if (!err_A) s21_remove_matrix(&A);
  if (!err_R) s21_remove_matrix(&R);
  if (!err_R2) s21_remove_matrix(&R2);
}
END_TEST

START_TEST(mult_number_test_3) {
  matrix_t A, R;
  int err_A = s21_create_matrix(1, 1, &A);

  A.rows = 0;
  A.columns = 0;

  int err_R = s21_mult_number(&A, -4, &R);

  ck_assert_int_eq(err_R, 1);

  A.rows = 1;
  A.columns = 1;
  if (!err_A) s21_remove_matrix(&A);
  if (!err_R) s21_remove_matrix(&R);
}
END_TEST

START_TEST(mult_number_test_4) {
  int err_R = s21_mult_number(NULL, -4, NULL);

  ck_assert_int_eq(err_R, 1);
}
END_TEST

START_TEST(mult_number_test_5) {
  matrix_t A, R;
  int err_A = s21_create_matrix(1, 1, &A);

  A.matrix[0][0] = NAN;

  int err_R = s21_mult_number(&A, -4, &R);

  ck_assert_int_eq(err_R, 2);
  if (!err_A) s21_remove_matrix(&A);
  if (!err_R) s21_remove_matrix(&R);
}
END_TEST

START_TEST(mult_number_test_6) {
  matrix_t A, R;
  int err_A = s21_create_matrix(1, 1, &A);

  A.matrix[0][0] = 1.25;

  int err_R = s21_mult_number(&A, NAN, &R);

  ck_assert_int_eq(err_R, 2);

  if (!err_A) s21_remove_matrix(&A);
  if (!err_R) s21_remove_matrix(&R);
}
END_TEST

Suite *suite_s21_mult_number_matrix(void) {
  Suite *s = suite_create("suite_s21_mult_number_matrix");
  TCase *tc = tcase_create("s21_mult_number_matrix");

  tcase_add_test(tc, mult_number_test_1);
  tcase_add_test(tc, mult_number_test_2);
  tcase_add_test(tc, mult_number_test_3);
  tcase_add_test(tc, mult_number_test_4);
  tcase_add_test(tc, mult_number_test_5);
  tcase_add_test(tc, mult_number_test_6);

  suite_add_tcase(s, tc);
  return s;
}
