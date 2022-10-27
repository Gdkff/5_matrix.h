#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int err = OK;
  if (!A || A->rows < 1 || A->columns < 1) err = MATRIX_ERROR;
  if (!err) err = s21_create_matrix(A->columns, A->rows, result);
  if (!err) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (A->matrix[i][j] != A->matrix[i][j]) {
          err = CALC_ERROR;
          break;
        }
        result->matrix[j][i] = A->matrix[i][j];
      }
      if (err) break;
    }
    if (err == CALC_ERROR) s21_remove_matrix(result);
  }
  return err;
}
