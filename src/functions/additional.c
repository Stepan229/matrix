#include "../s21_matrix.h"

void matrix_from_string(char *str, matrix_t *A) {
  double number = 0;
  int index = 0;

  char *delim = " ";
  char *ptr = strtok(str, delim);

  while (ptr != NULL) {
    sscanf(ptr, "%lf", &number);
    A->matrix[0][index] = number;
    ptr = strtok(NULL, delim);

    index++;
  }

  free(ptr);
}

int size_eq_matrix(matrix_t *A, matrix_t *B) {
  int ans = FAILURE;
  if (A->columns == B->columns && A->rows == B->rows) ans = SUCCESS;
  return ans;
}

int check_matrix(matrix_t *A) {
  int ans = OK;
  if (A->columns <= 0 || A->rows <= 0) ans = CALCULATION;
  return ans;
}

int check_square_matrix(matrix_t *A) {
  int ans = OK;
  if (A->columns != A->rows || A->columns <= 0 || A->rows <= 0)
    ans = CALCULATION;
  return ans;
}