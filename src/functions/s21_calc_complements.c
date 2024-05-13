#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = OK;
  if (A == NULL || result == NULL)
    error = INCORRECT;
  else if (check_square_matrix(A) == 0) {
    double determinant;
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        matrix_t minor;
        s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
        find_minor(A, &minor, i, j);
        s21_determinant(&minor, &determinant);
        result->matrix[i][j] = (i + j) % 2 == 0 ? determinant : -determinant;
        s21_remove_matrix(&minor);
      }
    }
  } else
    error = CALCULATION;
  return error;
}

void find_minor(matrix_t *A, matrix_t *result, int row, int column) {
  int flag_column = 0;
  int flag_row = 0;
  for (int i = 0; i < A->rows; i++) {
    flag_column = 0;
    if (i != row) {
      for (int j = 0; j < A->columns; j++) {
        if (j == column) {
          // показывает прошёл ли цикл не нужную столбец
          flag_column = 1;
        } else
          result->matrix[i - flag_row][j - flag_column] = A->matrix[i][j];
      }
    } else
      flag_row = 1;
  }
}