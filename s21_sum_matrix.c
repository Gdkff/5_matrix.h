#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int err = OK;
  if (!A || A->rows < 1 || A->columns < 1 || !A->matrix || !B || B->rows < 1 ||
      B->columns < 1 || !B->matrix || !result) {
    err = MATRIX_ERROR;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    err = CALC_ERROR;
  }
  if (!err) err = s21_create_matrix(A->rows, A->columns, result);
  if (!err) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (A->matrix[i][j] != A->matrix[i][j] ||
            B->matrix[i][j] != B->matrix[i][j]) {
          err = CALC_ERROR;
          break;
        }
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
      if (err) break;
    }
    if (err == CALC_ERROR) s21_remove_matrix(result);
  }
  return err;
}
