#include "test_s21_matrix.h"

START_TEST(mult_matrix_test_1) {
  matrix_t A, B, R, R2;
  int err_A = s21_create_matrix(1, 1, &A);
  int err_B = s21_create_matrix(1, 1, &B);
  int err_R2 = s21_create_matrix(1, 1, &R2);

  A.matrix[0][0] = -1;
  B.matrix[0][0] = 2;
  R2.matrix[0][0] = -2;

  int err_R = s21_mult_matrix(&A, &B, &R);

  ck_assert_int_eq(s21_eq_matrix(&R, &R2), 1);
  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
  if (!err_R) s21_remove_matrix(&R);
  if (!err_R2) s21_remove_matrix(&R2);
}
END_TEST

START_TEST(mult_matrix_test_2) {
  matrix_t A, B, R, R2;
  int err_A = s21_create_matrix(3, 2, &A);
  int err_B = s21_create_matrix(2, 3, &B);
  int err_R2 = s21_create_matrix(3, 3, &R2);

  A.matrix[0][0] = 0;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  A.matrix[2][0] = 6;
  A.matrix[2][1] = 7;

  B.matrix[0][0] = 9;
  B.matrix[0][1] = 8;
  B.matrix[0][2] = 7;
  B.matrix[1][0] = 6;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 4;

  R2.matrix[0][0] = 6;
  R2.matrix[0][1] = 5;
  R2.matrix[0][2] = 4;
  R2.matrix[1][0] = 51;
  R2.matrix[1][1] = 44;
  R2.matrix[1][2] = 37;
  R2.matrix[2][0] = 96;
  R2.matrix[2][1] = 83;
  R2.matrix[2][2] = 70;

  int err_R = s21_mult_matrix(&A, &B, &R);

  ck_assert_int_eq(s21_eq_matrix(&R, &R2), 1);
  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
  if (!err_R) s21_remove_matrix(&R);
  if (!err_R2) s21_remove_matrix(&R2);
}
END_TEST

START_TEST(mult_matrix_test_3) {
  matrix_t A, B, R;
  int err_A = s21_create_matrix(1, 1, &A);
  int err_B = s21_create_matrix(1, 1, &B);

  A.matrix[0][0] = NAN;
  B.matrix[0][0] = 2;

  int err_R = s21_mult_matrix(&A, &B, &R);

  ck_assert_int_eq(err_R, 2);
  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
  if (!err_R) s21_remove_matrix(&R);
}
END_TEST

START_TEST(mult_matrix_test_4) {
  matrix_t A, B, R;
  int err_A = s21_create_matrix(1, 1, &A);
  int err_B = s21_create_matrix(1, 1, &B);

  A.matrix[0][0] = 2;
  B.matrix[0][0] = NAN;

  int err_R = s21_mult_matrix(&A, &B, &R);

  ck_assert_int_eq(err_R, 2);
  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
  if (!err_R) s21_remove_matrix(&R);
}
END_TEST

START_TEST(mult_matrix_test_5) {
  matrix_t A, B, R;
  int err_A = s21_create_matrix(1, 1, &A);
  int err_B = s21_create_matrix(2, 2, &B);

  int err_R = s21_mult_matrix(&A, &B, &R);

  ck_assert_int_eq(err_R, 2);
  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
  if (!err_R) s21_remove_matrix(&R);
}
END_TEST

START_TEST(mult_matrix_test_6) {
  matrix_t A, B;
  int err_A = s21_create_matrix(1, 1, &A);
  int err_B = s21_create_matrix(1, 1, &B);

  int err_R = s21_mult_matrix(&A, &B, NULL);

  ck_assert_int_eq(err_R, 1);
  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_test_7) {
  matrix_t A;
  int err_A = s21_create_matrix(1, 1, &A);

  int err_R = s21_mult_matrix(&A, NULL, NULL);

  ck_assert_int_eq(err_R, 1);
  if (!err_A) s21_remove_matrix(&A);
}
END_TEST

START_TEST(mult_matrix_test_8) {
  int err_R = s21_mult_matrix(NULL, NULL, NULL);

  ck_assert_int_eq(err_R, 1);
}
END_TEST

START_TEST(mult_matrix_test_9) {
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

  int err_R = s21_mult_matrix(&A, &B, &R);
  ck_assert_int_eq(err_R, 1);

  A.rows = 3;

  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
  if (!err_R) s21_remove_matrix(&R);
}
END_TEST

Suite *suite_s21_mult_matrix(void) {
  Suite *s = suite_create("suite_s21_mult_matrix");
  TCase *tc = tcase_create("s21_mult_matrix");

  tcase_add_test(tc, mult_matrix_test_1);
  tcase_add_test(tc, mult_matrix_test_2);
  tcase_add_test(tc, mult_matrix_test_3);
  tcase_add_test(tc, mult_matrix_test_4);
  tcase_add_test(tc, mult_matrix_test_5);
  tcase_add_test(tc, mult_matrix_test_6);
  tcase_add_test(tc, mult_matrix_test_7);
  tcase_add_test(tc, mult_matrix_test_8);
  tcase_add_test(tc, mult_matrix_test_9);

  suite_add_tcase(s, tc);
  return s;
}
