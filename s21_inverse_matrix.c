#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t* A, matrix_t* result) {
  double detr = 0;
  int err = OK;
  if (!A || A->rows < 1 || A->columns < 1) {
    err = MATRIX_ERROR;
  } else if (A->rows != A->columns) {
    err = CALC_ERROR;
  }
  int err_comp = 0, err_transp;
  if (!err) err = s21_determinant(A, &detr);
  if (!err && fabs(detr) < 1e-7) err = CALC_ERROR;
  matrix_t compl, transp;
  if (!err) err = err_comp = s21_calc_complements(A, &compl );
  if (!err) err = err_transp = s21_transpose(&compl, &transp);
  if (!err && !err_comp) s21_remove_matrix(&compl );
  if (!err) err = s21_mult_number(&transp, 1 / detr, result);
  if (!err && !err_transp) s21_remove_matrix(&transp);
  return err;
}
