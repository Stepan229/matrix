#include "../s21_matrix.h"

// проверка на квадратную матрицу
int s21_determinant(matrix_t *A, double *result) {
  int error = OK;
  if (result == NULL || A == NULL)
    error = INCORRECT;
  else if (check_square_matrix(A) == 0) {
    if (A->columns == 2) {
      *result = (A->matrix[0][0] * A->matrix[1][1] -
                 A->matrix[0][1] * A->matrix[1][0]);
    } else if (A->columns == 1) {
      *result = A->matrix[0][0];
    } else {
      for (int i_columns = 0; i_columns < A->columns; i_columns++) {
        matrix_t minor;
        double minor_determinant = 0;
        s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
        // find_minor(A, &minor, 1, i_columns);
        for (int i = 1; i < A->rows; i++) {
          int flag_columns = 0;
          for (int j = 0; j < A->columns; j++) {
            if (j == i_columns) {
              // показывает прошёл ли цикл не нужную столбец
              flag_columns = 1;
            } else
              minor.matrix[i - 1][j - flag_columns] = A->matrix[i][j];
          }
        }
        s21_determinant(&minor, &minor_determinant);
        *result = *result + A->matrix[0][i_columns] *
                                (pow(-1, 2 + i_columns) * minor_determinant);
        s21_remove_matrix(&minor);
      }
    }
  } else
    error = CALCULATION;
  return error;
}
