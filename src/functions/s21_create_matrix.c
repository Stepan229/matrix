#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = 0;
  if (result == NULL)
    error = INCORRECT;
  else if (rows > 0 && columns > 0) {
    result->columns = columns;
    result->rows = rows;
    result->matrix = (double **)calloc(rows, sizeof(int *));
    result->matrix[0] = (double *)calloc(rows * columns, sizeof(double));
    for (int i = 1; i < rows; i++) {
      result->matrix[i] = result->matrix[0] + i * columns;
    }
  } else
    error = CALCULATION;
  return error;
}
