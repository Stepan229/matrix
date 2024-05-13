#include "../test.h"

START_TEST(remove_matrix_1) {
  matrix_t A;

  s21_create_matrix(2, 5, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
}
END_TEST

START_TEST(remove_matrix_2) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
}
END_TEST

START_TEST(remove_matrix_3) {
  matrix_t A;

  s21_create_matrix(2, 2, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
}
END_TEST

START_TEST(remove_matrix_4) {
  matrix_t A;

  s21_create_matrix(3, 1, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
}
END_TEST

Suite *remove_matrix(void) {
  Suite *s = suite_create("remove_matrix");
  TCase *tc = tcase_create("remove_matrix");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, remove_matrix_1);
  tcase_add_test(tc, remove_matrix_2);
  tcase_add_test(tc, remove_matrix_3);
  tcase_add_test(tc, remove_matrix_4);

  return s;
}