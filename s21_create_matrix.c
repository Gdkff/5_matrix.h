#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int err = OK;
  if (!result || rows < 1 || columns < 1) {
    err = MATRIX_ERROR;
  }
  if (!err) {
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (!result->matrix) {
      err = MATRIX_ERROR;
    } else {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (!result->matrix[i]) exit(1);
      }
    }
  }
  if (!err) {
    result->rows = rows;
    result->columns = columns;
  }
  return err;
}
