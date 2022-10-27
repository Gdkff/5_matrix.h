#include "test_s21_matrix.h"

START_TEST(create_matrix_test_1) {
  matrix_t A;
  int err_A = s21_create_matrix(0, 5, &A);

  ck_assert_int_eq(err_A, 1);
  if (!err_A) s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_matrix_test_2) {
  matrix_t A;
  int err_A = s21_create_matrix(5, 0, &A);

  ck_assert_int_eq(err_A, 1);
  if (!err_A) s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_matrix_test_3) {
  int err_A = s21_create_matrix(5, 0, NULL);
  ck_assert_int_eq(err_A, 1);
}
END_TEST

Suite *suite_s21_create_matrix(void) {
  Suite *s = suite_create("suite_s21_create_matrix");
  TCase *tc = tcase_create("s21_create_matrix");

  tcase_add_test(tc, create_matrix_test_1);
  tcase_add_test(tc, create_matrix_test_2);
  tcase_add_test(tc, create_matrix_test_3);

  suite_add_tcase(s, tc);
  return s;
}
