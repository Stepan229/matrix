#include "../test.h"

START_TEST(mult_matrix_1) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t result1;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &result1);

  char str1[] = "1, 2, 3, 4";
  char str2[] = "5, 6, 7, 8";
  char str3[] = "19, 22, 43, 50";

  matrix_from_string(str1, &A);
  matrix_from_string(str2, &B);
  matrix_from_string(str3, &result1);

  s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(s21_eq_matrix(&result1, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result1);
}
END_TEST

START_TEST(mult_matrix_2) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t result1;

  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &B);
  s21_create_matrix(2, 2, &result1);

  char str1[] = "2, -3, 1, 5, 4, -2";
  char str2[] = "-7, 5, 2, -1, 4, 3";
  char str3[] = "-16, 16, -35, 15";

  matrix_from_string(str1, &A);
  matrix_from_string(str2, &B);
  matrix_from_string(str3, &result1);

  s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(s21_eq_matrix(&result1, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result1);
}
END_TEST

START_TEST(mult_matrix_3) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t result1;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &result1);

  char str1[] = "1, 2, 3, 4, 5, 6, 7, 8, 9";
  char str2[] = "1, 1, 2, 1, 0, 3, 1, 0, -4";
  char str3[] = "6, 1, -4, 15, 4, -1, 24, 7, 2";

  matrix_from_string(str1, &A);
  matrix_from_string(str2, &B);
  matrix_from_string(str3, &result1);

  s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(s21_eq_matrix(&result1, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result1);
}
END_TEST

START_TEST(mult_matrix_4) {
  ck_assert_int_eq(s21_mult_matrix(NULL, NULL, NULL), 1);
}
END_TEST

START_TEST(mult_matrix_5) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(2, 3, &B);

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &B), 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *mult_matrix(void) {
  Suite *s = suite_create("mult_matrix");
  TCase *tc = tcase_create("mult_matrix");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, mult_matrix_1);
  tcase_add_test(tc, mult_matrix_2);
  tcase_add_test(tc, mult_matrix_3);
  tcase_add_test(tc, mult_matrix_4);
  tcase_add_test(tc, mult_matrix_5);

  return s;
}