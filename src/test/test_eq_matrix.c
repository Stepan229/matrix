#include "../test.h"

START_TEST(eq_matrix_1) {
  matrix_t A;
  matrix_t B;

  s21_create_matrix(2, 5, &A);
  s21_create_matrix(2, 5, &B);

  char str[] =
      "3.123 2.123 1.1231 2.123 3.53123 1.12333 2.12321 1.9004 2.53123 312";
  char str1[] =
      "3.123 2.123 1.1231 2.123 3.53123 1.12333 2.12321 1.9004 2.53123 312";

  matrix_from_string(str, &A);
  matrix_from_string(str1, &B);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_2) {
  matrix_t A;
  matrix_t B;

  s21_create_matrix(2, 5, &A);
  s21_create_matrix(2, 5, &B);

  char str[] =
      "3.123 2.123 1.1231 2.123 3.53123 1.12333 2.12321 1.9004 2.53123 312";

  matrix_from_string(str, &A);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_3) {
  matrix_t A;
  matrix_t B;

  s21_create_matrix(2, 5, &A);
  s21_create_matrix(2, 5, &B);

  char str1[] =
      "3.123 2.123 1.1231 2.123 3.5312334 1.12712371 2.12321 1.9004 "
      "2.53123 312";
  char str2[] =
      "3.123 2.123 1.1231 2.123 3.5312334 1.12712371 2.12321 1.9004 "
      "2.53123 312";

  matrix_from_string(str1, &A);
  matrix_from_string(str2, &B);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_4) {
  matrix_t A;
  matrix_t B;

  s21_create_matrix(2, 5, &A);
  s21_create_matrix(2, 5, &B);

  char str1[] =
      "3.123 2.123 1.1231 2.123 3.53123 1.12333 2.12321 1.9004 2.53123 313";
  char str2[] =
      "3.123 2.123 1.1231 2.123 3.53123 1.12333 2.12321 1.9004 2.53123 312";

  matrix_from_string(str1, &A);
  matrix_from_string(str2, &B);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_5) {
  matrix_t A;
  matrix_t B;

  s21_create_matrix(3, 5, &A);
  s21_create_matrix(2, 5, &B);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *eq_matrix(void) {
  Suite *s = suite_create("eq_matrix");
  TCase *tc = tcase_create("eq_matrix");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, eq_matrix_1);
  tcase_add_test(tc, eq_matrix_2);
  tcase_add_test(tc, eq_matrix_3);
  tcase_add_test(tc, eq_matrix_4);
  tcase_add_test(tc, eq_matrix_5);

  return s;
}
