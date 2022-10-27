#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int err = OK;
  if (!A || A->rows < 1 || A->columns < 1)
    err = MATRIX_ERROR;
  else if (number != number)
    err = CALC_ERROR;
  if (!err) err = s21_create_matrix(A->rows, A->columns, result);
  if (!err) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (A->matrix[i][j] != A->matrix[i][j]) {
          err = CALC_ERROR;
          break;
        }
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
      if (err) break;
    }
    if (err == 2) s21_remove_matrix(result);
  }
  return err;
}
