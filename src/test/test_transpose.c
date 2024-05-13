#include "../test.h"

START_TEST(transpose_1) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);

  char str1[] = "1, 4, 2, 5, 3, 6";
  char str2[] = "1, 2, 3, 4, 5, 6";

  matrix_from_string(str1, &A);
  matrix_from_string(str2, &B);

  s21_transpose(&A, &result);

  ck_assert_int_eq(s21_eq_matrix(&result, &B), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_2) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &B);

  char str1[] = "1, 2, 3, 4, 5, 6";
  char str2[] = "1, 4, 2, 5, 3, 6";

  matrix_from_string(str1, &A);
  matrix_from_string(str2, &B);

  s21_transpose(&A, &result);

  ck_assert_int_eq(s21_eq_matrix(&result, &B), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_3) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  char str1[] = "1, 4, 2, 5";
  char str2[] = "1, 2, 4, 5";

  matrix_from_string(str1, &A);
  matrix_from_string(str2, &B);

  s21_transpose(&A, &result);

  ck_assert_int_eq(s21_eq_matrix(&result, &B), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_4) { ck_assert_int_eq(s21_transpose(NULL, NULL), 1); }
END_TEST

Suite *transpose(void) {
  Suite *s = suite_create("transpose");
  TCase *tc = tcase_create("transpose");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, transpose_1);
  tcase_add_test(tc, transpose_2);
  tcase_add_test(tc, transpose_3);
  tcase_add_test(tc, transpose_4);

  return s;
}