#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int err = OK;
  if (!A || A->rows < 1 || A->columns < 1 || !A->matrix || !B || B->rows < 1 ||
      B->columns < 1 || !B->matrix || !result) {
    err = MATRIX_ERROR;
  } else if (A->columns != B->rows) {
    err = CALC_ERROR;
  }
  if (!err) err = s21_create_matrix(A->rows, B->columns, result);
  if (!err) {
    for (int m = 0; m < A->rows; m++) {
      for (int n = 0; n < B->columns; n++) {
        result->matrix[m][n] = 0;
        for (int k = 0; k < A->columns; k++) {
          if (A->matrix[m][k] != A->matrix[m][k] ||
              B->matrix[k][n] != B->matrix[k][n]) {
            err = CALC_ERROR;
            break;
          }
          result->matrix[m][n] += A->matrix[m][k] * B->matrix[k][n];
        }
        if (err) break;
      }
      if (err) break;
    }
    if (err == 2) s21_remove_matrix(result);
  }
  return err;
}
