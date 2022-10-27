#include "s21_matrix.h"
#define S21_EPS 1e-7

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int ret = SUCCESS;
  if (A->rows != B->rows || A->columns != B->columns) {
    ret = FAILURE;
  }
  if (ret) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= S21_EPS) {
          ret = FAILURE;
          break;
        }
      }
      if (!ret) break;
    }
  }
  return ret;
}
