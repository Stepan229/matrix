#include "../test.h"

START_TEST(determinant_1) {
  matrix_t A;
  double det = 0;
  s21_create_matrix(3, 3, &A);

  char str1[] = "1, 2, 3, 4, 5, 6, 7, 8, 9";

  matrix_from_string(str1, &A);

  s21_determinant(&A, &det);
  ck_assert_double_eq(det, 0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_2) {
  matrix_t A;
  double det = 0;
  s21_create_matrix(4, 4, &A);

  char str1[] = "18, 6, 13, 14, 8, 12, 12, 0, 8, 110, 1, 5, 5, 16, 7, 0";
  matrix_from_string(str1, &A);

  s21_determinant(&A, &det);
  ck_assert_int_eq((int)det, 196);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_3) {
  matrix_t A;
  double det = 0;
  s21_create_matrix(3, 3, &A);

  char str1[] = "2, 5, 4, -2, 4, 3, 1, 0, -2";
  matrix_from_string(str1, &A);

  s21_determinant(&A, &det);
  ck_assert_double_eq((int)det, -37);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_4) { ck_assert_int_eq(s21_determinant(NULL, NULL), 1); }
END_TEST

START_TEST(determinant_5) {
  matrix_t A;

  s21_create_matrix(3, 3, &A);

  char str1[] = "2, 5, 4, -2, 4, 3, 1, 0, -2";
  matrix_from_string(str1, &A);

  ck_assert_double_eq(s21_determinant(&A, NULL), 1);

  s21_remove_matrix(&A);
}
END_TEST

Suite *determinant(void) {
  Suite *s = suite_create("determinant");
  TCase *tc = tcase_create("determinant");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, determinant_1);
  tcase_add_test(tc, determinant_2);
  tcase_add_test(tc, determinant_3);
  tcase_add_test(tc, determinant_4);
  tcase_add_test(tc, determinant_5);

  return s;
}
