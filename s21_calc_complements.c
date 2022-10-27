#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int err = OK;
  if (!A || A->rows < 1 || A->columns < 1) {
    err = MATRIX_ERROR;
  }
  if (!err) err = s21_create_matrix(A->rows, A->columns, result);
  if (!err) {
    if (A->rows == 1 && A->columns == 1) {
      result->matrix[0][0] = 1;
    } else {
      double det;
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          matrix_t temp;
          s21_create_matrix(A->rows - 1, A->columns - 1, &temp);
          matrix_downgrade(A, &temp, i, j);
          determinant(&temp, &det);
          result->matrix[i][j] = (i + j) % 2 == 0 ? det : -det;
          s21_remove_matrix(&temp);
        }
      }
    }
  }
  return err;
}
