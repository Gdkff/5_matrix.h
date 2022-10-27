#include "test_s21_matrix.h"

START_TEST(inverse_test_1) {
  matrix_t A, B, R;
  int err_A = s21_create_matrix(1, 1, &A);
  int err_B = s21_create_matrix(1, 1, &B);

  A.matrix[0][0] = 1.25;
  B.matrix[0][0] = 0.8;

  int err_R = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(s21_eq_matrix(&R, &B), 1);

  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
  if (!err_R) s21_remove_matrix(&R);
}
END_TEST

START_TEST(inverse_test_2) {
  matrix_t A, B, R;
  int err_A = s21_create_matrix(3, 3, &A);
  int err_B = s21_create_matrix(3, 3, &B);

  A.matrix[0][0] = -1;
  A.matrix[0][1] = -10;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 10;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 1;
  A.matrix[2][2] = 1;

  int err_R = s21_inverse_matrix(&A, &R);

  B.matrix[0][0] = -0.5;
  B.matrix[0][1] = -11.0 / 18.0;
  B.matrix[0][2] = 10.0 / 9.0;
  B.matrix[1][0] = 0;
  B.matrix[1][1] = 1.0 / 9.0;
  B.matrix[1][2] = -1.0 / 9.0;
  B.matrix[2][0] = 0.5;
  B.matrix[2][1] = 0.5;
  B.matrix[2][2] = 0;

  ck_assert_int_eq(s21_eq_matrix(&R, &B), 1);
  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
  if (!err_R) s21_remove_matrix(&R);
}
END_TEST

START_TEST(inverse_test_3) {
  matrix_t A, R;
  int err_A = s21_create_matrix(1, 1, &A);

  A.rows = -1;
  A.columns = -1;

  int err_R = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(err_R, 1);
  A.rows = 1;
  A.columns = 1;
  if (!err_A) s21_remove_matrix(&A);
  if (!err_R) s21_remove_matrix(&R);
}
END_TEST

START_TEST(inverse_test_4) {
  matrix_t A, R;
  int err_A = s21_create_matrix(2, 5, &A);

  A.rows = -1;
  A.columns = -1;

  int err_R = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(err_R, 1);

  A.rows = 2;
  A.columns = 5;
  if (!err_A) s21_remove_matrix(&A);
  if (!err_R) s21_remove_matrix(&R);
}
END_TEST

START_TEST(inverse_test_5) {
  matrix_t A, R;
  int err_A = s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 1;
  A.matrix[2][2] = 1;

  int err_R = s21_inverse_matrix(&A, &R);

  ck_assert_int_eq(err_R, 2);
  if (!err_A) s21_remove_matrix(&A);
  if (!err_R) s21_remove_matrix(&R);
}
END_TEST

START_TEST(inverse_test_6) {
  matrix_t A, R;
  int err_A = s21_create_matrix(2, 2, &A);

  int err_R = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(err_R, 2);

  if (!err_A) s21_remove_matrix(&A);
  if (!err_R) s21_remove_matrix(&R);
}
END_TEST

Suite *suite_s21_inverse_matrix(void) {
  Suite *s = suite_create("suite_s21_inverse_matrix");
  TCase *tc = tcase_create("s21_inverse_matrix");

  tcase_add_test(tc, inverse_test_1);
  tcase_add_test(tc, inverse_test_2);
  tcase_add_test(tc, inverse_test_3);
  tcase_add_test(tc, inverse_test_4);
  tcase_add_test(tc, inverse_test_5);
  tcase_add_test(tc, inverse_test_6);

  suite_add_tcase(s, tc);
  return s;
}
