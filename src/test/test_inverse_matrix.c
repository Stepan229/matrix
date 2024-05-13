#include "../test.h"

START_TEST(inverse_matrix_1) {
  matrix_t A, B, result;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  char str1[] = "2, 5, 7, 6, 3, 4, 5, -2, -3";
  char str2[] = "1, -1, 1, -38, 41, -34, 27, -29, 24";

  matrix_from_string(str1, &A);
  matrix_from_string(str2, &B);

  s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(s21_eq_matrix(&result, &B), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_2) {
  matrix_t A, B, result;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  char str1[] = "4, 3, 6, 3";
  char str2[] = "-0.5, 0.5, 1, -0.6666666666666666";

  matrix_from_string(str1, &A);
  matrix_from_string(str2, &B);

  s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(s21_eq_matrix(&result, &B), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_3) {
  matrix_t A, B, result;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  char str1[] = "1, 2, 3, 4";
  char str2[] = "-2, 1, 1.5, -0.5";

  matrix_from_string(str1, &A);
  matrix_from_string(str2, &B);

  s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(s21_eq_matrix(&result, &B), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_4) {
  ck_assert_int_eq(s21_inverse_matrix(NULL, NULL), 1);
}
END_TEST

START_TEST(inverse_matrix_5) {
  matrix_t A, B;

  s21_create_matrix(2, 3, &A);

  ck_assert_int_eq(s21_inverse_matrix(&A, &B), 2);

  s21_remove_matrix(&A);
}
END_TEST

Suite *inverse_matrix(void) {
  Suite *s = suite_create("inverse_matrix");
  TCase *tc = tcase_create("inverse_matrix");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, inverse_matrix_1);
  tcase_add_test(tc, inverse_matrix_2);
  tcase_add_test(tc, inverse_matrix_3);
  tcase_add_test(tc, inverse_matrix_4);
  tcase_add_test(tc, inverse_matrix_5);

  return s;
}