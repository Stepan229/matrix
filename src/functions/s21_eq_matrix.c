#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int ans = SUCCESS;
  if (size_eq_matrix(A, B) || A == NULL || B == NULL) {
    int size_matrix = A->columns * A->rows;
    for (int i = 0; i < size_matrix; i++) {
      if (A->matrix[0][i] != B->matrix[0][i]) {
        ans = FAILURE;
        break;
      }
    }
  } else
    ans = FAILURE;
  return ans;
}

// Сюда можно добавить проверку на NULL
