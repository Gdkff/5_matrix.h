#include "test_s21_matrix.h"

START_TEST(sum_matrix_test_1) {
  matrix_t A, B, R, R2;
  int err_A = s21_create_matrix(1, 1, &A);
  int err_B = s21_create_matrix(1, 1, &B);
  int err_R2 = s21_create_matrix(1, 1, &R2);

  A.matrix[0][0] = 1.25;
  B.matrix[0][0] = 2.25;
  R2.matrix[0][0] = 3.5;

  int err_R = s21_sum_matrix(&A, &B, &R);

  ck_assert_double_eq_tol(R.matrix[0][0], R2.matrix[0][0], 1e-7);

  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
  if (!err_R) s21_remove_matrix(&R);
  if (!err_R2) s21_remove_matrix(&R2);
}
END_TEST

START_TEST(sum_matrix_test_2) {
  matrix_t A, B, R, R2;
  int err_A = s21_create_matrix(3, 3, &A);
  int err_B = s21_create_matrix(3, 3, &B);
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

  B.matrix[0][0] = 9.65;
  B.matrix[0][1] = 8.65;
  B.matrix[0][2] = 7.65;
  B.matrix[1][0] = 6.65;
  B.matrix[1][1] = 5.65;
  B.matrix[1][2] = 4.65;
  B.matrix[2][0] = 3.65;
  B.matrix[2][1] = 2.65;
  B.matrix[2][2] = 1.65;

  R2.matrix[0][0] = 9.9;
  R2.matrix[0][1] = 9.9;
  R2.matrix[0][2] = 9.9;
  R2.matrix[1][0] = 9.9;
  R2.matrix[1][1] = 9.9;
  R2.matrix[1][2] = 9.9;
  R2.matrix[2][0] = 9.9;
  R2.matrix[2][1] = 9.9;
  R2.matrix[2][2] = 9.9;

  int err_R = s21_sum_matrix(&A, &B, &R);

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
  if (!err_B) s21_remove_matrix(&B);
  if (!err_R) s21_remove_matrix(&R);
  if (!err_R2) s21_remove_matrix(&R2);
}
END_TEST

START_TEST(sum_matrix_test_3) {
  matrix_t A, B, R;
  int err_A = s21_create_matrix(1, 1, &A);
  int err_B = s21_create_matrix(1, 1, &B);

  A.matrix[0][0] = NAN;
  B.matrix[0][0] = 2;

  int err_R = s21_sum_matrix(&A, &B, &R);

  ck_assert_int_eq(err_R, 2);
  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
  if (!err_R) s21_remove_matrix(&R);
}
END_TEST

START_TEST(sum_matrix_test_4) {
  matrix_t A, B, R;
  int err_A = s21_create_matrix(1, 1, &A);
  int err_B = s21_create_matrix(1, 1, &B);

  A.matrix[0][0] = 2;
  B.matrix[0][0] = NAN;

  int err_R = s21_sum_matrix(&A, &B, &R);

  ck_assert_int_eq(err_R, 2);
  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
  if (!err_R) s21_remove_matrix(&R);
}
END_TEST

START_TEST(sum_matrix_test_5) {
  matrix_t A, B, R;
  int err_A = s21_create_matrix(1, 1, &A);
  int err_B = s21_create_matrix(2, 2, &B);

  int err_R = s21_sum_matrix(&A, &B, &R);

  ck_assert_int_eq(err_R, 2);
  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
  if (!err_R) s21_remove_matrix(&R);
}
END_TEST

START_TEST(sum_matrix_test_6) {
  matrix_t A, B;
  int err_A = s21_create_matrix(1, 1, &A);
  int err_B = s21_create_matrix(1, 1, &B);

  int err_R = s21_sum_matrix(&A, &B, NULL);

  ck_assert_int_eq(err_R, 1);
  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_test_7) {
  matrix_t A;
  int err_A = s21_create_matrix(1, 1, &A);

  int err_R = s21_sum_matrix(&A, NULL, NULL);

  ck_assert_int_eq(err_R, 1);
  if (!err_A) s21_remove_matrix(&A);
}
END_TEST

START_TEST(sum_matrix_test_8) {
  int err_R = s21_sum_matrix(NULL, NULL, NULL);

  ck_assert_int_eq(err_R, 1);
}
END_TEST

START_TEST(sum_matrix_test_9) {
  matrix_t A, B, R;
  int err_A = s21_create_matrix(3, 3, &A);
  int err_B = s21_create_matrix(3, 3, &B);

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

  B.matrix[0][0] = 0.25;
  B.matrix[0][1] = 1.25;
  B.matrix[0][2] = 2.25;
  B.matrix[1][0] = 3.25;
  B.matrix[1][1] = 4.25;
  B.matrix[1][2] = 5.25;
  B.matrix[2][0] = 6.25;
  B.matrix[2][1] = 7.25;
  B.matrix[2][2] = 8.25;

  int err_R = s21_sum_matrix(&A, &B, &R);
  ck_assert_int_eq(err_R, 1);

  A.rows = 3;
  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
  if (!err_R) s21_remove_matrix(&R);
}
END_TEST

START_TEST(sum_matrix_test_10) {
  matrix_t A, B, R;
  int err_A = s21_create_matrix(1, 1, &A);
  int err_B = s21_create_matrix(1, 1, &B);

  B.rows = 0;
  B.columns = 0;

  int err_R = s21_sum_matrix(&A, &B, &R);

  ck_assert_int_eq(err_R, 1);

  B.rows = 1;
  B.columns = 1;

  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
  if (!err_R) s21_remove_matrix(&R);
}
END_TEST

START_TEST(sum_matrix_test_11) {
  matrix_t A, B, R;
  int err_A = s21_create_matrix(1, 1, &A);
  int err_B = s21_create_matrix(1, 1, &B);
  A.rows = 0;
  A.columns = 0;
  B.rows = 0;
  B.columns = 0;

  int err_R = s21_sum_matrix(&A, &B, &R);

  ck_assert_int_eq(err_R, 1);
  A.rows = 1;
  A.columns = 1;
  B.rows = 1;
  B.columns = 1;

  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
  if (!err_R) s21_remove_matrix(&R);
}
END_TEST

Suite *suite_s21_sum_matrix(void) {
  Suite *s = suite_create("suite_s21_sum_matrix");
  TCase *tc = tcase_create("s21_sum_matrix");

  tcase_add_test(tc, sum_matrix_test_1);
  tcase_add_test(tc, sum_matrix_test_2);
  tcase_add_test(tc, sum_matrix_test_3);
  tcase_add_test(tc, sum_matrix_test_4);
  tcase_add_test(tc, sum_matrix_test_5);
  tcase_add_test(tc, sum_matrix_test_6);
  tcase_add_test(tc, sum_matrix_test_7);
  tcase_add_test(tc, sum_matrix_test_8);
  tcase_add_test(tc, sum_matrix_test_9);
  tcase_add_test(tc, sum_matrix_test_10);
  tcase_add_test(tc, sum_matrix_test_11);

  suite_add_tcase(s, tc);
  return s;
}
