#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int err = OK;
  if (!A || A->rows < 1 || A->columns < 1) {
    err = MATRIX_ERROR;
  } else if (A->rows != A->columns) {
    err = CALC_ERROR;
  } else {
    double det;
    err = determinant(A, &det);
    if (!err) *result = det;
  }
  return err;
}

double determinant(matrix_t *A, double *det) {
  int err = 0;
  *det = 0;
  if (A->rows == 1 && A->columns == 1) {
    *det = A->matrix[0][0];
  } else if (A->rows == 2 && A->columns == 2) {
    *det =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    matrix_t temp;
    if (!err) {
      float sign;
      double det_temp;
      for (int j = 0; j < A->columns; j++) {
        int err = s21_create_matrix(A->rows - 1, A->columns - 1, &temp);
        sign = j % 2 == 0 ? 1 : -1;
        matrix_downgrade(A, &temp, 0, j);
        err = determinant(&temp, &det_temp);
        s21_remove_matrix(&temp);
        if (!err)
          *det += sign * det_temp * A->matrix[0][j];
        else
          break;
      }
    }
  }
  return err;
}

void matrix_downgrade(matrix_t *in, matrix_t *out, int i_del, int j_del) {
  int n = 0, m;
  for (int i = 0; i < in->rows; i++) {
    if (i != i_del) {
      m = 0;
      for (int j = 0; j < in->columns; j++) {
        if (j != j_del) {
          out->matrix[n][m++] = in->matrix[i][j];
        }
      }
      n++;
    }
  }
}
