#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = OK;
  if (A == NULL || B == NULL || result == NULL)
    error = INCORRECT;
  else if (size_eq_matrix(A, B)) {
    int size_matrix = A->columns * A->rows;
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < size_matrix; i++) {
      result->matrix[0][i] = A->matrix[0][i] - B->matrix[0][i];
    }
  } else
    error = CALCULATION;
  return error;
}