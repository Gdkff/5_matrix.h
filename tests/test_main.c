#include "test_s21_matrix.h"

int main(void) {
  Suite *list_cases[] = {suite_s21_create_matrix(),
                         suite_s21_eq_matrix(),
                         suite_s21_sum_matrix(),
                         suite_s21_sub_matrix(),
                         suite_s21_mult_number_matrix(),
                         suite_s21_mult_matrix(),
                         suite_s21_transpose_matrix(),
                         suite_s21_calc_complements(),
                         suite_s21_determinant(),
                         suite_s21_inverse_matrix(),
                         NULL};

  for (Suite **current_testcase = list_cases; *current_testcase != NULL;
       current_testcase++) {
    SRunner *sr = srunner_create(*current_testcase);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    srunner_free(sr);
  }

  return 0;
}
