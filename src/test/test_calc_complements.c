#include "../test.h"

START_TEST(calc_complements_1) {
  matrix_t A, B, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  char str1[] = "1, 2, 3, 0, 4, 2, 5, 2, 1";
  char str2[] = "0 10 -20 4 -14 8 -8 -2 4";

  matrix_from_string(str1, &A);
  matrix_from_string(str2, &B);

  s21_calc_complements(&A, &result);
  ck_assert_int_eq(s21_eq_matrix(&result, &B), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements_2) {
  ck_assert_int_eq(s21_calc_complements(NULL, NULL), INCORRECT);
}
END_TEST

START_TEST(calc_complements_3) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  char str1[] = "4 3 6 3";
  char str2[] = "3 -6 -3 4";

  matrix_from_string(str1, &A);
  matrix_from_string(str2, &B);

  s21_calc_complements(&A, &result);
  ck_assert_int_eq(s21_eq_matrix(&result, &B), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements_4) {
  matrix_t A, result;
  s21_create_matrix(1, 4, &A);

  char str1[] = "4 3 6 3";

  matrix_from_string(str1, &A);

  ck_assert_int_eq(s21_calc_complements(&A, &result), 2);

  s21_remove_matrix(&A);
  // s21_remove_matrix(&result);
}
END_TEST

Suite *calc_complements(void) {
  Suite *s = suite_create("calc_complements");
  TCase *tc = tcase_create("calc_complements");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, calc_complements_1);
  tcase_add_test(tc, calc_complements_2);
  tcase_add_test(tc, calc_complements_3);
  tcase_add_test(tc, calc_complements_4);

  return s;
}