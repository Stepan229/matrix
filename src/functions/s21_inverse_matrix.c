#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = OK;

  if (A == NULL || result == NULL)
    error = INCORRECT;
  else if (check_square_matrix(A) == 0) {
    double determinant = 0;
    s21_determinant(A, &determinant);
    if (determinant != 0) {
      matrix_t complement, transpos;
      s21_calc_complements(A, &complement);
      s21_transpose(&complement, &transpos);
      s21_mult_number(&transpos, 1 / determinant, result);
      s21_remove_matrix(&complement);
      s21_remove_matrix(&transpos);
    } else
      error = CALCULATION;
  } else
    error = CALCULATION;
  return error;
}
