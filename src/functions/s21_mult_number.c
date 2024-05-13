#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error = OK;
  if (A == NULL || result == NULL)
    error = INCORRECT;
  else if (check_matrix(A) == 0) {
    int size_matrix = A->columns * A->rows;
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < size_matrix; i++)
      result->matrix[0][i] = A->matrix[0][i] * number;
  } else
    error = CALCULATION;
  return error;
}