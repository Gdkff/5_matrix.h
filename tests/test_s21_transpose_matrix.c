#include "test_s21_matrix.h"

START_TEST(transpose_test_1) {
  matrix_t A, B, R;
  int err_A = s21_create_matrix(1, 1, &A);
  int err_B = s21_create_matrix(1, 1, &B);

  A.matrix[0][0] = 1.25;
  B.matrix[0][0] = 1.25;

  int err_R = s21_transpose(&A, &R);
  ck_assert_int_eq(s21_eq_matrix(&R, &B), 1);
  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
  if (!err_R) s21_remove_matrix(&R);
}
END_TEST

START_TEST(transpose_test_2) {
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

  int err_R = s21_transpose(&A, &R);

  B.matrix[0][0] = 0.25;
  B.matrix[1][0] = 1.25;
  B.matrix[2][0] = 2.25;
  B.matrix[0][1] = 3.25;
  B.matrix[1][1] = 4.25;
  B.matrix[2][1] = 5.25;
  B.matrix[0][2] = 6.25;
  B.matrix[1][2] = 7.25;
  B.matrix[2][2] = 8.25;

  ck_assert_int_eq(s21_eq_matrix(&R, &B), 1);
  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
  if (!err_R) s21_remove_matrix(&R);
}
END_TEST

START_TEST(transpose_test_3) {
  matrix_t A, R;
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

  int err_R = s21_transpose(&A, &R);
  ck_assert_int_eq(err_R, 1);

  A.rows = 3;
  if (!err_A) s21_remove_matrix(&A);
  if (!err_R) s21_remove_matrix(&R);
}
END_TEST

START_TEST(transpose_test_4) {
  matrix_t A, R;
  int err_A = s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 0.25;
  A.matrix[0][1] = 1.25;
  A.matrix[0][2] = NAN;
  A.matrix[1][0] = 3.25;
  A.matrix[1][1] = 4.25;
  A.matrix[1][2] = 5.25;
  A.matrix[2][0] = 6.25;
  A.matrix[2][1] = 7.25;
  A.matrix[2][2] = 8.25;

  int err_R = s21_transpose(&A, &R);
  ck_assert_int_eq(err_R, 2);

  if (!err_A) s21_remove_matrix(&A);
  if (!err_R) s21_remove_matrix(&R);
}
END_TEST

START_TEST(transpose_test_5) {
  int err_R = s21_transpose(NULL, NULL);
  ck_assert_int_eq(err_R, 1);
}
END_TEST

Suite *suite_s21_transpose_matrix(void) {
  Suite *s = suite_create("suite_s21_transpose_matrix");
  TCase *tc = tcase_create("s21_transpose_matrix");

  tcase_add_test(tc, transpose_test_1);
  tcase_add_test(tc, transpose_test_2);
  tcase_add_test(tc, transpose_test_3);
  tcase_add_test(tc, transpose_test_4);
  tcase_add_test(tc, transpose_test_5);

  suite_add_tcase(s, tc);
  return s;
}
