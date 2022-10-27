#include "test_s21_matrix.h"

START_TEST(eq_test_1) {
  matrix_t A, B;
  int err_A = s21_create_matrix(1, 1, &A);
  int err_B = s21_create_matrix(1, 1, &B);

  A.matrix[0][0] = 1.25;
  B.matrix[0][0] = 2.25;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_test_2) {
  matrix_t A, B;
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

  B.matrix[0][0] = 0.25;
  B.matrix[0][1] = 1.25;
  B.matrix[0][2] = 2.25;
  B.matrix[1][0] = 3.25;
  B.matrix[1][1] = 4.25;
  B.matrix[1][2] = 5.25;
  B.matrix[2][0] = 6.25;
  B.matrix[2][1] = 7.25;
  B.matrix[2][2] = 8.25;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 1);
  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_test_3) {
  matrix_t A, B;
  int err_A = s21_create_matrix(1, 1, &A);
  int err_B = s21_create_matrix(1, 1, &B);

  A.matrix[0][0] = 1.25;
  B.matrix[0][0] = 2.25;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_test_4) {
  matrix_t A, B;
  int err_A = s21_create_matrix(5, 7, &A);
  int err_B = s21_create_matrix(3, 2, &B);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_test_5) {
  matrix_t A, B;
  int err_A = s21_create_matrix(5, 7, &A);
  int err_B = s21_create_matrix(5, 2, &B);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_test_6) {
  matrix_t A, B;
  int err_A = s21_create_matrix(1, 1, &A);
  int err_B = s21_create_matrix(1, 1, &B);

  A.matrix[0][0] = 10.2500001;

  B.matrix[0][0] = 10.2500002;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_test_7) {
  matrix_t A, B;
  int err_A = s21_create_matrix(1, 1, &A);
  int err_B = s21_create_matrix(1, 1, &B);

  A.matrix[0][0] = 10.25000002;

  B.matrix[0][0] = 10.25000001;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 1);
  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_test_8) {
  matrix_t A, B;
  int err_A = s21_create_matrix(1, 1, &A);
  int err_B = s21_create_matrix(1, 1, &B);

  A.matrix[0][0] = 10.2500002;

  B.matrix[0][0] = 10.2500001;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  if (!err_A) s21_remove_matrix(&A);
  if (!err_B) s21_remove_matrix(&B);
}
END_TEST

Suite *suite_s21_eq_matrix(void) {
  Suite *s = suite_create("suite_s21_eq_matrix");
  TCase *tc = tcase_create("s21_eq_matrix");

  tcase_add_test(tc, eq_test_1);
  tcase_add_test(tc, eq_test_2);
  tcase_add_test(tc, eq_test_3);
  tcase_add_test(tc, eq_test_4);
  tcase_add_test(tc, eq_test_5);
  tcase_add_test(tc, eq_test_6);
  tcase_add_test(tc, eq_test_7);
  tcase_add_test(tc, eq_test_8);

  suite_add_tcase(s, tc);
  return s;
}
