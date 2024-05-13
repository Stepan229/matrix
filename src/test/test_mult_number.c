#include "../test.h"

START_TEST(mult_number_1) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  char str1[] = "1.5, 2, 3.5, 4";
  char str2[] = "3, 4, 7, 8";

  matrix_from_string(str1, &A);
  matrix_from_string(str2, &B);

  s21_mult_number(&A, 2.0, &result);

  ck_assert_int_eq(s21_eq_matrix(&B, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_2) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  s21_create_matrix(1, 4, &A);
  s21_create_matrix(1, 4, &B);

  char str1[] = "7.5, 3.1, 0, 5.6";
  char str2[] = "15, 6.2, 0, 11.2";

  matrix_from_string(str1, &A);
  matrix_from_string(str2, &B);

  s21_mult_number(&A, 2, &result);

  ck_assert_int_eq(s21_eq_matrix(&B, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_3) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  s21_create_matrix(4, 1, &A);
  s21_create_matrix(4, 1, &B);

  char str1[] = "7.5, 3.1, 0, 5.6";
  char str2[] = "15, 6.2, 0, 11.2";

  matrix_from_string(str1, &A);
  matrix_from_string(str2, &B);

  s21_mult_number(&A, 2, &result);

  ck_assert_int_eq(s21_eq_matrix(&B, &result), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_4) {
  ck_assert_int_eq(s21_mult_number(NULL, 2, NULL), 1);
}
END_TEST

START_TEST(mult_number_5) {
  matrix_t A;
  A.rows = -1;
  A.columns = -2;
  ck_assert_int_eq(s21_mult_number(&A, 2, &A), 2);
}
END_TEST

Suite *mult_number(void) {
  Suite *s = suite_create("mult_number");
  TCase *tc = tcase_create("mult_number");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, mult_number_1);
  tcase_add_test(tc, mult_number_2);
  tcase_add_test(tc, mult_number_3);
  tcase_add_test(tc, mult_number_4);
  tcase_add_test(tc, mult_number_5);

  return s;
}