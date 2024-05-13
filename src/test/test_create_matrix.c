#include "../test.h"

START_TEST(create_matrix_1) {
  matrix_t A;

  ck_assert_int_eq(s21_create_matrix(2, 5, &A), 0);
  ck_assert_int_eq(A.rows, 2);
  ck_assert_int_eq(A.columns, 5);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_matrix_2) {
  matrix_t A;

  ck_assert_int_eq(s21_create_matrix(3, 9, &A), 0);
  ck_assert_int_eq(A.rows, 3);
  ck_assert_int_eq(A.columns, 9);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_matrix_3) {
  matrix_t A;

  ck_assert_int_eq(s21_create_matrix(-4, 2, &A), 2);
}
END_TEST

START_TEST(create_matrix_4) {
  matrix_t A;

  ck_assert_int_eq(s21_create_matrix(1, -3, &A), 2);
}
END_TEST

START_TEST(create_matrix_5) {
  ck_assert_int_eq(s21_create_matrix(-1, -3, NULL), 1);
}
END_TEST

Suite *create_matrix(void) {
  Suite *s = suite_create("create_matrix");
  TCase *tc = tcase_create("create_matrix");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, create_matrix_1);
  tcase_add_test(tc, create_matrix_2);
  tcase_add_test(tc, create_matrix_3);
  tcase_add_test(tc, create_matrix_4);
  tcase_add_test(tc, create_matrix_5);

  return s;
}