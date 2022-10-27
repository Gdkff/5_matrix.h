#include "test_s21_matrix.h"

START_TEST(complements_1) {
  matrix_t A, B, R;
  int err_A = s21_create_matrix(3, 3, &A);
  int err_B = s21_create_matrix(3, 3, &B);

  A.matrix[0][0] = 5;
  A.matrix[0][1] = -1;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 3;

  int err_R = s21_calc_complements(&A, &R);

  B.matrix[0][0] = 9;
  B.matrix[0][1] = -2;
  B.matrix[0][2] = -3;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 14;
  B.matrix[1][2] = -1;
  B.matrix[2][0] = -7;
  B.matrix[2][1] = -18;
  B.matrix[2][2] = 17;

  ck_assert_int_eq(s21_eq_matrix(&R, &B), 1);
  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
  if (!err_R) s21_remove_matrix(&R);
}
END_TEST

START_TEST(complements_2) {
  matrix_t A, B, R;
  int err_A = s21_create_matrix(2, 2, &A);
  int err_B = s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 5;
  A.matrix[0][1] = -1;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 3;

  int err_R = s21_calc_complements(&A, &R);

  B.matrix[0][0] = 3;
  B.matrix[0][1] = -2;
  B.matrix[1][0] = 1;
  B.matrix[1][1] = 5;

  ck_assert_int_eq(s21_eq_matrix(&R, &B), 1);
  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
  if (!err_R) s21_remove_matrix(&R);
}
END_TEST

START_TEST(complements_3) {
  matrix_t A, B, R;
  int err_A = s21_create_matrix(1, 1, &A);
  int err_B = s21_create_matrix(1, 1, &B);

  A.matrix[0][0] = 5;
  int err_R = s21_calc_complements(&A, &R);

  B.matrix[0][0] = 1;

  ck_assert_int_eq(s21_eq_matrix(&R, &B), 1);
  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
  if (!err_R) s21_remove_matrix(&R);
}
END_TEST

START_TEST(complements_4) {
  matrix_t A;
  int err_A = s21_create_matrix(1, 1, &A);

  int err_R = s21_calc_complements(&A, NULL);

  ck_assert_int_eq(err_R, 1);
  if (!err_A) s21_remove_matrix(&A);
}
END_TEST

START_TEST(complements_5) {
  int err_R = s21_calc_complements(NULL, NULL);

  ck_assert_int_eq(err_R, 1);
}
END_TEST

Suite *suite_s21_calc_complements(void) {
  Suite *s = suite_create("suite_s21_calc_complements");
  TCase *tc = tcase_create("s21_calc_complements");

  tcase_add_test(tc, complements_1);
  tcase_add_test(tc, complements_2);
  tcase_add_test(tc, complements_3);
  tcase_add_test(tc, complements_4);
  tcase_add_test(tc, complements_5);

  suite_add_tcase(s, tc);
  return s;
}
